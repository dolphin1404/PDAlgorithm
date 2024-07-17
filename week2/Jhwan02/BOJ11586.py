n = int(input())
mir = []
for i in range(n):
    mir.append(input())
k = int(input())

if k == 1:
    for i in range(n):
        for j in range(n):
            print(mir[i][j],end="")
        print("\n",end="")
elif k == 2:
    for i in range(n):
        for j in range(n-1,-1,-1):
            print(mir[i][j],end="")
        print("\n",end="")
else:
    for i in range(n-1, -1, -1):
        for j in range(n):
            print(mir[i][j],end="")
        print("\n",end="")