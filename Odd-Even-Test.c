#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Arrange(int lower, int upper, int size, int *arr);

int main() {
  int lower = 1, upper = 9, size = 10000;
  int arr[size];

  srand(time(0));
  Arrange(lower, upper, size, arr);

  return 0;
}

void Arrange(int lower, int upper, int size, int *arr) {
  int i, j = 0, k = 0;
  int odd[size], even[size];

  for (i = 0; i < size; i++) {
    int num = (rand() % (upper - lower + 1)) + lower;
    arr[i] = num;

    if (num % 2 == 0) {
      even[k] = num;
      k++;
    } else {
      odd[j] = num;
      j++;
    }
  }
  double even_rate = k / (double)size * 100;
  double odd_rate = j / (double)size * 100;
  printf("\nEven rate: %.f %%", even_rate);
  printf("\nOdd rate: %.f %%", odd_rate);
}