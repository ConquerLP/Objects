#include "object.h"

CAST_FN(Object)

private _int hashcode(void* o);
private char* toString(void* o);
private void* clone(void* o);
private bool equals(void* o1, void* o2);

Object* new_Object(char* className)
{
	CREATE_STRUCT_HEAP(Object, o);
	SET_MAGIC(o, Object);
	o->className = className;
	o->hashcode = hashcode;
	o->toString = toString;
	o->clone = clone;
	o->equals = equals;
	return o;
}

private _int hashcode(void* o)
{
	return (_int)o;
}

private char* toString(void* o)
{
	return CAST(Object, o)->MAGIX;
}

private void* clone(void* o)
{
	return new_Object("Object");
}

private bool equals(void* o1, void* o2)
{
	return CAST(Object, o1)->hashcode == CAST(Object, o2)->hashcode;
}

bool instanceOf(void* o, char* className)
{
	return (strcmp(castObject(o)->className, className) == 0);
}
