#include <stdio.h>

void print_polynomials(int degree, float polynomial[degree+1])
{
  for(int i = 0; i <= (degree+1); ++i)
  {
    if(polynomial[i] == 0)
      continue;
    if((degree-i) == 0)
    {
      printf("%.2f", polynomial[i]);
      break;
    }
    if((degree-i) == 1)
      printf("%.2fx ", polynomial[i]);
    else
      printf("%.2fx^%d ", polynomial[i], degree);
  }
  printf("\n");

  return;
}

