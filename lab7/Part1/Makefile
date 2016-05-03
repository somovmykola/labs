ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m += lab7-11.o

EXTRA_CFLAGS := -I/usr/realtime/include -I/usr/include/
else
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
endif
