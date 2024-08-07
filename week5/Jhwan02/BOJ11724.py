import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

n,m = map(int,input().split())

graph = [[] for _ in range(n+1)]
visited = [0] * (n+1)
cnt = 0

for _ in range(m):
    u,v = map(int,input().split())
    graph[u].append(v)
    graph[v].append(u)

def get_cnt(v):
    visited[v] = 1
    for i in graph[v]:
        if visited[i] == 0:
            visited[i] = 1
            get_cnt(i)

for i in range(1,n+1):
    if visited[i] == 0:
        get_cnt(i)
        cnt += 1

print(cnt)