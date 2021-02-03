#include <stdio.h>

int main() {
  int isBlank = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (isBlank == 0) {
        putchar(c);
        isBlank = 1;
      }
    } else {
      isBlank = 0;
      putchar(c);
    }
  }

  return 0;
}
