#include "listInterface.h"

ListInterface* create_ListInterface(
	bool (*add)(void*, void*),
	bool (*addIndex)(void*, void*, _int),
	bool (*addAll)(void*, void*),
	bool (*addAllIndex)(void*, void* l, _int),
	void (*clear)(void*),
	bool (*contains)(void*, void*),
	bool (*containsAll)(void*, void*)
)
{
	CREATE_STRUCT_HEAP(ListInterface, interface);
	interface->add = add;
	interface->addIndex = addIndex;
	interface->addAll = addAll;
	interface->addAllIndex = addAllIndex;
	interface->clear = clear;
	interface->contains = contains;
	interface->containsAll = containsAll;
	return interface;
}