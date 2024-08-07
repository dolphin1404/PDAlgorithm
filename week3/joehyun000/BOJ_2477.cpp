#include <iostream>
#include <cmath>
using namespace std;

int N;

// 재귀적으로 별 패턴을 채우는 함수
void star(int x, int y, int n)
{
    // 현재 위치가 공백인지 확인
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
        cout << " "; // 공백 출력
    else
    {
        // 크기가 1이면 별 출력
        if (n == 1)
            cout << "*";
        else
            // 크기를 3으로 나누어 재귀 호출
            star(x, y, n / 3);
    }
}

int main()
{
    cin >> N; // N 입력받기

    // N x N 크기의 패턴을 생성
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            // (i, j) 위치에서 시작하여 크기 N의 패턴을 출력
            star(i, j, N);
        cout << '\n'; // 한 행이 끝나면 줄바꿈
    }
}
