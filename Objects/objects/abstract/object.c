#include "object.h"

private void* clone(void* o);
private bool equals(void* o1, void* o2);
private char* toString(void* o);
private _uint hashCode(void* o);

Object* new_ObjectType(int32 type)
{
	Object* o = new_Object();
	o->type = type;
	return o;
}

Object* new_Object()
{
	CREATE_STRUCT_HEAP(Object, o);
	o->clone = clone;
	o->equals = equals;
	o->toString = toString;
	o->hashCode = hashCode;
	o->type = Object_t;
	o->magic_string = magic_string;
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
	WRITE_BUFFER_INT(MACRO_BUFFER1, hashCode(o), 16);
	MERGE_STRING_STACK(MACRO_BUFFER2, "Object: 0x", MACRO_BUFFER1);
	return MACRO_BUFFER2;
}

private _uint hashCode(void* o)
{
	return (_uint)o;
}

int32 instanceOf(void* o)
{
	return (*(Object**)o)->type;
}

Object* cast_object(void* o)
{
	if (strcmp(((Object*)o)->magic_string, magic_string) == 0) return o;
	return cast_object((*(Object**)o));
}
