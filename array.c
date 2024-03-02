#include "array.h"
#include "exception.h"

CAST_FN(Array)

private void set(void* a, void* e, _int index);
private void* get(void* a, _int index);
private _int indexOf(void* a, void* e);
private _int lastIndexOf(void* a, void* e);
private _int indexOfOffset(void* a, void* e, _int index);

private bool try_index_check(va_list args);
private void catch_index_check(va_list args);

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
	_int index = indexOfOffset(a, e, 0);
	_int found = ABSTRACT_COLLECTION_INVALID_INDEX;
	while (index != ABSTRACT_COLLECTION_INVALID_INDEX) {
		found = index;
		index = indexOfOffset(a, e, index + 1);
		if (index == ABSTRACT_COLLECTION_INVALID_INDEX) return found;
	}
	return index;
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

private bool try_index_check(va_list args)
{
	Array* a = va_arg(args, void*);
	_int index = va_arg(args, _int);
	if (index >= a->absCol->size || index < 0) return false;
	else return true;
}

private void catch_index_check(va_list args)
{
	Array* a = va_arg(args, void*);
	_int index = va_arg(args, _int);
	if (index != ABSTRACT_COLLECTION_INVALID_INDEX) {
		ERROR__("Array index out of bounds.");
	}
}
