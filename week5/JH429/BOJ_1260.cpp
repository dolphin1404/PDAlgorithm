#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001

int graph[MAX][MAX];

int N, M, V;
int visited[MAX];
queue<int> q;

void DFS(int idx){
    visited[idx] = 1;
    cout << idx << " ";

    for (int i = 1; i <= N; i++) {
        if(visited[i] == 0 && graph[idx][i] == 1)
            DFS(i);
    }
}

void BFS(){
    q.push(V);
    visited[V] = 1;
    

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        
        for(int i = 1; i <= N; i++){
            if(visited[i] == 0 && graph[cur][i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }

    DFS(V);
    cout << endl;
    for(int i = 1; i <= N; i++)
        visited[i] = 0;
    
    BFS();

    return 0;
}