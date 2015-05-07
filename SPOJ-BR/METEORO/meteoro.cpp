#include <stdio.h>
#include <vector>

int solve(std::vector<std::pair<int, int>> points, int x1, int y1, int x2, int y2) {
    int sum = 0;

    for (int i = 0; i < points.size(); i++) {
        int x = points[i].first;
        int y = points[i].second;

        if ((x >= x1) && (x <= x2) && (y >= y2) && (y <= y1)) sum++;
    }

    return sum;
}

int main() {
    int x1, y1, x2, y2;
    int nTest = 1;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    while (x1 != 0 && y1 != 0 && x2 != 0 && y2 != 0) {
        // Reading the points
        int N;
        scanf("%d", &N);

        std::vector<std::pair<int, int>> points(N);

        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
    
            points[i] = std::make_pair(x, y);
        }

        // Solving the problem
        printf("Teste %d\n%d\n\n", nTest, solve(points, x1, y1, x2, y2));

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        nTest++;
    }

    return 0;
}