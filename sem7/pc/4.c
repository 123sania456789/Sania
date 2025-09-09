#include <stdio.h>
#include <omp.h>
#include <time.h>

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) 
        return 0;
    if (n == 2) 
        return 1;
    if (n % 2 == 0) 
        return 0;

    for (int i = 3; i <= n / 2; i++) {
        if (n % i == 0) 
            return 0;
    }
    return 1;
}

int main() {
    int n, i;
    double start, end, pstart, pend;

    // Input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Serial execution
    printf("\nSerial Execution:\n");
    start = omp_get_wtime();
    for (i = 1; i <= n; i++) {
        if (is_prime(i))
            printf("%d ", i);
    }
    end = omp_get_wtime();
    printf("\nTime taken (Serial): %f seconds\n", end - start);

    // Parallel execution using OpenMP
    printf("\nParallel Execution:\n");
    pstart = omp_get_wtime();
    #pragma omp parallel for default(none) shared(n) private(i)
    for (i = 1; i <= n; i++) {
        if (is_prime(i))
            printf("%d ", i);
    }
    pend = omp_get_wtime();
    printf("\nTime taken (Parallel): %f seconds\n", pend - pstart);

    return 0;
}
