numero = int(input("Digite um número para calcular o fatorial: "))
fatorial=0
if numero < 0:
    print( "O fatorial não está definido para números negativos")
    fatorial=-1
elif numero == 0:
    fatorial=1
else:
  fatorial = 1
  for i in range(1, numero + 1):
    fatorial *= i

if fatorial>=1:
    print(f"O fatorial de {numero} é {fatorial}")