vetor = input().split()
a = int(vetor[0])
b = int(vetor[1])
c = int(vetor[2])
maiorab = (a+b+abs(a-b))/2
maiorc = (maiorab + c + abs(maiorab-c))/2
print("%.i eh o maior"%maiorc)
