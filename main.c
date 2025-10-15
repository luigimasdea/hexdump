#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BYTES_PER_LINE 16

size_t byte_count = 0;

void hexdump(void *p, size_t len) {
  unsigned char *buf = (unsigned char*) p;
  size_t cycle_count = 0;

  for (size_t i = 0; i < len; ++i) {
    if (i % BYTES_PER_LINE == 0) {
      printf("%08lx  ", byte_count);
    }
    printf("%02X ", buf[i]);
    if ((i+1) % (BYTES_PER_LINE/2) == 0 && (i+1) % BYTES_PER_LINE != 0) {
      printf(" ");
    }
    ++byte_count;

    if ((i+1) % BYTES_PER_LINE == 0 || i == len - 1) {
      if (i == len - 1) {
        size_t padding = BYTES_PER_LINE - (len % BYTES_PER_LINE);
        padding %= BYTES_PER_LINE;
        for (size_t j = 0; j < padding; ++j) {
          printf("   ");
        }
        if (i % BYTES_PER_LINE < (BYTES_PER_LINE/2 - 1)) {
          printf(" ");
        }
      }

      printf(" |");

      if (i == len -1) {
        for (size_t j = cycle_count * BYTES_PER_LINE; j < len; ++j) {
          char c = isprint(buf[j]) ? buf[j] : '.';
          printf("%c", c);
        }
      } else {
        for (size_t j = cycle_count * BYTES_PER_LINE; j < cycle_count * BYTES_PER_LINE + BYTES_PER_LINE; ++j) {
          char c = isprint(buf[j]) ? buf[j] : '.';
          printf("%c", c);
        }
      }

      printf("|\n");
      ++cycle_count;
    }
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    perror("Invalid argument");
    exit(EXIT_FAILURE);
  }

  char *path = argv[1];

  int fd = open(path, O_RDONLY);
  if (fd < 0) {
    perror("Unable to open the file");
    exit(EXIT_FAILURE);
  }

  unsigned char buf[32];
  ssize_t nread;

  while (1) {
    nread = read(fd, buf, sizeof(buf));
    if (nread < 0) {
      perror("Read error");
      exit(EXIT_FAILURE);
    }
    if (nread == 0) {
      break;
    }
    hexdump(buf, (size_t) nread);
  }
  printf("%08lx\n", byte_count);

  close(fd);
  exit(EXIT_SUCCESS);
}
