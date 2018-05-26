  static int my_ker_thd_1 (void *unused){
       struct task_struct *c_task = current ;
       struct task_struct *task;
       strcpy(c_task -> comm, "SRINATH_KTHREAD_1");
       schedule();
       task = current;
           for_each_process(task){
               printk(KERN_NOTICE " SRINATH : \t UID \tPID\tPPID");
               printk(KERN_NOTICE " SRINATH : \t root\t%d",task->pid,task->parent->pid);
           }
       printk(KERN_NOTICE " SRINATH : my_ker_thd_1 is scheduled.");
       return 0;
   }

   static int my_ker_thd_2 (void *unused){
       struct task_struct *c_task = current ;
       struct task_struct *task;
       strcpy(c_task -> comm, "SRINATH_KTHREAD_2");
       schedule();
       task = current;                                                                                      
           for_each_process(task){                                                                          
               printk(KERN_NOTICE " SRINATH : \t UID \tPID\tPPID");                                         
               printk(KERN_NOTICE " SRINATH : \t root\t%d",task->pid,task->parent->pid);                    
           }                                                                                                
       printk(KERN_NOTICE " SRINATH KOILAKONDA: my_ker_thd_2 is scheduled.");                               
       return 0;                                                                                            
   }                                                                                                        
                                                                                                            
   static void my_kernel_thread_create_1(void){                                                             
       int mypid;                                                                                           
       printk(KERN_NOTICE "SRINATH KOILAKONDA: Calling kernel_thread(my_ker_thd_1)");                       
       mypid = kernel_thread(my_ker_thd_1, NULL, CLONE_FS);                                                 
       printk(KERN_NOTICE "SRINATH KOILAKONDA : my_ker_thd_1 = %d", mypid);                                 
   }                                                                                                        
   static void my_kernel_thread_create_2(void){                                                             
       int mypid;                                                                                           
       printk(KERN_NOTICE "SRINATH KOILAKONDA: Calling kernel_thread(my_ker_thd_2)");                       
        mypid = kernel_thread(my_ker_thd_2, NULL, CLONE_FS);                                                
       printk(KERN_NOTICE "SRINATH KOILAKONDA: my_ker_thd_2 = %d", mypid);                                  
  }       
