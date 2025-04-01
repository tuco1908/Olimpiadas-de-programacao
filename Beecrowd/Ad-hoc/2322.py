n = int(input())
conjunto = {int(i) for i in input().split()}
for item in range(1, n+1):
    if item not in conjunto: print(item)
