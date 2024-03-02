#include "double.h"

OBJECT_STRING_BUFFER_SETUP(Double);
OBJECT_STATIC_TO_STRING_FUN(Double, double, %lf)

CAST_FN(Double)

private _int hashcode(void* o);
private char* toString(void* o);
private void* clone(void* o);
private bool equals(void* o1, void* o2);

Double* new_Double(double value)
{
	CREATE_STRUCT_HEAP(Double, d);
	SET_MAGIC(d, Double);
	d->object = new_Object("Double");
	d->value = value;
	d->object->hashcode = hashcode;
	d->object->clone = clone;
	d->object->toString = toString;
	d->object->equals = equals;
	return d;
}

private _int hashcode(void* o)
{
	return (_int)(CAST(Double, o)->value);
}

private char* toString(void* o)
{
	return OBJECT_STATIC_STRING_CALL(Double, CAST(Double, o)->value);
}

private void* clone(void* o)
{
	return new_Double(CAST(Double, o)->value);
}

private bool equals(void* o1, void* o2)
{
	return CAST(Double, o1)->value == CAST(Double, o2)->value;
}
