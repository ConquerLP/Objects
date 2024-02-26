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
typedef uint64_t _uint;
typedef int64_t _int;

#define true 1
#define false 0
#define bool char
#define null NULL
#define private static

#define MALLOC(ptr, type, amount) ptr = malloc(sizeof(type) * (amount)); if(!ptr) { fprintf(stderr, "Could not allocate memory. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1);}
#define REALLOC(ptr, type, amount) ptr = realloc(ptr, sizeof(type) * (amount)); if(!ptr) { fprintf(stderr, "Could not allocate memory. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1); }

#define COPY_STRING(dest, src) MALLOC(dest, char, strlen(src) + 1); strcpy(dest, src);
#define MERGE_STRING(dest, src1, src2) MALLOC(dest, char, strlen(src1) + strlen(src2) + 1); strcpy(dest, src1); strcat(dest, src2);
#define SUBSTRING(string, start, end, ptr) MALLOC(ptr, char, end - start + 1); strncpy(ptr, string + start, end - start);
#define BOOL_STRING(expression) (expression) ? "true" : "false"

#define CHECK(ptr) if(!ptr) { fprintf(stderr, "Nullpointer. In File: \n%s\nIn Line: %i", __FILE__, __LINE__); exit(1); }
#define ERROR__(msg) { fprintf(stderr, "%s", msg); exit(1); }

#define STRINGYFY(c) #c
#define ARRAY_SIZE(ptr) (sizeof((ptr)) / sizeof((*ptr)))

//instance of()
#define CREATE_STRUCT_HEAP(type, id) type* id; MALLOC(id, type, 1);

#endif // !MACRO_H
