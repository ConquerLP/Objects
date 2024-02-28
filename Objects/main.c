#include "objects/stdlib.h"

int main(void) {

	Array* a = new_Array("double", 10);

	Object* o = new_Object("double");

	a->a->set(a, o, 0);

	Object* o1 = a->a->get(a, 0);

	printf("%s", BOOL_STRING(instanceOf(o1, "double")));

	return 0;
}