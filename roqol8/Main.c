#include <stdio.h>
#include "Bits.h"

int main(void)
{
	printf("0 NAND 0: %d\n", tBit_NAND(0, 0) ? 1 : 0);
	printf("0 NAND 1: %d\n", tBit_NAND(0, 1) ? 1 : 0);
	printf("1 NAND 0: %d\n", tBit_NAND(1, 0) ? 1 : 0);
	printf("1 NAND 1: %d\n", tBit_NAND(1, 1) ? 1 : 0);
	return 0;
}
