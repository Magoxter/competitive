#include <iostream>

int main() {
    int V;
    int nTest = 1;

    std::cin >> V;
    while (V != 0) {
        int notes[4] = {0, 0, 0, 0};
        
        while (V > 0) {
            if (V >= 50) {
                notes[0]++;
                V -= 50;
                continue;
            } 
            else if (V >= 10) {
                notes[1]++;
                V -= 10;
                continue;
            }
            else if (V >= 5) {
                notes[2]++;
                V -= 5;
                continue;
            }
            else if (V >= 1) {
                notes[3]++;
                V -= 1;
                continue;
            }
        }

        std::cout << "Teste " << nTest << std::endl;
        for (int i = 0; i < 4; i++) std::cout << notes[i] << " ";
        std::cout << std::endl << std::endl;

        nTest++;

        std::cin >> V;
    }
    
    return 0;
}