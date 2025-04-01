vetor = input().split()
a = float(vetor[0])
b = float(vetor[1])
c = float(vetor[2])
r1 = (a*c)/2
r2 = 3.14159*c**2
r3 = ((a+b)*c)/2
r4 = b*b
r5 = a*b
print("TRIANGULO: %.3f"%r1)
print("CIRCULO: %.3f"%r2)
print("TRAPEZIO: %.3f"%r3)
print("QUADRADO: %.3f"%r4)
print("RETANGULO: %.3f"%r5)
