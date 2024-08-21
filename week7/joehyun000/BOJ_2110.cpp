#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
int arr[200001];

void binarySearch() {
    int left = 1;
    int right =  arr[N-1] - arr[0];
    int result = 0;
    int distance = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        int start = arr[0];
        int count = 1;
    }

    for (int i = 1; i < N; i++) {
			distance = arr[i] - start;
			if (mid <= distance) {	// 공유기 설치
				count++;			// 설치 갯수 증가
				start = arr[i];		// 최근 설치 위치 갱신
			}
		}
}

int main() {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

    binarySearch();
}