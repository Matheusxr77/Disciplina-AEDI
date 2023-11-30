#include <stdio.h>

// Definição de tamanho máximo
#define MAX 100

// Definição de uma estrutura para representar uma lista sequencial
struct lista_sequencial {
    int valores[MAX];  // Array para armazenar os valores da lista
    int tamanho;       // Variável para armazenar o tamanho atual da lista
};

// Função para ordenar uma lista usando o algoritmo Bubble Sort
void bubble_sort (struct lista_sequencial *l) {
    int n = l->tamanho;  // Número de elementos na lista
    int i, j, troca;     // Variáveis de controle para loops e trocas

    // Loop externo para percorrer a lista
    for (i = 0; i < n - 1; i++) {
        troca = 0;  // Variável para rastrear se houve trocas nesta iteração

        // Loop interno para comparar elementos adjacentes e trocá-los se estiverem fora de ordem
        for (j = 0; j < n - i - 1; j++) {
            if (l->valores[j] > l->valores[j + 1]) {
                // Troca de elementos usando uma variável temporária
                int temp = l->valores[j];
                l->valores[j] = l->valores[j + 1];
                l->valores[j + 1] = temp;
                troca = 1;  // Indica que uma troca ocorreu nesta iteração
            }
        }

        // Se nenhuma troca foi feita, a lista está ordenada e podemos interromper o loop externo
        if (!troca) {
            break;
        }
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

    // Impressão da lista antes de aplicar o Bubble Sort
    printf("Lista antes do Bubble Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função bubble_sort para ordenar a lista
    bubble_sort(&lista);

    // Impressão da lista após aplicar o Bubble Sort
    printf("Lista após o Bubble Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}