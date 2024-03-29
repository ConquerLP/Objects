#include "exception.h"

void try_catch_block(bool (*try_fun)(va_list args), void (*catch_fun)(va_list args), int start,  ...)
{
	va_list args;
	va_start(args, start);
	if (!try_fun(args)) {
		catch_fun(args);
	}
	va_end(args);
}