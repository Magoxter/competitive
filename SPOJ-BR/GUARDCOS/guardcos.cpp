#include <iostream>
#include <math.h>

int main() {
    int D, V1, V2;

    while (std::cin >> D >> V1 >> V2) {
        double h = sqrt(D*D + 144);
        
        double T1 = double(12) / V1;
        double T2 = h / V2;

        T1 >= T2 ? std::cout << "S\n" : std::cout << "N\n";
    }

    return 0;
}