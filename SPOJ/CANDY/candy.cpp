#include <iostream>

int main() {
    int N;

    std::cin >> N;
    while (N != -1) {
        int cand[N];

        int sum = 0;
        for (int i = 0; i < N; i++) {
            std::cin >> cand[i];
            sum += cand[i];
        }

        // If we can't divide the candies equally, write -1
        // If we can, calculate the number of moves
        if ((sum % N) != 0) {
            std::cout << -1 << std::endl;
        } else {
            int mean = sum / N;
            int answer = 0;

            for (int i = 0; i < N; i ++) {
                if (mean > cand[i]) {
                    answer += (mean - cand[i]);
                }
            }

            std::cout << answer << std::endl;
        }

        std::cin >> N;
    }

    return 0;
}