#include <stdio.h>

// definição de tamanho máximo da lista
#define MAX 1000

// definição da estrutura da lista
typedef struct {
    int elementos[MAX];
    int tamanho;  // tamanho atual da lista
    int particao; // tamanho máximo permitido
} lista;

// inverte a posição dos elementos da lista
void inverterLista (lista* lista) {
    int i, j, temp, tamanho;
    tamanho = lista->tamanho;
    for (i = 0, j = tamanho - 1; i < j; i++, j--) {  // inverte a ordem dos elementos
        temp = lista->elementos[i];
        lista->elementos[i] = lista->elementos[j];
        lista->elementos[j] = temp;
    }
}

int main() {
    lista minhaLista;
    int i;

    minhaLista.particao = MAX;
    minhaLista.tamanho = 5; // Exemplo de tamanho atual da lista

    // Exemplo de preenchimento da lista
    for (i = 0; i < minhaLista.tamanho; i++) {
        minhaLista.elementos[i] = i + 1;
    }

    printf("Lista original: ");
    for (i = 0; i < minhaLista.tamanho; i++) {
        printf("%d ", minhaLista.elementos[i]);
    }

    inverterLista(&minhaLista);

    printf("\nLista invertida: ");
    for (i = 0; i < minhaLista.tamanho; i++) {
        printf("%d ", minhaLista.elementos[i]);
    }

    return 0;
}