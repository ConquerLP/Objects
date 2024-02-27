#ifndef OBJECT_H

#define OBJECT_H

#include "..\macro.h"

static char* magic_string = "Object";

typedef struct _Object Object, * pObject;

struct _Object {
	char* magic_string;
	int32 type;
	void* (*clone)(void* o);
	bool (*equals)(void* o1, void* o2);
	char* (*toString)(void* o);
	_uint(*hashCode)(void* o);
};

Object* new_Object();
Object* new_ObjectType(int32 type);
Object* cast_object(void* o);
int32 instanceOf(void* o);

#endif // !OBJECT_H
