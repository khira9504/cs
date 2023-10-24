#include <stdio.h>

int main(void) {
  int numbers[] = { 2, 4, 6, 8, 10, 12, 14 };
  printf("%i\n", numbers[0]);
  printf("%i\n", numbers[1]);
  printf("%i\n", numbers[2]);
  printf("%i\n", *numbers);
  printf("%i\n", *(numbers + 1));
  printf("%i\n", *(numbers + 2));
};