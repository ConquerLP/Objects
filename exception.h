#ifndef EXCEPTION_H

#define EXCEPTION_H

#include <stdarg.h>
#include "macro.h"

void try_catch_block(bool (*try_fun)(va_list args), void (*catch_fun)(va_list args), int start, ...);

#endif //!EXCEPTION_H