t = int(input())

def get_cnt(i):
    visited[i] = 1
    next = arr[i]
    if visited[next] == 0:
        get_cnt(next)
    return 0

for _ in range(t):
    n = int(input())
    cnt = 0
    visited = [0]*(n+1)
    arr = list(map(int,input().split()))
    arr.insert(0,-1)
    for i in range(1,n+1):
        if visited[i] == 0:
            get_cnt(i)
            cnt += 1
    print(cnt)