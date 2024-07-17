n = int(input())
num = []
for _ in range(n):
    tmp = list(map(int,input().split()))
    num.append(tmp)

num.sort(key = lambda x : (x[0],x[1]))

for i in range(len(num)):
    print(num[i][0], num[i][1])