from itertools import combinations

n,m = map(int,input().split())

num = [i+1 for i in range(n)]

res = combinations(num,m)

for i in res:
    for j in range(len(i)):
        print(i[j], end=" ")
    print("\n",end="")