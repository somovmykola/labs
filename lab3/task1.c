
// Use the Makefile created in 'module' directory to compile         

#include <linux/module.h> /* Declarations needed for kernel modules */
#include <linux/kernel.h>
#include <linux/version.h> /* LINUX_VERSION_CODE, KERNEL_VERSION() */
#include <asm/io.h>
#include <linux/errno.h>    /* EINVAL, ENOMEM */

#include <rtai.h>  /*RTAI configuration switches*/
#include <rtai_sched.h> /* rt_set_periodic_mode(), start_rt_timer(),
				   nano2count(), RT_LOWEST_PRIORITY,
				   rt_task_init(), rt_task_make_periodic() */



RT_TASK task_one;


void task_code( int arg)
 {
    printk("Hello, I am task1 %p\n", rt_whoami()); /* Print task Id */
}
           
  



  /* Add  code to do the following:
     1. init the RT_TASK structure
     2. start the RT_Task
 */

    int init_module( void) {
       RT_TASK * rttask_struct;
       void * rttask_code;
       int rttask_param;
       int rttask_stack;
       int rttask_priority;
       int rttask_use_fp;
       void * rttask_signal;
       int retvalue;
       
  rt_set_oneshot_mode();/*Set timer in one-shot mode*/
  start_rt_timer(0); /* Start the timer with a dummy value 0*/

       
     /* Set up the rt task   */
       rttask_struct   = &task_one ;
       rttask_code     = task_code  ;
       rttask_stack    = 1024       ;
       rttask_param    = 0          ;
       rttask_priority = RT_SCHED_LOWEST_PRIORITY;
       rttask_use_fp   = 0          ;
       rttask_signal   = NULL       ;
    
       //Create the rt task
       retvalue = rt_task_init(rttask_struct,
                        rttask_code,
                        rttask_param,
                        rttask_stack,
                        rttask_priority,
                        rttask_use_fp,
                        rttask_signal);
/* Note: the above initialization can be done directly by passing values to
   the  rt_task_init as follows:
 retvalue = rt_task_init(&task_one, task_code, 1024, 0, 
                         RT_SCHED_LOWEST_PRIORITY, 0, 0);
However the code used in this example shows some of the fields of the task structure.*/

     /*Ensure the task is created*/
     if (0 != retvalue) {
        if (-EINVAL == retvalue) {
            /* task structure is already in use */
            printk("Task1: task structure is invalid\n");
        } else {
            /* unknown error */
            printk("Task1: error starting task\n");
        }
        return retvalue;
    }
     /* Start up the rt task */
    rt_task_resume(rttask_struct);
    printk("Task1: started\n");
     return 0;
  }
 
void cleanup_module( void) {
RT_TASK * rttask_struct;
        stop_rt_timer();
        rttask_struct = &task_one;
        rt_task_delete(rttask_struct);
        
        printk(" Task1: stopped\n");  
  }

MODULE_LICENSE("GPL"); /* Avoids kernel taint message*/

