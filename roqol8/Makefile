CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OUT = ../Binaries/roqol8

OBJS = \
	../Binaries/roqol8_Bits.o \
	../Binaries/roqol8_Main.o

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

../Binaries/roqol8_Bits.o: Bits.c Bits.h
	$(CC) $(CFLAGS) -c Bits.c -o $@

../Binaries/roqol8_Main.o: Main.c Bits.h
	$(CC) $(CFLAGS) -c Main.c -o $@

clean:
	rm -f $(OBJS) $(OUT)