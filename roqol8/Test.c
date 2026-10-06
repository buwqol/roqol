#include "Bits.h"
#include "Test.h"
void test_NAND(void)
{
	TEST(NAND(0, 0) == 1);
	TEST(NAND(0, 1) == 1);
	TEST(NAND(1, 0) == 1);
	TEST(NAND(1, 1) == 0);
}
void test_AND(void)
{
	TEST(AND(0, 0) == 0);
	TEST(AND(0, 1) == 0);
	TEST(AND(1, 0) == 0);
	TEST(AND(1, 1) == 1);
}
void test_OR(void)
{
	TEST(OR(0, 0) == 0);
	TEST(OR(0, 1) == 1);
	TEST(OR(1, 0) == 1);
	TEST(OR(1, 1) == 1);
}
void test_NOR(void)
{
	TEST(NOR(0, 0) == 1);
	TEST(NOR(0, 1) == 0);
	TEST(NOR(1, 0) == 0);
	TEST(NOR(1, 1) == 0);
}
void test_XOR(void)
{
	TEST(XOR(0, 0) == 0);
	TEST(XOR(0, 1) == 1);
	TEST(XOR(1, 0) == 1);
	TEST(XOR(1, 1) == 0);
}
void test_XNOR(void)
{
	TEST(XNOR(0, 0) == 1);
	TEST(XNOR(0, 1) == 0);
	TEST(XNOR(1, 0) == 0);
	TEST(XNOR(1, 1) == 1);
}
void test_NOT(void)
{
	TEST(NOT(0) == 1);
	TEST(NOT(1) == 0);
}
int main(void)
{
	test_NAND();
	test_AND();
	test_NOT();
	test_NOR();
	test_OR();
	test_XOR();
	test_XNOR();

	printf("ALL TESTS PASSED!\n");
	return 0;
}
