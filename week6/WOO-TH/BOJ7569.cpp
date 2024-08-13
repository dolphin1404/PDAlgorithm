#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    int m, n, h;
    cin >> m >> n >> h;
    int tomato[h][n][m];
    queue<tuple<int, int, int>> q;
    int directions[6][3] = {{-1,0,0}, {1,0,0}, {0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

    // 입력받기
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                cin >> tomato[i][j][k];
                if(tomato[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                }
            }
        }
    }

    int day = -1;

    // BFS로 토마토 익히기
    while (!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; ++i)
        {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());
            q.pop();

            for(int j = 0; j < 6; ++j)
            {
                int nx = x + directions[j][0];
                int ny = y + directions[j][1];
                int nz = z + directions[j][2];

                if (nx >= 0 && nx < h && ny >= 0 && ny < n && nz >= 0 && nz < m && tomato[nx][ny][nz] == 0)
                {
                    tomato[nx][ny][nz] = 1;
                    q.push(make_tuple(nx, ny, nz));
                }
            }
        }
        ++day;
    }

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < n; ++j) {
            for(int k = 0; k < m; ++k) {
                if(tomato[i][j][k] == 0) {  //익지못하는 토마토가 남아있어서
                    cout << -1;     //모두 익지 못하는 상황
                    return 0;
                }
            }
        }
    }

    cout << day;
    return 0;
}
