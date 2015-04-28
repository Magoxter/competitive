#include <stdio.h>

int main() {
    int N, P;

    scanf("%d %d", &N, &P);
    while (N != 0) {
        int pages;
        
        if (N % P == 0) pages = N / P;
        else pages = (N / P) + 1;

        if (pages <= 6) printf("Poodle\n");
        else if (pages >= 20) printf("Poooooooooooooooodle\n");
        else {
            printf("P");
            for (int i = 0; i < pages-4; i++) printf("o");
            printf("dle\n");
        }

        scanf("%d %d", &N, &P);
    }

    return 0;
}