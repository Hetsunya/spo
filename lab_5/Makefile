obj-m += random_gen.o


mod:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
main:
	gcc program_with_mod/main.c -o main
all: mod main

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm *.o
