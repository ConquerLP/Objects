#ifndef IF_LIST_H

#define IF_LIST_H

#include "..\..\macro.h"

typedef struct _IF_List IF_List, * pIF_List;

struct _IF_List {
	void (*add)(void* list, void* e);
	void (*addIndex)(void* list, void* e, _uint index);
	void (*addCollection)(void* list, void* c);
	void (*addCollectionIndex)(void* list, void* c, _uint index);
	void (*clear)(void* list);
	bool (*contains)(void* list, void* e);
	bool (*containsAll)(void* list, void* c);
	_int (*indexOf)(void* list, void* e);
	_int (*lastIndexOf)(void* list, void* e);
	bool (*isEmpty)(void* list);
	void (*removeE)(void* list, void* e);
	void (*removeIndex)(void* list, _uint index);
	void (*removeAll)(void* list, void* c);
	void (*set)(void* list, void* e, _uint index);
	void* (*get)(void* list, _uint index);
	_uint (*getSize)(void* list);
	void* (*subList)(void* list, _uint start, _uint end);
};

IF_List* create_IF_List(void (*add)(void* list, void* e),
			void (*addIndex)(void* list, void* e, _uint index),
			void (*addCollection)(void* list, void* c),
			void (*addCollectionIndex)(void* list, void* c, _uint index),
			void (*clear)(void* list),
			bool (*contains)(void* list, void* e),
			bool (*containsAll)(void* list, void* c),
			_int(*indexOf)(void* list, void* e),
			_int(*lastIndexOf)(void* list, void* e),
			bool (*isEmpty)(void* list),
			void (*removeE)(void* list, void* e),
			void (*removeIndex)(void* list, _uint index),
			void (*removeAll)(void* list, void* c),
			void (*set)(void* list, void* e, _uint index),
			void* (*get)(void* list, _uint index),
			_uint (*getSize)(void* list),
			void* (*subList)(void* list, _uint start, _uint end));

bool valid_list_size(_uint size);

#endif // !IF_LIST_H
