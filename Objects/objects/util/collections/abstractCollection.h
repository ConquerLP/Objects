#ifndef ABSTRACTCOLLECTION_H

#define ABSTRACTCOLLECTION

#include "..\..\macro.h"
#include "..\..\base\object.h"

typedef struct _AbstractCollection AbstractCollection, * pAbstractCollection;

struct _AbstractCollection {
	Object* o;
	_int size;
	_int (*getSize)(void*);
	void* (*get)(void*, _int);
	void (*set)(void*, void*, _int);
};

AbstractCollection* new_AbstractCollection(char* classNames, _int size);

#endif // !ABSTRACTCOLLECTION_H
