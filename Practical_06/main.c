#include <stdio.h>

// Define N,P and Q
#define N 5
#define P 3
#define Q 4


// A Matrix Definition
struct a_matrix {
  int values[N][P];
};

// B Matrix definition
struct b_matrix {
 int values[P][Q];
};
// C Matrix definition
struct c_matrix {
 int values[N][Q];
};

// Function Prototype
void matmult(void);


// Main
void main(void)
{

// Counter variables
int i,j;

// Declare Matrix structs
struct a_matrix am;
struct b_matrix bm;
struct c_matrix cm;

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



// Print A
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

  printf("C Matrix ----\n");
  for (i=0; i<N; i++){
    for (j=0; j<Q; j++){
      printf("%3d", cm.values[i][j]);
    }
    printf("\n");
  }
  printf("-------------\n");

}
