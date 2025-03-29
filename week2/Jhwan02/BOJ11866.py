n,k = map(int, input().split())

arr = [i+1 for i in range(n)]
idx = 0
res = []

while len(arr)!=0:
    idx += k-1
    idx = idx % len(arr)
    res.append(arr.pop(idx))

print("<",end="")
for i in range(n-1):
    print(res[i],end=", ")
print(res[n-1], end = "")
print(">",end="")