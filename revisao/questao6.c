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

// Função para calcular a distância entre duas cidades
double calcularDistanciaEntreCidades (struct le_cidade lista, char cidade1[], char cidade2[]) {
    struct cidade cidadeA, cidadeB;
    int encontrouCidade1 = 0, encontrouCidade2 = 0;

    // Procura pelas cidades na lista encadeada
    struct no* temp = lista.inicio;
    while (temp != NULL) {
        if (strcmp(temp->dado.nome, cidade1) == 0) {
            cidadeA = temp->dado;
            encontrouCidade1 = 1;
        }
        if (strcmp(temp->dado.nome, cidade2) == 0) {
            cidadeB = temp->dado;
            encontrouCidade2 = 1;
        }

        temp = temp->proximo;

        if (encontrouCidade1 && encontrouCidade2) {
            break;
        }
    }

    // Verifica se ambas as cidades foram encontradas
    if (!encontrouCidade1 || !encontrouCidade2) {
        printf("Uma das cidades não foi encontrada.\n");
        return -1;
    }

    // Calcula a distância usando a fórmula da distância euclidiana
    double distancia = sqrt(pow(cidadeB.x - cidadeA.x, 2) + pow(cidadeB.y - cidadeA.y, 2));
    return distancia;
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

    // Cidades para calcular a distância
    char cidade1[81] = "Cidade A";
    char cidade2[81] = "Cidade C";

    // Chamando a função para calcular a distância entre as cidades
    double distancia = calcularDistanciaEntreCidades(lista, cidade1, cidade2);

    // Imprimindo o resultado
    if (distancia != -1) {
        printf("Distância entre %s e %s: %.2lf\n", cidade1, cidade2, distancia);
    }

    return 0;
}