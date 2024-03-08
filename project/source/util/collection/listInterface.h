#ifndef LIST_INTERFACE_H

#define LIST_INTERFACE_H

#include "..\..\base\misc\macro.h"

typedef struct _ListInterface ListInterface, * pListInterface;

struct _ListInterface {
	bool (*add)(void* , void*);
	bool (*addIndex)(void* , void* , _int);
	bool (*addAll)(void* , void* );
	bool (*addAllIndex)(void* , void* l, _int);
	void (*clear)(void*);
	bool (*contains)(void*, void*);
	bool (*containsAll)(void*, void*);
};

ListInterface* create_ListInterface(
	bool (*add)(void*, void*),
	bool (*addIndex)(void*, void*, _int),
	bool (*addAll)(void*, void*),
	bool (*addAllIndex)(void*, void* l, _int),
	void (*clear)(void*),
	bool (*contains)(void*, void*),
	bool (*containsAll)(void*, void*)
);

#endif // !LIST_INTERFACE_H
