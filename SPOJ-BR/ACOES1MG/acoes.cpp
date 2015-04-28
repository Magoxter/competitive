#include <stdio.h>
#include <math.h>

int solve(double N, double K) {
    // If we can already invest this much in a company
    if (N <= K) return 1;

    // If we cant, divide the amount
    return solve(floor(N/2), K) + solve(ceil(N/2), K);
}

int main() {
    int N, K;

    scanf("%d %d", &N, &K);
    while (N != 0) {
        printf("%d\n", solve(double(N), double(K)));
        scanf("%d %d", &N, &K);
    }

    return 0;
}