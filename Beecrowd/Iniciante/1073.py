n = int(input())
if n%2 == 0:
    for i in range(2,n+1,2):
        print("{}^2 = {}".format(i,i*i))   
else:
    for i in range(2,n,2):
        print("{}^2 = {}".format(i,i*i))
