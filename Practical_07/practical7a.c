#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#undef DEBUG

// Dynamically allocate the memory for an array of 'n' doubles
double *allocatearray(const int n){
  double *mydoubles;

  mydoubles = (double *)malloc(n * sizeof(double));


  // Check return value
  if (mydoubles == NULL){
    printf("Malloc Failed, exiting...\n");
    
    // exit on failure
    exit(1);
  }

  // return allocated memory space
  return mydoubles;
}


// fill the array of doubles with the result for each piece of the formula
void pre_calcs(double* mydoubles, int polynomials)
{

  double x=1.0;
  double fact=0.0;
 
  // factorial counter
  double j=0.0;
 
  int i=0;
 
  // Outer loop, work through each polynomial
  for(i=0; i<polynomials; i++){

    // First two cases are special 
    if (i == 0){
      mydoubles[0] = 1;
      continue;
    }
    if (i == 1){
      mydoubles[1] = x;
      continue;
    }

    // Set/Reset to 1 before starting the loop
    fact = 1.0;

    // Calculator factorial for i
    for (j=1; j<=i; j++){
      fact = fact * j;

#ifdef DEBUG
      printf("x= %lf, j=%lf , fact=%lf\n", x, j, fact);
#endif
      // Store the current polynomial value
      mydoubles[i] = pow(x,j) / fact;
    }

#ifdef DEBUG
    printf("\n");
    printf("%lf %d %lf", x, i, fact);
    printf("\n");
#endif
 }
}


// Main
int main(void)
{
  // Declare pointer to array of doubles (to be allocated later) 
  double* mydoubles=NULL;

  // Declare variable to hold the result
  double result = 0;
  
  // User filled variably to control number of iterations
  int polynomials; 

  // Interator variable
  int i=0;
 
  printf("Please enter the order of the polynomial requred\n"); 
  scanf("%d", &polynomials);

  // Allocate memory now we know how much
  mydoubles = allocatearray(polynomials);

  // Fill the array with calculated values
  pre_calcs(mydoubles, polynomials);
  
  // Work through the estimates, totalling as we go
  for(i=0;i<polynomials;i++){
    result = result + mydoubles[i];
    printf("f i = %d, result is %.10lf\n",i, result);
  }

  free(mydoubles);
  mydoubles = NULL;
  // Exit cleanly
  printf("Done!\n");
  return 0;
}
