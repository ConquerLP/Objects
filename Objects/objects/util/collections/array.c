#include "array.h"

private void add(void* list, void* e);
private void addIndex(void* list, void* e, _uint index);
private void addCollection(void* list, void* c);
private void addCollectionIndex(void* list, void* c, _uint index);
private void clear(void* list);
private bool contains(void* list, void* e);
private bool containsAll(void* list, void* c);
private _int indexOf(void* list, void* e);
private _int lastIndexOf(void* list, void* e);
private bool isEmpty(void* list);
private void removeE(void* list, void* e);
private void removeIndex(void* list, _uint index);
private void removeAll(void* list, void* c);
private void set(void* list, void* e, _uint index);
private void* get(void* list, _uint index);
private _uint getSize(void* list);
private void* subList(void* list, _uint start, _uint end);

Array* new_Array(_uint size, int32 type)
{
	if (!valid_list_size(size)) ERROR__("Invalid array size.");
	CREATE_STRUCT_HEAP(Array, a);
	a->o = new_ObjectType(Array_t);
	a->size = size;
	a->type = type;
	MALLOC(a->e, void*, size);
	for (_uint i = 0; i < size; ++i) {
		a->e[i] = null;
	}
	a->meth = create_IF_List(add, addIndex, addCollection, addCollectionIndex,
				clear, contains, containsAll, indexOf, lastIndexOf, isEmpty, removeE,
				removeIndex, removeAll, set, get, getSize, subList);
	return a;
}

private void add(void* list, void* e)
{

}

private void addIndex(void* list, void* e, _uint index)
{

}

private void addCollection(void* list, void* c)
{

}

private void addCollectionIndex(void* list, void* c, _uint index)
{

}

private void clear(void* list)
{

}

private bool contains(void* list, void* e)
{

}

private bool containsAll(void* list, void* c)
{

}

private _int indexOf(void* list, void* e)
{

}

private _int lastIndexOf(void* list, void* e)
{

}

private bool isEmpty(void* list)
{

}

private void removeE(void* list, void* e)
{

}

private void removeIndex(void* list, _uint index)
{

}

private void removeAll(void* list, void* c)
{

}

private void set(void* list, void* e, _uint index)
{

}

private void* get(void* list, _uint index)
{

}

private _uint getSize(void* list)
{

}

private void* subList(void* list, _uint start, _uint end) 
{

}
