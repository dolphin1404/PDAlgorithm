def solution(priorities, location):
    answer = 0
    compare = priorities[location]
    idx = location
    while True:
        if any(priorities[0] < i for i in priorities):
            if idx == 0:
                idx += len(priorities)-1
                priorities.append(priorities.pop(0))
            else:
                idx -= 1
                priorities.append(priorities.pop(0))
        else:
            answer += 1
            if idx == 0 and priorities[0] == compare:
                return answer
            else:
                if idx == 0:
                    idx += len(priorities)-1
                else:
                    idx -= 1
                priorities.pop(0)