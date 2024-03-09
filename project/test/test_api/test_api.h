#ifndef TEST_API_H

#define TEST_API_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST_FUNCNAME_MAX 50
#define TEST_EXPECTED_MAX 10
#define TEST_VALUE_MAX 10

#define BOOL_TO_STRING(expression) (expression) ? "passed" : "not passed"

#define FN_PROTO_PRIMITIVE(ftype, type) \
	void assert_eq_##ftype(type expected, type value); \
	void assert_neq_##ftype(type expected, type value); 

#define FN_PRIMITIVE(ftype, type, specifier) \
	void assert_eq_##ftype(type ex, type val) { \
	fprintf(stdout, "%-*s: %*"#specifier" | %*"#specifier" | %s\n", \
	TEST_FUNCNAME_MAX, __func__, \
	TEST_EXPECTED_MAX, ex, \
	TEST_VALUE_MAX, val, \
	BOOL_TO_STRING(ex == val)); } \
	void assert_neq_##ftype(type ex, type val) { \
	fprintf(stdout, "%-*s: %*"#specifier" | %*"#specifier" | %s\n", \
	TEST_FUNCNAME_MAX, __func__, \
	TEST_EXPECTED_MAX, ex, \
	TEST_VALUE_MAX, val, \
	BOOL_TO_STRING(ex != val)); }
/*
	FILE:
				| ex | val | result
	test_name: 
*/

FN_PROTO_PRIMITIVE(float, float)
FN_PROTO_PRIMITIVE(double, double)
FN_PROTO_PRIMITIVE(longdouble, long double)

FN_PROTO_PRIMITIVE(short, short)
FN_PROTO_PRIMITIVE(unsignedshort, unsigned short)
FN_PROTO_PRIMITIVE(int, int)
FN_PROTO_PRIMITIVE(unsignedint, unsigned int)
FN_PROTO_PRIMITIVE(longint, long int)
FN_PROTO_PRIMITIVE(unsignedlongint, unsigned long int)
FN_PROTO_PRIMITIVE(longlongint, long long int)
FN_PROTO_PRIMITIVE(unsignedlonglongint, unsigned long long int)

FN_PROTO_PRIMITIVE(char, char)
FN_PROTO_PRIMITIVE(unsignedchar, unsigned char)



#endif // !TEST_API_H
