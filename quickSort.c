#include <stdio.h>

int arr[10];
int partition(int, int);
void quickSort(int, int);

int main()
{
    int i;
    arr[9] = 100;
    printf("Enter list elements to be sorted : ");
    for (i = 0; i < 9; i++)
        scanf("%d", &arr[i]);
    quickSort(0, 9);
    printf("\nThe sorted list is : ");
    for (i = 0; i < 9; i++)
        printf("%d ", arr[i]);
}

int partition(int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    int temp = 0;
    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(l, h);
        quickSort(l, j);
        quickSort(j + 1, h);
    }
}