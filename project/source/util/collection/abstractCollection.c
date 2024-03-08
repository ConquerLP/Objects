#include "abstractCollection.h"

CAST_FN(AbstractCollection)

private _int getSize(void* c);

AbstractCollection* new_AbstractCollection(char* type, _int size)
{
	CREATE_STRUCT_HEAP(AbstractCollection, a);
	a->object = new_Object("AbstractCollection");
	SET_MAGIC(a, AbstractCollection);
	a->type = type;
	a->size = size;
	a->getSize = getSize;
	a->set = null;
	a->get = null;
	a->indexOf = null;
	a->lastIndexOf = null;
	a->indexOfOffset = null;
	return a;
}

private _int getSize(void* c)
{
	return CAST(AbstractCollection, c)->size;
}

void check_type(void* c, void* e)
{
	if (strcmp(CAST(AbstractCollection, c)->type, CAST(Object, e)->className) != 0) {
		ERROR__("Tried to insert wrong class-type into a collection.");
	}
}

bool try_index_check(va_list args)
{
	void* collection = va_arg(args, void*);
	_int index = va_arg(args, _int);
	if (index >= CAST(AbstractCollection, collection)->size || index < 0) return false;
	else return true;
}

void catch_index_check(va_list args)
{
	va_arg(args, void*);
	_int index = va_arg(args, _int);
	if (index != ABSTRACT_COLLECTION_INVALID_INDEX) {
		ERROR__("Index out of bounds.");
	}
}