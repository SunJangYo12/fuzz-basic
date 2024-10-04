#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256



/*
* target function find with:
* objdump -T libvuln.so
*/
extern void fuzzMe(const uint8_t*, uint32_t);


/*Persistent loop*/
void fuzz_one_input(const uint8_t *buf, int len) {
   fuzzMe(buf, len);
}

int main(void)
{
  const uint8_t buffer[BUFFER_SIZE];

  ssize_t rlength = fread((void*) buffer, 1, BUFFER_SIZE, stdin);
  if (rlength == -1)
    return errno;

  fuzz_one_input(buffer, BUFFER_SIZE);

  return 0;
}
