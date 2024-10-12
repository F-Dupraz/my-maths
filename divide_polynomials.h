#include <stdlib.h>

typedef struct {
  int quotient_d;
  int reminder_d;
  float* quotient_p;
  float* reminder_p;
} Polynomial_division_result;

Polynomial_division_result divide_polynomials(
  int dividend_d, int divisor_d,
  float dividend_p[dividend_d+1], float divisor_p[divisor_d+1])
{
  int quotient_d = (dividend_d - divisor_d);
  int reminder_d = (dividend_d - divisor_d);

  float quotient_p[quotient_d+1], reminder_p[reminder_d+1];

  for(int i = 0; i <= quotient_d; ++i)
  {
    if(i == 0)
    {
      quotient_p[i] = dividend_p[0] / divisor_p[0];
      for(int j = 0; j <= reminder_d; ++j)
        reminder_p[j] = dividend_p[j] - (quotient_p[i] * divisor_p[j]);
      
      for(int k = 0; k <= reminder_d; ++k)
      {
        if(k == reminder_d)
          reminder_p[k] = dividend_p[i+k+1];
        else
          reminder_p[k] = reminder_p[k+1];
      }
    }
    else
    {
      quotient_p[i] = reminder_p[0] / divisor_p[0];
      for(int j = 0; j <= reminder_d; ++j)
        reminder_p[j] = reminder_p[j] - (quotient_p[i] * divisor_p[j]);
    
      for(int k = 0; k <= reminder_d; ++k)
      {
        if(k == reminder_d)
          reminder_p[k] = dividend_p[i+k+1];
        else
          reminder_p[k] = reminder_p[k+1];
      }
    }
  }

  Polynomial_division_result result;
  result.quotient_d = quotient_d;
  result.reminder_d = reminder_d;
  result.quotient_p = malloc((result.quotient_d + 1) * sizeof(float));
  result.reminder_p = malloc((result.reminder_d + 1) * sizeof(float));
  for(int m = 0; m <= result.quotient_d; ++m)
    result.quotient_p[m] = quotient_p[m];
  for(int n = 0; n <= result.reminder_d; ++n)
    result.reminder_p[n] = reminder_p[n];

  return result;
}

