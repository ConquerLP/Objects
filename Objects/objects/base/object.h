#ifndef OBJECT_H

#define OBJECT_H

#include "..\macro.h"

#define CAST_FN(className) \
	CAST_FN_PROTO(className) { \
	className* name = o; \
	if (strcmp(name->magicString, className##_magicString) == 0) return o; \
	else return cast##className((*(className**)o)); \
	} 

#define CAST_FN_PROTO(className) \
	className* cast##className(void* o)

static char* Object_magicString = "Object";

typedef struct _Object Object, * pObject;

struct _Object {
	char* magicString;
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
