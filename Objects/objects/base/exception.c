#include "exception.h"

void try_catch_block(bool (*try_fun)(_int, ...), void (*catch_fun)(_int, ...),
	_int argc1, va_list args1, _int argc2, va_list args2)
{
	if (!try_fun(argc1, args1)) {
		catch_fun(argc2, args2);
	}
}