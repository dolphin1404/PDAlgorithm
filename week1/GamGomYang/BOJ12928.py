def Solution(n):
    sum =0



    for i in range(1, n+1):
        if n%i ==0:
            sum += i


    return sum


if __name__ == "__main__":
    print(sum)