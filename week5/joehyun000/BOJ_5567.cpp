#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[501];
bool visited[501] = {false ,};
int ans =0;

void dfs(int n, int depth) {
    if(depth == 2) return;

    for(int i=0; i<arr[n].size(); i++) {
        int next = arr[n][i];
        visited[next] = true;
        dfs(next, depth + 1);
    }
}

int main() {
    int n,m;
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++) {
		int a,b; 
		cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visited[1] = true;
    dfs(1,0);

    for(int i=1; i<=n; i++) {
        if(visited[i]) {
            ans++;
        }
    }
    cout << ans-1 <<endl;
}