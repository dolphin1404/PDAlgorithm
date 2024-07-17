#include<stdio.h>
#include<stdlib.h>

int compare(void* first, void* second) {
	return strcmp(first, second);
}

typedef struct {
	char array[21];
}name;

typedef struct {
	char final_array[21];
}answer;

name str1[1000001];
answer str2[500001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n + m; i++) {
		scanf("%s", str1[i].array);
	}
	qsort(str1, n + m, sizeof(str1[0]), compare);
	int count = 0;
	for (int i = 0; i < n + m; i++) {
		if (strcmp(str1[i].array, str1[i + 1].array) == 0) {
			strcpy(str2[count].final_array, str1[i++].array); // 배열 자체는 대입연산이 불가능하므로 strcpy를 사용해서 복사를 해야함. 
		
			count++; // i++ 하는이유 : i와 i + 1은 이미 같다는걸 성립했으니 두번 건너뛰는게 맞음
		}
	}
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%s\n", str2[i].final_array);
	}
	

}