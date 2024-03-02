#ifndef DOUBLE_H

#define DOUBLE_H

#include "macro.h"
#include "object.h"

static char* DoublemagicString = "Double";

typedef struct _Double Double, * pDouble;

struct _Double {
	Object* object;
	MAGIC;
	double value;
};

Double* new_Double(double value);
CAST_FN_PROTO(Double);

#endif //!DOUBLE_H