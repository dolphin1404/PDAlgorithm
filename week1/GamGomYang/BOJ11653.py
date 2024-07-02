from typing import Sequence, Any

number = int(input())
i=2

while(number>1):
    if (number%i == 0):
        number = number/i
        print(i)
        i=2
    else:
        i +=1


        