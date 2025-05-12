v, n = [int(i) for i in input().split()]
x = []
while n != 0:
    z = int(input())
    if z >= 110:
        continue
    x.append(z)
    n -= 1
resp = "fretepago"

c = len(x)
if c%2 == 0:
    c2 = c//2
else:
    c2 = c//2 + 1
for i in range(c2):
    for j in range(i+1,c):
        for k in range(j+1,c):
            if v + x[i] + x[j] + x[k] == 200:
                resp = "fretegratis"
                break
print(resp)
