ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m += servobasic-str.o

EXTRA_CFLAGS := -I/usr/realtime/include -I/usr/include/
EXTRA_LDFLAGS := -lcomedi -lm -lrtai
else
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
endif
