#include <stdio.h>

using namespace std;

int main() {
	int n, x;

	//Number of tests so far.
	int t = 1;

	scanf("%d", &n);
	while (n != 0) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &x);

			if (x == i) {
				printf("Teste %d\n", t);
				printf("%d\n\n", x);
			}
		}

		scanf("%d", &n);
		t++;
	}


	return 0;
}