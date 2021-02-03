#include <stdio.h>

#define UPPER 500
#define LOWER 0
#define STEP 20

int main() {
  printf("Celc Farhenheit\n");
  for (int C = UPPER; C >= LOWER; C -= STEP) {
    printf("%3d %6.1f\n", C, (C * 9.0 / 5.0) + 32);
  }
}
