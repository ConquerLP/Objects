#ifndef ARRAY_H

#define ARRAY_H

#include "abstractCollection.h"

MAGIC_STRING(Array);

typedef struct _Array Array, * pArray;

struct _Array {
	AbstractCollection* absCol;
	MAGIC;
	void** e;
};

Array* new_Array(char* type, _int size);
CAST_FN_PROTO(Array);

#endif // !ARRAY_H
