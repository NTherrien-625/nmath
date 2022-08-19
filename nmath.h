#ifndef NMATH_H
#define NMATH_H

#define E 2.718281828459045
#define LN2 0.693147180559945
#define LN10 2.302585092994045
#define PI 3.141592653589793

// Trigonometric functions

// cos(x)
// Input : A real number, x
// Output : The cosine of x
double cos(double x);

// sin(x)
// Input : A real number, x
// Output : The sine of x
double sin(double x);

// tan(x)
// Input : A real number, x
// Ouput : The tangent of x
double tan(double x);

// acos(x)
// Input : A real number, x
// Output : The arc cosine (inverse cosine) of x
double acos(double x);

// asin(x)
// Input : A real number, x
// Output : The arc sine (inverse sine) of x
double asin(double x);

// atan(x)
// Input : A real number, x
// Output : The arc tangent (inverse tangent) of x
double atan(double x);

// atan2(x, y)
// Input : A real number, x
//         A real number, y
// Output : The arc tangent (inverse tangent) of y / x
double atan2(double x, double y);

// HYPERBOLIC FUNCTIONS

// cosh(x)
// Input : A real number, x
// Output : The hyperbolic cosine of x
double cosh(double x);

// sinh(x)
// Input : A real number, x
// Output : The hyperbolic sine of x
double sinh(double x);

// tanh(x)
// Input : A real number, x
// Output : The hyperbolic tangent of x
double tanh(double x);

// acosh(x)
// Input : A real number, x
// Output : The area hyperbolic cosine (inverse hyberbolic cosine) of x
double acosh(double x);

// asinh(x)
// Input : A real number, x
// Output : The area hyperbolic sine (inverse hyperbolic sine) of x
double asinh(double x);

// atanh(x)
// Input : A real number x
// Output : The area hyperbolic tangent (inverse hyperbolic tangent) of x
double atanh(double x);

// exp(x)
// Input : A real number x
// Output : The exponential of x (e^x)
double exp(double x);

// frexp(x, exp)
// Input : A real number, x
//         An integer pointer that points to the value of the exponent     
// Output : ?
double frexp(double x, int* exp);

// ldexp(x, exp)
// Input : A real number, x
//         An integer, exp
// Output : x * 2^exp
double ldexp(double x, int exp);

// log(x)
// Input : A real number, x
// Output : The natural logarithm of x
double log(double x);

// log10(x)
// Input : A real number, x
// Output : The common logarithm of x
double log10(double x);

// modf(x, intpart)
// Input : A real number, x
//         A pointer to an object that is that same type as x, intpart
// Output : The fractional portion of x is returned and the integer portion
//          is stored in intpart
double modf(double x, double* intpart);

// exp2(x)
// Input : A real number, x
// Output : 2 raised to the power of x
double exp2(double x);

// expm1(x)
// Input : A real number, x
// Output : The exponential of x, then subtract minus 1
double expm1(double x);

// ilogb(x)
// Input : A real number, x
// Output : The integer portion of log base 2 of the absolue value of x
int ilogb(double x);

// log1p(x)
// Input : A real number, x
// Output : The natural logarithm of one plus x
double log1p(double x);

// log2(x)
// Input : A real number, x
// Output : The log base 2 of x
double log2(double x);

// logb(x)
// Input : A real number, x
//         FLT_RADIX, the base of all floating types for a given platform
// Output : The log base FLT_RADIX of x
double logb(double x);

// scalbn(x, n)
// Input : A real number, x
//         An integer, n
//         FLT_RADIX, the base of all floating types for a given platform
// Output : x * FLT_RADIX^n
double scalbn(double x, int n);

// scalbln(x, n)
// Input : A real number, x
//         A long integer, x
//         FLT_RADIX, the base of all floating types for a given platform
// Output : x * FLT_RADIX^n
double scalbln(double x, long int n);

// POWER FUNCTIONS

// pow(base, exponent)
// Input : A real number, base
//         A real number, exponent
// Output : base ^ exponent
double pow(double base, double exponent);

// sqrt(x)
// Input : A real number, x
// Output : The square root of x
double sqrt(double x);

// cbrt(x)
// Input : A real number, x
// Ouput : The cube root of x
double cbrt(double x);

// hypot(x, y)
// Input : A real number, x
//         A real number, y
// Output : The hypotnuse of a triangle whose legs are x and y
double hypot(double x, double y);

// ERROR AND GAMMA FUNCTIONS

// erf(x)
// Input : A real number, x
// Output : The error function of x
double erf(double x);

// erfc(x)
// Input : A real number, x
// Output : The complementary error function of x
double erfc(double x);

// tgamma(x)
// Input : A real number, x
// Output : The gamma of x
double tgamma(double x);

// lgamma(x)
// Input : A real number, x
// Output : The logarithim of the absolute value of the gamma of x
double lgamma(double x);

// ROUDNING AND REMAINDER FUNCTIONS

// ceil(x)
// Input : A real number, x
// Output : Rounds up x to the nearest integer
double ceil(double x);

// floor(x)
// Input : A real number, x
// Output : Rounds down x to the nearest integer
double floor(double x);

// fmod(numer, denom)
// Input : A real number, numer
//         A real number, denom
// Output : The remainder of numer/denom
double fmod(double numer, double denom);

// trunc(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer towards 0
double trunc(double x);

// round(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer away from 0
double round(double x);

// lround(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer away from 0 and castes it as a
//          long int
long int lround(double x);

// llround(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer away from 0 and castes it as a
//          long long int
long long int llround(double x);

// rint(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer, direction specified by fegetround()
int rint(double x);

// lrint(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer, direction specified by fegetround()
//          and typecastes it to a long integer
long int lrint(double x);

// llrint(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer, direction specified by fegetround(),
//          and typecastes to to a long long integer
long long int llrint(double x);

// nearbyint(x)
// Input : A real number, x
// Output : Rounds x to the nearest integer, direction specified by fegetround()
double nearbyint(double x);



#endif
