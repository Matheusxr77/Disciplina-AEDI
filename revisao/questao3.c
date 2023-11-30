#include <stdio.h>
#include <string.h>

// Definindo a estrutura para representar uma cidade
struct cidade {
    char nome[81];
    int x;
    int y;
};

// Definindo a estrutura para representar uma lista de cidades
struct ls_cidade {
    struct cidade elementos[500];
    int particao;
};

// Função para imprimir as cidades localizadas no primeiro quadrante
void imprimirCidadesPrimeiroQuadrante (struct ls_cidade lista) {
    int i;
    for (i = 0; i < lista.particao; i++) {
        struct cidade cidadeAtual = lista.elementos[i];
        if (cidadeAtual.x > 0 && cidadeAtual.y > 0) {
            printf("%s\n", cidadeAtual.nome);
        }
    }
}

// Função principal
int main() {
    struct ls_cidade lista;
    lista.particao = 4;

    // Preenchendo a lista de cidades
    strcpy(lista.elementos[0].nome, "Cidade A");
    lista.elementos[0].x = 2;
    lista.elementos[0].y = 3;

    strcpy(lista.elementos[1].nome, "Cidade B");
    lista.elementos[1].x = 4;
    lista.elementos[1].y = -1;

    strcpy(lista.elementos[2].nome, "Cidade C");
    lista.elementos[2].x = -3;
    lista.elementos[2].y = 5;

    strcpy(lista.elementos[3].nome, "Cidade D");
    lista.elementos[3].x = 1;
    lista.elementos[3].y = 1;

    // Imprimindo as cidades localizadas no primeiro quadrante
    printf("Cidades localizadas no primeiro quadrante:\n");
    imprimirCidadesPrimeiroQuadrante(lista);

    return 0;
}