//
// Created by samsung on 24. 8. 7.
//
#include <iostream>
#include <queue>
using namespace std;

struct Grid {
    int status;
};

istream operator>>(const istream & cin, const Grid & rhs);

int main ( ){
    int M = 0;
    int N = 0; //상자의 가로세로 크기
    cin >> M >> N;
    if ((M < 2 || M > 1000) || (N < 2 || N > 1000)) {   //상자의 범위 벗어 났을때
        return 0;
    }
    Grid grid[M][N];
    int day = 0;
    queue<pair<int,int>> q;
    for (int i = 0; i< M ;++i) {
        for(int j = 0; j < N ; ++j) {
            cin >>grid[i][j].status;
            if (grid[i][j].status == 1) {
                q.push({i,j});
            }
        }
    }
    int directions[4][2] = {{-1,0},{1,0},{0,-1}, {0,1}};

    while(!q.empty()) {
        int size = q.size();
        bool changed = false;
        for(int i = 0; i < size; ++i) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int d = 0; d < 4 ; d++) {
                int nx = x +directions[d][0];
                int ny = y + directions[d][1];

                if(nx >= 0 && nx < M && ny >= 0 && ny <N && grid[nx][ny].status == 0) {
                    grid[nx][ny].status = 1;
                    q.push({nx,ny});    //새로익은 토마토 큐에 추가
                    changed = true;
                }
            }//상하좌우 확인
        }
        if (changed)// 바뀌지 않으면 반복 중단
            ++day;
    }
    for(int i = 0;i<M;++i) {
        for(int j = 0;j < N;++j) {
            if(grid[i][j].status == 0) {
                cout << -1 <<endl;
                return 0;
            }
        }
    }
    cout << day<<endl;
}
