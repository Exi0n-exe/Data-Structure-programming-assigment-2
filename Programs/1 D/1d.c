//Program to find sum of the first n numbers using recursion, where the value of n is provided by the user.
#include <stdio.h>

int sum(int n) {
    if (n == 0)
        return 0;
    else
        return n + sum(n - 1);
}

int main() {
    int n, result;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    result = sum(n);
    printf("Sum of first %d numbers is: %d\n", n, result);
    return 0;
}
