#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista encadeada
typedef struct Node {
    int valor;
    struct Node* prox;
} Node;

// Função para criar um novo nó com o valor fornecido
Node* criarNovoNode (int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));  // Aloca dinamicamente memória para o novo nó
    novoNo->valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um novo nó no final da lista encadeada
Node* inserir_fim (Node* lista, int valor) {
    if (lista == NULL) {
        return criarNovoNode(valor);  // Se a lista estiver vazia, cria um novo nó
    } else {
        Node* temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;  // Percorre até o final da lista
        }
        temp->prox = criarNovoNode(valor);  // Insere o novo nó no final
        return lista;
    }
}

// Função para criar uma nova lista encadeada com os somatórios acumulados
Node* segunda (Node* input) {
    int soma = 0;
    Node* output = NULL;
    Node* temp = input;
    while (temp != NULL) {
        soma += temp->valor;
        output = inserir_fim(output, soma);  // Cria a lista de saída com os somatórios acumulados
        temp = temp->prox;
    }
    return output;
}

// Função para imprimir os valores da lista encadeada
void imprimirLista (Node* lista) {
    Node* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

// Função principal
int main() {
    // Criando a lista encadeada de entrada: {7, 4, 3, 5}
    Node* input = NULL;
    input = inserir_fim(input, 7);
    input = inserir_fim(input, 4);
    input = inserir_fim(input, 3);
    input = inserir_fim(input, 5);

    // Imprimindo a lista de entrada
    printf("Lista de entrada: ");
    imprimirLista(input);

    // Chamando a função para criar a lista resultante
    Node* output = segunda(input);

    // Imprimindo a lista de saída
    printf("Lista de saída: ");
    imprimirLista(output);

    // Liberando a memória alocada para as listas
    Node* temp;
    while (input != NULL) {
        temp = input;
        input = input->prox;
        free(temp);  // Libera a memória alocada para a lista de entrada
    }
    while (output != NULL) {
        temp = output;
        output = output->prox;
        free(temp);  // Libera a memória alocada para a lista de saída
    }

    return 0;
}