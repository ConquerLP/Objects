#include "object.h"

private void* clone(void* o);
private bool equals(void* o1, void* o2);
private char* toString(void* o);
private _uint hashCode(void* o);
private int32 instanceOf(void* o);

Object* new_ObjectType(int32 type)
{
	Object* o = new_Object();
	o->type = type;
	return o;
}

Object* new_Object()
{
	CREATE_STRUCT_HEAP(Object, o);
	o->meth = create_IF_Object(clone, equals, toString, hashCode, instanceOf);
	o->type = Object_t;
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

private int32 instanceOf(void* o)
{
	return (*(Object**)o)->type;
}