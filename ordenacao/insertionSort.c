#include <stdio.h>

// Definição do tamanho máximo
#define MAX 100

// Definição da estrutura de lista sequencial
struct lista_sequencial {
    int valores[MAX];  // Array para armazenar os valores da lista
    int tamanho;       // Variável para armazenar o tamanho atual da lista
};

// Função para ordenar a lista usando o algoritmo Insertion Sort
void insertion_sort (struct lista_sequencial *l) {
    int n = l->tamanho;
    int i, j, chave;

    // Loop para percorrer os elementos da lista a partir do segundo elemento
    for (i = 1; i < n; i++) {
        chave = l->valores[i];  // Elemento atual sendo comparado
        j = i - 1;

        // Loop para mover os elementos maiores que a chave para frente
        // e abrir espaço para inserir a chave na posição correta
        while (j >= 0 && l->valores[j] > chave) {
            l->valores[j + 1] = l->valores[j];
            j--;
        }

        // Inserção da chave na posição correta
        l->valores[j + 1] = chave;
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

    // Impressão da lista antes de aplicar o Insertion Sort
    printf("Lista antes do Insertion Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função insertion_sort para ordenar a lista
    insertion_sort(&lista);

    // Impressão da lista após aplicar o Insertion Sort
    printf("Lista após o Insertion Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}