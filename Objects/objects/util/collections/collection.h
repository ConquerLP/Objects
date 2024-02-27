#ifndef COLLECTION_H

#define COLLECTION_H

#include "..\..\macro.h"
#include "..\..\abstract\object.h"

typedef struct _Collection Collection, * pCollection;

struct _Collection {
	Object* o;
	int32 type;
	int32 collectionType;
	_int size;
	void (*add)(void* list, void* e);
	void (*addIndex)(void* list, void* e, _int index);
	void (*addCollection)(void* list, void* c);
	void (*addCollectionIndex)(void* list, void* c, _int index);
	void (*clear)(void* list);
	bool (*contains)(void* list, void* e);
	bool (*containsAll)(void* list, void* c);
	_int(*indexOf)(void* list, void* e);
	_int(*lastIndexOf)(void* list, void* e);
	bool (*isEmpty)(void* list);
	void (*removeE)(void* list, void* e);
	void (*removeIndex)(void* list, _int index);
	void (*removeAll)(void* list, void* c);
	void (*set)(void* list, void* e, _int index);
	void* (*get)(void* list, _int index);
	_int (*getSize)(void* list);
	void* (*subList)(void* list, _int start, _int end);
};

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
	void* (*subList)(void* list, _int start, _int end));

Collection* cast_collection(void* c);
bool valid_list_size(_int size);
void valid_index(void* c, _int index);
void valid_type(void* c, void* e);

#endif //!COLLECTION_H
