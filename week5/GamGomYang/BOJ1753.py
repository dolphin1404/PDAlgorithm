import heapq
import sys

input = sys.stdin.read
def dijkstra(start, graph, V):
    dist = [float('inf')] * (V + 1)
    dist[start] = 0
    # 우선순위 큐 선언
    pq = [(0, start)]

    while pq:
        current_dist, u = heapq.heappop(pq)

        # 현재 노드의 거리 값이 갱신된 것과 일치하지 않으면 무시
        if current_dist > dist[u]:
            continue

        # 현재 노드와 연결된 모든 노드 확인
        for weight, v in graph[u]:
            distance = current_dist + weight

            # 현재 노드를 통해 가는 거리가 기존 거리보다 짧으면 거리 갱신
            if distance < dist[v]:
                dist[v] = distance
                heapq.heappush(pq, (distance, v))

    return dist

def main():

    data = input().split()
    idx = 0

    V = int(data[idx])
    E = int(data[idx + 1])
    K = int(data[idx + 2])
    idx += 3


    graph = [[] for _ in range(V + 1)]

    for _ in range(E):
        u = int(data[idx])
        v = int(data[idx + 1])
        w = int(data[idx + 2])
        idx += 3
        graph[u].append((w, v))


    dist = dijkstra(K, graph, V)


    for i in range(1, V + 1):
        if dist[i] == float('inf'):
            print("INF")
        else:
            print(dist[i])

if __name__ == "__main__":
    main()
