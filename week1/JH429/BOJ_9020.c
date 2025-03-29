#include <stdio.h>

int main() {
	int n[10001], prime[10001] = { 0, 1 };
	int T, middle_n;

	scanf("%d", &T);

	for (int i = 2; i <= 10000; i++){
		for (int j = 2; j * i <= 10000; j++)
			prime[i * j] = 1;
	}

	for (int i = 0; i < T; i++)
		scanf("%d", n + i);

	for (int a = 0; a < T; a++){
		middle_n = n[a] / 2;
		for (int i = middle_n; i > 1; i--) {
			for (int j = middle_n; j < n[a]; j++) {
				if (!prime[i] && !prime[j] && (i + j == n[a])) {
					printf("%d %d\n", i, j);
					i = 1;
					break;
				}
			}
		}
	}

	return 0;
}