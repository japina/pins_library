SRCS = pins.c stm32f0xx_gpio.c stm32f0xx_rcc.c


###################################################

CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

CFLAGS  = -g -O2 -Wall 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m0 -mthumb-interwork
CFLAGS += -mfloat-abi=soft
CFLAGS += -ffreestanding -nostdlib

###################################################

vpath %.c src

ROOT=$(shell pwd)

CFLAGS += -I../libs/inc -I../libs/inc/core -I../libs/inc/peripherals

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: libpins.a

all: libpins.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libpins.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libpins.a
