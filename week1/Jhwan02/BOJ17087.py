def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

n,s = map(int,input().split())
pos = list(map(int, input().split()))

for i in range(len(pos)):
    pos[i] = abs(pos[i]-s)

res = min(pos)
for i in pos:
    res = gcd(i,res)

print(res) 