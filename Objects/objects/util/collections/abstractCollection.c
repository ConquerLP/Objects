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
	return a;
}

private _int getSize(void* c)
{
	return CAST(AbstractCollection, c)->size;
}

check_type(void* c, void* e)
{
	if (strcmp(CAST(AbstractCollection, c)->type, CAST(Object, e)->className) != 0) {
		ERROR__("Tried to insert wrong class-type into a collection.");
	}
}
