n,m = map(int, input().split())

list1 = set()
list2 = set()
result = []

for _ in range(n):
    list1.add(input())

for _ in range(m):
    list2.add(input())

result = sorted(list1&list2)

print(len(result))
for i in result:
    print(i)