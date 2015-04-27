#include <iostream>

int main() {
    int T, N;

    std::cin >> T >> N;
    while (T != 0) {
        int total = 0;

        for (int i = 0; i < T; i++) {
            std::string team;
            int points;
            std::cin >> team >> points;

            total += points;
        }

        // Answer will be the max points we can get minux the total we have now
        int answer = 3*N - total;
        std::cout << answer << "\n";

        std::cin >> T >> N;
    }

    return 0;
}