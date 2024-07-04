import math
from functools import reduce

def gcd_multiple(numbers):
    return reduce(math.gcd, numbers)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    N = int(data[0])
    S = int(data[1])
    A = list(map(int, data[2:2 + N]))

    distances = [abs(S - a) for a in A]
    max_D = gcd_multiple(distances)

    print(max_D)

if __name__ == "__main__":
    main()
