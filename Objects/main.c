#include "objects/stdlib.h"

int main(void) {

	pArray a = new_Array(10, Array_t);
	printf("%s\n", a->c->o->toString(a));

	Collection* c = new_Collection(Array_t, double_t, 10, 
		null, null, null, null, null, null, null, null, 
		null, null, null, null, null, null, null, null, null);

	Object* o = new_ObjectType(double_t);

	for (_int i = 0; i < a->c->getSize(a); ++i) {
		a->c->set(a, a, i);
	}

	return 0;
}