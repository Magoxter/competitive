#include <stdio.h>

int f91(int n) {
    if (n > 100) return n - 10;

    return f91(f91(n + 11));
}

int main() {
    while (true) {
        // Reading input
        int N;
        scanf("%d", &N);

        if (N == 0) break;

        // Just print the implementation as defined in the problem
        // Note that if N <= 100, the result will always be 91 by the definition
        // of the function.
        printf("f91(%d) = %d\n", N, f91(N));
    }

    return 0;
}