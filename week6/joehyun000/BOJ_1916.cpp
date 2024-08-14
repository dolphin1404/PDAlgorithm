#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX를 사용하기 위해 추가

using namespace std;

int N, M;
int dist[1001];
vector<pair<int, int>> arr[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (cost > dist[current]) {
            continue;
        }

        for (int i = 0; i < arr[current].size(); i++) {
            int next = arr[current][i].first;
            int nextCost = dist[current] + arr[current][i].second;

            if (nextCost < dist[next]) {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main() {
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x].push_back({y, z});
    }

    int start, end;
    cin >> start >> end;

    fill(dist, dist + N + 1, INT_MAX);

    dist[start] = 0;
    dijkstra(start);

    if (dist[end] == INT_MAX) {
        cout << -1;
    } else {
        cout << dist[end];
    }
}
