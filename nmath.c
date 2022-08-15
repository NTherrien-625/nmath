#include <stdio.h>
#include "nmath.h"

// Trigonometric Functions
double cos(double x) {
  double sum = 0;

  for (int i = 0; i < 10; ++i) 
    sum += pow(-1, i) * (pow(x, 2*i) / tgamma(2*i));

  return sum;
}

double sin(double x) {
  double sum = 0;

  for (int i = 0; i < 10; ++i)
    sum += pow(-1, i) * (pow(x, (2*i) + 1) / tgamma((2*i) + 1));

  return sum;
}

double tan(double x) { return (sin(x) / cos(x)); }

// Hyperbolic Functions
double cosh(double x) { return ((exp(x) + exp(-x)) / 2); }

double sinh(double x) { return ((exp(x) - exp(-x)) / 2); }

double tanh(double x) { return (sinh(x) / cosh(x)); }

// Exponentiation Functions
double exp(double x) {
  int center = (int) x;
  x -= center;

  double rolling_numerator = 1;
  double rolling_denominator = 1;
  double sum = 0;

  for (int i = 0; i < 10; ++i) {
    sum += (rolling_numerator / rolling_denominator);
    rolling_numerator *= x;
    rolling_denominator *= (i + 1);
  }

  return pow(E, center) * sum;
}

double frexp(double x, int* exp) {
  int div_counter = 0;
  int is_negative = 0;

  if (x == 0) {
    *exp = div_counter;
    return x;
  }

  if (x < 0) {
    is_negative = 1;
    x *= -1;
  }

  if (x >= 1) {
    while (x >= 1) {
      div_counter += 1;
      x /= 2;
    }
    *exp = div_counter;
  }

  if (x < 0.5) {
    while (x < 0.5) {
      div_counter -= 1;
      x *= 2;
    }
    *exp = div_counter;
  }

  if (is_negative == 1)
    x *= -1;

  return x;
}

double ldexp(double x, int exp) {
  fprintf(stdout, "ldexp called from nmath\n");
  fprintf(stdout, "x = %d, exp = %i\n", x, exp);
  return (x * pow(2, exp));
}

double log(double x) {
  if (x <= 0) {
    fprintf(stdout, "Breach of domain, ln(x) does not exist when x <= 0\n");
    return 0;
  }

  double sum = 0;
  
  while (x > 1) {
    x /= 2;
    sum += LN2;
  }

  x -= 1;

  double rolling_numerator = x;
  double rolling_denominator = 1;
  int is_negative = 0;

  for (int i = 0; i < 10; ++i) {
    if (is_negative == 0) {
      sum += (rolling_numerator / rolling_denominator);
      is_negative = 1;
    }
    else {
      sum -= (rolling_numerator / rolling_denominator);
      is_negative = 0;
    }
    rolling_numerator *= x;
    rolling_denominator += 1;
  }

  return sum;
}

double pow(double base, double exponent) {
  double integral_power = (int) exponent;
  double floating_power = exponent - integral_power;
  double integral_component, floating_component;

  // Integral part
  integral_component = 1;
  for (int i = 0; i < integral_power; ++i)
    integral_component *= base;

  if (floating_power == 0)
    return integral_component;

  // Floating part
  floating_component = exp(floating_power * log(base));

  return integral_component * floating_component;
}

double sqrt(double x) {
  // Get to the closest integer
  int counter = 0;
  int product = counter * counter;
  while (x >= product) {
    counter += 1;
    product = counter * counter;
  }
  counter -= 1;
  for (int i = 0; i < 10; ++i) {
   x = 0.5 * (x + (counter / x));
  }
  return x;
}

double cbrt(double x) {
  // Get to the closest integer
  int is_negative = 0;
  int counter = 0;
  int product = counter * counter * counter;
  if (x < 0) {
    x *= -1;
    is_negative = 1;
  }
  while (x >= product) {
    counter += 1;
    product = counter * counter * counter;
  }
  if (is_negative == 1)
    return (-1 * (counter - 1));
  return (counter - 1);
}

double hypot(double x, double y) {
  return sqrt(x*x + y*y);
}

// Error and Gamma Functions
double tgamma(double x) {
  double rolling_product = 1;
  for (int i = 2; i <= x; ++i)
    rolling_product *= i;
  return rolling_product;
}

// Rounding and Remainder functions
double ceil(double x) {
  if (x > 0) {
    if ((x - (int) x) != 0)
      return (double) ((int) x + 1);
  }
  if ((x - (int) x) != 0)
    return (double) ((int) x);
  return x;
}

double floor(double x) {
  if (x > 0) {
    if ((x - (int) x) != 0)
      return (double) ((int) x);
  }
  if ((x - (int) x) != 0)
    return (double) ((int) x - 1);
  return x;
}

double fmod(double numer, double denom) {
  while (numer > denom)
    numer -= denom;
  return numer;
}

double trunc(double x) {
  return (double) ((int) x);
}

double round(double x) {
  if (x < 0) {
    if ((x - (int) x) <= -0.5)
      return (double) ((int) x - 1);
  }

  if ((x - (int) x) >= 0.5)
    return (double) ((int) x + 1);
  return x;
}

long int lround(double x) {
  if (x < 0) {
    if ((x - (int) x) <= -0.5)
      return (long int) ((int) x - 1);
  }

  if ((x - (int) x) >= 0.5)
    return (long int) ((int) x + 1);
  return x;
}

long long int llround(double x) {
  if (x < 0) {
    if ((x - (int) x) <= -0.5)
      return (long long int) ((int) x - 1);
  }

  if ((x - (int) x) >= 0.5)
    return (long long int) ((int) x + 1);
  return x;
}