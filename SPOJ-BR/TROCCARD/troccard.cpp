#include <set>
#include <iostream>
#include <algorithm>

int count(std::set<int> first, std::set<int> second) {
    std::set<int> inter;

    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), 
                          std::inserter(inter, inter.begin()));

    // The number of trades is equal to the smallest number of cards
    // minus the intersection.
    if (first.size() < second.size()) return first.size() - inter.size(); 
    else return second.size() - inter.size();
}

int main() {
    int A, B;

    std::cin >> A >> B;
    while (A != 0 && B != 0) {
        std::set<int> alice, beatriz;
        int tmp;

        for (int i = 0; i < A; i++) {
            std::cin >> tmp;
            alice.insert(tmp);
        }

        for (int i = 0; i < B; i++) {
            std::cin >> tmp;
            beatriz.insert(tmp);
        }

        std::cout << count(alice, beatriz) << std::endl;

        std::cin >> A >> B;
    }

    return 0;
}