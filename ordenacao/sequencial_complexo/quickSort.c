#include <stdio.h>
#include <stdlib.h>

// Definição de tamanho máximo
#define MAX 100

// Definição da estrutura da lista sequencial
struct lista_sequencial {
    int valores[MAX];
    int tamanho;
};

void inicializar(struct lista_sequencial *l) {
    l->tamanho = 0;
}

// Função de inserir valores
int inserir (struct lista_sequencial *l, int n) {
    if (l->tamanho < MAX) {
        l->valores[l->tamanho] = n;
        l->tamanho++;
        return 1;
    } else {
        return 0;
    }
}

// Função de exibir os valores
void exibir (struct lista_sequencial *l) {
    int i;
    for (i = 0; i < l->tamanho; i++) {
        printf("%d ", l->valores[i]);
    }
    printf("\n");
}

// Função auxiliar para fazer a partição da lista
int particao (struct lista_sequencial *l, int inicio, int fim) {
    int pivo = l->valores[fim]; // Escolhe o pivô como o elemento mais à direita
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (l->valores[j] < pivo) {
            i++;
            int temp = l->valores[i];
            l->valores[i] = l->valores[j];
            l->valores[j] = temp;
        }
    }

    int temp = l->valores[i + 1];
    l->valores[i + 1] = l->valores[fim];
    l->valores[fim] = temp;

    return i + 1;
}

// Função principal do Quick Sort
void quick_sort (struct lista_sequencial *l, int inicio, int fim) {
    if (inicio < fim) {
        int indice = particao(l, inicio, fim);  // Encontra o índice de partição
        quick_sort(l, inicio, indice - 1);  // Ordena a metade à esquerda do pivô
        quick_sort(l, indice + 1, fim);  // Ordena a metade à direita do pivô
    }
}

int main() {
    struct lista_sequencial lista;
    inicializar(&lista);

    // Inserir elementos na lista
    inserir(&lista, 5);
    inserir(&lista, 8);
    inserir(&lista, 3);
    inserir(&lista, 10);
    inserir(&lista, 1);

    printf("Lista antes do Quick Sort: ");
    exibir(&lista);

    quick_sort(&lista, 0, lista.tamanho - 1);

    printf("Lista após o Quick Sort: ");
    exibir(&lista);

    return 0;
}