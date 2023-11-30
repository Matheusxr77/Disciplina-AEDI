#include <stdio.h>

// Definição do tamanho máximo
#define MAX 100

// Definição da estrutura de lista sequencial
struct lista_sequencial {
    int valores[MAX];  // Array para armazenar os valores da lista
    int tamanho;       // Variável para armazenar o tamanho atual da lista
};

// Função para ordenar a lista usando o algoritmo Selection Sort
void selection_sort(struct lista_sequencial *l) {
    int i, j, temp, indice_minimo;
    int n = l->tamanho;

    // Loop para percorrer a lista
    for (i = 0; i < n - 1; i++) {
        indice_minimo = i;

        // Encontra o índice do menor elemento na parte não ordenada
        for (j = i + 1; j < n; j++) {
            if (l->valores[j] < l->valores[indice_minimo]) {
                indice_minimo = j;
            }
        }

        // Troca o elemento mínimo com o elemento na posição atual
        temp = l->valores[i];
        l->valores[i] = l->valores[indice_minimo];
        l->valores[indice_minimo] = temp;
    }
}

int main() {
    // Inicialização de uma lista com valores desordenados
    struct lista_sequencial lista;
    int i;

    lista.tamanho = 5;
    lista.valores[0] = 5;
    lista.valores[1] = 8;
    lista.valores[2] = 3;
    lista.valores[3] = 10;
    lista.valores[4] = 1;

    // Impressão da lista antes de aplicar o Selection Sort
    printf("Lista antes do Selection Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função selection_sort para ordenar a lista
    selection_sort(&lista);

    // Impressão da lista após aplicar o Selection Sort
    printf("Lista após o Selection Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}