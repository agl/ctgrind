#include "ctgrind.h"

// These are no-op functions which exist only so that valgrind can intercept
// them.

void ct_poison(const void *dat, size_t datlen)
{
}

void ct_unpoison(const void *dat, size_t datlen)
{
}
