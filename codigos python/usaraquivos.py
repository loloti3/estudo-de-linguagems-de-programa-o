def ler_arquivo():
  try:
      with open('pessoas.txt', 'r') as arquivo:
          return [linha.strip().split(';') for linha in arquivo]
  except FileNotFoundError:
      return []

def escrever_arquivo(pessoas):
  with open('pessoas.txt', 'w') as arquivo:
      for pessoa in pessoas:
          arquivo.write(';'.join(pessoa) + '\n')

def inserir_pessoa():
  pessoas = ler_arquivo()
  cpf = input("Informe o CPF da pessoa: ")
  for pessoa in pessoas:
      if pessoa[0] == cpf:
          print("CPF já cadastrado. Não é possível inserir a pessoa.")
          return

  nome = input("Informe o nome da pessoa: ")
  endereco = input("Informe o endereço da pessoa: ")
  telefones = input("Informe os telefones (separados por vírgula): ")

  nova_pessoa = [cpf, nome, endereco, telefones]
  pessoas.append(nova_pessoa)

  escrever_arquivo(pessoas)
  print("Pessoa inserida com sucesso!")

def listar_pessoas():
  pessoas = ler_arquivo()
  if not pessoas:
      print("Nenhuma pessoa cadastrada.")
  else:
      for pessoa in pessoas:
          print("\nCPF:", pessoa[0])
          print("Nome:", pessoa[1])
          print("Endereço:", pessoa[2])
          print("Telefones:", pessoa[3])

def buscar_pessoa_por_cpf():
  pessoas = ler_arquivo()
  cpf = input("Informe o CPF da pessoa a ser buscada: ")

  for pessoa in pessoas:
      if pessoa[0] == cpf:
          print("\nCPF:", pessoa[0])
          print("Nome:", pessoa[1])
          print("Endereço:", pessoa[2])
          print("Telefones:", pessoa[3])
          return

  print("Pessoa não encontrada.")

def buscar_pessoa_por_telefone():
  pessoas = ler_arquivo()
  telefone = input("Informe o telefone da pessoa a ser buscada: ")

  for pessoa in pessoas:
      if telefone in pessoa[3]:
          print("\nCPF:", pessoa[0])
          print("Nome:", pessoa[1])
          print("Endereço:", pessoa[2])
          print("Telefones:", pessoa[3])
          return

  print("Pessoa não encontrada.")

def remover_pessoa_por_cpf():
  pessoas = ler_arquivo()
  cpf = input("Informe o CPF da pessoa a ser removida: ")

  for pessoa in pessoas:
      if pessoa[0] == cpf:
          pessoas.remove(pessoa)
          escrever_arquivo(pessoas)
          print("Pessoa removida com sucesso!")
          return

  print("Pessoa não encontrada.")

def main():
  while True:
      print("\nMenu:")
      print("1. Inserir pessoa")
      print("2. Listar pessoas cadastradas")
      print("3. Buscar pessoa por CPF")
      print("4. Buscar pessoa por Telefone")
      print("5. Remover pessoa por CPF")
      print("6. Sair")

      opcao = input("Escolha uma opção (1-6): ")

      if opcao == '1':
          inserir_pessoa()
      elif opcao == '2':
          listar_pessoas()
      elif opcao == '3':
          buscar_pessoa_por_cpf()
      elif opcao == '4':
          buscar_pessoa_por_telefone()
      elif opcao == '5':
          remover_pessoa_por_cpf()
      elif opcao == '6':
          print("Saindo do programa. Até mais!")
          break
      else:
          print("Opção inválida. Por favor, escolha uma opção válida.")

if __name__ == "__main__":
  main()
