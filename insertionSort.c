#include <stdio.h>

int arr[20];
void insertionSort(int);

int main()
{
    int i, n;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);
    printf("Enter %d elements to be sorted : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    insertionSort(n);
    printf("\nThe sorted list is : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void insertionSort(int n)
{
    int temp, i, j;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}