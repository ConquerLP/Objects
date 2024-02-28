#ifndef ABSTRACTCOLLECTION_H

#define ABSTRACTCOLLECTION

#include "..\..\macro.h"
#include "..\..\base\object.h"

MAGIC_STRING(AbstractCollection);

typedef struct _AbstractCollection AbstractCollection, * pAbstractCollection;

struct _AbstractCollection {
	Object* o;
	MAGIC;
	char* type;
	_int size;
	_int (*getSize)(void*);
	void* (*get)(void*, _int);
	void (*set)(void*, void*, _int);
};

AbstractCollection* new_AbstractCollection(char* type, _int size);
CAST_FN_PROTO(AbstractCollection);
check_type(void* c, void* e);

#endif // !ABSTRACTCOLLECTION_H
