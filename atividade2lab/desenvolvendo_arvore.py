import tkinter as tk
from tkinter import messagebox

# Definição da classe No para representar os nós da árvore
class No:
    def __init__(self, chave):
        self.chave = chave
        self.esquerda = None
        self.direita = None

# Definição da classe ArvoreBuscaBinaria para representar a árvore de busca binária
class ArvoreBuscaBinaria:
    def __init__(self):
        self.raiz = None

    # Método para inserir um elemento na árvore
    def inserir(self, chave):
        self.raiz = self._inserir(self.raiz, chave)

    # Método auxiliar recursivo para a inserção
    def _inserir(self, no, chave):
        if no is None:
            return No(chave)
        if chave < no.chave:
            no.esquerda = self._inserir(no.esquerda, chave)
        elif chave > no.chave:
            no.direita = self._inserir(no.direita, chave)
        return no

    # Métodos para obter informações sobre a árvore
    def tamanho(self, no):
        if no is None:
            return 0
        return 1 + self.tamanho(no.esquerda) + self.tamanho(no.direita)

    def altura(self, no):
        if no is None:
            return 0
        return 1 + max(self.altura(no.esquerda), self.altura(no.direita))

    def encontrar_minimo(self, no):
        while no.esquerda is not None:
            no = no.esquerda
        return no.chave

    def encontrar_maximo(self, no):
        while no.direita is not None:
            no = no.direita
        return no.chave

    def comprimento_interno(self, no, profundidade=0):
        if no is None:
            return 0
        return profundidade + self.comprimento_interno(no.esquerda, profundidade + 1) + self.comprimento_interno(no.direita, profundidade + 1)

    def esta_balanceada(self, no):
        if no is None:
            return True
        altura_esquerda = self.altura(no.esquerda)
        altura_direita = self.altura(no.direita)
        return abs(altura_esquerda - altura_direita) <= 1 and self.esta_balanceada(no.esquerda) and self.esta_balanceada(no.direita)

    # Métodos para realizar travessias na árvore
    def travessia_em_ordem(self, no):
        resultado = []
        if no:
            resultado += self.travessia_em_ordem(no.esquerda)
            resultado.append(no.chave)
            resultado += self.travessia_em_ordem(no.direita)
        return resultado

    def travessia_pos_ordem(self, no):
        resultado = []
        if no:
            resultado += self.travessia_pos_ordem(no.esquerda)
            resultado += self.travessia_pos_ordem(no.direita)
            resultado.append(no.chave)
        return resultado

    def travessia_pre_ordem(self, no):
        resultado = []
        if no:
            resultado.append(no.chave)
            resultado += self.travessia_pre_ordem(no.esquerda)
            resultado += self.travessia_pre_ordem(no.direita)
        return resultado

    def travessia_largura(self, no):
        resultado = []
        fila = [no]
        while fila:
            atual = fila.pop(0)
            if atual:
                resultado.append(atual.chave)
                fila.append(atual.esquerda)
                fila.append(atual.direita)
        return resultado

# Definição da classe Aplicacao que cria a interface gráfica usando tkinter
class Aplicacao:
    def __init__(self, mestre):
        self.mestre = mestre
        self.mestre.title("Árvore de Busca Binária GUI")

        self.arvore = ArvoreBuscaBinaria()

        # Configuração de elementos da interface
        self.rotulo = tk.Label(mestre, text="Nome:")
        self.rotulo.pack()

        self.entrada = tk.Entry(mestre)
        self.entrada.pack()

        self.botao_inserir = tk.Button(
            mestre, text="Inserir", command=self.inserir)
        self.botao_inserir.pack()

        self.botao_info = tk.Button(
            mestre, text="Mostrar Informações", command=self.mostrar_info)
        self.botao_info.pack()

        self.botao_balanceada = tk.Button(
            mestre, text="Verificar Balanceamento", command=self.verificar_balanceamento)
        self.botao_balanceada.pack()

        self.botao_travessias = tk.Button(
            mestre, text="Travessias", command=self.mostrar_travessias)
        self.botao_travessias.pack()
        # Adiciona um evento para a tecla Enter na entrada (Entry) para facilitar a inserção e fica bem mais intuitivo
        self.entrada.bind('<Return>', lambda event: self.inserir())

    # Métodos de ação para os botões da interface
    def inserir(self):
        nome = self.entrada.get().strip()
        if nome:
            self.arvore.inserir(nome)
            messagebox.showinfo(
                "Inserção", f"{nome} inserido com sucesso na árvore!")
            self.entrada.delete(0, 'end')
        else:
            messagebox.showwarning("Inserção Inválida", "Por favor, insira um nome válido.")
            self.entrada.delete(0, 'end')

    def mostrar_info(self):
        tamanho = self.arvore.tamanho(self.arvore.raiz)
        altura = self.arvore.altura(self.arvore.raiz)
        min_elemento = self.arvore.encontrar_minimo(self.arvore.raiz)
        max_elemento = self.arvore.encontrar_maximo(self.arvore.raiz)
        comprimento_interno = self.arvore.comprimento_interno(self.arvore.raiz)

        info_str = f"Tamanho: {tamanho}\nAltura: {altura}\nMenor Elemento: {min_elemento}\nMaior Elemento: {max_elemento}\nComprimento Interno: {comprimento_interno}"
        messagebox.showinfo("Informações da Árvore", info_str)

    def verificar_balanceamento(self):
        esta_balanceada = self.arvore.esta_balanceada(self.arvore.raiz)
        if esta_balanceada:
            messagebox.showinfo("Balanceamento", "A árvore está balanceada!")
        else:
            messagebox.showinfo(
                "Balanceamento", "A árvore não está balanceada!")

    def mostrar_travessias(self):
        em_ordem = self.arvore.travessia_em_ordem(self.arvore.raiz)
        pos_ordem = self.arvore.travessia_pos_ordem(self.arvore.raiz)
        pre_ordem = self.arvore.travessia_pre_ordem(self.arvore.raiz)
        largura = self.arvore.travessia_largura(self.arvore.raiz)

        travessia_str = f"Em-ordem: {em_ordem}\n"
        travessia_str += f"Pós-ordem: {pos_ordem}\n"
        travessia_str += f"Pré-ordem: {pre_ordem}\n"
        travessia_str += f"Busca em Largura: {largura}"

        messagebox.showinfo("Travessias da Árvore", travessia_str)

# Verifica se o script está sendo executado como um programa principal
if __name__ == "__main__":
    # Cria a janela principal usando tkinter
    raiz = tk.Tk()
    # Cria uma instância da classe Aplicacao
    app = Aplicacao(raiz)
    # Inicia o loop principal do tkinter
    raiz.mainloop()
