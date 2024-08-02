from typing import Sequence, List , Any
from collections import deque

def solution(priorities, location):
    queue = deque([(p,i)for i,p in enumerate(priorities)])
    count = 0


    while queue:
        current = queue.popleft()

        if any(current[0]< item[0] for item in queue):
            queue.append(current)
        else:
            count+=1
            if current[1] == location:
                return count
            


if __name__ == "__main__":
    
    priorities1 = [2, 1, 3, 2]
    location1 = 1
    print(solution(priorities1, location1)) 

    priorities2 = [1, 1, 9, 1, 1, 1]
    location2 = 0
    print(solution(priorities2, location2))  