#ifndef ARRAY_H

#define ARRAY_H

#include "..\..\macro.h"
#include "..\..\abstract\object.h"
#include "..\interface\if_list.h"

typedef struct _Array Array, * pArray;

struct _Array {
	Object* o;
	IF_List* meth;
	int32 type;
	_uint size;
	void** e;
};

Array* new_Array(_uint size, int32 type);

#endif // !ARRAY_H
