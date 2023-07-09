#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int random_number = (int)(10.0 * rand() / (RAND_MAX + 1.0));
  printf("%d ", random_number);
  return 0;
}