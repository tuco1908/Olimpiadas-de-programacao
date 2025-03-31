n, q = [int(i) for i in input().split()]
matriz = [[0 for j in range(n+2)] for i in range(n+2)]
for x in range(1, n+1):
    string = str(input())
    for y in range(1, n+1):
        if string[y-1] == "1":
            matriz[x][y] = 1

x = [[0 for j in range(n+2)] for i in range(n+2)]
for i in range(1, n+1):
    for j in range(1, n+1):
        if matriz[i][j] == 1:
            x[i][j] = 1

for _ in range(q):
    for i in range(1, n+1):
        for j in range(1, n+1):
            vizinhas = 0
            celula = 0
            celula += matriz[i][j]
            vizinhas += matriz[i-1][j-1]
            vizinhas += matriz[i-1][j]
            vizinhas += matriz[i-1][j+1]
            vizinhas += matriz[i][j-1]
            vizinhas += matriz[i][j+1]
            vizinhas += matriz[i+1][j-1]
            vizinhas += matriz[i+1][j]
            vizinhas += matriz[i+1][j+1]

            if celula == 1:
                if vizinhas < 2 or vizinhas > 3:
                    x[i][j] = 0
            else:
                if vizinhas == 3:
                    x[i][j] = 1
                    
    matriz = [[0 for j in range(n+2)] for i in range(n+2)]
    for i in range(1, n+1):
        for j in range(1, n+1):
            if x[i][j] == 1:
                matriz[i][j] = 1
                
for i in range(1, n+1):
    for j in range(1, n+1):
        print(x[i][j], end="")
    print()
