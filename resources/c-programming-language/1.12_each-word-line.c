#include <stdio.h>

int main() {
  int c;
  int isWord = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (isWord == 0) {
        isWord = 1;
        putchar('\n');
      }
    } else {
      isWord = 0;
      putchar(c);
    }
  }

  return 0;
}
