#include	<stdio.h>
#include	<stdlib.h>

/*

수도코드

1. 입력 받기: 집의 개수 N, 설치할 공유기 수 C
2. 집의 좌표 배열 입력
3. 집의 좌표 배열을  정렬

4. 이분 탐색 초기화:
   - left = 1 (최소 거리)
   - right = (최대 거리)

5. 이분 탐색 시작:
   WHILE left <= right:
       - 처음 시작 간격 설정  = (left + right) / 2 

       - FOR 각 집 i에 대해:
           IF (집 i와 최근 설치한 집 간 거리) >= mid:
               공유기 설치 (count 증가, start 위치 갱신)

       - IF 설치된 공유기 수 >= C:
           간격을 더 크게 설정 (left = mid + 1)
           결과값(result) 갱신
       - ELSE:
           간격을 줄임 (right = mid - 1)


예시

input : 1,2,8,4,9

입력: N = 5, C = 3

오름차순 정렬: [1, 2, 4, 8, 9]

최소 최대 거리 설정:

최소  left = 1
최대  right = 8 (arr[4] - arr[0] = 9 - 1)
이분 탐색:

mid = (1 + 8) / 2 = 4: 공유기 간의 간격을 4로 설정
1번 집에 설치,  4번 집에 설치,  9번 집에 설치 
→ 공유기 3개 설치 가능. count >= 설정개수 이므로 더 큰 간격을 탐색 (left = mid + 1)

mid = (5 + 8) / 2 = 6: 공유기 간의 간격을 6으로 설정
 1번 집에 설치, 8번 집에 설치
→ 공유기 2개 설치 가능. count < 설정개수 이므로 간격을 줄임 (right = mid - 1)

mid = (5 + 5) / 2 = 5: 공유기 간의 간격을 5로 설정
 1번 집에 설치,  8번 집에 설치 
→ 공유기 2개 설치 가능. count < 설정개수 이므로 간격을 줄임 (right = mid - 1)

*/



int cmp_func(const int* a, const int* b) {  // 오름차순으로 정렬을 위한 비교 함수
	if (*a < *b)		return -1;
	else if (*a > *b)	return 1;
	else				return 0;
}

int main(void) {
	int N, C;
	int* arr;

    //입력
	scanf("%d %d", &N, &C);
	arr = calloc(N, sizeof(int));

	int i;
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	qsort(arr, N, sizeof(int), cmp_func);	// 오름차순 정렬
    //정렬을 하는이유 -> 효율적으로 탑색을 하기 위해서


	int left = 1;						// 가능한 최소 거리
	int right = arr[N - 1] - arr[0];	// 가능한 최대 거리
	int distance = 0;	// 공유기간 거리
	int result = 0;		// 결과
// 최대 최소거리 설정



	while (left <= right) {
		int mid = (left + right) / 2;	// 이분법의 중앙값
		int start = arr[0];	// arr[0]에서부터 시작
		int count = 1;		// arr[0]에서부터 시작

		// 간격 d를 기준으로 공유기 설치
		for (i = 1; i < N; i++) {
			distance = arr[i] - start;
			if (mid <= distance) {	// 공유기 설치
				count++;			// 설치 갯수 증가
				start = arr[i];		// 최근 설치 위치 갱신
			}
		}

		if (count >= C) {	// 최대 공유기 설치 간격을 위해 반복
			result = mid;
			left = mid + 1;
		}
		else {				// 공유기 설치 간격을 줄여 갯수를 늘인다.
			right = mid - 1;
		}
	}

	printf("%d\n", result);	// 최대 거리를 출력

	free(arr);
	return 0;
}