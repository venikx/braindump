#include <stdio.h>

int main() {
  float C = 0.0, F;
  int step = 20;
  int end = 500;

  printf("Celc Farhenheit\n");
  while (C <= end) {
    F = (C * 9 / 5) + 32;
    printf("%3.0f %6.1f\n", C, F);
    C += step;
  }
}
