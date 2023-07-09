#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setRandoms(int lower, int upper, int size, int *arr);
void countNums(int *arr, int size);

int main() {
  int lower = 1, upper = 9, size = 10000;
  int arr[size];

  srand(time(0));

  *arr = setRandoms(lower, upper, size, arr);

  countNums(arr, size);

  return 0;
}

int setRandoms(int lower, int upper, int size, int *arr) {
  int i;
  for (i = 0; i < size; i++) {
    int num = (rand() % (upper - lower + 1)) + lower;
    arr[i] = num;
  }

  return *arr;
}

void countNums(int *arr, int size) {
  int freq[size];
  int visited = -1;
  int i, j, count;
  for (i = 0; i < size; i++) {
    freq[i] = -1;
  }

  for (i = 0; i < size; i++) {
    count = 1;
    for (j = i + 1; j < size; j++) {
      /* If duplicate element is found */
      if (arr[i] == arr[j]) {
        count++;
        freq[j] = 0;
      }
    }

    /* If frequency of current element is not counted */
    if (freq[i] != 0) {
      freq[i] = count;
    }
  }

  /*
   * Print frequency of each element
   */
  printf("\nFrequency of all elements of array : \n");
  for (i = 0; i < size; i++) {
    if (freq[i] != 0) {
      printf("%d occuring rate %.f %%\n", arr[i], 100 * freq[i] / (double)size);
    }
  }
}