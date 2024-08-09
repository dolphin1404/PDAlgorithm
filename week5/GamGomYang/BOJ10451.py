from collections import deque

def count_cycles(n, permutation):
    visited = [False] * (n + 1)  # 방문 체크
    def bfs(start):# BFS
        queue = deque([start])  # 큐에 시작 노드를 넣음
        visited[start] = True  # 시작 노드를 방문 처리

        while queue:
            node = queue.popleft()  # 큐에서 노드를 꺼냄
            next_node = permutation[node]  # 현재 노드의 다음 노드를 찾음

            if not visited[next_node]:  # 다음 노드를 방문하지 않았다면?
                visited[next_node] = True  # 방문 처리
                queue.append(next_node)  # 큐에 다음 노드를 추가함

    count = 0  # 사이클의 개수를 셀 변수

    for i in range(1, n + 1):
        if not visited[i]:  # 아직 방문하지 않은 노드가 있으면
            bfs(i)  # BFS 탐색 시작
            count += 1  # 사이클 개수 증가

    return count





def count_cycles(n, permutation):
    visited = [False] * (n + 1)  
    def dfs(node):
        stack = [node]
        while stack:
            current = stack.pop()
            next_node = permutation[current]
            if not visited[next_node]:
                visited[next_node] = True
                stack.append(next_node)

    count = 0  
    for i in range(1, n + 1):
        if not visited[i]:  # 아직 방문하지 않은 노드가 있으면?
            visited[i] = True
            dfs(i)  # DFS 탐색 시작
            count += 1  

    return count






# 입력 
t = int(input())  
for _ in range(t):
    n = int(input())  
    permutation = [0] + list(map(int, input().split()))  
    print(count_cycles(n, permutation))  
