#include <stdio.h>

void print_polynomials(int degree, float polynomial[])
{
  for(int i = 0; i <= (degree+1); ++i)
  {
    if(polynomial[i] == 0)
      continue;
    if((degree-i) == 0)
    {
      printf("%f", polynomial[i]);
      break;
    }
    if((degree-i) == 1)
      printf("%fx ", polynomial[i]);
    else
      printf("%fx^%d ", polynomial[i], degree);
  }
  printf("\n");

  return;
}

