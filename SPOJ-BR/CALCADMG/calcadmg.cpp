#include <iostream>
#include <stdlib.h>

long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);

    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        long long x1, y1;
        long long x2, y2;

        std::cin >> x1 >> y1 >> x2 >> y2;

        std::cout << gcd(abs(x1-x2), abs(y1-y2)) + 1 << "\n";
    }

    return 0;
}