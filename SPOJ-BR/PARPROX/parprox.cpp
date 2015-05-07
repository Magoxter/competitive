#include <stdio.h>
#include <math.h>
#include <vector>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2),  2));
}

int main() {
    int N;
    scanf("%d", &N);

    double min = 999999999999;
    std::vector<std::pair<int, int>> points(N); 

    for (int i = 0; i < N; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        points[i] = std::make_pair(x, y);
    }

    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            double dist = distance(points[i].first, points[i].second, points[j].first, points[j].second);
            if (dist < min) min = dist;
        }
    }

    printf("%.3lf\n", min);

    return 0;
}