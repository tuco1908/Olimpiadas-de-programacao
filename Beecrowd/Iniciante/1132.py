x = int(input())
y = int(input())
j = 0
z = y
w = x
if x>y:   
    x=z
    y=w
for i in range(x,y+1,1):
    if i%13 == 0:
        continue
    else:
        j += i
print(j)
