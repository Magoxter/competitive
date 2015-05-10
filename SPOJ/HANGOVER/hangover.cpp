#include <stdio.h>
#include <vector>
#include <math.h>

int main() {
    double c;
    scanf("%lf", &c);

    while (c != 0) {
        int index = 0;
        double current = 0;
        while (current < c) {
            double k = index+2;
            double value = 1/k;

            current += value;
            index++;
        }

        printf("%d card(s)\n", index);
        scanf("%lf", &c);
    }

    return 0;
}