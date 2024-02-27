#include "array.h"

private void add(void* list, void* e);
private void addIndex(void* list, void* e, _int index);
private void addCollection(void* list, void* c);
private void addCollectionIndex(void* list, void* c, _int index);
private void clear(void* list);
private bool contains(void* list, void* e);
private bool containsAll(void* list, void* c);
private _int indexOf(void* list, void* e);
private _int lastIndexOf(void* list, void* e);
private bool isEmpty(void* list);
private void removeE(void* list, void* e);
private void removeIndex(void* list, _int index);
private void removeAll(void* list, void* c);
private void set(void* list, void* e, _int index);
private void* get(void* list, _int index);
private _int getSize(void* list);
private void* subList(void* list, _int start, _int end);

Array* new_Array(_int size, int32 type)
{
	if (!valid_list_size(size)) ERROR__("Invalid array size.");
	CREATE_STRUCT_HEAP(Array, a);
	a->c = new_Collection(type, Array_t, size, add, addIndex, addCollection, addCollectionIndex,
		clear, contains, containsAll, indexOf, lastIndexOf, isEmpty, removeE,
		removeIndex, removeAll, set, get, getSize, subList);
	MALLOC(a->e, void*, size);
	for (_int i = 0; i < size; ++i) {
		a->e[i] = null;
	}
	return a;
}

private void add(void* list, void* e)
{
}

private void addIndex(void* list, void* e, _int index)
{
}

private void addCollection(void* list, void* c)
{
}

private void addCollectionIndex(void* list, void* c, _int index)
{
}

private void clear(void* list)
{
}

private bool contains(void* list, void* e)
{
	Array* a = list;
	Object* o = cast_object(e);
	for (_int i = 0; i < a->c->size; ++i) {
		if (o->equals(e, a->e[i])) return true;
	}
	return false;
}

private bool containsAll(void* list, void* c)
{
	Array* a = list;
	Collection* col = cast_collection(c);
	for (_int i = 0; i < col->size; ++i) {
		if (!contains(list, col->get(c, i))) return false;
	}
	return true;
}

private _int indexOf(void* list, void* e)
{
	Array* a = list;
	Object* o = cast_object(e);
	for (_int i = 0; i < a->c->size; ++i) {
		if (o->equals(e, a->e[i])) return i;
	}
	return -1;
}

private _int lastIndexOf(void* list, void* e)
{
	Array* a = list;
	Object* o = cast_object(e);
	for (_int i = a->c->size; i >= 0; --i) {
		if (o->equals(e, a->e[i])) return i;
	}
	return -1;
}

private bool isEmpty(void* list)
{
	Array* a = list;
	return !(a->e[0]);
}

private void removeE(void* list, void* e)
{
}

private void removeIndex(void* list, _int index)
{
}

private void removeAll(void* list, void* c)
{
}

private void set(void* list, void* e, _int index)
{
	valid_index(list, index);
	valid_type(list, e);
	Array* a = list;
	a->e[index] = e;
}

private void* get(void* list, _int index)
{
	valid_index(list, index);
	Array* a = list;
	return a->e[index];
}

private _int getSize(void* list)
{
	return cast_collection(list)->size;
}

private void* subList(void* list, _int start, _int end)
{
	return null;
}
