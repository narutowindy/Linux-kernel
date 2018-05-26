/**/
/*
 *  hello-5.c - Demonstrates command line argument passing to a module.
 */
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Srinath Koilakonda");

static char *myname = "Srinath koilakonda";
static char *street = "12 elizabeth st";
static char *City = "Jersey city";
static long int Zip = 07306;

/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

module_param(myname, charp, 0000);
MODULE_PARM_DESC(myname, "My name");
module_param(street, charp, 0000);
MODULE_PARM_DESC(street, "my street adress");
module_param(City, charp, 0000);
MODULE_PARM_DESC(City, "My city");
module_param(Zip, long, 0000);
MODULE_PARM_DESC(Zip, "my zip code");

/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */

static int __init hello3_init(void)
{
	int i;
	printk(KERN_INFO "LOADING Hello 3, Hello world 3\n===============\n");
	printk(KERN_INFO "name: %s\n", myname);
	printk(KERN_INFO "Street : %s\n", street);
	printk(KERN_INFO "City : %s\n", City);
	printk(KERN_INFO "Zip : %ld\n", Zip);
	return 0;
}

static void __exit hello3_exit(void)
{
	printk(KERN_INFO "Goodbye, world 3\n");
}

module_init(hello3_init);
module_exit(hello3_exit);
