#include "abstractCollection.h"

CAST_FN(AbstractCollection)

private _int getSize(void* c);
private void* get(void* c, _int index);
private void set(void* c, void* e, _int index);

AbstractCollection* new_AbstractCollection(char* classNames, _int size)
{
	CREATE_STRUCT_HEAP(AbstractCollection, a);
	a->o = new_Object("AbstractCollection");
	a->magicString = AbstractCollection_magicString;
	a->size = size;
	a->getSize = getSize;
	a->set = set;
	a->get = get;
	return a;
}

private _int getSize(void* c)
{

}

private void* get(void* c, _int index)
{

}

private void set(void* c, void* e, _int index)
{

}

