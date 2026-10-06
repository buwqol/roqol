#ifndef ROQOL_BITS_H
#define ROQOL_BITS_H
typedef _Bool tBit;
static inline tBit NAND(tBit inA, tBit inB)
{
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA && inB); /* Would binary comparisons and be faster here? No idea. */
#else
	return !(inA & inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
}
static inline tBit NOT(tBit in)
{
#ifdef ROQOL_NAND_ONLY
	return NAND(in, in);
#else
	return !in;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit AND(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return NOT(NAND(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA && inB;
#else
	return inA & inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit OR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return NAND(NOT(inA), NOT(inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return inA || inB;
#else
	return inA | inB;
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit NOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return NOT(OR(inA, inB));
#else
#ifdef ROQOL_LOGICAL_PRIMITIVES
	return !(inA || inB);
#else
	return !(inA | inB);
#endif/*ROQOL_LOGICAL_PRIMITIVES*/
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit XOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return NOR(AND(inA, inB), NOR(inA, inB));
#else
	return inA ^ inB;
#endif/*ROQOL_NAND_ONLY*/
}
static inline tBit XNOR(tBit inA, tBit inB)
{
#ifdef ROQOL_NAND_ONLY
	return OR(AND(inA, inB), NOR(inA, inB));;
#else
	return !(inA ^ inB);
#endif/*ROQOL_NAND_ONLY*/
}
//#ifdef ROQOL_LOGICAL_PRIMITIVES
//#undef ROQOL_LOGICAL_PRIMITIVES
//#endif/*ROQOL_LOGICAL_PRIMITIVES*/
//#ifdef ROQOL_NAND_ONLY
//#undef ROQOL_NAND_ONLY
//#endif/*ROQOL_NAND_ONLY*/
#endif/*ROQOL_BITS_H*/