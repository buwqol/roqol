#include "Bits.h"
inline tBit NAND(tBit inA, tBit inB)
{
#ifdef ROQOL_LOGICAL_NAND
	return !(inA && inB); /* Would binary comparisons and be faster here? No idea. */
#else
	return !(inA & inB);
#endif/*ROQOL_LOGICAL_NAND*/
}
inline tBit NOT(tBit in)
{
#ifdef ROQOL_NAND_ONLY
	return NAND(in);
#else
	return !in;
#endif/*ROQOL_NAND_ONLY*/
}