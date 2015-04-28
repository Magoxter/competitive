#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int total = 0;
        
        int T;
        scanf("%d", &T);

        for (int j = 0; j < T; j++) {
            int tmp;
            scanf("%d", &tmp);
            total += tmp;
        }

        if (total <= T) printf("nao precisa\n");
        else printf("precisa\n");
    }
    
    return 0;
}