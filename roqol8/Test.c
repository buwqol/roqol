#include "Bits.h"
#include "Test.h"
void test_NAND(void)
{
	TEST(NAND(0, 0) == 1);
	TEST(NAND(0, 1) == 1);
	TEST(NAND(1, 0) == 1);
	TEST(NAND(1, 1) == 0);
}
void test_NOT(void)
{
	TEST(NOT(0) == 1);
	TEST(NOT(1) == 0);
}
int main(void)
{
	test_NAND();
	test_NOT();

	printf("ALL TESTS PASSED!\n");
	return 0;
}
