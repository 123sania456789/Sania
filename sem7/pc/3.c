#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// Recursive Fibonacci function using OpenMP tasks
int fib_recursive_omp(int n) {
    int x, y;

    if (n < 2) {
        return n;
    }

    // Create tasks for parallel computation
    #pragma omp task shared(x)
    x = fib_recursive_omp(n - 1);

    #pragma omp task shared(y)
    y = fib_recursive_omp(n - 2);

    // Wait for both tasks to complete
    #pragma omp taskwait

    return x + y;
}

int main() {
    int n = 10; // Fibonacci number to compute
    double start_time, end_time;

    // Start parallel region
    #pragma omp parallel shared(n)
    {
        // Only one thread should start the recursion
        #pragma omp single
        {
            start_time = omp_get_wtime();

            int result = fib_recursive_omp(n);
            printf("fib(%d) = %d\n", n, result);

            end_time = omp_get_wtime();
            printf("Time taken: %f seconds\n", end_time - start_time);
        }
    }

    return 0;
}
