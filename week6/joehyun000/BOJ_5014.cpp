#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int F, S, G, U, D;
int dx[2];
bool visited[1000001] = {false ,};
int arr[1000001] = {-1, };

void bfs() {
    queue<int> q;
    q.push(S);
    visited[S] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        arr[S] = 0; 
        
        for(int i=0; i<2; i++) {
            int nx = x + dx[i];
            
            if(0 < nx && nx <= F) {
                if(!visited[nx]) {
                    visited[nx] = true;
                    q.push(nx);
                    arr[nx] = arr[x] + 1;
                }
            }
        }
    }    
}

int main() {
    cin >> F >> S >> G >> U >> D;

    dx[0]= U;
    dx[1]= -D;

    bfs();

    if (visited[G]) {
        cout << arr[G];
    }
    else {
        cout << "use the stairs";
    }
}