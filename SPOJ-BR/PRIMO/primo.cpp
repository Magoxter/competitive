#include <stdio.h>
#include <math.h>	

int main() {
    int n;

	scanf("%d", &n);

	if (n < 0) n = -n;

	if ((n == 0) || (n == 1)) {
		printf("nao\n");
		return 0;
	}

	for (int i = 2; i <= sqrt(n); i++) {
		if ((n % i) == 0) {
			printf ("nao\n");
			return 0;
		}
	}

	printf("sim\n");
	return 0;
}