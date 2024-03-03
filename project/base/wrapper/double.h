#ifndef DOUBLE_H

#define DOUBLE_H

#include "..\misc\macro.h"	
#include "..\object.h"

MAGIC_STRING(Double);

typedef struct _Double Double, * pDouble;

struct _Double {
	Object* object;
	MAGIC;
	double value;
};

Double* new_Double(double value);
CAST_FN_PROTO(Double);

OBJECT_STATIC_TO_STRING_PROTO(Double, double);

#endif //!DOUBLE_H