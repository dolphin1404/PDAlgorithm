#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& v, int target) {
    int left = 0;
    int right = v.size() - 1;
    int result = v.size(); // 조건을 만족하는 값이 없을 경우 대비해 최대 인덱스로 초기화

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (v[mid] > target) {
            result = mid;  // 현재 중간 값이 타겟보다 큰 경우
            right = mid - 1;  // 왼쪽 부분 배열을 계속 탐색
        } else {
            left = mid + 1;  // 오른쪽 부분 배열을 탐색
        }
    }

    return result;
}

int main() {
    int N, M;
    int sum = 0;

    cin >> N;
    vector<int> v(N);

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v[i] = num;
        sum += num;
    }

    cin >> M;
    int average = sum / N;

    sort(v.begin(), v.end());
    int resultIndex = binarySearch(v, average);
    
    sum = 0;
    for(int i = resultIndex; i < v.size(); i++) {
        sum += v[i];
    }
    int standard = sum / (v.size() - resultIndex);

    for(int i = resultIndex; i < v.size(); i++) {
        if (v[i] > standard) {
            v[i] = standard;
        }
    }

    cout << v[N-1] << endl;
}
