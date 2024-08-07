#include <stdio.h>
#define MAX 1001

int graph[MAX][MAX];
int visit[MAX];
int N, M, ans;


void DFS(int x) {
    visit[x] = 1;

    for (int i = 1; i <= N; i++) {
        if (visit[i] == 0 && graph[x][i] == 1) { 
            DFS(i);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }

    for (int i = 1; i <= N; i++) { 
        if (visit[i] == 0) {
            DFS(i);
            ans++;
        }
    }

    printf("%d", ans);

    return 0;
}
