#include <stdio.h>

// Definição de tamanho máximo
#define MAX 100

// Estrutura da lista sequencial
struct lista_sequencial {
    int valores[MAX];
    int tamanho;
};

// Funções auxiliares
int pai (int n) {
    if (n > 0) {
       return (n - 1) / 2; 
    } else {
        return -1;
    }
}

// Função de trocar a posição dos valores
void trocar (struct lista_sequencial *l, int i, int j) {
    int temp = l->valores[i];
    l->valores[i] = l->valores[j];
    l->valores[j] = temp;
}

// Função para reorganizar o heap
void re_heap (struct lista_sequencial *l, int i, int limite) {
    while (i <= limite) {
        int filho_esq = 2 * i + 1;
        int filho_dir = 2 * i + 2;
        int maior_filho = filho_esq; // Supomos inicialmente que o filho esquerdo é o maior

        if (filho_esq > limite) // Verifica se o filho esquerdo está dentro dos limites
            return;

        if (filho_dir <= limite && l->valores[filho_dir] > l->valores[filho_esq])
            maior_filho = filho_dir;

        if (l->valores[maior_filho] > l->valores[i]) {
            trocar(l, i, maior_filho);
            i = maior_filho;
        } else {
            return;
        }
    }
}

// Função para transformar a lista em um heap
void heapify (struct lista_sequencial *l) {
    int i, p, j;
    for (i = 1; i < l->tamanho; i++) {
        for (j = i; j > 0; j = pai(j)) {
            p = pai(j);
            if (l->valores[j] > l->valores[p]) {
                trocar(l, j, p); 
            } else {
                break;
            }
        }
    }
}

// Função principal do HeapSort
void heap_sort (struct lista_sequencial *l) {
    int i;
    
    // Primeira parte do algoritmo: transformar a lista em um heap
    heapify(l);

    // Sequência de trocas e reorganizações para ordenar
    for (i = l->tamanho - 1; i > 0; i--) {
        trocar(l, 0, i);
        re_heap(l, 0, i - 1);
    }
}

int main() {
    // Exemplo de uso
    struct lista_sequencial lista;
    inicializar(&lista);
    inserir(&lista, 4);
    inserir(&lista, 10);
    inserir(&lista, 2);
    inserir(&lista, 8);
    inserir(&lista, 6);

    printf("Lista antes do HeapSort: ");
    exibir(&lista);

    heap_sort(&lista);

    printf("Lista após o HeapSort: ");
    exibir(&lista);

    return 0;
}