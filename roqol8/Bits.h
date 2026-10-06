#ifndef ROQOL_BITS_H
#define ROQOL_BITS_H
typedef _Bool tBit;
static inline tBit NAND(tBit inA, tBit inB)
{
#ifdef ROQOL_LOGICAL_NAND
	return !(inA && inB); /* Would binary comparisons and be faster here? No idea. */
#else
	return !(inA & inB);
#endif/*ROQOL_LOGICAL_NAND*/
}
static inline tBit NOT(tBit in)
{
#ifdef ROQOL_NAND_ONLY
	return NAND(in, in);
#else
	return !in;
#endif/*ROQOL_NAND_ONLY*/
}
#ifdef ROQOL_LOGICAL_NAND
#undef ROQOL_LOGICAL_NAND
#endif/*ROQOL_LOGICAL_NAND*/
#ifdef ROQOL_NAND_ONLY
#undef ROQOL_NAND_ONLY
#endif/*ROQOL_NAND_ONLY*/
#endif/*ROQOL_BITS_H*/