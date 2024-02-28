#include "abstractCollection.h"

CAST_FN(AbstractCollection)

private _int getSize(void* c);

AbstractCollection* new_AbstractCollection(char* classNames, _int size)
{
	CREATE_STRUCT_HEAP(AbstractCollection, a);
	a->o = new_Object("AbstractCollection");
	SET_MAGIC(a, AbstractCollection);
	a->size = size;
	a->getSize = getSize;
	a->set = null;
	a->get = null;
	return a;
}

private _int getSize(void* c)
{
	return CAST(AbstractCollection, c)->size;
}
