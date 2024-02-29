#ifndef EXCEPTION_H

#define EXCEPTION_H

#include <stdarg.h>

void try_catch_block(bool (*try_fun)(_int, ...), void (*catch_fun)(_int, ...),
	_int argc1, va_list args1, _int argc2, va_list args2);

#endif //!EXCEPTION_H