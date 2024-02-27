#ifndef ARRAY_H

#define ARRAY_H

#include "..\..\macro.h"
#include "..\collections\collection.h"

typedef struct _Array Array, * pArray;

struct _Array {
	Collection* c;
	void** e;
};

Array* new_Array(_int size, int32 type);

#endif // !ARRAY_H
