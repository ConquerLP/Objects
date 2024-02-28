#ifndef ABSTRACTCOLLECTION_H

#define ABSTRACTCOLLECTION

#include "..\..\macro.h"
#include "..\..\base\object.h"

static char* AbstractCollection_magicString = "AbstractCollection";

typedef struct _AbstractCollection AbstractCollection, * pAbstractCollection;

struct _AbstractCollection {
	Object* o;
	char* magicString;
	_int size;
	_int (*getSize)(void*);
	void* (*get)(void*, _int);
	void (*set)(void*, void*, _int);
};

AbstractCollection* new_AbstractCollection(char* classNames, _int size);
CAST_FN_PROTO(AbstractCollection);

#endif // !ABSTRACTCOLLECTION_H
