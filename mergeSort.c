#include <stdio.h>

int arr[20];
int n;
void merge(int, int, int);
void mergeSort(int, int);

int main()
{
    int i;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);
    printf("Enter %d elements to be sorted : ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    mergeSort(0, n - 1);
    printf("\nThe sorted list is : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void merge(int l, int mid, int h)
{
    int B[20];
    for (int i = 0; i < n; i++)
        B[i] = arr[i];
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }
    for (; i <= mid; i++)
        B[k++] = arr[i];
    for (; j <= h; j++)
        B[k++] = arr[j];
    for (int i = 0; i < n; i++)
        arr[i] = B[i];
}

void mergeSort(int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, h);
        merge(l, mid, h);
    }
}