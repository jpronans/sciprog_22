#include <stdio.h>
#include <math.h>


int main(void) {
  // Declare variables
  int int1, int2, i,n;
  float float1, float2;
  double a,b,area;
  
  // Test Values
  int1 = 33554430;
  int2 = 33554430;
  float1 = 33554430;
  float2 = 33554430;

  // No special formatting
  printf("Two ints %d, %d and two floats %f, %f\n", int1, int2, float1, float2);

  // Add formatting to float
  printf("Two ints %d, %d and two floats %.6f, %.6f\n", int1, int2, float1, float2);


  // Convert Degress to Radians multiply the value by pi/180
  // Convert Radians to Degrees multiply by 180/pi
  a = 0;
  b = (M_PI/3);
  n = 12;
  
  printf("Exercise 3\n");
  printf("a = %.6lf, b = %0.6lf, c = %d\n",a,b,n);

  // From class notes in announcement board
  // Start at 5 , stopping at 60 gives 11 hops or steps
  
  // Calculate Endpoints 
  double endpoints = tan(0) + tan(M_PI/3);
  printf("Endpoints in radians %.6lf\n",endpoints);
  
  // Calculate b-a/2N, all values in degrees 
  double ba2n = (b - a) / (2.0*n);    
  
  printf("ba2n in radians %.4lf\n",ba2n);   

  i=5;
  while(i<60)
  {
    // Get area under part of curve 
    area = area + 2 * tan((M_PI*i)/180.0);
    i = i + 5;
  }
  // add the endpoints
  //
  area = area + endpoints;
  
  // Multiply by b-a/2n
  area = area * ba2n;
  printf("area is %.6lf\nlog(2) is %.6lf\n-----\n",area,log(2));
  return 0;  
}
