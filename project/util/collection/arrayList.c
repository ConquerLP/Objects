#include "arrayList.h"

CAST_FN(ArrayList)

private void set(void* a, void* e, _int index);
private void* get(void* a, _int index);
private _int indexOf(void* a, void* e);
private _int lastIndexOf(void* a, void* e);
private _int indexOfOffset(void* a, void* e, _int index);

private bool try_index_check(va_list args);
private void catch_index_check(va_list args);
 
private bool *add(void* al, void* e);
private bool *addIndex(void* al, void* e, _int index);
private bool *addAll(void* al, void* l);
private bool *addAllIndex(void* al, void* l, _int index);
private void *clear(void* al);
private bool *contains(void* al, void* e);
private bool *containsAll(void* al, void* l);

ArrayList* new_ArrayListSize(char* type, _int size)
{
	ArrayList* al = new_ArrayList(type);
	if (size <= 0) ERROR__("ArrayList size must be positive.");
	MALLOC(al->e, void*, size);
	for (_int i = 0; i < size; i++) {
		al->e[i] = null;
	}
	return al;
}

ArrayList* new_ArrayList(char* type)
{
	CREATE_STRUCT_HEAP(ArrayList, al);
	al->absCol = new_AbstractCollection(type, 0);
	SET_MAGIC(al, ArrayList);
	al->e = null;
	al->absCol->object->className = "ArrayList";
	al->absCol->get = get;
	al->absCol->set = set;
	al->absCol->indexOf = indexOf;
	al->absCol->lastIndexOf = lastIndexOf;
	al->listIF = create_ListInterface(
		add,
		addIndex,
		addAll,
		addAllIndex,
		clear,
		contains,
		containsAll
	);
	return al;
}

private void set(void* a, void* e, _int index)
{

}

private void* get(void* a, _int index)
{

}

private _int indexOf(void* a, void* e)
{

}

private _int lastIndexOf(void* a, void* e)
{

}

private _int indexOfOffset(void* a, void* e, _int index)
{

}

private bool try_index_check(va_list args)
{

}

private void catch_index_check(va_list args)
{

}

private bool* add(void* al, void* e)
{

}

private bool* addIndex(void* al, void* e, _int index)
{

}

private bool* addAll(void* al, void* l)
{

}

private bool* addAllIndex(void* al, void* l, _int index)
{

}

private void* clear(void* al)
{

}

private bool* contains(void* al, void* e)
{

}

private bool* containsAll(void* al, void* l)
{

}
