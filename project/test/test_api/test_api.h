#ifndef TEST_API_H

#define TEST_API_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_FUNCNAME_MAX 50
#define TEST_EXPECTED_MAX 10
#define TEST_VALUE_MAX 10

#define BOOL_TO_STRING(expression) (expression) ? "passed" : "not passed"

static FILE* output_stream = null;

#define FN_PROTO_PRIMITIVE(type) \
	void assert_eq_##type(type expected, type value); \
	void assert_neq_##type(type expected, type value); 
/*
	FILE:
				| ex | val | result
	test_name: 
*/


void assert_eq_float(double ex, double val)
{
	fprintf(stdout, "%-*s: %*lf | %*lf | %s\n", 
		TEST_FUNCNAME_MAX,  __func__,
		TEST_EXPECTED_MAX, ex,
		TEST_VALUE_MAX, val,
		BOOL_TO_STRING(ex == val));

}




#endif // !TEST_API_H
