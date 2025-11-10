#include <stdio.h> 
#include <mpi.h> 
int main(int argc, char** argv){ 
int process_Rank, size_Of_Cluster, message_Item; 
MPI_Init(&argc, &argv); 
MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster); 
MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank); 
If (process_Rank == 0){ 
message_Item = 42; 
MPI_Send(&message_Item, 1, MPI_INT, 1, 1, MPI_COMM_WORLD); 
printf("%d is sent from from %d to process 1\n", message_Item, process_Rank); 
} 
else if(process_Rank == 1){ 
MPI_Recv(&message_Item, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, 
MPI_STATUS_IGNORE); 
printf("process 1 received %d from process 0 \n", message_Item); 
} 
MPI_Finalize(); 
return 0; 
} 
