for _ in range(int(input())):
    x = str(input())
    tamanho = len(x)//2 -1
    z = x[tamanho::-1] + x[(tamanho+1)*2:tamanho:-1]
    print(z)
