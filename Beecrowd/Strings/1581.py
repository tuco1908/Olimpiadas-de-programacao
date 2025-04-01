n = int(input())
while n != 0:
    k = int(input())
    lista = []
    while k != 0:
        lista.append(str(input()))
        k -= 1
    conjunto = set(lista)
    if len(conjunto) == 1:
        for item in conjunto:
            print(item)
    else:
        print("ingles")
    n -= 1
