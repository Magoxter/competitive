#include <iostream>
#include <map>
#include <ctype.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::map<char, int> m;

    for (int i = 0; i <= N; i++) {
        std::string line;
        std::getline(std::cin, line);

        for (int i = 0; i < line.size(); i++) {
            if (isalpha(line[i])) m[toupper(line[i])]++;
        }
    }

    std::vector<std::pair<int, char>> v;

    for (auto it = m.begin(); it != m.end(); ++it) {
        v.push_back(std::make_pair(it->second, it->first));
    }

    std::sort(v.begin(), v.end(), [](const std::pair<int, char> &left, const std::pair<int, char> &right) {
                if (left.first == right.first) return left.second > right.second;
                else return left.first < right.first;
            });

    for(int i = v.size()-1; i >= 0; i--) {
        std::cout << v[i].second << " " << v[i].first << "\n";
    }

    return 0;
}