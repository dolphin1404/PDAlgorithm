#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9; 
int arr[126][126] = {0,};
int visited[126][126] = {0,};
int N;

void bfs(int a, int b){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    queue<pair<int, int>> q;

    visited[a][b] = arr[a][b];
    q.push({a,b});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if(visited[x][y] + arr[nx][ny] >= visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + arr[nx][ny];
            q.push({nx,ny}); 
        }
    }
}

int main(){
    int num = 1;

    while(true){
        cin >> N;
        if(N == 0) break; 

        for(int i = 0; i < 126; i++)
            for(int j = 0; j < 126; j++) {
                visited[i][j] = INF; 
                arr[i][j] = 0;
            }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }

        bfs(0, 0);

        cout << "Problem " << num << ": " << visited[N-1][N-1] << endl;
        num++;
    }
    return 0;
}
