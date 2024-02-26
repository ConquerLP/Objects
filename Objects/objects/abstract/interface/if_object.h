#ifndef IF_OBJECT_H

#define IF_OBJECT_H

#include "..\..\macro.h"

typedef struct _IF_Object IF_Object, * pIF_Object;

struct _IF_Object {
	void* (*clone)(void* o);
	bool (*equals)(void* o1, void* o2);
	char* (*toString)(void* o);
	_uint (*hashCode)(void* o);
};

IF_Object* create_IF_Object();

#endif // !IF_OBJECT_H
