#include "object.h"

private void* clone(void* o);
private bool equals(void* o1, void* o2);
private char* toString(void* o);
private _uint hashCode(void* o);

Object* new_Object()
{
	CREATE_STRUCT_HEAP(Object, o);
	o->meth = create_IF_Object(clone, equals, toString, hashCode);
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
