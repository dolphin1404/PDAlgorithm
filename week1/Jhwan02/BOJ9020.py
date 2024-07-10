def isPrime(n):
    if n == 1:
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

n = int(input())

for _ in range(n):
    num = int(input())

    a = num//2
    b = num//2

    for _ in range(num//2):
        if isPrime(a) and isPrime(b):
            print(a,b)
            break
        else:
            a -= 1
            b += 1