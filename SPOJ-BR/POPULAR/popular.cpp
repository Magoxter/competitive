#include <iostream>
#include <map>

int main() {
    int N;

    std::cin >> N;
    while (N != 0) {
        // Declare and initialize the vote count.
        // Each index represents a student, the value represent how many votes he had.
        int votes[N];
        for (int i = 0; i < N; i++) votes[i] = 0;

        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int vote;
                std::cin >> vote;

                if (vote) votes[j]++;
            }
        }

        int max = 0;
        for (int i = 0; i < N; i++) {
            if (votes[i] > max) max = votes[i];
        }

        std::cout << max << std::endl;
        std::cin >> N;
    }
}