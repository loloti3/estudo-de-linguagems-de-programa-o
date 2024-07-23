
conjunto1 = set()
conjunto2 = set()
conjunto3 = set()

conjunto1.update({"vermelho", "azul", "verde", "amarelo"})
conjunto2.update({"azul", "roxo", "verde", "laranja"})
conjunto3.update({"vermelho", "roxo", "amarelo", "branco"})
print("Os conjuntos são:")
print("Conjunto 1:",conjunto1)
print("Conjunto 2:",conjunto2)
print("Conjunto 3:",conjunto3)
while True:
    print("\nOpções:")
    print("1 - Realizar a união entre dois conjuntos de cores.")
    print("2 - Realizar a interseção entre dois conjuntos de cores.")
    print("3 - Realizar a diferença entre dois conjuntos de cores.")
    print("4 - Sair do programa")

    opcao = input("Digite a opção desejada: ")

    if opcao == "1":
        conjunto_selecionado1 = int(input("Digite o número do primeiro conjunto (1, 2, 3): "))
        conjunto_selecionado2 = int(input("Digite o número do segundo conjunto (1, 2, 3): "))

        if 1 <= conjunto_selecionado1 <= 3 and 1 <= conjunto_selecionado2 <= 3:
            resultado_uniao = eval(f"conjunto{conjunto_selecionado1} | conjunto{conjunto_selecionado2}")
            print(f"Resultado da união: {resultado_uniao}")
        else:
            print("Conjunto inválido.")

    elif opcao == "2":
        conjunto_selecionado1 = int(input("Digite o número do primeiro conjunto (1, 2, 3): "))
        conjunto_selecionado2 = int(input("Digite o número do segundo conjunto (1, 2, 3): "))

        if 1 <= conjunto_selecionado1 <= 3 and 1 <= conjunto_selecionado2 <= 3:
            resultado_intersecao = eval(f"conjunto{conjunto_selecionado1} & conjunto{conjunto_selecionado2}")
            print(f"Resultado da interseção: {resultado_intersecao}")
        else:
            print("Conjunto inválido.")

    elif opcao == "3":
  
        conjunto_selecionado1 = int(input("Digite o número do primeiro conjunto (1, 2, 3): "))
        conjunto_selecionado2 = int(input("Digite o número do segundo conjunto (1, 2, 3): "))

        if 1 <= conjunto_selecionado1 <= 3 and 1 <= conjunto_selecionado2 <= 3:
            resultado_diferenca = eval(f"conjunto{conjunto_selecionado1} - conjunto{conjunto_selecionado2}")
            print(f"Resultado da diferença: {resultado_diferenca}")
        else:
            print("Conjunto inválido.")

    elif opcao == "4":
        # Digitar '4' para sair do programa.
        print("Programa encerrado.")
        break

    else:
        print("Opção inválida. Por favor, escolha uma opção válida.")
