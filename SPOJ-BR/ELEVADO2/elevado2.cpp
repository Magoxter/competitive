#include <iostream>

int main() {
    // Reading input
    int N, C;
    std::cin >> N >> C;

    int flow[N][2];
    for (int i = 0; i < N; ++i) {
        std::cin >> flow[i][0] >> flow[i][1];
    }

    // Just add/remove people and see if it overflows the capacity
    int current = 0;
    char answer = 'N';

    for (int i = 0; i < N; ++i) {
        // How many people left
        current -= flow[i][0];

        // How many people entered
        current += flow[i][1];

        if (current > C) {
            answer = 'S';
            break;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}