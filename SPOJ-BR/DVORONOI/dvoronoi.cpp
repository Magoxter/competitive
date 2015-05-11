#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        // Reading the points
        int A[3], B[3], C[3], D[3];
        scanf("%d %d %d", &A[0], &A[1], &A[2]);
        scanf("%d %d %d", &B[0], &B[1], &B[2]);
        scanf("%d %d %d", &C[0], &C[1], &C[2]);
        scanf("%d %d %d", &D[0], &D[1], &D[2]);

        // Creating the 3 vectors
        int AB[3];
        for (int i = 0; i < 3; i++) AB[i] = B[i] - A[i];

        int AC[3];
        for (int i = 0; i < 3; i++) AC[i] = C[i] - A[i];

        int AD[3];
        for (int i = 0; i < 3; i++) AD[i] = D[i] - A[i];

        // Now, all we have to do is |(AB x AC) . AD| /2
        // (AB x AC) . AD is determinant of the matrix with the vectors as columns
        int determinant = (AB[0]*AC[1]*AD[2]) + (AC[0]*AD[1]*AB[2]) + (AD[0]*AB[1]*AC[2])
                          - (AB[2]*AC[1]*AD[0]) - (AC[2]*AD[1]*AB[0]) - (AD[2]*AB[1]*AC[0]);
        // Modulo
        if (determinant < 0) determinant = -determinant;

        // Answer
        double answer = double(determinant) / 6.0;
        printf("%.6lf\n", answer);
    }
}