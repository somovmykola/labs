
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

/*Insert code so that "position" may be passed on to the module as a parameter while loading.
Since we do not want to use floats in the code, use equivalent nanoseconds for milliseconds */


#define MIN_POSITION 200000      //0.2 ms
#define CYCLE_PERIOD 20000000    //20 ms
#define STEP 100000              //control the motor step, ~10 degree on step. Also used for tick period for timer 

/* Insert code that generates the pulse here. It can be done by sending a high signal (1) to the relevant channel of a sub-device
   on the device (card). You can use sub-device 2 for this purpose*/ 
void task_code( int arg) {
	
	//Any declarations etc
	
           /* start an infinite loop */
  for (;;) { 
	  /* send a high signal to channel 0 of sub-device 2  */
              
              /* wait a while (on time) */
      /* stay on for sometime (on time) */
    		rt_sleep(nano2count(MIN_POSITION+position));
      /* send a low signal to channel 0 of sub-device 2  */
      
     // Suspend the task until the next period
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

  /* Add  code to do the following:
     1. Start the timer in periodic mode with a time tick of 0.1 ms
     2. init the RT_TASK structure
     3. start the RT_Task in periodic mode with period = 20 ms
 */

       
     return 0;
  }
 

/*
void cleanup_module(void) {

  /* Add code to do the following:
    delete the rttask
    stop timer  stop_rt_timer();
  printk("servobasic: stopped, position=%i\n",position);
}
MODULE_LICENSE("GPL"); /* Avoids kernel taint message*/

*/
