#include <iostream>

void processString(std::string s, int *a) {
    a[0] = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) a[i] = a[i-1];
        else a[i] = a[i-1] + 1;
    }
}

int main() {
    std::string s;
    int test = 0;

    while (std::cin >> s) {
        test++;
        std::cout << "Case " << test << ":\n";

        int a[s.size()];
        processString(s, a);

        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int first, second;
            std::cin >> first >> second;

            if (a[first] == a[second]) std::cout << "Yes\n";
            else std::cout << "No\n";
        }
    }

    return 0;
}