#include "object.h"

private void* clone(void* o);
private bool equals(void* o1, void* o2);
private char* toString(void* o);
private _uint hashCode(void* o);

Object* new_Object()
{
	CREATE_STRUCT_HEAP(Object, o);
	o->meth->clone = clone;
	o->meth->equals = equals;
	o->meth->toString = toString;
	o->meth->hashCode = hashCode;
	return o;
}

private void* clone(void* o)
{
	return new_Object();
}

private bool equals(void* o1, void* o2)
{
	return o1 == o2;
}

private char* toString(void* o)
{
	return "Object";
}

private _uint hashCode(void* o)
{
	return (_uint)o;
}
