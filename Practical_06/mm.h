#ifndef MYMM_H
#define MYMM_H

// Define N,P and Q
#define N 5
#define P 3
#define Q 4

//A Matrix Definition
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
//

#endif
