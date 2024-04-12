#include <math.h>
#include <stdio.h>

#define PRINT_ERR printf("n/a")

double find_mass(double r, double p);

int main() {
  double r;
  if (scanf("%lf", &r) != 1 || r <= 0) {
    PRINT_ERR;
  } else {
    double p = 21500;
    double result = round(find_mass(r, p));
    printf("%.0lf", result);
  }

  return 0;
}

double find_mass(double r, double p) { return (4. / 3) * M_PI * pow(r, 3) * p; }
