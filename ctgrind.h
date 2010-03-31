#ifndef CT_GRIND_H_
#define CT_GRIND_H_

#include <sys/types.h>

extern void ct_poison(void* address, size_t length);
extern void ct_unpoison(void* address, size_t length);

#endif
