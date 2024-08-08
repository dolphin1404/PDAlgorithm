#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[1001][1001] = {0, };
int visitedDay[1001][1001];
queue <pair<int, int>> q; 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int M,N;


void bfs() {
    while (!q.empty()) {
        int y = q.front().first;          
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
        
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;   //상하좌우가 해당 범위내에 있는지 판단

            if (arr[ny][nx] == 0 && visitedDay[ny][nx] == -1) {     //아직 안익었고, 방문한적이 없다면 
                visitedDay[ny][nx] = visitedDay[y][x] + 1;          //현재 날짜에 +1한 날짜가 현재 날짜
                q.push(make_pair(ny, nx));                          //그 인접위치의 토마토도 익게되기에 q에넣어서 그 인접의 인접도 탐색하도록 설정
            }
        }
    }
    
}

int main() {
    cin >> M >> N;
    int dayCount = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 1) {  //익었으면 q에 넣고 이미 익어있기에 날짜를 0으로 설정
                q.push(make_pair(i, j)); 
				visitedDay[i][j] = 0;
            }
            else {                //그게 아니면 아직 방문 안했으니 일단 날짜를 -1로 설정
                visitedDay[i][j] = -1;
            }
        }
    }

    bfs();

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == 0 && visitedDay[i][j] == -1) {   //탐색함수 돌린 뒤에도 아직 안익은게 있는지 확인 후
				cout << -1;                                  //그렇다면 -1출력하고 프로그램 종료
				return 0; 
            }
            if(visitedDay[i][j] > dayCount) {                //방문한지 가장 오래된 날짜를 출력하기위한 코드
                dayCount = visitedDay[i][j];
            } 
        }
    }
    cout << dayCount;
}