#include <stdio.h>

int main() {
	int n;
	int x = 1;

	scanf("%d", &n);

	for (int i = n; i > 1; i--) {
		x *= i;
	}

	printf("%d\n", x);

	return 0;
}