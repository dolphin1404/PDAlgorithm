#include<stdio.h>
 
int map[101][101];
int visited[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
 
typedef struct _Queue {
	int v_x;	
	int v_y;	
} Queue;
 
 
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
 
	Queue queue[10000];
 
	int head = -1, rear = -1;
	int x = 0, y = 0;
 
	rear++;
	queue[rear].v_x = x;
	queue[rear].v_y = y;
	visited[x][y] = 1;
 
	while (head < rear) {
		head++;
		x = queue[head].v_x;
		y = queue[head].v_y;
		for (i = 0; i < 4; i++) {
			int dir_x = dx[i];
			int dir_y = dy[i];
			if (!visited[x + dir_x][y + dir_y] && map[x + dir_x][y + dir_y]) {
				visited[x + dir_x][y + dir_y] = visited[x][y] + 1;
				rear++;
				queue[rear].v_x = x + dir_x;
				queue[rear].v_y = y + dir_y;
			}
		}
	}
 
	printf("%d", visited[N - 1][M - 1]);
	return 0;
}