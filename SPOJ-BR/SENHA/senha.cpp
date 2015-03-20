#include <iostream>
#include <vector>
#include <array>
#include <map>

std::vector<int> getPassword(std::vector<std::array<int, 10>> comb, std::vector<std::array<char, 6>> seq) {
    std::vector<int> pass(6);

    // While we are still discovering the password
    std::map<int, int> passDigits[6];

    for (int i = 0; i < seq.size(); i++) {
        for (int j = 0; j < 6; j++) {
            int first, second;
            switch (seq[i][j]) {
                case 'A':
                    first = comb[i][0];
                    second = comb[i][1];

                    passDigits[j][first]++;
                    passDigits[j][second]++;
                    break;
                case 'B':
                    first = comb[i][2];
                    second = comb[i][3];

                    passDigits[j][first]++;
                    passDigits[j][second]++;
                    break;
                case 'C':
                    first = comb[i][4];
                    second = comb[i][5];

                    passDigits[j][first]++;
                    passDigits[j][second]++;
                    break;
                case 'D':
                    first = comb[i][6];
                    second = comb[i][7];

                    passDigits[j][first]++;
                    passDigits[j][second]++;
                    break;
                case 'E':
                    first = comb[i][8];
                    second = comb[i][9];

                    passDigits[j][first]++;
                    passDigits[j][second]++;
                    break;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        for (auto it = passDigits[i].begin(); it != passDigits[i].end(); it++) {
            if (it->second == seq.size()) {
                pass[i] = it->first;
            }
        } 
    }

    return pass;
}

int main() {
    int N;
    int test = 0;

    std::cin >> N;

    while (N != 0) {
        test++;

        // Associations between the letters and the numbers
        std::vector<std::array<int, 10>> comb(N);
        // The typed sequence
        std::vector<std::array<char, 6>> seq(N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 10; j++) std::cin >> comb[i][j];
            for (int j = 0; j < 6; j++) std::cin >> seq[i][j];
        }

        std::vector<int> pass = getPassword(comb, seq);
            
        std::cout << "Teste " << test << std::endl;
        for (int i = 0; i < 5; i++) std::cout << pass[i] << " ";
        std::cout << pass[5] << std::endl;

        std::cin >> N;
    }

    return 0;
}