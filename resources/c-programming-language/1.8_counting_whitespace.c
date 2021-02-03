#include <stdio.h>

int main() {
  int c;
  int blanks = 0;
  int tabs = 0;
  int nl = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      ++tabs;
    } else if (c == ' ') {
      ++blanks;
    } else if (c == '\n') {
      ++nl;
    }
  }

  printf("\nBlanks: %d\nTabs: %d\nNew Lines: %d\n", blanks, tabs, nl);
  return 0;
}
