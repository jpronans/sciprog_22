#include <stdio.h>
#include "mm.h"

// N,P and Q defined in mm.h


// Function Prototype
struct c_matrix  matmult(const struct a_matrix, const struct b_matrix, struct c_matrix);


// Main
void main(void)
{

// Counter variables
int i,j;

// Declare Matrix structs
struct a_matrix am;
struct b_matrix bm;
struct c_matrix cm;
struct c_matrix ret_cm;

// Initialise A. A_ij = i+j
  for (i=0; i<N; i++){
    for (j=0; j<P; j++){
      am.values[i][j] = i + j;
    }
  }


// Initialise B. B_ij = i-j
  for (i=0; i<P; i++){
    for (j=0; j<Q; j++){
      bm.values[i][j] = i - j;
    }
  }

// Initialise C. All zeros.
  for (i=0; i<N; i++){
    for (j=0; j<Q; j++){
      cm.values[i][j] = 0;
    }
  }
  // Perform Multiplication
  ret_cm = matmult(am, bm, cm);

  printf("C Matrix ----\n");
  for (i=0; i<N; i++){
    for (j=0; j<Q; j++){
      printf("%3d", ret_cm.values[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");
}
