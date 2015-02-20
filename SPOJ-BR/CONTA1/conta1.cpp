#include <iostream>

int main() {
    // Reading the number
    int n;
    std::cin >> n;

    // To solve the problems, simply go through all of the ranges and calculate 
    // how much they have to pay in each
    int total = 0;
    int dif;

    switch (n) {
        // 1000 is the maximum consumption specified by the problem
        case 101 ... 1000:
            // How much he consumed in this range
            dif = n - 100;
            // How much he has to pay for this consumption
            total += dif * 5;
            // How much is left for the next range
            n -= dif;

        case 31 ... 100:
            dif = n - 30;
            total += dif * 2;
            n -= dif;

        case 11 ... 30:
            dif = n - 10;
            total += dif;
            n -= dif;

        default:
            total += 7;
    }

    std:: cout << total << std::endl;

    return 0;
}