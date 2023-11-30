#include <stdio.h>

// Definição do tamanho máximo
#define MAX 100

// Definição da estrutura de lista sequencial
struct lista_sequencial {
    int valores[MAX];  // Array para armazenar os valores da lista
    int tamanho;       // Variável para armazenar o tamanho atual da lista
};

// Função para realizar a operação de partição no Quick Sort
int particao (struct lista_sequencial *l, int inicio, int fim) {
    int pivô = l->valores[fim];  // Escolhe o último elemento como pivô
    int i = inicio - 1;           // Inicializa o índice do menor elemento

    // Loop para percorrer os elementos e rearranjá-los em relação ao pivô
    for (int j = inicio; j <= fim - 1; j++) {
        if (l->valores[j] < pivô) {
            i++;
            // Troca os elementos menores que o pivô com o elemento na posição i
            int temp = l->valores[i];
            l->valores[i] = l->valores[j];
            l->valores[j] = temp;
        }
    }

    // Troca o pivô com o elemento na posição (i + 1)
    int temp = l->valores[i + 1];
    l->valores[i + 1] = l->valores[fim];
    l->valores[fim] = temp;

    // Retorna a posição do pivô após a partição
    return i + 1;
}

// Função recursiva para realizar o Quick Sort
void quick_sort (struct lista_sequencial *l, int inicio, int fim) {
    int pi;

    if (inicio < fim) {
        // Obtém a posição do pivô após a partição
        pi = particao(l, inicio, fim);

        // Chama a função quick_sort recursivamente para os subarrays esquerdo e direito do pivô
        quick_sort(l, inicio, pi - 1);
        quick_sort(l, pi + 1, fim);
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

    // Impressão da lista antes de aplicar o Quick Sort
    printf("Lista antes do Quick Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função quick_sort para ordenar a lista
    quick_sort(&lista, 0, lista.tamanho - 1);

    // Impressão da lista após aplicar o Quick Sort
    printf("Lista após o Quick Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}