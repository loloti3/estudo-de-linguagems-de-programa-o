num=int(input("Digite um numero: "))
print("sequencia de Fibonacci ate",num,)
b=0
a=1
while b<num: 
  anterior=b
  b=b+a
  a=anterior
  if b<num:
    print(b)