#include "array.h"

CAST_FN(Array)

private void set(void* a, void* e, _int index);
private void* get(void* a, _int index);

private void check_index(void* a, _int index);

Array* new_Array(char* type, _int size)
{
	CREATE_STRUCT_HEAP(Array, a);
	if (size <= 0) ERROR__("Invalid array size.");
	a->a = new_AbstractCollection(type, size);
	SET_MAGIC(a, Array);
	MALLOC(a->e, void*, size);
	for (_int i = 0; i < size; i++) {
		a->e[i] = null;
	}
	a->a->o->className = "Array";
	a->a->get = get;
	a->a->set = set;
	return a;
}

private void set(void* a, void* e, _int index)
{
	check_index(a, index);
	check_type(a, e);
	Array* array = a;
	array->e[index] = e;
}

private void* get(void* a, _int index)
{
	check_index(a, index);
	Array* array = a;
	return array->e[index];
}

private void check_index(void* a, _int index)
{
	Array* array = a;
	if (index < 0 || index >= array->a->getSize(a))
		ERROR__("Array index out of bounds.");
}