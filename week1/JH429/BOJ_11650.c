#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

typedef struct {
	int x;
	int y;
}ps;

int N;
ps pst[MAX];

int cmp(const void* lhs, const void* rhs) {
	ps* xl = (ps*)lhs;
	ps* yl = (ps*)rhs;

	if (xl->x == yl->x) {
		if (xl->y > yl->y) 
            return 1;
		else
            return -1;
	}
	else {
		if (xl->x > yl->x)
            return 1;
		else
            return -1;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &pst[i].x, &pst[i].y);
	}
	qsort(pst, N, sizeof(ps), cmp);

	for (int i = 0; i < N; i++) printf("%d %d\n", pst[i].x, pst[i].y);

	return 0;
}