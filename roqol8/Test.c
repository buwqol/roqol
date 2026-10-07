#include "Bits.h"
#include "Test.h"
void test_NAND(void)
{
	TEST(tBit_NAND(tBit_LOW, tBit_LOW) == tBit_HIGH);
	TEST(tBit_NAND(tBit_LOW, tBit_HIGH) == tBit_HIGH);
	TEST(tBit_NAND(tBit_HIGH, tBit_LOW) == tBit_HIGH);
	TEST(tBit_NAND(tBit_HIGH, tBit_HIGH) == tBit_LOW);
}
void test_AND(void)
{
	TEST(tBit_AND(tBit_LOW, tBit_LOW) == tBit_LOW);
	TEST(tBit_AND(tBit_LOW, tBit_HIGH) == tBit_LOW);
	TEST(tBit_AND(tBit_HIGH, tBit_LOW) == tBit_LOW);
	TEST(tBit_AND(tBit_HIGH, tBit_HIGH) == tBit_HIGH);
}
void test_OR(void)
{
	TEST(tBit_OR(tBit_LOW, tBit_LOW) == tBit_LOW);
	TEST(tBit_OR(tBit_LOW, tBit_HIGH) == tBit_HIGH);
	TEST(tBit_OR(tBit_HIGH, tBit_LOW) == tBit_HIGH);
	TEST(tBit_OR(tBit_HIGH, tBit_HIGH) == tBit_HIGH);
}
void test_NOR(void)
{
	TEST(tBit_NOR(tBit_LOW, tBit_LOW) == tBit_HIGH);
	TEST(tBit_NOR(tBit_LOW, tBit_HIGH) == tBit_LOW);
	TEST(tBit_NOR(tBit_HIGH, tBit_LOW) == tBit_LOW);
	TEST(tBit_NOR(tBit_HIGH, tBit_HIGH) == tBit_LOW);
}
void test_XOR(void)
{
	TEST(tBit_XOR(tBit_LOW, tBit_LOW) == tBit_LOW);
	TEST(tBit_XOR(tBit_LOW, tBit_HIGH) == tBit_HIGH);
	TEST(tBit_XOR(tBit_HIGH, tBit_LOW) == tBit_HIGH);
	TEST(tBit_XOR(tBit_HIGH, tBit_HIGH) == tBit_LOW);
}
void test_XNOR(void)
{
	TEST(tBit_XNOR(tBit_LOW, tBit_LOW) == tBit_HIGH);
	TEST(tBit_XNOR(tBit_LOW, tBit_HIGH) == tBit_LOW);
	TEST(tBit_XNOR(tBit_HIGH, tBit_LOW) == tBit_LOW);
	TEST(tBit_XNOR(tBit_HIGH, tBit_HIGH) == tBit_HIGH);
}
void test_NOT(void)
{
	TEST(tBit_NOT(tBit_LOW) == tBit_HIGH);
	TEST(tBit_NOT(tBit_HIGH) == tBit_LOW);
}
void test_MUX(void)
{
	TEST(tBit_MUX(tBit_LOW, tBit_LOW, tBit_LOW) == tBit_LOW);
	TEST(tBit_MUX(tBit_LOW, tBit_HIGH, tBit_LOW) == tBit_LOW);
	TEST(tBit_MUX(tBit_HIGH, tBit_LOW, tBit_LOW) == tBit_HIGH);
	TEST(tBit_MUX(tBit_HIGH, tBit_HIGH, tBit_LOW) == tBit_HIGH);
	TEST(tBit_MUX(tBit_LOW, tBit_LOW, tBit_HIGH) == tBit_LOW);
	TEST(tBit_MUX(tBit_LOW, tBit_HIGH, tBit_HIGH) == tBit_HIGH);
	TEST(tBit_MUX(tBit_HIGH, tBit_LOW, tBit_HIGH) == tBit_LOW);
	TEST(tBit_MUX(tBit_HIGH, tBit_HIGH, tBit_HIGH) == tBit_HIGH);
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
	test_MUX();

	printf("ALL TESTS PASSED!\n");
	return 0;
}
