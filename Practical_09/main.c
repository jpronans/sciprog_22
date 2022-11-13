#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"

// Function in header declared
int isMagicSquare(int ** square, const int n);

// Dynamically allocate the memory for an array of 'n' integers
int *allocatearray(const int order){
  int *myints;

  myints = (int *)malloc((order * order ) * sizeof(int));

  // Check return value
  if (myints == NULL){
  printf("Malloc Failed, exiting...\n");
                 
  // exit on failure
  exit(1);
  }

  // return allocated memory space
  return myints;
}


// Main
int main(void)
{

  // Counter variables
  //int i,j,k,p,q,mid,order,res;
  //int* magic;
  //int line[20];
  // Variably for holding matrix
  int **matrix=NULL;
  char temp;
  int r,c, order;
   
  printf("Initial Test of 3x3\n");
  
  int three1[3]= {2,7,6};
  int three2[3]= {9,5,1};
  int three3[3]= {4,3,8};

  int *newthree[3] = {three1,three2,three3};

  
  // Check return value of isMagicSquare  
  if (isMagicSquare(newthree, 3) == 1)
    printf("Matrix is Magic\n");

  FILE* fp=fopen("test","w");
  fprintf(fp, "%d\n", 3); 
  for(r = 0; r < 3; r++){
    for(c = 0; c < 3; c++){

      fprintf(fp, " %d", newthree[r][c]); 
      printf(" %d", newthree[r][c]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
  printf("\n");

  fp = fopen("test","r");
  fscanf(fp, "%d", &order);
  // Allocate space for 1 row
  //int *tmp=(int *)malloc(order+ sizeof(int));
  //allocatearray(order);
  //line[0]=0;
  //line[1]=0;
  //line[2]=0;
  
   

  printf("Order read from file is %d\n", order);
  // Allocate space for Int Memory Pointers
  matrix=(int **)malloc(order+sizeof(int*));

  //int *row=NULL;
  //int *line=(int *)malloc(order+ sizeof(int)); 
  //int r = 0;
  // Row count
  for(r=0; r<order; r++){
    int *line=(int *)malloc(order+ sizeof(int));
    int i=0;
    do {
      fscanf(fp, "%d%c", line+i, &temp);
      i++;
    } while (temp != '\n' && i < 20);

    int j=0;
    for(j=0; j<order; j++) { 
      printf("%d ", line[j]); 
    }
    //printf("%d", matrix[r]);
    //printf("%d", *matrix[r]);
    //printf("%d", matrix);
    
    //printf("%d", line);
    //printf("After printfs\n");
    // Copy pointer to the allocated line into its location in matrix pointer array
    matrix[r]=line;
    //printf("Copied row %d\n",r);
    //printf("%d %d %d\n", line[0], line[1], line[2]);
    printf("%d %d %d\n ",matrix[r][0], matrix[r][1], matrix[r][2]);
    printf("%p\n", line);
    //matrix[r]=line;
    if(matrix !=NULL)
      printf("%p", matrix[r]);
   
    //free(line);
  }
  // Check return value of isMagicSquare  
  if (isMagicSquare(matrix, 3) == 1)
         printf("Matrix is Magic\n");  
  //for(r=0;r< order; r++){
  //  for(c=0; c< order; c++){
  //    fscanf(fp, "%d", &tmp[c]);
  //    printf("%d\n", tmp[c]);
  //  }
    //int *matrix[r] = int *tmp[];

  //}
  

  //for(i=0; i< order; i++){
  //     printf("%d", tmp[i]);
 // }

  //if (order <=1)
  printf("Before Free\n");
  //free(row);
  //free(line);
  //free(tmp);
  // Release the memory allocated to each line
  for(r=0; r < order; r++){
    printf("Freeing %p\n", matrix[r]);
    free(matrix[r]);
  }
  // Release the memory allocated to the list of pointers
  free(matrix);
  return 0;

}
