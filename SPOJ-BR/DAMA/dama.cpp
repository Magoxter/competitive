#include <iostream>

int solve(int X1, int Y1, int X2, int Y2) {
    // Same position
    if (X1 == X2 && Y1 == Y2) return 0;
    
    // Same line
    if (X1 == X2) return 1;
    
    // Same column
    if (Y1 == Y2) return 1;
    
    // Same diagonals (we can do this 8 time without checking just because its easier)
    for (int i = 1; i <= 8; i++) { 
        if ((X2 == X1 + i) && (Y2 == Y1 + i)) return 1;     // Down right
        if ((X2 == X1 - i) && (Y2 == Y1 + i)) return 1;     // Up right
        if ((X2 == X1 - i) && (Y2 == Y1 - i)) return 1;     // Up left
        if ((X2 == X1 + i) && (Y2 == Y1 - i)) return 1;     // Down left
    }

    return 2;
}

int main() {
    int X1, Y1, X2, Y2;

    std::cin >> X1 >> Y1 >> X2 >> Y2;
    while (X1 != 0) {
        std::cout << solve(X1, Y1, X2, Y2) << "\n";
        std::cin >> X1 >> Y1 >> X2 >> Y2;
    }

    return 0;
}