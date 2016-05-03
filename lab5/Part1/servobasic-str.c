
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
comedi_t * device;

RT_TASK task_data;

static int position=0;
//MODULE_PARAM(position, "i");

/*Insert code so that "position" may be passed on to the module as a parameter while loading.
Since we do not want to use floats in the code, use equivalent nanoseconds for milliseconds */


#define MIN_POSITION 200000      //0.2 ms
#define CYCLE_PERIOD 20000000    //20 ms
#define STEP 100000              //control the motor step, ~10 degree on step. Also used for tick period for timer 

/* Insert code that generates the pulse here. It can be done by sending a high signal (1) to the relevant channel of a sub-device
   on the device (card). You can use sub-device 2 for this purpose*/ 
void task_code( int arg) {
	
	
	RTIME nowns = rt_get_time();

	//Any declarations etc
	
           /* start an infinite loop */
  for (;;) { 
	  /* send a high signal to channel 0 of sub-device 2  */
	comedi_data_write(device,2,0,0,0,1);        
//comedi_dio_write(0,0,2,1);  
// enter a port here	outb()
              /* wait a while (on time) */
	nowns += STEP + position;
      /* stay on for sometime (on time) */
    		rt_sleep(nano2count(MIN_POSITION+position));
      /* send a low signal to channel 0 of sub-device 2  */
      
	comedi_data_write(device,2,0,0,0,0);
//	comedi_dio_write(0,0,2,0);
// set port to off here outb(whatever)

	nowns += CYCLE_PERIOD - position;

	//rt_sleep(nano2count(MIN_POSITION+position));

	rt_task_wait_period();
     // Suspend the task until the next period

	
   /* end of loop                    */
   }
}


int init_module(void) {
	// initialize the comedi, open a device and configure channel 2 for output
	RTIME r_period_count;	/* requested timer period, in counts */
        RTIME timer_period_count;	/* actual timer period, in counts */
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

  /* Add  code to do the following:
     1. Start the timer in periodic mode with a time tick of 0.1 ms
     2. init the RT_TASK structure
     3. start the RT_Task in periodic mode with period = 20 ms
 */

	rt_set_periodic_mode();

	timer_period_count = start_rt_timer(STEP);

	  ret = 
    		 rt_task_init(&task_data,	/* pointer to our task structure */
		 task_code, /* the actual timer function */
		 0,		/* initial task parameter; we ignore */
		 1024,		/* 1-K stack is enough for us */
		 0, /* lowest is fine for our 1 task */
		 0,		/* uses floating point; we don't */
		 0);		/* signal handler; we don't use signals */

	  //RTIME period = 20000000;

	
	  ret = rt_task_make_periodic(&task_code, /* pointer to our task structure */
			  /* start one cycle from now */
			  rt_get_time()+nano2count(STEP), 
			  nano2count(200000000)); /* recurring period As period = 0.01 s,*/

	

       
     return 0;
  }
 


void cleanup_module(void) {


	RT_TASK * rttask_struct;
	
	rttask_struct = rt_task_delete(rttask_struct);

	stop_rt_timer();

  /* Add code to do the following:
    delete the rttask
    stop timer  stop_rt_timer();
  printk("servobasic: stopped, position=%i\n",position);
}
MODULE_LICENSE("GPL"); /* Avoids kernel taint message*/

}



