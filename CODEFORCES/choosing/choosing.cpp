#include <iostream>
#include <map>

int main() {
    std::string str;
    std::cin >> str;

    std::map<char, long long int> m;

    for (int i = 0; i < str.size(); i++) {
        m[str[i]]++;
    }

    long long int sum = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        sum += it->second * it->second; 
    }

    std::cout << sum << "\n";

    return 0;
}