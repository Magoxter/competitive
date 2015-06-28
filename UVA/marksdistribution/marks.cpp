#include <iostream>
#include <string.h>

int table[71][71];

int F(int N, int T, int P) {
    if (table[N][T] != -1) return table[N][T];

    if (N == 0) {
        if (T == 0) table[N][T] = 1;
        else table[N][T] = 0;

        return table[N][T];
    }

    int total = 0;
    for (int i = P; i <= T; i++) {
        total += F(N-1, T-i, P);
    }

    table[N][T] = total;

    return table[N][T];
}

int main() {
    int K;
    std::cin >> K;

    for (int i = 0; i < K; i++) {
        memset(table, -1, sizeof(table));

        int N, T, P;
        std::cin >> N >> T >> P;


        std::cout << F(N, T, P) << '\n';
    }

    return 0;
}