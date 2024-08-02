#include <stdio.h>
//topdown dp
int arr[501][501];

int max(int a, int b) {
    return a > b ? a : b;
}

void BOJ1932(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                arr[i][j] += arr[i - 1][j];
            } else if (i == j) {
                // i 와 j가 같을때 -> 1가지의 경로 밖에 없음
                arr[i][j] += arr[i - 1][j - 1];
            } else {
                //그 외의 경우(가장자리에 위치하지 않는경우) -> 2가지의 경로(좌 우)가 있음
                //1
                //23
                //456
                //여기에서 숫자 5는 가장자리에 위치하지 않는 [3][2]에 위치
                // 2개의 합을 비교하여 가장 큰 수 갱신 
                //(2+5) 와 (3+5) 비교 하여 갱신
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);

               
            }
        }
    }

// 마지막 n번째 줄에서 가장 큰값 탐색후 갱신
    int num = -9999;
    for (int j = 1; j <= n; j++) {
        if (num < arr[n][j]) {
            num = arr[n][j];
        }
    }

    printf("%d", num);
}

int main(void) {
    int n = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    BOJ1932(n);
    return 0;
}
