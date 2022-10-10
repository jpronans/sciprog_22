#include <stdio.h>
#include <math.h>

// Used to get the approx first and last values
float y(float x)
{
	// f(x) = 1/(1+x*x)
	//return tan(x);
	return 1/(1+x*x);
}

float trapezodial(float a, float b, float n)
{
	int i=0;
	// Figure out spacing
	float h = (b-a)/n;

	// Compute first and last terms
	float s = y(a)+y(b);
	
	// Fill in the rest
	for (i = 1; i < n; i++)
	{
		s=s+2*y(a+i*h);
	}
	
	// h/2 is (b-a)/2n multiplied then by s
	return (h/2)*s;
}
double f(double x)
{
	return pow(x,2);
	//return x*x;
}

void main(void) {
  // Declare variables
  int int1, int2, i;
  float float1, float2, spacing;
  double sum;
  double area;
  
  // Test Values
  int1 = 33554430;
  int2 = 33554430;
  float1 = 33554430;
  float2 = 33554430;

  // No special formatting
  printf("Two ints %d, %d and two floats %f, %f\n", int1, int2, float1, float2);

  // Add formatting to float
  printf("Two ints %d, %d and two floats %.4f, %.4f\n", int1, int2, float1, float2);

  // Testing trapezodial code
  float x0=0;
  float xn=1;
  int n = 6;
  printf("-----\nExercise 3a\n");
  printf("Result of integral = %6.6f\n-----\n",trapezodial(x0,xn,n));
  
  sum = 0.0;
  i = 0;

  // Convert Degress to Radians multiply the value by pi/180
  // Convert Radians to Degrees multiply by 180/pi
  double a = 0;
  double b = (M_PI/3) * (180/M_PI);
  n = 12;
  
  printf("Exercise 3\n");
  printf("a = %.4lf, b = %0.4lf, c = %d\n",a,b,n);

  // From class notes in announcement board
  // Start at 5 , stopping at 60 gives 11 hops or steps
  
  // Calculate Endpoints and convert to degrees
  double endpoints = tan(0) + tan(M_PI/3);
  printf("Endpoints in radians %.4f\n",endpoints);
  
  // Calculate b-a/2N, all values in degrees 
  double ba2n = (b - a) / (2.0*n);    
  
  printf("ba2n in degrees %.4lf\n",ba2n);   

  

  i=5;
  while(i<60)
  {
    // Convert to Radians before feeding to tan() function
    area = area + tan((M_PI*i)/180);
    //area = area + 2 * tan((M_PI*i)/180.0);
    i = i + 5;
  }
  // add the endpoints
  //
  area = area + endpoints;
  
  // Multiply by b-a/2n
  area = area * ba2n;
  printf("area is %.4lf\nlog(2) is %.4f\n-----\n",area,log(2));
  
}
