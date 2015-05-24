#include <iostream>

int main() {
    long long N;
    std::cin >> N;

    while (N >= 0) {
        long long answer = (N*N + N)/2 + 1;
        std::cout << answer << "\n";
        std::cin >> N;
    }

    return 0;
}