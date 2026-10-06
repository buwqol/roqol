#ifndef ROQOL_TEST_H
#define ROQOL_TEST_H
#include <stdio.h>
#include <stdlib.h>
void Test(int cond, const char *expr, const char *fileName, int lineNum) { if (!cond) { fprintf(stderr, "TEST FAILED: %s:%d: %s\n", fileName, lineNum, expr); exit(1); } else fprintf(stderr, "TEST PASSED: %s:%d: %s\n", fileName, lineNum, expr); }
#define TEST(x) Test((x), #x, __FILE__, __LINE__)
#endif/*ROQOL_TEST_H*/