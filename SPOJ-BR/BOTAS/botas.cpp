#include <stdio.h>
#include <map>
#include <algorithm>

int main() {
    int N;

    while (scanf("%d\n", &N) > 0) {
        std::map<int, int> right;
        std::map<int, int> left;
        
        for (int i = 0; i < N; i++) {
            int size;
            char side;
            scanf("%d %c", &size, &side);

            if (side == 'D') right[size]++;
            else left[size]++;
        }

        int total = 0;
        for (auto it = right.begin(); it != right.end(); ++it) {
            total += std::min(right[it->first], left[it->first]);
        }

        printf("%d\n", total);
    }

    return 0;
}