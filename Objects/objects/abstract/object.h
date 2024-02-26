#ifndef OBJECT_H

#define OBJECT_H

#include "..\macro.h"
#include "interface\if_object.h"

typedef struct _Object Object, * pObject;

struct _Object {
	IF_Object* meth;
};

Object* new_Object();

#endif // !OBJECT_H
