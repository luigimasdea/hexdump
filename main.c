#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_LINE 16
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

void hexdump(void *p, size_t len) {
  unsigned char *buf = (unsigned char*) p;

  for (int i = 0; i < len; ++i) {
    if (i % BYTES_PER_LINE == 0) {
      printf("\n");
    }

    // if (i % (BYTES_PER_LINE / 2) == 0) {
    //   printf(" ");
    // }
    printf("%02X ", buf[i]);
  }
}

int main(void) {
  FILE *fp = fopen("text", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  unsigned char buf[32];
  size_t nread;

  int j = 0;
  while (1) {
    nread = fread(buf, sizeof(*buf), ARRAY_SIZE(buf), fp);
    if (nread == 0) {
      break;
    }
    hexdump(buf, nread);

    // printf("\n\nCICLO N°: %d\n\n", j++);
  }

  // int a = 255;
  // printf("%02X\n", a);

  fclose(fp);
  exit(EXIT_SUCCESS);
}
