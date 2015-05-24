#include <iostream>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int F1, F2;
        std::cin >> F1 >> F2;

        std::cout << gcd(F1, F2) << "\n";
    }

    return 0;
}