n = int(input())

count = 0

num = list(map(int, input().split()))

for i in num:
    for j in range(2,i-1):
        if i % j == 0:
            break
    else:
        if i != 1:
            count += 1

print(count)
