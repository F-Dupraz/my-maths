#include <stdio.h>
#include "print_polynomials.h"
#include "multiply_polynomials.h"
#include "divide_polynomials.h"

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

  printf("\033[H\033[J");

  /* Printing the polynomials */
  printf("Dividend: ");
  print_polynomials(i_dividend, dividend_polynomial);
  printf("Divisor: ");
  print_polynomials(i_divisor, divisor_polynomial);

  /* Divide the polynomials */
  Polynomial_division_result result;
  result = divide_polynomials(i_dividend, i_divisor, dividend_polynomial, divisor_polynomial);  

  printf("Quotient: ");
  print_polynomials(result.quotient_d, result.quotient_p);
  printf("Reminder: ");
  print_polynomials(result.reminder_d, result.reminder_p);

  Polynomial_multiplication_result product;
  product = multiply_polynomials(result.quotient_d, i_divisor, result.quotient_p, divisor_polynomial);

  printf("\nProduct: ");
  print_polynomials(product.product_d, product.product_p);
}

