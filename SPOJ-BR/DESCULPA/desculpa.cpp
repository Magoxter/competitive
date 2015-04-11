#include <iostream>
#include <vector>

int knapSack(std::vector<int> weights, std::vector<int> values, int W) {
    int n = weights.size();    

    // The DP table
    int table[n+1][W+1];

    for (int i = 0; i <= W; i++) {
        table[0][i] = 0;
    }

    // Build the table, bottom-up
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (weights[i-1] <= j) {
                table[i][j] = std::max((table[i-1][j-weights[i-1]] + values[i-1]), table[i-1][j]);
            }
            else {
                table[i][j] = table[i-1][j];
            } 
        }
    }

    return table[n][W];
}

int main() {
    int S, F;
    int nTest = 1;

    std::cin >> S >> F;
    while (S != 0 && F != 0) {
        std::vector<int> weights(F), values(F);

        for (int i = 0; i < F; i++) {
            std::cin >> weights[i] >> values[i];
        }

        std::cout << "Teste " << nTest << std::endl;
        std::cout << knapSack(weights, values, S) << std::endl << std::endl;

        nTest++;
        std::cin >> S >> F;
    }

    
    return 0;
}