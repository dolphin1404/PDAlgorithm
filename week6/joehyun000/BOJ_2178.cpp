#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[101][101];
bool visited[101][101] = {false};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, M;

void bfs(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        int y = q.front().first;          
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue; 

            if (arr[ny][nx] == 1 && !visited[ny][nx]) {
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
                arr[ny][nx] = arr[y][x] + 1;  
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);  
        }
    }

    bfs(make_pair(0, 0));

    cout << arr[N-1][M-1] << endl;  
    return 0;
}
