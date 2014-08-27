#include <stdio.h>

int main() {
	int n;
	int r = 1;
	int a, b;
	char player1[11], player2[11];

	scanf("%d", &n);

	while (n > 0) {
		scanf("%s", &player1);
		scanf("%s", &player2);

		printf("Teste %d\n", r);

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);

			printf("%s\n", ((a+b)%2 == 0)? player1 : player2);
		}

		printf("\n");
		r++;
		scanf("%d", &n);
	}

	return 0;
}