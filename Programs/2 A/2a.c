//C Program to Find the Largest of three numbers using Pointers
#include <stdio.h>

void largest(int *a, int *b, int *c) {
    int *largest = a;
    if (*b > *largest) {
        largest = b;
    }
    if (*c > *largest) {
        largest = c;
    }
    printf("Largest number is: %d\n", *largest);
}

void main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c);
    largest(&a, &b, &c);
}
