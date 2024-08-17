#include<iostream>
#include<vector>
using namespace std;

void check_num(const vector<vector<int>>& grid, int *a, int *b, int *c, int N) {
    int firstValue = grid[0][0];
    bool allSame = true;

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(grid[i][j] != firstValue) {
                allSame = false;
                break;
            }
        }
        if (!allSame) break;
    }

    if(allSame) {
        if(firstValue == -1) {
            ++(*a);
        } else if(firstValue == 0) {
            ++(*b);
        } else if(firstValue == 1) {
            ++(*c);
        }
    } else {
        int new_N = N / 3;                      //같지않으면 N 재정의

        for(int i = 0; i < 3; ++i) {      //9번 반복
            for(int j = 0; j < 3; ++j) {

                vector<vector<int>> subGrid(new_N, vector<int>(new_N));         //NEW_N으로 새로운 2차원 배열 생성

                for(int x = 0; x < new_N; ++x) {
                    for(int y = 0; y < new_N; ++y) {
                        subGrid[x][y] = grid[i*new_N + x][j*new_N + y];                 //새로운 배열에 위치에 맞는 값 담아주고
                    }
                }
                check_num(subGrid, a, b, c, new_N);                                     //각 배열마다 같은지 확인

            }
        }
    }
}

int main() {
    int N;
    int a = 0;  // -1의 수
    int b = 0;  // 0의 수
    int c = 0;  // 1의 수
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    check_num(grid, &a, &b, &c, N);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
}
