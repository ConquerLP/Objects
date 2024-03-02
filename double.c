#include "double.h"

Double* castDouble(void* o) {
	Double* clazz = o; 
	if (strcmp(clazz->magicString, DoublemagicString) == 0) return o; 
	else return castDouble((*(Double**)o));
}

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
	return "Double";
}

private void* clone(void* o)
{
	return new_Double(CAST(Double, o)->value);
}

private bool equals(void* o1, void* o2)
{
	return CAST(Double, o1)->value == CAST(Double, o2)->value;
}
