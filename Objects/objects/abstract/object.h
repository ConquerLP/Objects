#ifndef OBJECT_H

#define OBJECT_H

#include "..\macro.h"
#include "interface\if_object.h"

typedef struct _Object Object, * pObject;

struct _Object {
	int32 type;
	IF_Object* meth;
};

Object* new_Object();
Object* new_ObjectType(int32 type);

#endif // !OBJECT_H
