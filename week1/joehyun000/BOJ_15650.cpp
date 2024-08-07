#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int depth, int N, int M, vector<int>& arr) {
    if(depth == M) {
        for(int i =0; i < M; i++) {
            cout << arr[i]<< " ";
        }
        cout << "\n";
        return ; 
    }
    for (int i = start; i<= N; i++) {
        
    }
}

int main() {
    int N,M;

    cin >> N >> M;

    vector<int>arr(M);
    dfs(1,0,N,M,arr);

    return 0;
}