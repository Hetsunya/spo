#include <linux/kernel.h>
#include <linux/module.h>

int init_module(void)
{
    pr_info("Hello world!\n");
    return 0;
}

void cleanup_module(void)
{
    pr_info("Goodbye world!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("LKMPG");
MODULE_DESCRIPTION("A sample char device driver");
