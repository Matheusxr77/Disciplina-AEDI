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

// Função para inserir uma nova cidade na primeira posição da lista
void inserirCidadePrimeiraPosicao (struct ls_cidade* lista, struct cidade novaCidade) {
    int i;
    for (i = lista->particao - 1; i >= 0; i--) {
        lista->elementos[i + 1] = lista->elementos[i];  // Desloca os elementos para abrir espaço
    }
    lista->elementos[0] = novaCidade;  // Insere a nova cidade na primeira posição
    lista->particao++;  // Incrementa o número de elementos na lista
}

// Função principal
int main() {
    struct ls_cidade lista;
    lista.particao = 3;

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

    // Imprimindo a lista de cidades antes da inserção
    printf("Lista de cidades antes da inserção:\n");
    int i;
    for (i = 0; i < lista.particao; i++) {
        printf("%s\n", lista.elementos[i].nome);
    }

    // Criando uma nova cidade para inserção
    struct cidade novaCidade;
    strcpy(novaCidade.nome, "Cidade D");
    novaCidade.x = 1;
    novaCidade.y = 1;

    // Chamando a função para inserir a nova cidade na primeira posição
    inserirCidadePrimeiraPosicao(&lista, novaCidade);

    // Imprimindo a lista de cidades após a inserção
    printf("\nLista de cidades após a inserção:\n");
    for (i = 0; i < lista.particao; i++) {
        printf("%s\n", lista.elementos[i].nome);
    }

    return 0;
}