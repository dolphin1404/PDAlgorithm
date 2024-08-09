#include <vector>
#include <queue>
#include <iostream>

using namespace std;

# define INF 99999999

// 시작 위치와 정점의 개수, 인접 행렬을 받아
// 최소 거리 행렬을 반환함
vector<int> dijkstra(int start, int N, vector<pair<int, int>> graph[])
{
    vector<int> dist(N, INF);  // 거리를 저장할 리스트 초기화
    priority_queue<pair<int, int>> pq;  // 우선순위 큐 선언

    dist[start] = 0;  // 시작 노드 거리를 0으로 함
    pq.push({ 0, start });  // 우선순위 큐에 넣기

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first; // 큐에서 꺼내 방문하고 있는 정점의 거리
        int cur_node = pq.top().second;  // 정점의 인덱스(번호)
        pq.pop();

        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int nxt_node = graph[cur_node][i].first;  // 인접 정점 번호
            int nxt_dist = cur_dist + graph[cur_node][i].second;  // 인접 정점까지 거리

            if (nxt_dist < dist[nxt_node])  // 지금 계산한 것이 기존 거리값보다 작다면
            {
                dist[nxt_node] = nxt_dist;  // 거리값 업데이트
                pq.push({ -nxt_dist, nxt_node });  // 우선순위 큐에 넣기
            }
        }
    }

    return dist;  // start 노드로부터 각 노드까지 최단거리를 담은 벡터 리턴
}