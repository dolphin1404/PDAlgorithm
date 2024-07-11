from typing import Sequence, List, Any

number = int(input())

sik = input()

sik_list = [0] * number

for i in range(number):
    sik_list[i] = int(input())   

stack = []

for i in sik:
    if 'A' <= i <= 'Z':
        stack.append(sik_list[ord(i) - ord('A')])
    else:
        str2 = stack.pop()
        str1 = stack.pop()

        if i == '+':
            stack.append(str1 + str2)
        elif i == '-':
            stack.append(str1 - str2)
        elif i == '/':
            stack.append(str1 / str2)
        elif i == '*':
            stack.append(str1 * str2)

print(f'{stack[0]:.2f}')
