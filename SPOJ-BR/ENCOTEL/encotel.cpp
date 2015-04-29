#include <iostream>
#include <map>

int main() {
    std::string s;
    
    // Map to map (yea, I know) a character to a number
    std::map<char, char> m;
    // Mapping
    m['0'] = '0';
    m['1'] = '1';
    m['-'] = '-';
    m['A'] = m['B'] = m['C'] = '2';
    m['D'] = m['E'] = m['F'] = '3';
    m['G'] = m['H'] = m['I'] = '4';
    m['J'] = m['K'] = m['L'] = '5';
    m['M'] = m['N'] = m['O'] = '6';
    m['P'] = m['Q'] = m['R'] = m['S'] = '7';
    m['T'] = m['U'] = m['V'] = '8';
    m['W'] = m['X'] = m['Y'] = m['Z'] = '9';
    
    while (std::cin >> s) {
        std::string number = "";
        for(int i = 0; i < s.size(); i++) number += m[s[i]];
        std::cout << number << "\n";
    }

    return 0;
}