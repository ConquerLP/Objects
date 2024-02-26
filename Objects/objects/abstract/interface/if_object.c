#include "if_object.h"

IF_Object* create_IF_Object()
{
	CREATE_STRUCT_HEAP(IF_Object, interface);
	interface->clone = null;
	interface->equals = null;
	interface->toString = null;
	interface->hashCode = null;
	return interface;
}

