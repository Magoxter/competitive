#include <stdio.h>
#include <math.h>

double triangleArea(int a, int b, int c, double p) {
    return sqrt(p * (p-a)* (p-b) * (p-c));
}

double insideCircleArea(int a, int b, int c, double p, double area) {
    return M_PI*pow((area/p), 2);
}

double outsideCircleArea(int a, int b, int c, double p, double area) {
    return M_PI*pow(((a*b*c)/(4*area)), 2);
}

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        double p = double(a + b + c) / 2.0;     // Semi perimeter of the triangle, used in all formulas
        double area = triangleArea(a, b, c, p);

        double roses = insideCircleArea(a, b, c, p, area);
        double violets = area - roses;
        double sun = outsideCircleArea(a, b, c, p, area) - roses - violets;

        printf("%.4lf %.4lf %.4lf\n", sun, violets, roses);
    }

    return 0;
}