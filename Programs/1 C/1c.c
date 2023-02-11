//C program to demonstrate priority queue.
#include <stdio.h>
#define MAX_SIZE 100

void insert(int priority_queue[], int *n, int item) {
  int i, j;
  (*n)++;
  priority_queue[*n] = item;

  // Maintaining the heap property
  for (i = *n; i > 1; i /= 2) {
    if (priority_queue[i] > priority_queue[i / 2]) {
      // Swapping the values
      int temp = priority_queue[i];
      priority_queue[i] = priority_queue[i / 2];
      priority_queue[i / 2] = temp;
    } else {
      break;
    }
  }
}

int delete(int priority_queue[], int *n) {
  int i, j, x, item, val;
  item = priority_queue[1];
  val = priority_queue[*n];
  (*n)--;

  // Maintaining the heap property
  i = 1;
  j = 2 * i;
  while (j <= *n) {
    if (j < *n && priority_queue[j] < priority_queue[j + 1]) {
      j = j + 1;
    }
    if (val < priority_queue[j]) {
      priority_queue[i] = priority_queue[j];
      i = j;
      j = 2 * i;
    } else {
      break;
    }
  }
  priority_queue[i] = val;
  return item;
}

void display(int priority_queue[], int n) {
  int i;
  printf("Priority Queue: ");
  for (i = 1; i <= n; i++) {
    printf("%d ", priority_queue[i]);
  }
}

void main() {
  int n = 0;
  int priority_queue[MAX_SIZE];
  int item, choice;

  while (1) {
    printf("\n1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the item to be inserted: ");
        scanf("%d", &item);
        insert(priority_queue, &n, item);
        break;
      case 2:
        item = delete(priority_queue, &n);
        printf("The deleted item is: %d\n", item);
        break;
      case 3:
        display(priority_queue, n);
        break;
      case 4:
        return;
      default:
        printf("Invalid choice\n");
    }
  }
}