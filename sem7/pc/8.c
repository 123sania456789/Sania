#include <mpi.h> 
#include <stdio.h> 
int main(int argc, char** argv) { 
int rank, size; 
int send_data[100], recv_data, gather_data[100]; 
MPI_Init(&argc, &argv);                        // Initialize MPI 
MPI_Comm_rank(MPI_COMM_WORLD, &rank);          // Get process rank 
MPI_Comm_size(MPI_COMM_WORLD, &size);          // Get number of processes 
// Only root initializes the data to be scattered 
if (rank == 0) { 
for (int i = 0; i < size; i++) { 
send_data[i] = (i + 1) * 10;  // e.g., 10, 20, 30, 40... 
} 
printf("\nRoot process initialized data: "); 
for (int i = 0; i < size; i++) { 
printf("%d ", send_data[i]); 
} 
printf("\n"); 
} 
// Scatter one integer to each process from root 
MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD); 
printf("\nProcess %d received value %d\n", rank, recv_data); 
// Each process modifies its data 
recv_data *= 2; 
// Gather all modified values back to root 
MPI_Gather(&recv_data, 1, MPI_INT, gather_data, 1, MPI_INT, 0, MPI_COMM_WORLD); 
// Root prints gathered data 
if (rank == 0) {
printf("\nRoot process gathered modified data: "); 
for (int i = 0; i < size; i++) { 
printf("%d ", gather_data[i]); 
} 
printf("\n"); 
} 
MPI_Finalize();    // Finalize MPI 
return 0; 
}
