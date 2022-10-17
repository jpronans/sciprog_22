#include <stdio.h>
#include <math.h>

#define SPACING 12 
//#define a 0
//#define b 60
float result[SPACING];

/* 
 * Convert Degress to Radians multiply the value by pi/180
 * Convert Radians to Degrees multiply by 180/pi
 *
 */
float convert(const float deg)
{
	return M_PI * deg/180;
}
/*
 * Original, before reading exercise requirement to have one argument 
 * float trapezoid(float a, float b,int spacing, float array[12]){
 */
float trapezoid(const int spacing)
{
  const float a=convert(0);
  const float b=convert(60);
 
  float sum = result[0] + result[12]; // array[0] + array[12];
  int i;
  for ( i=1; i < spacing; i++)
    {
    
    sum = sum + 2 * result[i]; // array[i];
    }
    return (b-a)*sum/(2*spacing);
}

int main(void) {
  // Declare variables
  int i;
  const float a = 0;
  const float b = 60;
  const int spacing = SPACING; 
  const float step_size = (b-a)/spacing;

  double area;
  
  printf("-----\nPractical 4\n");

  for(i=0; i<=spacing; i++)
  {
     result[i]	= tan((convert(step_size*i)));
     printf("Result [%d]: %.6f\n", i, result[i]);
  }
  /*
   * Original, before reading exercise requirement to have one argument 
   * area = trapezoid(convert(a),convert(b),spacing,result);
   */
  area = trapezoid(spacing);
  
  printf("Approximate area is %.6f\n", area); 
  
  // No problems, exit cleanly
  return 0; 
}
