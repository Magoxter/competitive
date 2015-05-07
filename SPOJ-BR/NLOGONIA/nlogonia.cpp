#include <stdio.h>

void solve(int xC, int yC, int x, int y) {
    // Left part
    if (x < xC) {
        if (y > yC) printf("NO\n");
        else if (y < yC) printf("SO\n");
        else printf("divisa\n");
        return;
    }
    // Right part
    if (x > xC) {
        if (y > yC) printf("NE\n");
        else if (y < yC) printf("SE\n");
        else printf("divisa\n");
        return;
    }
    // None of them
    printf("divisa\n");
}

int main() {
    // Number of lookups
    int K;
    scanf("%d", &K);

    while (K != 0) {
        // Coordinates of the centre
        int xC, yC;
        scanf("%d %d", &xC, &yC);

        for (int i = 0; i < K; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            solve(xC, yC, x, y);
        }

        scanf("%d", &K);
    }
    return 0;
}