#include <iostream>
#include <set>
#include <algorithm>
#include <limits.h>

int main() {
    int M, N;

    std::cin >> M;
    while (M != 0) {
        std::cin >> N;
        std::set<int> notes;
        
        for (int i = 0; i < N; i++) {
            int temp;
            std::cin >> temp;

            notes.insert(temp);
        }

        // Vector for the dynamic programming
        int nCoins = 0;

        int change[M+1];
        change[0] = 0;

        for (int i = 1; i <= M; i++) {
            nCoins = INT_MAX;

            // Check for all possible coins, which is the smallest number
            for (auto it = notes.begin(); it != notes.end(); it++) {
                if (*it <= i) nCoins = std::min(nCoins, change[i-(*it)]);
            }

            if (nCoins < INT_MAX) change[i] = nCoins + 1;
            else change[i] = INT_MAX;
        }

        if (change[M] < INT_MAX) std::cout << change[M] << std::endl;
        else std::cout << "Impossivel" << std::endl;

        std::cin >> M;
    }
    
    return 0;
}