#include <stdio.h>

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
  
  printf("Enter the coeficients of the dividend: \n"
  "If you have (for example) X**4 - X + 12, enter: 1 0 0 -1 12.\n");
  for(int i = 0; i <= i_dividend; ++i)
  {
    scanf("%f", &idk);
    dividend_polynomial[i] = idk;
  }    
  
  printf("Enter the coeficients of the divisor: \n"
  "If you have (for example) X**2 - 5, enter: 1 0 -5.\n");
  for(int i = 0; i <= i_divisor; ++i)
  {
    scanf("%f", &idk);
    divisor_polynomial[i] = idk;
  } 

  /* Printing the polynomials */
  for(int j = 0; j <= (i_dividend+1); ++j)
  {
    if(dividend_polynomial[j] == 0)
      continue;
    if((i_dividend-j) == 0)
    {
      printf("%f", dividend_polynomial[j]);
      break;
    }
    if((i_dividend-j) == 1)
      printf("%fx ", divisor_polynomial[j]);
    else
      printf("%fx**%d ", dividend_polynomial[j], (i_dividend-j));
  }
  printf("\n");

  for(int j = 0; j <= (i_divisor+1); ++j)
  {
    if(divisor_polynomial[j] == 0)
      continue;
    if((i_divisor-j) == 0)
    {
      printf("%f", divisor_polynomial[j]);
      break;
    }
    if((i_divisor-j) == 1)
      printf("%fx ", divisor_polynomial[j]);
    else
      printf("%fx**%d ", divisor_polynomial[j], (i_divisor-j));
 }
  printf("\n");
}

