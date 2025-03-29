#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char arr[101][101];
bool visited[101][101];
queue <pair<int, int>> q; 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N;

void bfs(int a, int b) {
     visited[a][b] = true;
    q.push({a, b});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && arr[nx][ny] == arr[x][y]){ 
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
    


int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    int count = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count << " "; 
	count = 0; 
	memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'G') {
                arr[i][j] = 'R';
            } 
		}
	}

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                count++;
                bfs(i, j);
            }
        }
    }
    cout << count << '\n';
    
    return 0;
}
