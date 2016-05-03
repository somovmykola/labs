
// Use the Makefile created in 'module' directory to compile  
/* This  file gives you a structure of the code required to generate a
PWM type of signal to control the servomotor. This file should be used as a 
set of hints for coding. You will have to pick up suitable functions from comedi
and RTAI to complete the program */

/*In the lab we have found that 0.2 ms high pulse moves the motor to extreme left position
1.8 ms moves it to 180 degrees and 0.9 ms to middle position. We can use a step 0 0.1ms
for moving in-between. We also use 0.1ms as the timer tick for periodic timer*/       

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/version.h>
#include <asm/io.h>

#include <rtai.h>
#include <rtai_sched.h>

#include <rtai_comedi.h>

#if ! defined(RT_LOWEST_PRIORITY)
#if defined(RT_SCHED_LOWEST_PRIORITY)
#define RT_LOWEST_PRIORITY RT_SCHED_LOWEST_PRIORITY
#else
#error RT_SCHED_LOWEST_PRIORITY not defined
#endif
#endif


comedi_t * device;

RT_TASK task_data;

int Kp=1;
int Ki=1;
int Kd=0;


static int position=16384;



module_param(position, int, 0000);
MODULE_PARM_DESC(position, "pos");

static RTIME t_period_ns;

unsigned int MAXDATA = 65535;

int newout = 0;
int errorC=0;
int errorP=0;
int error2=0;
int pComp=0;
int iComp=0;
int dComp=0;
int count=0;

lsampl_t data;

/*Insert code so that "position" may be passed on to the module as a parameter while loading.
Since we do not want to use floats in the code, use equivalent nanoseconds for milliseconds */


#define MIN_POSITION 200000      //0.2 ms
#define CYCLE_PERIOD 20000000    //5 ms
#define STEP 100000              //control the motor step, ~10 degree on step. Also used for tick perio

/* Insert code that generates the pulse here. It can be done by sending a high signal (1) to the relevant channel of a sub-device
   on the device (card). You can use sub-device 2 for this purpose*/ 


void task_code( int arg) {
	
	//Any declarations etc
	
      printk("4AA4 Kp = %d, Ki = %d, Kd = %d \n", Kp, Ki, Kd);
      printk("4AA4 run -------------------------------------------------------------- \n");

        
           /* start an infinite loop */
      for (;;) 
    { 
      count++;

      comedi_data_read(device, 0, 0, 1, AREF_DIFF, &data);

      errorC = position-data;

      errorP = errorC;
     
      if(errorC>32767   )//re voltage will be withing +5 and -5
       {
	 errorC -= 65535;
       }

      else if(errorC<-32767       )
	{
	  errorC += 65535;
	}

      pComp = Kp*errorC;
      iComp += (Ki*errorC)/20;
      dComp = 20000*Kd*(errorC-errorP);

      comedi_data_write(device,1,0,0,AREF_DIFF,pComp+iComp+(dComp/1000));

      if(count%5==0)
	{
	  printk("4AA4 current output: %d\n",data);
	}
      rt_task_wait_period();

     /* end of loop                    */
    }
}


int init_module(void) {
	// initialize the comedi, open a device and configure channel 2 for output
	int ret;
        device = comedi_open("/dev/comedi0");

        if(!device){
                printk(KERN_WARNING "Failed to open comedi device\n");
                return -1;
        }

        ret = comedi_dio_config(device, 2, 0, COMEDI_OUTPUT);
        if(!ret){
                printk(KERN_WARNING "Failed to configure device\n");
                return -2;
        }


	/*initialization of task and timer*/
	RTIME r_period_count; /*requested timer period, in counts*/
	RTIME timer_period_count; /*actual timer period in counts*/
	int retval;

	
	
	t_period_ns = 100000;
	rt_set_periodic_mode();

	r_period_count = nano2count(t_period_ns);
	timer_period_count = start_rt_timer(r_period_count);


	retval = 
    rt_task_init(&task_data,	/* pointer to our task structure */
		 task_code, /* the actual timer function */
		 0,		/* initial task parameter; we ignore */
		 1024,		/* 1-K stack is enough for us */
		 RT_LOWEST_PRIORITY, /* lowest is fine for our 1 task */
		 0,		/* uses floating point; we don't */
		 0);		/* signal handler; we don't use signals */
	if (0 != retval) {
	  if (-EINVAL == retval) {
	    /* task structure is already in use */
	    printk("periodic task: task structure already in use\n");
	  } else if (-ENOMEM == retval) {
	    /* stack could not be allocated */
	    printk("periodic task: can't allocate stack\n");
	  } else {
	    /* unknown error */
	    printk("periodic task: error initializing task structure\n");
	  }
	  return retval;
	}


  retval = 
    rt_task_make_periodic(&task_data, /* pointer to our task structure */
			  /* start one cycle from now */
			  rt_get_time() + timer_period_count, 
			  200*timer_period_count); 
    
  if (0 != retval) {
    if (-EINVAL == retval) {
      /* task structure is already in use */
      printk("periodic task: task structure is invalid\n");
    } else {
      /* unknown error */
      printk("periodic task: error starting task\n");
    }
    return retval;
  }

  /* Add  code to do the following:
     1. Start the timer in periodic mode with a time tick of 0.1 ms
     2. init the RT_TASK structure
     3. start the RT_Task in periodic mode with period = 20 ms
 */

       
     return 0;
  }
 


void cleanup_module(void) {

  int retval;

  retval = rt_task_delete(&task_data);

  if (0 !=  retval) {
    if (-EINVAL == retval) {
      /* invalid task structure */
      printk("periodic task: task structure is invalid\n");
    } else {
      printk("periodic task: error stopping task\n");
    }
  }

  stop_rt_timer();
 
  /* Add code to do the following:
    delete the rttask
    stop timer  stop_rt_timer();
  printk("servobasic: stopped, position=%i\n",position);
  */
}

MODULE_LICENSE("GPL"); /* Avoids kernel taint message*/


