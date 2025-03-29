#include <iostream>
using namespace std;

const int MAX_N = 100;
char grid[MAX_N][MAX_N];        // 그림 저장
bool visited[MAX_N][MAX_N];     // 방문 여부

int dx[] = {-1, 1, 0, 0};       // 상하좌우 이동
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, char color, int n) {
    visited[x][y] = true;  // 방문으로 표시
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 인접한 칸이 범위 내에 있고, 방문하지 않았으며, 같은 색상인 경우 DFS 탐색
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == color) {
            dfs(nx, ny, color, n);
        }
    }
}

int count_regions(int n) {
    int region_count = 0;

    // 방문 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    }

    // 각 칸을 방문하며 구역의 수를 계산
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[i][j]) {
                dfs(i, j, grid[i][j], n);
                ++region_count;  // 새로운 구역이 발견될 때마다 구역 수 증가
            }
        }
    }

    return region_count;  // 구역의 수 반환
}

int main() {
    int N;
    cin >> N;  // 그림의 크기 입력

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int normal_count = count_regions(N);  // 적록색약이 아닌 경우 구역 수 계산

    // 적록색약인 경우를 위해 초록색(G)을 빨간색(R)으로 변경
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'G') {
                grid[i][j] = 'R';  // G를 R로 변경
            }
        }
    }

    int blind_count = count_regions(N);  // 적록색약인 경우 구역 수 계산

    // 결과 출력
    cout << normal_count << " " << blind_count << endl;

    return 0;
}
