#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Random Number Generator Character Device Driver");

#define DEVICE_NAME "random_gen"
#define BUF_SIZE 20

static int major_number;
static char message[BUF_SIZE];
static short size_of_message;

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);

static struct file_operations fops = {
    .read = device_read,
    .open = device_open,
    .release = device_release
};

static int __init random_gen_init(void) {
    major_number = register_chrdev(0, DEVICE_NAME, &fops);

    if (major_number < 0) {
        printk(KERN_ALERT "Failed to register a major number\n");
        return major_number;
    }

    printk(KERN_INFO "Random Number Generator: registered correctly with major number %d\n", major_number);
    return 0;
}

static void __exit random_gen_exit(void) {
    unregister_chrdev(major_number, DEVICE_NAME);
    printk(KERN_INFO "Random Number Generator: Goodbye from the LKM!\n");
}

static int device_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Random Number Generator: Device opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "Random Number Generator: Device closed\n");
    return 0;
}

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset) {
    int bytes_read = 0;
    unsigned int rand_num;

    get_random_bytes(&rand_num, sizeof(rand_num));

    if (size_of_message > 0) {
        while (length && message[size_of_message - 1] != '\0') {
            put_user(message[size_of_message - 1], buffer++);
            length--;
            size_of_message--;
            bytes_read++;
        }
    } else {
        bytes_read = snprintf(message, BUF_SIZE, "%u", rand_num);
        size_of_message = bytes_read;
        while (length && message[size_of_message - 1] != '\0') {
            put_user(message[size_of_message - 1], buffer++);
            length--;
            size_of_message--;
            bytes_read++;
        }
    }

    return bytes_read;
}

module_init(random_gen_init);
module_exit(random_gen_exit);
