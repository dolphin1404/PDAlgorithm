#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;  // 무한대 값 설정
int cost[1003];  // 비용 배열
vector<pair<int, int>> adj[1003];  // 인접 리스트: 도착 도시, 비용

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  // 시작 노드를 우선순위 큐에 추가
    cost[start] = 0;  // 시작점 비용은 0

    while (!pq.empty()) {
        int current_cost = pq.top().first;  // 현재까지의 비용
        int current_city = pq.top().second;
        pq.pop();

        if (cost[current_city] < current_cost)  // 이미 더 적은 비용으로 방문한 경우 스킵
            continue;

        for (const auto& edge : adj[current_city]) {
            int next_city = edge.first;
            int next_cost = current_cost + edge.second;

            // 더 저렴한 비용으로 다음 도시에 도달할 수 있으면 업데이트
            if (cost[next_city] > next_cost) {
                pq.push({next_cost, next_city});
                cost[next_city] = next_cost;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    fill(cost, cost + 1003, INF);  // 비용 배열을 무한대로 초기화

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int start, destination;
    cin >> start >> destination;

    dijkstra(start);  // 시작점으로부터 최단거리 계산

    cout << cost[destination];  // 목적지까지의 최단 거리 출력
    return 0;
}
