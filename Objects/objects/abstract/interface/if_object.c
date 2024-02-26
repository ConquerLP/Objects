#include "if_object.h"

IF_Object* create_IF_Object(void* (*clone)(void* o),
	bool (*equals)(void* o1, void* o2),
	char* (*toString)(void* o),
	_uint(*hashCode)(void* o),
	int32(*instanceOf)(void* o))
{
	CREATE_STRUCT_HEAP(IF_Object, interface);
	interface->clone = clone;
	interface->equals = equals;
	interface->toString = toString;
	interface->hashCode = hashCode;
	interface->instanceOf = instanceOf;
	return interface;
}

