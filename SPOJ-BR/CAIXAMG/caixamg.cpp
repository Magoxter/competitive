#include <stdio.h>
#include <math.h>

// Solving the equation 4x^3 - 2(a+b)x^2 + (ab)x
double volume(int a, int b, double x) {
    double first = 4*x*x*x;
    double second = -2*(a+b)*x*x;
    double third = (a*b)*x;
    return double(first + second + third);
}

// Its the max of the function above, so we calculate the roots of 
// its derivative 12x^2 - 4(a+b)x + ab
double solve(int a, int b) {
    int delta = pow(-4*(a+b), 2) - (48*a*b);

    double x1 = (4*(a+b) + sqrt(delta))/24;
    double x2 = (4*(a+b) - sqrt(delta))/24;

    if (volume(a, b, x1) > volume(a, b, x2)) return x1;
    else return x2;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    while (a != 0 && b != 0) {
        double x = solve(a, b);
        printf("%.4f %.4f\n", x, volume(a, b, x));
        scanf("%d %d", &a, &b);
    }

    return 0;
}