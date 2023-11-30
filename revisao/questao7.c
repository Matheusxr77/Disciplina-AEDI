#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura para representar um nó na lista encadeada
struct no {
    int dado;
    struct no* proximo;
};

// Função para calcular a soma dos primeiros n elementos de uma lista encadeada
int somaPrimeirosElementos (struct no* inicio, int n) {
    struct no* temp = inicio;
    int soma = 0;
    int contador = 0;

    // Percorre a lista e soma os primeiros n elementos
    while (temp != NULL && contador < n) {
        soma += temp->dado;
        temp = temp->proximo;
        contador++;
    }

    // Verifica se n é maior que o tamanho da lista
    if (contador < n) {
        return -1;
    }

    return soma;
}

// Função auxiliar para inserir um novo elemento no início da lista
struct no* inserirElemento (struct no* inicio, int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->dado = valor;
    novoNo->proximo = inicio;
    return novoNo;
}

// Função auxiliar para imprimir a lista
void imprimirLista (struct no* inicio) {
    struct no* temp = inicio;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

// Função principal
int main() {
    // Criação da lista encadeada
    struct no* lista = NULL;
    int n;

    lista = inserirElemento(lista, 5);
    lista = inserirElemento(lista, 8);
    lista = inserirElemento(lista, 2);
    lista = inserirElemento(lista, 3);
    lista = inserirElemento(lista, 10);

    n = 3;
    printf("Lista: ");
    imprimirLista(lista);
    printf("Soma dos primeiros %d elementos: %d\n", n, somaPrimeirosElementos(lista, n));

    n = 6;
    printf("Lista: ");
    imprimirLista(lista);
    printf("Soma dos primeiros %d elementos: %d\n", n, somaPrimeirosElementos(lista, n));

    // Liberar a memória alocada para a lista
    struct no* temp = lista;
    while (temp != NULL) {
        struct no* proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }

    return 0;
}