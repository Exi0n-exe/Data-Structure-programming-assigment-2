//C program for Factorial, GCD & Ackerman’s function ( Using Switch case)
#include <stdio.h>

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int ackermann(int m, int n) {
  if (m == 0)
    return n + 1;
  if (n == 0)
    return ackermann(m - 1, 1);
  return ackermann(m - 1, ackermann(m, n - 1));
}

void main() {
  int choice, m, n;

  printf("Enter 1 for Factorial\n");
  printf("Enter 2 for GCD\n");
  printf("Enter 3 for Ackermann's Function\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      printf("Enter a number to find its factorial: ");
      scanf("%d", &n);
      printf("Factorial of %d is %d\n", n, factorial(n));
      break;
    case 2:
      printf("Enter two numbers to find their GCD: ");
      scanf("%d%d", &m, &n);
      printf("GCD of %d and %d is %d\n", m, n, gcd(m, n));
      break;
    case 3:
      printf("Enter values of m and n for Ackermann's function: ");
      scanf("%d%d", &m, &n);
      printf("Ackermann's function for m = %d and n = %d is %d\n", m, n, ackermann(m, n));
      break;
    default:
      printf("Invalid choice\n");
  }
}
