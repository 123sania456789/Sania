#include <stdio.h>
#include <omp.h>

int main() {
    int n, i;
    printf("Enter no. of iterations: ");
    scanf("%d", &n);
    omp_set_num_threads(4); // Fix the number of threads = 4
    #pragma omp parallel for schedule(static, 2)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num(); // Get thread ID (0 to 3)

        // Each thread prints its work in an organized manner
        #pragma omp critical
        {
            printf("Thread %d -> Iteration %d\n", tid, i);
        }
    }
    return 0;
}
