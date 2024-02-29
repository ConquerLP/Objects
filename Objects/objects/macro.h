#ifndef MACRO_H

#define MACRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int8_t int8;
typedef uint8_t uint8;
typedef int16_t int16;
typedef uint16_t uint16;
typedef int32_t int32;
typedef uint32_t uint32;
typedef int64_t int64;
typedef uint64_t uint64;
typedef size_t _uint;
typedef int64_t _int;

#define true 1
#define false 0
#define bool char
#define null NULL
#define private static

#define MACRO_BUFFER_SIZE 1024
static char MACRO_BUFFER1[MACRO_BUFFER_SIZE] = { 0 };
static char MACRO_BUFFER2[MACRO_BUFFER_SIZE] = { 0 };

#define MALLOC(ptr, type, amount) ptr = malloc(sizeof(type) * (size_t)(amount)); if(!ptr) { fprintf(stderr, "Could not allocate memory. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1);}
#define REALLOC(ptr, type, amount) ptr = realloc(ptr, sizeof(type) * (size_t)(amount)); if(!ptr) { fprintf(stderr, "Could not allocate memory. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1); }

#define COPY_STRING_HEAP(dest, src) MALLOC(dest, char, strlen(src) + 1); strcpy(dest, src);
#define MERGE_STRING_HEAP(dest, src1, src2) MALLOC(dest, char, strlen(src1) + strlen(src2) + 1); strcpy(dest, src1); strcat(dest, src2);
#define SUBSTRING_HEAP(string, start, end, ptr) MALLOC(ptr, char, end - start + 1); strncpy(ptr, string + start, end - start);
#define MERGE_STRING_STACK(dest, src1, src2) memset(dest, 0, MACRO_BUFFER_SIZE); strncpy_s(dest, MACRO_BUFFER_SIZE, src1, MACRO_BUFFER_SIZE); strncat_s(dest ,MACRO_BUFFER_SIZE - strlen(dest), src2, MACRO_BUFFER_SIZE);

#define BOOL_STRING(expression) (expression) ? "true" : "false"
#define WRITE_BUFFER_INT(buffer, value, base) memset(buffer, 0, MACRO_BUFFER_SIZE); _itoa_s((int)(value), buffer, MACRO_BUFFER_SIZE, (base));

#define CHECK(ptr) if(!ptr) { fprintf(stderr, "Nullpointer. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1); }
#define ERROR__(msg) { fprintf(stderr, "%s", msg); exit(1); }

#define STRINGYFY(c) #c
#define ARRAY_SIZE(ptr) (sizeof((ptr)) / sizeof((*ptr)))

#define CREATE_STRUCT_HEAP(type, id) type* id; MALLOC(id, type, 1);

#endif // !MACRO_H
