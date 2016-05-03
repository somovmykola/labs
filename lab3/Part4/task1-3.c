
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
#include <rtai_sem.h>

SEM  sema;

void init_sema() {

	rt_typed_sem_init(&sema,0,BIN_SEM);
}

RT_TASK task_one;
RT_TASK task_two;
RT_TASK task_three;


void task_code( int arg)
 {
rt_sem_wait(&sema);
    printk("Hello, I am task%d %p\n",arg, rt_whoami()); /* Print task Id */
}



  /* Add  code to do the following:
     1. init the RT_TASK structure
     2. start the RT_Task
 */

    int init_module( void) {
       RT_TASK * rttask_struct;
       RT_TASK * rttask_struct2;
       RT_TASK * rttask_struct3;
       void * rttask_code;
       int rttask_param;
       int rttask_stack;
       int rttask_priority;
       int rttask_use_fp;
       void * rttask_signal;
       int retvalue;
       int retvalue2;
       int retvalue3;
       
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




       retvalue = rt_task_init_cpuid(rttask_struct,
                        rttask_code,
                        1,
                       1024,
                        1,
                        rttask_use_fp,
                        rttask_signal, 0);

       rttask_struct2   = &task_two ;	

       retvalue2 = rt_task_init_cpuid(rttask_struct2,
                        rttask_code,
                        2,
                        rttask_stack,
                        0,
                        rttask_use_fp,
                        rttask_signal,0);

       rttask_struct3   = &task_three ;

       retvalue3 = rt_task_init_cpuid(rttask_struct3,
                        rttask_code,
                        3,
                        rttask_stack,
                        0,
                        rttask_use_fp,
                        rttask_signal,0);

        init_sema();

/* Note: the above initialization can be done directly by passing values to
   the  rt_task_init as follows:
 retvalue = rt_task_init(&task_one, task_code, 1024, 0, 
                         RT_SCHED_LOWEST_PRIORITY, 0, 0);
However the code used in this example shows some of the fields of the task structure.*/

     /*Ensure the task is created*/
     if (0 != retvalue&&retvalue2&&retvalue3) {
        if (-EINVAL == retvalue||retvalue2||retvalue3) {
            /* task structure is already in use */
            printk("Task1: task structure is invalid\n");
        } else {
            /* unknown error */
            printk("Task1: error starting task\n");
        }
    if (0==retvalue) return retvalue;
    if (0==retvalue2) return retvalue2;
    else return retvalue3;
	
	
    }
     /* Start up the rt task 

	rt_task_init_cpuid(&task_one,
				 rttask_code,
				 0,
				 1024,
				 2,
				 0,
				 NULL,
				 0
				 );				

	        rt_task_init_cpuid(&task_two,
                                 rttask_code,
                                 0,
                                 1024,
                                 1,
                                 0,
                                 NULL,
                                 0
				 );

        rt_task_init_cpuid(&task_three,
                                 rttask_code,
                                 0,
                                 1024,
                                 0,
                                 0,
                                 NULL,
                                 0);
		

*/

    rt_task_resume(rttask_struct);

    rt_task_resume(rttask_struct2);

    rt_task_resume(rttask_struct3);

    
	rt_sem_delete(&sema);

    printk("Task1: started\n");
     return 0;
  }
 
void cleanup_module( void) {
RT_TASK * rttask_struct;
        stop_rt_timer();
        rttask_struct = &task_one;
        rt_task_delete(rttask_struct);
       
RT_TASK * rttask_struct2;
        rttask_struct = &task_two;
        rt_task_delete(rttask_struct);

RT_TASK * rttask_struct3;
        rttask_struct = &task_three;
        rt_task_delete(rttask_struct);


 
        printk(" Task1: stopped\n");  




  }

MODULE_LICENSE("GPL"); /* Avoids kernel taint message*/

