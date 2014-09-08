#include <stdio.h>
#include <math.h>

int main() {
	int n;

	//Number of tests so far
	int t = 1;

	scanf("%d", &n);

	while (n != 0) {
		int x = (int)(pow(2, n) - 1);

		printf("Teste %d\n%d\n\n", t, x);
		scanf("%d", &n);
		t++; 
	}
}