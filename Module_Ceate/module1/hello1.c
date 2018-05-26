/*  
 *  hello1.c - src of "hello world" kernel module.
 */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for Alerts and KERN_INFO */

int init_module(void)
{
	printk(KERN_INFO "Srinath Koilakonda: loading Hello world module -Hello world.\n");

	/* 
	 * A non 0 return means init_module failed; module can't be loaded. 
	 */
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Srinath Koilakonda:  Exiting Hello world module-Good bye world.\n");
}

