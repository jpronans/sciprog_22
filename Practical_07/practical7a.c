/*
 * Find e, this is apparently the taylor series
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#undef DEBUG


// Example of recursive function from Tuesday Class
int cs_factorial(int n){
  printf("n is %d\n",n);
  if (n == 0){
    return 1;
  }
  else if(n > 1){
    return (n * cs_factorial(n-1));
  }
  else
    return (-1);
}

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
void pre_calcs(double* mydoubles, const int polynomials)
{

  double x=1.0;
  // I didn't notice that 'fact' went negative as I went with Double instead of an Int.
  // Changing to int gives
  // f i = 13, result is 2.71828182782051 with a difference of -0.00000000063854
  // f i = 14, result is 2.71828182735485 with a difference of -0.00000000110420
  double fact=0.0;
 
  // factorial counter
  double j=0.0;
 
  int i=0;

  for(i=0; i<polynomials; i++){

    // Set/Reset to 1 before starting the loop
    fact = 1.0;

    // Calculate factorial for i
    for (j=1; j<=i; j++){
      fact = fact * j;

#ifdef DEBUG
      printf("x= %lf, j=%lf , fact=%lf\n", x, j, fact);
#endif
      // Store the current polynomial value
      mydoubles[i] = pow(x,j) / fact;
    }
    //printf("Recursive factorial for %d is %d\n", polynomials, cs_factorial(polynomials));

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
  
  // User filled variable to control number of iterations
  int polynomials; 

  // Interator variable
  int i=0;
 
  printf("Please enter the order of the polynomial requred\n"); 
  scanf("%d", &polynomials);

  // Allocate memory now we know how much
  mydoubles = allocatearray(polynomials);

  // Fill the array with calculated values
  pre_calcs(mydoubles, polynomials);
  
  // Hadn't thought of doing it this way until Buket pointed it out in the practical. Add the 1 at the end.
  result = 1.0; 

  // Work through the estimates, totalling as we go
  for(i=0;i<polynomials;i++){
    result = result + mydoubles[i];
    printf("f i = %d, result is %.14lf with a difference of %.14lf\n",i, result, result-exp(1.0));
  }
  // Free allocated RAM
  free(mydoubles);

  // defensively set to NULL
  mydoubles = NULL;
  // Exit cleanly
  printf("Done!\n");
  return 0;
}
