#include <math.h>
#include <iostream>

long long int solve(std::string word) {
    long long int sum = 0;
    
    for (int i = 1; i <= word.size(); i++) {
        if (word[i-1] == 'b') sum += pow(2, (word.size() - i));
    }

    return sum;
}

int main() {
    std::string word;  // Max of 60 letters plus the null character
    int nTest = 1;      // Number of tests so far

    while (std::cin >> word) {
        std::cout << "Palavra " << nTest << std::endl;
        std::cout << solve(word) << std::endl << std::endl;
        nTest++;
    }

    return 0;
}