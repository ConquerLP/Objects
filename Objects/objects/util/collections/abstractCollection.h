#ifndef ABSTRACTCOLLECTION_H

#define ABSTRACTCOLLECTION

#include "..\..\macro.h"
#include "..\..\base\object.h"

#define ABSTRACT_COLLECTION_INVALID_INDEX -1

MAGIC_STRING(AbstractCollection);

typedef struct _AbstractCollection AbstractCollection, * pAbstractCollection;

struct _AbstractCollection {
	Object* object;
	MAGIC;
	char* type;
	_int size;
	_int (*getSize)(void*);
	void* (*get)(void*, _int);
	void (*set)(void*, void*, _int);
	_int (*indexOf)(void*, void*);
	_int (*indexOfOffset)(void*, void*, _int);
	_int (*lastIndexOf)(void*, void*);
};

AbstractCollection* new_AbstractCollection(char* type, _int size);
CAST_FN_PROTO(AbstractCollection);
void check_type(void* c, void* e);

#endif // !ABSTRACTCOLLECTION_H
