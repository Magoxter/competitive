#include <stdio.h>

int main() {
	int r;
	int a, b;
	int aldo = 0;
	int beto = 0;

	int n = 1;

	scanf("%d", &r);

	while (r > 0) {
		for (int i = 1; i <= r; i++) {
			scanf("%d %d", &a, &b);
			aldo += a;
			beto += b;
		}

		printf("Teste %d\n", n);
		printf("%s\n\n", aldo > beto ? "Aldo" : "Beto");

		n++;
		aldo = 0;
		beto = 0;

		scanf("%d", &r);
	}

	return 0;
}