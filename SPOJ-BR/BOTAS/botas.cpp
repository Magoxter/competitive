#include <stdio.h>

#define MAX 31

int right[MAX], left[MAX];

int main() {
    int N;

    while (scanf("%d\n", &N) > 0) {
        int total = 0;

        for (int i = 0; i < MAX; i++) {
            right[i] = 0;
            left[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            int size;
            char side;
            scanf("%d %c", &size, &side);

            if (side == 'D') right[size-30]++;
            else left[size-30]++;
        }

        for (int i = 0; i < MAX; i++) {
            if (right[i] < left[i]) total += right[i];
            else total += left[i];
        }

        printf("%d\n", total);
    }

    return 0;
}