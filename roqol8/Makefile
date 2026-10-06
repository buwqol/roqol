CC = gcc

CFLAGS = -Wall -Wextra -std=c99 \
	-DROQOL_NAND_ONLY
	# -DROQOL_LOGICAL_NAND

OUT = ../Binaries/roqol8

OBJS = \
	../Binaries/roqol8_Bits.o \
	../Binaries/roqol8_Main.o

TEST = ../Binaries/roqol8_test

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT)

../Binaries/roqol8_Bits.o: Bits.c Bits.h
	$(CC) $(CFLAGS) -c Bits.c -o $@

../Binaries/roqol8_Main.o: Main.c Bits.h
	$(CC) $(CFLAGS) -c Main.c -o $@

.PHONY: test

test:
	$(CC) $(CFLAGS) Test.c -o $(TEST)
	$(TEST)

clean:
	rm -f $(OBJS) $(OUT) $(TEST)