#include <stdio.h>

// Definição de tamanho máximo
#define MAX 100

// Definição da estrutura de lista sequencial
struct lista_sequencial {
    int valores[MAX];
    int tamanho;
};

// Função para transformar a árvore com raiz em "i" em um heap máximo
void heapify (struct lista_sequencial *l, int n, int i) {
    int maior = i;          // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1;   // Índice da subárvore esquerda
    int direita = 2 * i + 2;    // Índice da subárvore direita

    // Verifica se o filho esquerdo é maior que a raiz
    if (esquerda < n && l->valores[esquerda] > l->valores[maior]) {
        maior = esquerda;
    }

    // Verifica se o filho direito é maior que a raiz ou o filho esquerdo
    if (direita < n && l->valores[direita] > l->valores[maior]) {
        maior = direita;
    }

    // Se o maior não é a raiz, troca a raiz com o maior e chama a função recursivamente
    if (maior != i) {
        int temp = l->valores[i];
        l->valores[i] = l->valores[maior];
        l->valores[maior] = temp;

        heapify(l, n, maior);
    }
}

// Função para realizar o heap sort na lista
void heap_sort (struct lista_sequencial *l) {
    int n = l->tamanho;
    int i, temp;

    // Construir um heap máximo
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(l, n, i);
    }

    // Extrair elementos do heap um por um
    for (i = n - 1; i > 0; i--) {
        // Troca o elemento raiz (maior elemento) com o último elemento
        temp = l->valores[0];
        l->valores[0] = l->valores[i];
        l->valores[i] = temp;

        // Chama heapify na subárvore reduzida
        heapify(l, i, 0);
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

    // Impressão da lista antes de aplicar o Heap Sort
    printf("Lista antes do Heap Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    // Chamada da função heap_sort para ordenar a lista
    heap_sort(&lista);

    // Impressão da lista após aplicar o Heap Sort
    printf("Lista após o Heap Sort: ");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.valores[i]);
    }
    printf("\n");

    return 0;
}