#include <sys/types.h>

// These are no-op functions which exist only so that valgrind can intercept
// them.

void ct_poison(void *dat, size_t datlen)
{
}

void ct_unpoison(void *dat, size_t datlen)
{
}
