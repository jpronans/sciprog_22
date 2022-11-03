#include <stdio.h>

// Declare GCD Function
int gcd (int a, int b);

// Find the Greatest Common Divisor of a pair of Integers using recursion
// Think I get it now, smaller/bigger gives bigger as remainder, so it just swaps 
// a and b and continues on.
int main(void)
{
  // Two numbers
  int a, b;
  
  printf("Please enter 'A'\n");
  scanf("%d", &a);
  if (a < 1){
    printf("Non zero please, try again\n");
    return 0;
  }

  printf("Please enter 'B'\n");
  scanf("%d", &b);
  if (b < 1){
    printf("Non zero please, try again\n");
    return 0;
  }
  
  printf("GCD is %d\n", gcd(a,b)); 

  // Exit cleanly
  printf("Done!\n");
  return 0;
}

// Slightly more headwrecking, but keep going until we hit zero, then unroll 
int gcd (int a, int b) {
  if (b != 0 ){
    return gcd(b, a % b);
  }
  else {
    return a;
  }
}
