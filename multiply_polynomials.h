#include <stdlib.h>

typedef struct {
  int product_d;
  float* product_p;
} Polynomial_multiplication_result;

Polynomial_multiplication_result multiply_polynomials(
  int multiplier_d, int multiplicand_d,
  float multiplier_p[multiplier_d+1],
  float multiplicand_p[multiplicand_d+1])
{
  Polynomial_multiplication_result result;
  result.product_d = multiplier_d + multiplicand_d;

  float product[result.product_d+1];
  for(int i = 0; i < result.product_d; ++i)
    product[i] = 0;

  float distributive_matrix[multiplier_d+1][result.product_d+1];

  for (int i = 0; i <= multiplier_d; ++i)
  {
    for (int j = 0; j <= result.product_d; ++j)
      distributive_matrix[i][j] = 0.0;
  }

  for(int i = 0; i <= multiplier_d; ++i)
  {
    for(int j = 0; j <= multiplicand_d; ++j)
      distributive_matrix[i][i+j] = multiplier_p[i] * multiplicand_p[j];
  } 

  for(int m = 0; m <= (multiplier_d+multiplicand_d); ++m)
  {
    for(int n = 0; n <= multiplier_d; ++n)
      product[m] += distributive_matrix[n][m];
  }
 
  result.product_p = malloc((result.product_d+1) * sizeof(float));
  
  for(int l = 0; l <= result.product_d; ++l)
    result.product_p[l] = product[l];

  return result;
}

