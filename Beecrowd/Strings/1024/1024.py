# -*- coding: utf-8 -*-
def desloca (copia2):
    copia3 = []
    for j in range((len(copia2)//2)):
        copia3.append(copia2[j])
    for i in range((len(copia2)//2), len(copia2)):
        copia3.append(chr(ord(copia2[i]) - 1))
    resp = ''.join(copia3)
    return resp

def inverte (copia1):
    copia2 = []
    for i in range(len(copia1)-1, -1, -1):
        copia2.append(copia1[i])
    return desloca(copia2)

def primeira (string):
    copia1 = []
    for j in range(len(string)):
        if (string[j] >= "A" and string[j] <= "Z") or (string[j] >= 'a' and string[j] <= 'z'):
            copia1.append(chr(ord(string[j]) + 3))
        else:
            copia1.append(string[j])
    return inverte(copia1)

n = int(input())
x = 0
vetor = []
while x != n:
    palavra = vetor.append(str(input()))
    string = vetor[x]
    print(primeira(string))
    x += 1
