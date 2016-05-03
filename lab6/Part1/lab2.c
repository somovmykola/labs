
// Use the Makefile created in 'module' directory to compile         

#include <linux/module.h> /* Declarations needed for kernel modules */
#include <linux/kernel.h>
#include <linux/version.h> /* LINUX_VERSION_CODE, KERNEL_VERSION() */
#include <asm/io.h>
#include <linux/errno.h>    /* EINVAL, ENOMEM */

#include <rtai.h>  /*RTAI configuration switches*/
#include <rtai_sched.h> 
#include <rtai_sem.h>

static RTIME t_period_ns = 100;

SEM  sema;

void init_sema() {

	rt_typed_sem_init(&sema,0,BIN_SEM);
}

RT_TASK task_one;
RT_TASK task_two;
RT_TASK task_three;


/*void task_code( int arg)
 {
rt_sem_wait(&sema);
    printk("Hello, I am task%d %p\n",arg, rt_whoami()); /* Print task Id */
//}



void task_code(int arg)
{
	//if (ioperm(0x61,1,1)) {perror("ioperm"); exit(1);}  
//int ioperm(0x61,1,1);
  //unsigned char toggle = 0;

  while (1) {
    /*
      Check the toggle and print a message
     */

    rt_sem_wait(&sema);
    printk("Hello, I am task %d %p\n",arg, rt_whoami());
 
    /*if (toggle) {
	outb(inb(0x61)|0x02, 0x61);
       //rt_printk("Toggle is not 0\n");
    } else {
	outb(inb(0x61)&0xfd, 0x61);
       //rt_printk("Toggle is 0\n");
    }
      rt_printk("Waiting for next period...\n");
    toggle = ! toggle; //Change the toggle value*/

    /*
      Wait one period by calling

      void rt_task_wait_period(void);

      which applies to the currently executing task, and uses the period
      set up in its task structure.
    */
    rt_task_wait_period();
  }

  /* we'll never get here */
  return;
}


int init_module( void) {

  RTIME r_period_count;	/* requested timer period, in counts */
  RTIME timer_period_count;	/* actual timer period, in counts */
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
	int retval;
  
  rt_set_periodic_mode();/*Set timer in one-shot mode*/
  //r_period_count = nano2count(t_period_ns);
  //timer_period_count = start_rt_timer(r_period_count);
       
 
  //start_rt_timer(0); /* Start the timer with a dummy value 0*/

       
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
                        0,
                        rttask_use_fp,
                        rttask_signal, 0);

       rttask_struct2   = &task_two ;	

       retvalue2 = rt_task_init_cpuid(rttask_struct2,
                        rttask_code,
                        2,
                        1024,
                        0,
                        rttask_use_fp,
                        rttask_signal,0);

       rttask_struct3   = &task_three ;

       retvalue3 = rt_task_init_cpuid(rttask_struct3,
                        rttask_code,
                        3,
                        1024,
                        0,
                        rttask_use_fp,
                        rttask_signal,0);

        init_sema();


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
	

	retvalue = 
    		rt_task_make_periodic(&rttask_struct, /* pointer to our task structure */
			  /* start one cycle from now */
			  rt_get_time() +timer_period_count, 
			  10*timer_period_count); /* recurring period As period = 0.01 s, the 					task will repeat every 0.1 seconds*/

	retvalue2 = 
    		rt_task_make_periodic(&rttask_struct2, /* pointer to our task structure */
			  /* start one cycle from now */
			  rt_get_time()+ timer_period_count, //+ timer_period_count, 
			  10*timer_period_count); /* recurring period As period = 0.01 s, the 					task will repeat every 0.1 seconds*/

	retvalue3 = 
    		rt_task_make_periodic(&rttask_struct3, /* pointer to our task structure */
			  /* start one cycle from now */
			  rt_get_time()+timer_period_count, 
			  10*timer_period_count); /* recurring period As period = 0.01 s, the 					task will repeat every 0.1 seconds*/






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

