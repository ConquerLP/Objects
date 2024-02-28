#ifndef ARRAY_H

#define ARRAY_H

#include "..\..\macro.h"
#include "..\collections\abstractCollection.h"

typedef struct _Array Array, * pArray;

struct _Array {
	AbstractCollection* a;
	char* magicString;
	void** e;
};


#endif // !ARRAY_H
