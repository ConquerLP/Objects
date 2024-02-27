#include "collection.h"

Collection* new_Collection(int32 type, int32 collectionType, _int size,
	void (*add)(void* list, void* e),
	void (*addIndex)(void* list, void* e, _int index),
	void (*addCollection)(void* list, void* c),
	void (*addCollectionIndex)(void* list, void* c, _int index),
	void (*clear)(void* list),
	bool (*contains)(void* list, void* e),
	bool (*containsAll)(void* list, void* c),
	_int(*indexOf)(void* list, void* e),
	_int(*lastIndexOf)(void* list, void* e),
	bool (*isEmpty)(void* list),
	void (*removeE)(void* list, void* e),
	void (*removeIndex)(void* list, _int index),
	void (*removeAll)(void* list, void* c),
	void (*set)(void* list, void* e, _int index),
	void* (*get)(void* list, _int index),
	_int (*getSize)(void* list),
	void* (*subList)(void* list, _int start, _int end))
{
	CREATE_STRUCT_HEAP(Collection, c);
	c->add = add;
	c->addIndex = addIndex;
	c->addCollection = addCollection;
	c->addCollectionIndex = addCollectionIndex;
	c->clear = clear;
	c->contains = contains;
	c->containsAll = containsAll;
	c->indexOf = indexOf;
	c->lastIndexOf = lastIndexOf;
	c->isEmpty = isEmpty;
	c->removeE = removeE;
	c->removeIndex = removeIndex;
	c->removeAll = removeAll;
	c->set = set;
	c->get = get;
	c->getSize = getSize;
	c->subList = subList;
	c->size = size;
	c->type = type;
	c->collectionType = collectionType;
	c->o = new_ObjectType(collectionType);
	return c;
}

Collection* cast_collection(void* c)
{
	return (*(Collection**)c);
}

bool valid_list_size(_int size)
{
	if (size <= 0) return false;
	else return true;
}

void valid_index(void* c, _int index)
{
	if (index < 0 || index >= cast_collection(c)->size) ERROR__("Index out of bounds.");
}

void valid_type(void* c, void* e)
{
	Object* o = cast_object(e);
	Collection* cc = cast_collection(c);
	if (instanceOf(e) != cast_collection(c)->type) ERROR__("Wrong type in collection.");
}