#include <iostream>

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int n1, d1; // Numerator and denominator for the first number
        int n2, d2; // Numerator and denominator for the second number
        char op;    // Operation to be performed

        char div1, div2; // Just to read the division marks between the numbers

        // Reading the numbers
        std::cin >> n1 >> div1 >> d1 >> op >> n2 >> div2 >> d2;
 
        int na, da; // Numerator and denominator for the answer

        // Perform the operation
        if (op == '+') {
            da = d1 * d2;
            na = (da/d1)*n1 + (da/d2)*n2; 
        }
        else if (op == '-') {
            da = d1 * d2;
            na = (da/d1)*n1 - (da/d2)*n2;     
        }
        else if (op == '*') {
            da = d1 * d2;
            na = n1 * n2;
        }
        else if (op == '/') {
            da = d1 * n2;
            na = d2 * n1;
        }

        // Calculating the simplified answer
        int ratio = gcd(na, da);
        int nas = na / ratio;
        int das = da / ratio;


        std::cout << na << "/" << da << " = " << nas << "/" << das << "\n";
    }

    return 0;
}