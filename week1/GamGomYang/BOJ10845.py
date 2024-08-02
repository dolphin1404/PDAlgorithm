from collections import deque
import sys

input = sys.stdin.read
data = input().split()

n = int(data[0])
queue = deque()
result = []

index = 1

for _ in range(n):
    command = data[index]
    if command == "push":
        index += 1
        value = int(data[index])
        queue.append(value)

    elif command == "pop":
        if queue:
            result.append(queue.popleft())
        else:
            result.append(-1)


    elif command == "size":
        result.append(len(queue))

    elif command == "empty":
        result.append(1 if not queue else 0)

    elif command == "front":
        if queue:
            result.append(queue[0])
        else:
            result.append(-1)


    elif command == "back":
        if queue:
            result.append(queue[-1])
        else:
            result.append(-1)
            
    
    index += 1

print("\n".join(map(str, result)))
