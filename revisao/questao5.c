#include <stdio.h>
#include <string.h>
#include <math.h>

// Definindo a estrutura para representar uma cidade
struct cidade {
    char nome[81];
    int x;
    int y;
};

// Definindo a estrutura para representar um nó na lista encadeada
struct no {
    struct cidade dado;
    struct no* proximo;
};

// Definindo a estrutura para representar uma lista encadeada de cidades
struct le_cidade {
    struct no* inicio;
};

// Função para imprimir a cidade mais próxima ao ponto (0,0)
void imprimirCidadeMaisProxima (struct le_cidade lista) {
    if (lista.inicio == NULL) {
        printf("Lista de cidades vazia.\n");
        return;
    }

    // Inicializando a menor distância com a distância da primeira cidade
    double menorDistancia = sqrt(pow(lista.inicio->dado.x, 2) + pow(lista.inicio->dado.y, 2));
    struct no* temp = lista.inicio;
    struct cidade cidadeMaisProxima = temp->dado;

    // Percorrendo a lista para encontrar a cidade mais próxima
    while (temp != NULL) {
        double distancia = sqrt(pow(temp->dado.x, 2) + pow(temp->dado.y, 2));
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            cidadeMaisProxima = temp->dado;
        }
        temp = temp->proximo;
    }

    // Imprimindo a cidade mais próxima
    printf("Cidade mais próxima: %s\n", cidadeMaisProxima.nome);
}

// Função principal
int main() {
    // Criando cidades
    struct cidade cidadeA = {"Cidade A", 2, 3};
    struct cidade cidadeB = {"Cidade B", 4, -1};
    struct cidade cidadeC = {"Cidade C", -3, 5};
    struct cidade cidadeD = {"Cidade D", 1, 1};

    // Criando nós para as cidades
    struct no noA = {cidadeA, NULL};
    struct no noB = {cidadeB, NULL};
    struct no noC = {cidadeC, NULL};
    struct no noD = {cidadeD, NULL};

    // Criando lista encadeada e conectando os nós
    struct le_cidade lista = {&noA};
    noA.proximo = &noB;
    noB.proximo = &noC;
    noC.proximo = &noD;
    noD.proximo = NULL;

    // Chamando a função para imprimir a cidade mais próxima
    imprimirCidadeMaisProxima(lista);

    return 0;
}