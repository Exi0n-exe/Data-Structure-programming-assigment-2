//C program to demonstrate hash table creation and show various operations.4
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Node {
  int key;
  int value;
  struct Node* next;
};

struct Node* hashTable[MAX];

void init() {
  int i;
  for (i = 0; i < MAX; i++) {
    hashTable[i] = NULL;
  }
}

int hashFunction(int key) {
  return key % MAX;
}

void insert(int key, int value) {
  int index = hashFunction(key);
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = hashTable[index];
  hashTable[index] = newNode;
}

int search(int key) {
  int index = hashFunction(key);
  struct Node* current = hashTable[index];

  while (current != NULL) {
    if (current->key == key) {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

void delete(int key) {
  int index = hashFunction(key);
  struct Node* current = hashTable[index];
  struct Node* prev = NULL;

  while (current != NULL) {
    if (current->key == key) {
      if (prev == NULL) {
        hashTable[index] = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void main() {
  int i, key, value, choice;

  init();

  while (1) {
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the key: ");
        scanf("%d", &key);
        printf("Enter the value: ");
        scanf("%d", &value);
        insert(key, value);
        break;

      case 2:
        printf("Enter the key to search: ");
        scanf("%d", &key);
        value = search(key);
        if (value == -1) {
          printf("Key not found\n");
        } else {
          printf("Value: %d\n", value);
        }
        break;

      case 3:
        printf("Enter the key to delete: ");
        scanf("%d", &key);
        delete(key);
        break;

      case 4:
        exit(0);

      default:
        printf("Invalid choice\n");
        break;
    }
  }

}