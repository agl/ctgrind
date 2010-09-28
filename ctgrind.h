#ifndef CT_GRIND_H_
#define CT_GRIND_H_

#include <stddef.h>

#if defined(__cplusplus)
  #define CT_POISON_EXTERN extern "C"
#else
  #define CT_POISON_EXTERN extern
#endif

CT_POISON_EXTERN void ct_poison(const void* address, size_t length);
CT_POISON_EXTERN void ct_unpoison(const void* address, size_t length);

#endif
