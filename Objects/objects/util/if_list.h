#ifndef IF_LIST_H

#define IF_LIST_H

#include "..\macro.h"

typedef struct _IF_List IF_List, * pIF_List;

struct _IF_List {
	void (*add)(void* list, void* e);
	void (*addIndex)(void* list, void* e, _uint index);

};



#endif // !IF_LIST_H
