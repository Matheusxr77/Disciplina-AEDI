#include <stdio.h>
#include <stdlib.h>

// Definição de tamanho máximo
#define MAX 100

// Definição da estrutura da lista sequencial
struct lista_sequencial {
    int valores[MAX];
    int tamanho;
};

// Função de inicializar uma lista vazia
void inicializar (struct lista_sequencial *l) {
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

// Função auxiliar para realizar a fusão de duas partes ordenadas de uma lista
void merge (struct lista_sequencial *l, int inicio, int meio, int fim) {
    int *temp;
    int i, j, k;
    int tamanho = fim - inicio + 1;
    temp = (int *)malloc(sizeof(int) * tamanho);

    for (i = inicio, j = meio + 1, k = 0; i <= meio && j <= fim; k++) {
        if (l->valores[i] < l->valores[j]) {
            temp[k] = l->valores[i];
            i++;
        } else {
            temp[k] = l->valores[j];
            j++;
        }
    }

    while (i <= meio) {
        temp[k] = l->valores[i];
        k++;
        i++;
    }

    while (j <= fim) {
        temp[k] = l->valores[j];
        k++;
        j++;
    }

    for (i = inicio, k = 0; k < tamanho; k++, i++) {
        l->valores[i] = temp[k];
    }

    free(temp);
}

// Função principal do Merge Sort
void merge_sort (struct lista_sequencial *l, int inicio, int fim) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        merge_sort(l, inicio, meio);  // Ordena a metade esquerda
        merge_sort(l, meio + 1, fim);  // Ordena a metade direita
        merge(l, inicio, meio, fim);  // Combina as duas metades ordenadas
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

    printf("Lista antes do Merge Sort: ");
    exibir(&lista);

    merge_sort(&lista, 0, lista.tamanho - 1);

    printf("Lista após o Merge Sort: ");
    exibir(&lista);

    return 0;
}