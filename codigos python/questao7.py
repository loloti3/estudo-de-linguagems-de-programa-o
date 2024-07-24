frase=str(input("Digite uma frase: ")).split()
frase.reverse()
frase_invertida = ' '.join(frase).replace('"', '').replace(',', '')
print(frase_invertida)
