
rota = []

while True:
    print("\nOpções:")
    print("1 - Adicionar um novo ponto GPS à rota")
    print("2 - Remover um ponto GPS da rota")
    print("3 - Exibir a rota atual")
    print("4 - Sair do programa")

    opcao = input("Digite a opção desejada: ")

    if opcao == "1":
        latitude = float(input("Digite a latitude: "))
        longitude = float(input("Digite a longitude: "))
        ponto_gps = (latitude, longitude)

        if ponto_gps in rota:
            print("Este ponto GPS já está na rota.")
        else:
          rota.append(ponto_gps)
          print("Ponto GPS adicionado à rota.")
    if opcao == "2":
        if len(rota) > 0:
            latitude = float(input("Digite a latitude do ponto a ser removido: "))
            longitude = float(input("Digite a longitude do ponto a ser removido: "))
            ponto_removido = None

            for ponto in rota:
                if ponto[0] == latitude and ponto[1] == longitude:
                    ponto_removido = ponto
                    break

            if ponto_removido:
                rota.remove(ponto_removido)
                print(f"Ponto GPS removido da rota: Latitude {latitude}, Longitude {longitude}")
            else:
                print("Ponto GPS não encontrado na rota.")
        else:
            print("A rota está vazia. Nada para remover.")

 
    if  opcao == "3":
        if len(rota) > 0:
            print("Rota atual:")
            for i, ponto in enumerate(rota):
                print(f"{i + 1}: Latitude {ponto[0]}, Longitude {ponto[1]}")
        else:
            print("A rota está vazia.")

    if opcao == "4":
        print("Programa encerrado.")
        break

    elif opcao>"4" or opcao<"1" :
        print("Opção inválida. Por favor, escolha outra opção valida")
