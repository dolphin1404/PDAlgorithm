#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<pair<int, int>>& arr, int start, int next, int visited[]) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        int next = arr[current].second;
        if (!visited[next]) {
            q.push(next);
            visited[next] = 1;
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<pair<int, int>> arr(N);
        int visited[1001] = {0};

        for (int i = 0; i < N; i++) {
            int next;
            cin >> next;
            arr[i] = {i, next - 1}; 
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                bfs(arr, arr[i].first, arr[i].second, visited);
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
