def prime_counter(max_num):
    prime_counter = [True] * (max_num + 1)
    prime_counter[0] = False
    prime_counter[1] = False

    for i in range(2, int(max_num**0.5) + 1):
        if prime_counter[i]:
            for j in range(i * i, max_num + 1, i):
                prime_counter[j] = False

    return [i for i in range(max_num + 1) if prime_counter[i]]

def Solution(n, primes):
    primes_set = set(primes)
    for prime in primes:
        if prime > n // 2:
            break
        if n - prime in primes_set:
            return prime, n - prime
    return None

def main():
    primes = prime_counter(10000)
    input_counter = int(input(""))
    for _ in range(input_counter):
        n = int(input(""))
        if n % 2 == 0 and n > 2:
            pair = Solution(n, primes)
            if pair:
                print(f"{n} = {pair[0]} + {pair[1]}")


if __name__ == "__main__":
    main()
