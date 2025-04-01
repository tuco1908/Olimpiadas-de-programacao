a = int(input())
i = 1
j = 0
while i < 5:
    a = int(input())
    if a%2 == 0:
        j += 1
        i += 1
    else:
        i += 1
if i == 5:
    print(j,"valores pares")
