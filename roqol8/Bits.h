#ifndef ROQOL_BITS_H
#define ROQOL_BITS_H
typedef _Bool tBit;
#define tBit_High ((tBit)1U)
#define tBit_Low ((tBit)0U)
static inline tBit tBit_Nand(tBit inA, tBit inB)
{
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA && inB); /* Would binary comparisons and be faster here? No idea. */
#else
	return !(inA & inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
}
static inline tBit tBit_Not(tBit in)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Nand(in, in);
#else
	return !in;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_And(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Not(tBit_Nand(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA && inB;
#else
	return inA & inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_Or(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Nand(tBit_Not(inA), tBit_Not(inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA || inB;
#else
	return inA | inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_Nor(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Not(tBit_Or(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA || inB);
#else
	return !(inA | inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_Xor(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Nor(tBit_And(inA, inB), tBit_Nor(inA, inB));
#else
	return inA ^ inB;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_Xnor(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return tBit_Or(tBit_And(inA, inB), tBit_Nor(inA, inB));;
#else
	return !(inA ^ inB);
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit tBit_On(void)
{
	return tBit_High;
}
static inline tBit tBit_Off(void)
{
	return tBit_Low;
}
//#ifdef ROQOL_LOGICAL_PRIMITIVES
//#undef ROQOL_LOGICAL_PRIMITIVES
//#endif/*ROQOL_LOGICAL_PRIMITIVES*/
//#ifdef ROQOL_NAND_ONLY
//#undef ROQOL_NAND_ONLY
//#endif/*ROQOL_NAND_ONLY*/
#endif/*ROQOL_BITS_H*/