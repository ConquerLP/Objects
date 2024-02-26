#include "if_list.h"	

IF_List* create_IF_List(void (*add)(void* list, void* e),
	void (*addIndex)(void* list, void* e, _uint index),
	void (*addCollection)(void* list, void* c),
	void (*addCollectionIndex)(void* list, void* c, _uint index),
	void (*clear)(void* list),
	bool (*contains)(void* list, void* e),
	bool (*containsAll)(void* list, void* c),
	_int (*indexOf)(void* list, void* e),
	_int (*lastIndexOf)(void* list, void* e),
	bool (*isEmpty)(void* list),
	void (*removeE)(void* list, void* e),
	void (*removeIndex)(void* list, _uint index),
	void (*removeAll)(void* list, void* c),
	void (*set)(void* list, void* e, _uint index),
	void* (*get)(void* list, _uint index),
	_uint(*getSize)(void* list),
	void* (*subList)(void* list, _uint start, _uint end))
{
	CREATE_STRUCT_HEAP(IF_List, list);
	list->add = add;
	list->addIndex = addIndex;
	list->addCollection = addCollection;
	list->addCollectionIndex = addCollectionIndex;
	list->clear = clear;
	list->contains = contains;
	list->containsAll = containsAll;
	list->indexOf = indexOf;
	list->lastIndexOf = lastIndexOf;
	list->isEmpty = isEmpty;
	list->removeE = removeE;
	list->removeIndex = removeIndex;
	list->removeAll = removeAll;
	list->set = set;
	list->get = get;
	list->getSize = getSize;
	list->subList = subList;
	return list;
}

bool valid_list_size(_uint size)
{
	if (size <= 0) return false;
	else return true;
}