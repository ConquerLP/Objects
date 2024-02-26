#include "objects/stdlib.h"

int main(void) {

	Object* o = new_Object();

	printf("%s", o->meth->toString(o));

	return 0;
}