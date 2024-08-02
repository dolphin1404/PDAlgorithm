#include <stdio.h>

int main() {
	int N;

	scanf("%d", &N);
	if (N == 1)
		return 0;

	for (int i = 2; i <= N; i++) {
		if (N % i == 0) {
			N /= i;
			printf("%d\n", i);
			i = 1;
		}
	}
}