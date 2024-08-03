#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring> 

using namespace std;

vector<int> adjList[1001];
bool isVisited[1001] = {false, };
queue<int> q;

void DFS(int n) {
    if (isVisited[n]) return;
    isVisited[n] = true;
    cout << n << " ";

    for (int i = 0; i < adjList[n].size(); i++) {
        DFS(adjList[n][i]);
    }
}

void BFS(int n) {
    q.push(n);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (isVisited[current]) continue;
        isVisited[current] = true;
        cout << current << " ";

        for (int i = 0; i < adjList[current].size(); i++) {
            q.push(adjList[current][i]);
        }
    }
}

int main() {
    int N, M, V;

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int n, m;
        cin >> n >> m;
        adjList[n].push_back(m);
        adjList[m].push_back(n);
    }


    for (int i = 1; i <= N; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    DFS(V);
    cout << endl;

    memset(isVisited, false, sizeof(isVisited));

    BFS(V);
    cout << endl;

    return 0;
}
