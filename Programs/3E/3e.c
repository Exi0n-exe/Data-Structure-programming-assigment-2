//C Program to demonstrate address calculation sort.
#include <stdio.h>
#define MAX_SIZE 100

void address_calculation_sort(int arr[], int n)
{
    int i, j, k, index, temp[MAX_SIZE];

    for (i = 0; i < n; i++)
    {
        index = arr[i] % n;
        temp[index] = arr[i];
    }

    j = 0;
    for (i = 0; i < n; i++)
    {
        if (temp[i] != 0)
        {
            arr[j++] = temp[i];
        }
    }
}

void main()
{
    int i, n, arr[MAX_SIZE];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    address_calculation_sort(arr, n);

    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

}
