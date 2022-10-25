#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 1000

// Approximation to the Maclaurin series
double arctanh1(const double x, const double delta);

// Approximitation to natural logarithms
double arctanh2(const double x);

int main(void) {
 

  double delta, x;
  printf("Enter the precision for the Maclaurin series\n");
  scanf("%lf", &delta);
 
  //int len = LENGTH;
  
  double tan1[LENGTH]; // Storage for the reults of arctanh1
  double tan2[LENGTH]; // Storage for the reults of arctanh2

  int j =0; // array index
  
  x = -0.9;
  while (x <= 0.9 && j < LENGTH){
    tan1[j]=arctanh1(x,delta);
    tan2[j]=arctanh2(x);
    printf("the difference at x:%lf is %.10lf\n",x, fabs(tan1[j]-tan2[j]));
    j++;
    x=x+0.1; // try with 0.01 later
  } 
 
  // Exit cleanly 
  return 0;
}

// Need to review this again later to fully understand it.
double arctanh1(const double x, const double delta){
  double arctan = 0; // Approximate result
  double elem, val;
  int n = 0; // sum parameter
  do{
    val = 2 * n + 1;  // Pre-calc
    elem=pow(x,val)/val;
    arctan = arctan + elem;
    n++;
  } while (fabs(elem) >= delta); 

  return arctan;
}

double arctanh2(const double x)
{
 return ((log(1+x)-log(1-x))/2);
}