from typing import List

def prime_solution(num: int) -> bool:
    if num <= 1:
        return False
    for i in range(2, num):
        if num % i == 0:
            return False
    return True

def prime_counter(numbers: List[int]) -> int:
    counter = 0
    for number in numbers:
        if prime_solution(number):
            counter += 1
    return counter


n = int(input())
numbers = list(map(int, input().split()))


counter = prime_counter(numbers)


print(counter)
