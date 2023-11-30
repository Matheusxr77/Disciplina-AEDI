#include <stdio.h>
#include <stdlib.h>

// Definição do tamanho máximo
#define MAX 100

// Definição da estrutura de lista sequencial
struct lista_sequencial {
    int valores[MAX];  // Array para armazenar os valores da lista
    int tamanho;       // Variável para armazenar o tamanho atual da lista
};

// Função para realizar a operação de merge em dois subarrays ordenados
void merge (struct lista_sequencial *l, int inicio, int meio, int fim) {
    int *temp;
    int i, j, k;
    int tamanho = fim - inicio + 1;

    temp = (int *)malloc(sizeof(int) * tamanho);

    // Mescla os dois subarrays ordenados
    for (i = inicio, j = meio + 1, k = 0; i <= meio && j <= fim; k++) {
        if (l->valores[i] < l->valores[j]) {
            temp[k] = l->valores[i];
            i++;
        } else {
            temp[k] = l->valores[j];
            j++;
        }
    }

    // Copia os elementos restantes do subarray esquerdo, se houver
    while (i <= meio) {
        temp[k] = l->valores[i];
        k++;
        i++;
    }

    // Copia os elementos restantes do subarray direito, se houver
    while (j <= fim) {
        temp[k] = l->valores[j];
        k++;
        j++;
    }

    // Copia os elementos ordenados de volta para o array original
    for (i = inicio, k = 0; k < tamanho; k++, i++) {
        l->valores[i] = temp[k];
    }

    // Libera a memória alocada para o array temporário
    free(temp);
}

// Função recursiva para realizar o Merge Sort
void merge_sort (struct lista_sequencial *l, int inicio, int fim) {
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;

        // Chama a função merge_sort recursivamente para os subarrays esquerdo e direito
        merge_sort(l, inicio, meio);
        merge_sort(l, meio + 1, fim);

        // Realiza a operação de merge para combinar os subarrays ordenados
        merge(l, inicio, meio, fim);
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

    // Impressão da lista antes de aplicar o Merge Sort
    printf("Lista antes do Merge Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função merge_sort para ordenar a lista
    merge_sort(&lista, 0, lista.tamanho - 1);

    // Impressão da lista após aplicar o Merge Sort
    printf("Lista após o Merge Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}