#include <math.h>
#include <stdio.h>

int main(void) {
  float x, t, theta, y;
  float vo, ay;

  // Input values for x, t, and theta
  printf("Enter the distance x: ");
  scanf("%f", &x);

  printf("Enter the time t: ");
  scanf("%f", &t);

  printf("Enter the launch angle theta: ");
  scanf("%f", &theta);

  // Calculate the initial vertical velocity
  vo = x / (t * cos(theta));

  // Calculate the vertical acceleration
  ay = -9.8; // Assuming acceleration due to gravity is -9.8 m/s^2

  // Calculate the vertical displacement at point P
  y = vo * sin(theta) * t + 0.5 * ay * pow(t, 2);

  // Output the result
  printf("The vertical displacement at point P is: %f\n", y);
}
