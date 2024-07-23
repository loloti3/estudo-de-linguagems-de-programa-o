
lista_alunos=[]
while(True):
  
  print("Menu:\n1-inserir um novo aluno na lista.\n2-buscar um aluno na lista.\n3-exibir a lista de alunos em ordem alfabética\n4-remover um aluno da lista.\n5-para sair do programa.")
  resp=int(input("digite uma opcao do menu: "))
  if resp==1:
    nome=input("digite o nome do aluno: ")
    lista_alunos.append(nome)
  if resp==2:
    nome=input("digite o nome do aluno que deseja encontrar na lista: ")
    if nome in lista_alunos:
      print("O aluno",nome,"esta na lista")
    else:
      print("O aluno",nome,"não está na lista")
  if resp==3:
    lista_alunos.sort()
    lista_alfabetica = ' '.join(lista_alunos).replace('"', '').replace(',', '')
    print(lista_alfabetica)
  if resp==4:
     nome=input("digite o nome do aluno que deseja encontrar na lista: ")
     if nome in lista_alunos:
       lista_alunos.remove(nome)
       print("O aluno",nome,"foi removido da lista")
     else:
       print("O aluno",nome,"não está na lista")
  if resp==5:
    print("fim do progrma")
    break;
  if resp>5 or resp<=0:
    print("opção invalida digite outra opção do menu")