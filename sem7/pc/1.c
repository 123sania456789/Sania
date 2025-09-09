#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#define MAX 10

void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1, k = l;

    // ? allocate enough memory up to r
    int *temp = (int *)malloc(sizeof(int) * (r + 1));

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    // ? copy back correctly
    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    free(temp);
}

void sequentialMergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        sequentialMergeSort(arr, l, m);
        sequentialMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void parallelMergeSort(int arr_copy[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
      if (r - l < 50000) {   // threshold: sort small chunks sequentially
            sequentialMergeSort(arr_copy, l, r);
       } else {
        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr_copy, l, m);
            #pragma omp section
            parallelMergeSort(arr_copy, m + 1, r);
        }
        merge(arr_copy, l, m, r);
       }
    }
}

int main() {
    int n,i;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *arr_copy = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    printf("\nThe original array is\n");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Randomize input values
        arr_copy[i] = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");

    double start, end;

    start = omp_get_wtime();
    sequentialMergeSort(arr, 0, n - 1);
    end = omp_get_wtime();
    printf("\nSequential MergeSort Time: %f seconds\n", end - start);

    printf("\nSorted array using sequential processing:\n");
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    start = omp_get_wtime();
    parallelMergeSort(arr_copy, 0, n - 1);
    end = omp_get_wtime();
    printf("\nParallel MergeSort Time: %f seconds\n", end - start);

    printf("\nSorted array using parallel processing:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr_copy[i]);
    printf("\n");

    free(arr);
    free(arr_copy);

    return 0;
}
