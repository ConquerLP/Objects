#include "arrayList.h"
#include "..\..\base\misc\exception.h"

CAST_FN(ArrayList)

private void set(void* al, void* e, _int index);
private void* get(void* al, _int index);
private _int indexOf(void* al, void* e);
private _int lastIndexOf(void* al, void* e);
private _int indexOfOffset(void* al, void* e, _int index);
 
private bool add(void* al, void* e);
private bool addIndex(void* al, void* e, _int index);
private bool addAll(void* al, void* l);
private bool addAllIndex(void* al, void* l, _int index);
private void clear(void* al);
private bool contains(void* al, void* e);
private bool containsAll(void* al, void* l);

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
		containsAll);
	return al;
}

private void set(void* al, void* e, _int index)
{
	check_type(al, e);
	try_catch_block(try_index_check, catch_index_check, 0, al, index);

}

private void* get(void* al, _int index)
{
	try_catch_block(try_index_check, catch_index_check, 0, al, index);
}

private _int indexOf(void* al, void* e)
{
	check_type(al, e);
}

private _int lastIndexOf(void* al, void* e)
{

}

private _int indexOfOffset(void* al, void* e, _int index)
{
	check_type(al, e);
	ArrayList* list = al;
	Object* o = null;
	for (_int i = index; i < list->absCol->size; i++) {
		o = CAST(Object, list->e[i]);
		if (o->equals(list->e[i], e)) return i;
	}
	return ABSTRACT_COLLECTION_INVALID_INDEX;

}

private bool add(void* al, void* e)
{

}

private bool addIndex(void* al, void* e, _int index)
{

}

private bool addAll(void* al, void* l)
{

}

private bool addAllIndex(void* al, void* l, _int index)
{

}

private void clear(void* al)
{

}

private bool contains(void* al, void* e)
{


}

private bool containsAll(void* al, void* l)
{

}
