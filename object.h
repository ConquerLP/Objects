#ifndef OBJECT_H

#define OBJECT_H

#include "macro.h"

#define MAGIC char* MAGIX
#define MAGIX magicString
#define SET_MAGIC(ptr, className) \
	ptr->magicString = className##magicString
	
#define MAGIC_STRING(className) \
	static char* className##magicString = #className

#define CAST_FN(className) \
	CAST_FN_PROTO(className) { \
	className* clazz = o; \
	if (strcmp(clazz->magicString, className##magicString) == 0) return o; \
	else return cast##className((*(className**)o)); \
	} 

#define CAST_FN_PROTO(className) \
	className* cast##className(void* o)

#define CAST(className, ptr) \
	cast##className(ptr)

#define OBJECT_BUFFER_LENGTH 20
#define OBJECT_STRING_BUFFER_SETUP(className) static char className##buffer[OBJECT_BUFFER_LENGTH]
#define OBJECT_STRING_BUFFER(className) className##buffer
#define OBJECT_STRING_CLEAN(className) memset(className##buffer, 0, OBJECT_BUFFER_LENGTH)
#define OBJECT_STATIC_TO_STRING_PROTO(className, type) \
	char* static_##className##_toString(type value)

#define OBJECT_STATIC_TO_STRING_FUN(className, type, specifier) \
	char* static_##className##_toString(type value) { \
	OBJECT_STRING_CLEAN(className); \
	snprintf(OBJECT_STRING_BUFFER(className), OBJECT_BUFFER_LENGTH,  #specifier, value); \
	return Doublebuffer; \
	} \

#define OBJECT_STATIC_STRING_CALL(className, value) \
	static_##className##_toString(value)


MAGIC_STRING(Object);

typedef struct _Object Object, * pObject;

struct _Object {
	MAGIC;
	char* className;
	_int (*hashcode)(void*);
	char* (*toString)(void*);
	void* (*clone)(void*);
	bool (*equals)(void*, void*);
};

Object* new_Object(char* className);
CAST_FN_PROTO(Object);
bool instanceOf(void* o, char* className);

#endif // !OBJECT_H
