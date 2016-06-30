CC=arm-none-eabi-gcc
CP=arm-none-eabi-g++
OC=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump
LD=arm-none-eabi-ld

CCFLAGS=-lctr
CPFLAGS=
OCFLAGS=
ODFLAGS=
LDFLAGS=

PROJNAME=arm9loaderhax_si

all:
	@mkdir temp
	$(CC) -g source/*.c source/sdmmc/*.c -c -march=armv5te -O2 -ffast-math -std=c99 -Wall
	$(CC) -g source/*.s source/sdmmc/*.s -c -march=armv5te
	@mv start.o temp/start.o
	$(CC) -T 3ds.ld temp/start.o *.o $(CCFLAGS)
	$(OC) --set-section-flags .bss=alloc,load,contents -O binary a.out $(PROJNAME).bin
	@rm -rf *.out
	@rm -rf *.o

clean:
	@rm -rf *.o temp/*
	@rm -rf $(PROJNAME).bin
	@rmdir temp