#ifndef ROQOL_BITS_H
#define ROQOL_BITS_H
typedef _Bool tBit;
#define tBit_HIGH ((tBit)1U)
#define tBit_LOW ((tBit)0U)
static inline tBit tBit_NAND(tBit inA, tBit inB)
{
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA && inB); /* Would binary comparisons and be faster here? No idea. */
#else
	return !(inA & inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
}
static inline tBit tBit_NOT(tBit in)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_NAND(in, in);
#else
	return !in;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_AND(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_NOT(tBit_NAND(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA && inB;
#else
	return inA & inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_OR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_NAND(tBit_NOT(inA), tBit_NOT(inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA || inB;
#else
	return inA | inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_NOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_NOT(tBit_OR(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA || inB);
#else
	return !(inA | inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_XOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_NOR(tBit_AND(inA, inB), tBit_NOR(inA, inB));
#else
	return inA ^ inB;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_XNOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_OR(tBit_AND(inA, inB), tBit_NOR(inA, inB));;
#else
	return !(inA ^ inB);
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_ON(void)
{
	return tBit_HIGH;
}
static inline tBit tBit_OFF(void)
{
	return tBit_LOW;
}
static inline tBit tBit_MUX(tBit inA, tBit inB, tBit sel)
{
	return sel ? inB : inA;
}
//#ifdef ROQOL_LOGICAL_PRIMITIVES
//#undef ROQOL_LOGICAL_PRIMITIVES
//#endif/*ROQOL_LOGICAL_PRIMITIVES*/
//#ifdef ROQOL_NAND_ONLY
//#undef ROQOL_NAND_ONLY
//#endif/*ROQOL_NAND_ONLY*/
#endif/*ROQOL_BITS_H*/