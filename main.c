#include <stdio.h>
#include "print_polynomials.h"

int main()
{
  /* Setting the degree of the divisor and dividend polynomials */
  int i_dividend, i_divisor;
  
  printf("Enter the degree of the dividend: ");
  scanf("%d", &i_dividend);
  printf("Enter the degree of the divisor: ");
  scanf("%d", &i_divisor);

  printf("Degrees: %d and %d\n", i_dividend, i_divisor);

  /* Setting the coefficients of the polynomials */
  float  dividend_polynomial[i_dividend+1], divisor_polynomial[i_divisor+1], idk;
  
  printf("Enter the coeficients of the dividend one at a time: \n"
  "If you have (for example) X**4 - X + 12, enter:\n1\n0\n0\n-1\n12\n\n");
  for(int i = 0; i <= i_dividend; ++i)
  {
    scanf("%f", &idk);
    dividend_polynomial[i] = idk;
  }    
  
  printf("Enter the coeficients of the divisor one at a time: \n"
  "If you have (for example) X**2 - 5, enter:\n1\n0\n-5\n\n");
  for(int i = 0; i <= i_divisor; ++i)
  {
    scanf("%f", &idk);
    divisor_polynomial[i] = idk;
  } 

  /* Printing the polynomials */
  printf("Dividend: ");
  print_polynomials(i_dividend, dividend_polynomial);
  printf("Divisor: ");
  print_polynomials(i_divisor, divisor_polynomial);

  /* Divide the polynomials */
  int i_quotient = (i_dividend - i_divisor);
  int i_reminder = (i_dividend - i_divisor);

  float quotient_polynomial[i_quotient+1], reminder_polynomial[i_reminder+1];

  for(int k = 0; k <= i_quotient; ++k)
  {
    if(k == 0)
    {
      quotient_polynomial[k] = dividend_polynomial[0] / divisor_polynomial[0];
      for(int l = 0; l <= i_reminder; ++l)
      {
        reminder_polynomial[l] = dividend_polynomial[l]-(quotient_polynomial[k]*divisor_polynomial[l]);
      }
      for(int m = 0; m <= i_reminder; ++m)
      {
        if(m == i_reminder)
          reminder_polynomial[m] = dividend_polynomial[k+m+1];
        else
          reminder_polynomial[m] = reminder_polynomial[m+1];
      }
    }
    else
    {
      quotient_polynomial[k] = reminder_polynomial[0] / divisor_polynomial[0];
      for(int l = 0; l <= i_reminder; ++l)
      {
        reminder_polynomial[l] = reminder_polynomial[l]-(quotient_polynomial[k]*divisor_polynomial[l]);
      }
      for(int m = 0; m <= i_reminder; ++m)
      {
        if(m == i_reminder)
          reminder_polynomial[m] = dividend_polynomial[k+m+1];
        else
          reminder_polynomial[m] = reminder_polynomial[m+1];
      } 
    }
  }

  printf("Quotient: ");
  print_polynomials(i_quotient, quotient_polynomial);
  printf("Reminder: ");
  print_polynomials(i_reminder, reminder_polynomial);
}

