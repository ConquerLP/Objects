#include "base\misc\stdlib.h"

int main(void) {

	Array* a = new_Array("Double", 2);
	Double* b = new_Double(3.1);
	a->absCol->set(a, b, 0);
	a->absCol->set(a, b, 1);

	a->absCol->lastIndexOf(a, b);

	return 0;
}