#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setRandoms(int lower, int upper, int size, int *arr) {
  int i;
  for (i = 0; i < size; i++) {
    int num = (rand() % (upper - lower + 1)) + lower;
    arr[i] = num;
  }

  return *arr;
}

int calSum(int *arr, int size) {
  int sum = 0;
  double mean = 0;
  int i;
  for (i = 0; i < size; i++) {
    sum += arr[i];
  }

  return sum;
}

int main() {
  int lower = 1, upper = 9;
  const int size = 1000;
  int arr[size];
  for(int i =0; i < size; i++){
    arr[i] = 0;
  }

  srand(time(0));

  *arr = setRandoms(lower, upper, size, arr);

  int sum = calSum(arr, size);
  double mean = sum / (double)size;
  printf("%.2f\n", mean);
  return 0;
}