#include "array.h"
#include "..\..\base\misc\exception.h"

CAST_FN(Array)

private void set(void* a, void* e, _int index);
private void* get(void* a, _int index);
private _int indexOf(void* a, void* e);
private _int lastIndexOf(void* a, void* e);
private _int indexOfOffset(void* a, void* e, _int index);



Array* new_Array(char* type, _int size)
{
	CREATE_STRUCT_HEAP(Array, a);
	if (size <= 0) ERROR__("Invalid array size.");
	a->absCol = new_AbstractCollection(type, size);
	SET_MAGIC(a, Array);
	MALLOC(a->e, void*, size);
	for (_int i = 0; i < size; i++) {
		a->e[i] = null;
	}
	a->absCol->object->className = "Array";
	a->absCol->get = get;
	a->absCol->set = set;
	a->absCol->indexOf = indexOf;
	a->absCol->lastIndexOf = lastIndexOf;
	return a;
}

private void set(void* a, void* e, _int index)
{
	check_type(a, e);
	try_catch_block(try_index_check, catch_index_check, 0, a, index);
	Array* array = a;
	array->e[index] = e;
}

private void* get(void* a, _int index)
{
	try_catch_block(try_index_check, catch_index_check, 0, a, index);
	Array* array = a;
	return array->e[index];
}

private _int indexOf(void* a, void* e)
{
	return indexOfOffset(a, e, 0);
}

private _int lastIndexOf(void* a, void* e)
{
	check_type(a, e);
	Array* array = a;
	Object* o = null;
	for (_int i = array->absCol->size - 1; i >= 0; i--) {
		o = CAST(Object, array->e[i]);
		if (o->equals(array->e[i], e)) return i;
	}
	return ABSTRACT_COLLECTION_INVALID_INDEX;
}

private _int indexOfOffset(void* a, void* e, _int index)
{
	check_type(a, e);
	Array* array = a;
	Object* o = null;
	for (_int i = index; i < array->absCol->size; i++) {
		o = CAST(Object, array->e[i]);
		if (o->equals(array->e[i], e)) return i;
	}
	return ABSTRACT_COLLECTION_INVALID_INDEX;
}
