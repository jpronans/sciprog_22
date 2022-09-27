#include <stdio.h>


int main(void) {
// Declare variables
  int int1, int2;
  float float1, float2;
  
// Test Value
  int1 = 33554430;
  int2 = 33554430;
  float1 = 33554430;
  float2 = 33554430;

// No special formatting
  printf("Two ints %d, %d and two floats %f, %f\n", int1, int2, float1, float2);

// Add formatting to float
 printf("Two ints %d, %d and two floats %.4f, %.4f\n", int1, int2, float1, float2);


}
