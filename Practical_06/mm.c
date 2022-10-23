#include <stdio.h>
#include "mm.h"

// Passing by value
struct c_matrix matmult(const struct a_matrix am, const struct b_matrix bm, struct c_matrix cm)
{
  // For Loop Counter variables
  int i,j;
   
  int sum;
  int n,p,q;
  printf("Inside matmult\n");
  printf("A Matrix -\n");
  for (i=0; i<N; i++){
    for (j=0; j<P; j++){
      printf("%3d", am.values[i][j]);
    }
    printf("\n");
  }
  printf("----------\n\n");

  // Print B
  printf("B Matrix ----\n");
  for (i=0; i<P; i++){
    for (j=0; j<Q; j++){
      printf("%3d", bm.values[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
  
  // No of rows of first matrix N='5'
  // Easier to understand using the same variable names as the practical document
  for (n=0; n < N; n++){
    // No of Columns in second matrix Q='4'
    for (q=0; q < Q ; q++){
      // No of Rows in Second matrix P='3'
      // Only can work if columns in first and rows in second matrix are equal
      for (p=0; p < P; p++){
          sum = sum +  am.values[n][p] * bm.values[p][q];
      }
      // Take the result and store it in the correct location in 'C'
      cm.values[n][q] = sum;
      sum = 0;
    } 
  }
  
  // Return the struct as requested     
  return cm;
}
