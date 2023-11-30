#include <stdio.h>

// definição de tamanho máximo da fila
#define MAX 100

// Definindo a estrutura para representar a lista
typedef struct {
    int elementos[MAX];
    int particao;
} lista;

// Função para remover o primeiro elemento da lista
void removerPrimeiroElemento (lista* l) {
    int i;

    if (l->particao == 0) {
        printf("A lista está vazia. Não é possível remover.\n");
        return;
    }

    // Desloca os elementos para a posição anterior
    for (i = 0; i < l->particao - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }

    // Atualiza o tamanho da lista
    l->particao--;
}

// Função auxiliar para imprimir a lista
void imprimirLista (lista l) {
    int i;
    for (i = 0; i < l.particao; i++) {
        printf("%d ", l.elementos[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    // Inicializando a lista
    lista l;
    l.particao = 5;
    l.elementos[0] = 2;
    l.elementos[1] = 5;
    l.elementos[2] = 8;
    l.elementos[3] = 3;
    l.elementos[4] = 10;

    // Imprimindo a lista antes da remoção
    printf("Lista antes da remoção: ");
    imprimirLista(l);

    // Chamando a função para remover o primeiro elemento
    removerPrimeiroElemento(&l);

    // Imprimindo a lista após a remoção
    printf("Lista após a remoção: ");
    imprimirLista(l);

    return 0;
}