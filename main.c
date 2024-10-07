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

  /* Divide the polynomials */
  int i_quotient = (i_dividend - i_divisor);
  int i_reminder = (i_dividend - i_divisor);

  float quotient_polynomial[i_quotient+1], reminder_polynomial[i_reminder+1];

  for(int k = 0; k <= i_quotient; ++k)
  {
    if(k == 0)
    {
      quotient_polynomial[k] = dividend_polynomial[0] / divisor_polynomial[0]; 
      printf("Quotient: %f\n", quotient_polynomial[k]);
      for(int l = 0; l <= i_reminder; ++l)
      {
        reminder_polynomial[l] = dividend_polynomial[l]-(quotient_polynomial[k]*divisor_polynomial[l]);
        printf("Reminder: %f\n", reminder_polynomial[l]);
      }
      for(int m = 0; m <= i_reminder; ++m)
      {
        if(m == i_reminder)
          reminder_polynomial[m] = dividend_polynomial[k+m];
        else
          reminder_polynomial[m] = reminder_polynomial[m+1];
      }
      printf("\n");
    }
    else
    {
      quotient_polynomial[k] = reminder_polynomial[0] / divisor_polynomial[0]; 
      printf("Quotient: %f\n", quotient_polynomial[k]);
      for(int l = 0; l <= i_reminder; ++l)
      {
        reminder_polynomial[l] = reminder_polynomial[l]-(quotient_polynomial[0]*divisor_polynomial[l]);
        printf("Divisor: %f\nQuotient: %f\n", divisor_polynomial[l], quotient_polynomial[k]);
        printf("Reminder: %f\n\n", reminder_polynomial[l]);
      }
      for(int m = 0; m <= i_reminder; ++m)
      {
        if(m == i_reminder)
          reminder_polynomial[m] = dividend_polynomial[k+m];
        else
          reminder_polynomial[m] = reminder_polynomial[m+1];
      }
      printf("\n"); 
    }
  }

  for(int j = 0; j <= (i_reminder+1); ++j)
  {
    if(reminder_polynomial[j] == 0)
      continue;
    if((i_reminder-j) == 0)
    {
      printf("%f", reminder_polynomial[j]);
      break;
    }
    if((i_reminder-j) == 1)
      printf("%fx ", reminder_polynomial[j]);
    else
      printf("%fx**%d ", reminder_polynomial[j], (i_reminder-j));
  }
  printf("\n");

  for(int j = 0; j <= (i_quotient+1); ++j)
  {
    if(quotient_polynomial[j] == 0)
      continue;
    if((i_quotient-j) == 0)
    {
      printf("%f", quotient_polynomial[j]);
      break;
    }
    if((i_quotient-j) == 1)
      printf("%fx ", quotient_polynomial[j]);
    else
      printf("%fx**%d ", quotient_polynomial[j], (i_quotient-j));
 }
  printf("\n");
}

