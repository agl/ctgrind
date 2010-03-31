#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "ctgrind.h"

char check16_bad(unsigned char *a, unsigned char *b) {
  unsigned i;
  for (i = 0; i < 16; i++) {
    if (a[i] != b[i])
      return 0;
  }

  return 1;
}

char check16_good(unsigned char *a, unsigned char *b) {
  unsigned i;
  char result = 0;

  for (i = 0; i < 16; i++) {
    result |= a[i] ^ b[i];
  }

  return !result;
}

char bad_memory_access(unsigned char *a) {
  static const char r[2] = {1, 0};
  return r[a[0] & 1];
}

int
main() {
  unsigned char a[16], b[16];

  memset(a, 42, sizeof(a));
  memset(b, 42, sizeof(b));

  ct_poison(a, sizeof(a));

  printf("check16_bad\n");
  check16_bad(a, b);
  printf("check16_good\n");
  check16_good(a, b);
  printf("bad_memory_access\n");
  bad_memory_access(a);

  return 0;
}
