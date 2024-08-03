#include <iostream>
#include <vector>
using namespace std;

vector<int> arr[1001];
bool visited[1001] = {false};

void dfs(int n) {
    visited[n] = true;
    for(int i = 0; i < arr[n].size(); i++) {
        int next = arr[n][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
