#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/* To solve this, we use a greedy algorithm. This greedy algorithm gives the optimal solution.
 * First, sort all the apointments by finish time, and then, just pick all the apointments that
 * are valid, in order.
 */

int main() {
    int N;
    std::vector<std::pair<int, int>> consults;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;

        consults.push_back(std::make_pair(a, b));
    }

    // Sorting by the end of appointment time
    std::sort(consults.begin(), consults.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
                                                    return left.second < right.second;
                                                   });

    int lastEnd = 0;
    int nCon = 0;
    while (consults.size() > 0) {
        if (consults.front().first >= lastEnd) {
            lastEnd = consults.begin()->second;
            nCon++;
        }
        consults.erase(consults.begin()); 
    }

    std::cout << nCon << std::endl;

    return 0;
}