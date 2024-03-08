#ifndef ARRAY_LIST_H

#define ARRAY_LIST_H

#include "..\..\base\misc\macro.h"
#include "listInterface.h"
#include "abstractCollection.h"

MAGIC_STRING(ArrayList);

typedef struct _ArrayList ArrayList, * pArrayList;

struct _ArrayList {
	AbstractCollection* absCol;
	ListInterface* listIF;
	MAGIC;
	void** e;
};

ArrayList* new_ArrayListSize(char* type, _int size);
ArrayList* new_ArrayList(char* type);
CAST_FN_PROTO(ArrayList);

#endif