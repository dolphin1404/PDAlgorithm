#include <iostream>
#include <vector>
#include <queue>
#include <tuple>  
using namespace std;

int M, N, H;
int arr[100][100][100];
int visitedDay[100][100][100];
queue<tuple<int, int, int>> q;  // (z, y, x)
int dz[6] = {0, 0, 0, 0, 1, -1};  // 위, 아래, 앞, 뒤, 오른쪽, 왼쪽
int dy[6] = {0, 0, -1, 1, 0, 0};
int dx[6] = {-1, 1, 0, 0, 0, 0};

void bfs() {
    while (!q.empty()) {
        int z, y, x;
        tie(z, y, x) = q.front();  
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) continue; 

            if (arr[nz][ny][nx] == 0 && visitedDay[nz][ny][nx] == -1) {  
                visitedDay[nz][ny][nx] = visitedDay[z][y][x] + 1;
                q.push(make_tuple(nz, ny, nx));
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
    int dayCount = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> arr[i][j][k];
                visitedDay[i][j][k] = -1;  
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[i][j][k] == 1) {  
                    q.push(make_tuple(i, j, k));
                    visitedDay[i][j][k] = 0;
                }
            }
        }
    }

    bfs();

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[i][j][k] == 0 && visitedDay[i][j][k] == -1) {  
                    cout << -1;
                    return 0;
                }
                if (visitedDay[i][j][k] > dayCount) {  
                    dayCount = visitedDay[i][j][k];
                }
            }
        }
    }

    cout << dayCount;
}
