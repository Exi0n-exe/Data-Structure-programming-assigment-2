//C program to demonstrate insertion sort.
#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d\t", arr[i]);
  }
}

int main() {
  int arr[100], n, i;

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  printf("Enter the elements of the array: \n");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  insertionSort(arr, n);

  printf("\nSorted array: ");
  printArray(arr, n);

  return 0;
}
