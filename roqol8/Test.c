#include "Bits.h"
#include "Test.h"
void test_NAND(void)
{
	TEST(tBit_Nand(tBit_Low, tBit_Low) == tBit_High);
	TEST(tBit_Nand(tBit_Low, tBit_High) == tBit_High);
	TEST(tBit_Nand(tBit_High, tBit_Low) == tBit_High);
	TEST(tBit_Nand(tBit_High, tBit_High) == tBit_Low);
}
void test_AND(void)
{
	TEST(tBit_And(tBit_Low, tBit_Low) == tBit_Low);
	TEST(tBit_And(tBit_Low, tBit_High) == tBit_Low);
	TEST(tBit_And(tBit_High, tBit_Low) == tBit_Low);
	TEST(tBit_And(tBit_High, tBit_High) == tBit_High);
}
void test_OR(void)
{
	TEST(tBit_Or(tBit_Low, tBit_Low) == tBit_Low);
	TEST(tBit_Or(tBit_Low, tBit_High) == tBit_High);
	TEST(tBit_Or(tBit_High, tBit_Low) == tBit_High);
	TEST(tBit_Or(tBit_High, tBit_High) == tBit_High);
}
void test_NOR(void)
{
	TEST(tBit_Nor(tBit_Low, tBit_Low) == tBit_High);
	TEST(tBit_Nor(tBit_Low, tBit_High) == tBit_Low);
	TEST(tBit_Nor(tBit_High, tBit_Low) == tBit_Low);
	TEST(tBit_Nor(tBit_High, tBit_High) == tBit_Low);
}
void test_XOR(void)
{
	TEST(tBit_Xor(tBit_Low, tBit_Low) == tBit_Low);
	TEST(tBit_Xor(tBit_Low, tBit_High) == tBit_High);
	TEST(tBit_Xor(tBit_High, tBit_Low) == tBit_High);
	TEST(tBit_Xor(tBit_High, tBit_High) == tBit_Low);
}
void test_XNOR(void)
{
	TEST(tBit_Xnor(tBit_Low, tBit_Low) == tBit_High);
	TEST(tBit_Xnor(tBit_Low, tBit_High) == tBit_Low);
	TEST(tBit_Xnor(tBit_High, tBit_Low) == tBit_Low);
	TEST(tBit_Xnor(tBit_High, tBit_High) == tBit_High);
}
void test_NOT(void)
{
	TEST(tBit_Not(tBit_Low) == tBit_High);
	TEST(tBit_Not(tBit_High) == tBit_Low);
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
