#include <stdio.h>

int main() {
  float F = 0.0, C;
  int step = 20;
  int end = 500;

  printf("Fahr Celcius\n");
  while (F <= end) {
    C = 5 * (F - 32) / 9;
    printf("%3.0f %6.1f\n", F, C);
    F += step;
  }
}
