#include <stdio.h>
#include "mm.h"

// Passing by value
struct c_matrix matmult(const struct a_matrix am, const struct b_matrix bm, struct c_matrix cm)
{
// Counter variables
  int i,j;
  
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
/*
   printf("C Matrix ----\n");
  for (i=0; i<N; i++){
    for (j=0; j<Q; j++){
      printf("%3d", cm.values[i][j]);
    }
    printf("\n");
  }
*/
  return cm;
}
