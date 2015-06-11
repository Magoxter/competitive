#include <iostream>

int T[] = {1, 5, 10, 25, 50};
long long table[30001][5];

long long count(int n, int m) {
    if (m >= 5) return 0;
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (table[n][m] != -1) return table[n][m];

    table[n][m] = count(n, m+1) + count(n-T[m], m);
    return table[n][m];
}

int main() {
    int C;

    // Initialise DP table with -1
    for (int i = 0; i < 30001; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = -1;
        }
    }

    while (std::cin >> C) {
        long long answer = count(C, 0);
        if (answer > 1) std::cout << "There are " << answer << " ways to produce " << C << " cents change.\n";
        else std::cout << "There is only 1 way to produce " << C << " cents change.\n";
    }
}