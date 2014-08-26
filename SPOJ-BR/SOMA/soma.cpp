#include <stdio.h>

int main() {
	int n, aux;
	int x = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &aux);
		x += aux;
	}

	printf("%d\n", x);

	return 0;
}