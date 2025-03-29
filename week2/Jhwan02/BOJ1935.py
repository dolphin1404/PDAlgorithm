n = int(input())
express = input()
num = list()
for _ in range(n):
    num.append(input())

char = list()

for i in range(len(express)):
    if express[i] >= "A" and express[i] <= "Z":
        char.append(num[ord(express[i])-65])
    else:
        op2 = char.pop()
        op1 = char.pop()
        char.append(str(eval(op1+express[i]+op2)))

print("%.2f"%float(char.pop()))