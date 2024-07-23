dicionario_pessoas = {}

def encontrar_pessoa(cod):
    if cod in dicionario_pessoas:
        print(dicionario_pessoas[cod])
    else:
        return 0

def encontrar_telefone(telefone):
  for dados in dicionario_pessoas.values():
      if telefone in dados[1]:
          print(f"Pessoa encontrada com o telefone {telefone}: {dados}")
          return
  print(f"Nenhuma pessoa encontrada com o telefone {telefone}.")
  
def ler_pessoa():
    cpf = str(input("Qual seu CPF? "))
    resultado = encontrar_pessoa(cpf)
    if resultado != 0:
        print('CPF já cadastrado, não podemos prosseguir :(')
        return 0
    else:
        nome = str(input("Qual seu nome? "))
        numeros = str(input("Digite 2 números de telefone separados por vírgula: "))
        numeros = numeros.split(',')
        pessoa = (cpf, nome, numeros)
        return pessoa

def inserir_pessoa(people): 
    chave = people[0]
    dados_pessoa = (people[1], people[2])
    dicionario_pessoas[chave] = dados_pessoa
    print("Pessoa inserida com sucesso!")

def listar_pessoas():
    for item in dicionario_pessoas.items():
        print(item)

def remover_pessoa(cod):
    if cod in dicionario_pessoas:
        print(dicionario_pessoas.pop(cod), "foi removida")
    else:
        print("CPF não encontrado :(")

def meu_menu():
    print("1. Inserir pessoa")
    print("2. Listar pessoas cadastradas")
    print("3. Encontrar pessoa pelo CPF")
    print("4. Encontrar pessoa pelo telefone")
    print("5. Remover pessoa pelo CPF")
    print("6. Sair")

aluno_temp = None
while True:
    meu_menu()
    opcao = input("Qual sua opção? ")
    if opcao == '1':
        pessoa_temp = ler_pessoa()
        if pessoa_temp!=0:
          inserir_pessoa(pessoa_temp)
    elif opcao == '2':
        listar_pessoas()
    elif opcao == '3':
        cpf = str(input("Digite o CPF: "))
        encontrar_pessoa(cpf)
    elif opcao == '4':
        telefone = str(input("Digite o telefone: "))
        encontrar_telefone(telefone)
    elif opcao == '5':
        cpf = str(input("Digite o CPF para remover: "))
        remover_pessoa(cpf)
    elif opcao == '6':
        break
    else:
        print("Opção inválida. Tente novamente.")

