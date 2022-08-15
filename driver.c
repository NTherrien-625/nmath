#include <stdio.h>
#include "nmath.h"

void cos_functionality_test(void);

void sin_functionality_test(void);

void tan_functionality_test(void);

void cosh_functionality_test(void);

void exp_functionality_test(void);

void frexp_functionality_test(void);

void ldexp_functionality_test(void);

void log_functionality_test(void);

// Power Function Tests
void pow_functionality_test(void);
void sqrt_functionality_test(void);
void cbrt_functionality_test(void);
void hypot_functionality_test(void);

// Rounding and remainder tests
void ceil_functionality_test(void);
void floor_functionality_test(void);
void fmod_functionality_test(void);
void trunc_functionality_test(void);
void round_functionality_test(void);
void lround_functionality_test(void);
void llround_functionality_test(void);

int main() {
  sqrt_functionality_test();

  return 0;
}

void cos_functionality_test(void) {
  for (int i = -6; i < 7; ++i)
    fprintf(stdout, "cos(%i) = %f\n", i, cos(i));
}

void sin_functionality_test(void) {
  for (int i = -6; i < 7; ++i)
    fprintf(stdout, "sin(%i) = %f\n", i, sin(i));
}

void tan_functionality_test(void) {
  for (int i = -6; i < 7; ++i)
    fprintf(stdout, "tan(%i) = %f\n", i, tan(i));
}

void cosh_functionality_test(void) {
  for (int i = -10; i < 11; ++i)
    fprintf(stdout, "cosh(%i) = %f\n", i, cosh(i));
}

void exp_functionality_test(void) {
  for (int i = 0; i < 10; ++i)
    fprintf(stdout, "e^%i = %f\n", i, exp(i));
}

void frexp_functionality_test(void) {
  int n;
  double result;
  for (int i = -10; i < 11; ++i) {
    if (i != 0) {
      result = frexp(i, &n);
      fprintf(stdout, "%d = %f * 2^%d\n", i, result, n);
    }
  }
}

void ldexp_functionality_test(void) {
  double result = ldexp(3, 3);
  fprintf(stdout, "%d = %d * 2^%d\n", result, 3, 3);
}

void log_functionality_test(void) {
  for (int i = 0; i < 10; ++i)
    fprintf(stdout, "ln(%i) = %f\n\n", i, log(i));
}

void pow_functionality_test(void) {
  for (int i = 0; i < 10; ++i)
    fprintf(stdout, "2^%i = %f\n", i, pow(2, i));
  for (int i = 0; i < 10; ++i)
    fprintf(stdout, "2^%f = %f\n", i + 0.25, pow(2, i + 0.25));
}

void sqrt_functionality_test(void) {
  for (int i = 0; i < 10; ++i)
    fprintf(stdout, "sqrt(%i) is close to %f\n", i, sqrt(i));
}

void cbrt_functionality_test(void) {
  for (int i = -9; i < 10; ++i)
    fprintf(stdout, "cbrt(%i) is close to %f\n", i, cbrt(i));
}

void hypot_functionality_test(void) {
  fprintf(stdout, "3, 4, %f\n", hypot(3, 4));
  fprintf(stdout, "5, 12, %f\n", hypot(5, 12));
  fprintf(stdout, "7, 24, %f\n", hypot(7, 24));
}

void ceil_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "ceil(%f) = %f\n", 10 + i, ceil(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "ceil(%f) = %f\n", -10 + i, ceil(-10 + i));
}

void floor_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "floor(%f) = %f\n", 10 + i, floor(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "floor(%f) = %f\n", -10 + i, floor(-10 + i));
}

void fmod_functionality_test(void) {
  fprintf(stdout, "%f mod %d = %f\n", 5.3, 2, fmod(5.3, 2));
  fprintf(stdout, "%f mod %f = %f\n", 18.5, 4.2, fmod(18.5, 4.2));
}

void trunc_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "trunc(%f) = %f\n", 10 + i, trunc(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "trunc(%f) = %f\n", -10 + i, trunc(-10 + i));
}

void round_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "round(%f) = %f\n", 10 + i, round(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "round(%f) = %f\n", -10 + i, round(-10 + i));
}

void lround_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "lround(%f) = %i\n", 10 + i, lround(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "lround(%f) = %i\n", -10 + i, lround(-10 + i));
}

void llround_functionality_test(void) {
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "llround(%f) = %i\n", 10 + i, llround(10 + i));
  for (double i = 0; i < 1; i += 0.1)
    fprintf(stdout, "llround(%f) = %i\n", -10 + i, llround(-10 + i));
}