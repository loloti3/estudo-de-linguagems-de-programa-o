num=int(input("Digite um numero: "))
soma=0
for i in range (num):
  if i%2!=0 :
    soma=soma+i

print("A soma dos numero impares de 1 ate",num,'=',soma)