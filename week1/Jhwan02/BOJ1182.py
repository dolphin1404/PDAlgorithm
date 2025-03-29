from itertools import combinations
import sys

input = sys.stdin.readline

n,s = map(int, input().split())

num = list(map(int, input().split()))

cnt = 0

for i in range(1,n+1):
    new_comb = combinations(num,i)
    for j in new_comb:
        if s == sum(j):
            cnt += 1


print(cnt)