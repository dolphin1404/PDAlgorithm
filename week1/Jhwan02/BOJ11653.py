n = int(input())
i = 2
while n>1:
    if n % i == 0:
        print(i)
        n //= i
        i = 2
    else:
        i += 1