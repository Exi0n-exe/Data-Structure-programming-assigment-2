//C Program to Find transpose of a given matrix.
#include <stdio.h>

void transpose(int a[][10], int n, int m) {
  int i, j;
  int trans[10][10];

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      trans[j][i] = a[i][j];
    }
  }

  printf("The transpose of the matrix is: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d\t", trans[i][j]);
    }
    printf("\n");
  }
}

void main() {
  int a[10][10], n, m, i, j;

  printf("Enter the number of rows and columns: ");
  scanf("%d%d", &n, &m);

  printf("Enter the elements of the matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }

  transpose(a, n, m);

}
