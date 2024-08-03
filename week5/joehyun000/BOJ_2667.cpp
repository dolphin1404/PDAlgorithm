#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[25][25] = {0, };
bool visited[25][25] = {0, };
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N;

void dfs(int y, int x, int &count) {
    visited[y][x] = true;
    count++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

        if (arr[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny, nx, count);
        }
    }
}

int main() {
    vector<int> v;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]); 
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && !visited[i][j]) {
                int count = 0;
                dfs(i, j, count);
                v.push_back(count);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl; 
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl; 
    }

    return 0;
}

