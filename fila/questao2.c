#include <stdio.h>
#include <stdlib.h>

// definição da estrutura do nó da fila
typedef struct no {
    int valor;
    struct no* proximo;
} no;

// definição da estrutura da fila
typedef struct {
    no* inicio;
    no* fim;
} Queue;

// adiciona um elemento no fim da fila
void enqueue (Queue* queue, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (queue->fim == NULL) {
        queue->inicio = queue->fim = novoNo;  // se a fila estiver vazia, o novo nó se torna tanto o início quanto o fim da fila
    } else {
        queue->fim->proximo = novoNo;  // se a fila não estiver vazia, o novo nó é adicionado ao fim da fila
        queue->fim = novoNo;
    }
}

// remove um elemento do início da fila
int dequeue (Queue* queue) {
    if (queue->inicio == NULL) {
        printf("A fila está vazia.\n");  // verifica se a fila está vazia
        return -1;
    }
    int valor = queue->inicio->valor;  // copia o valor do primeiro nó para o valor de retorno
    no* temp = queue->inicio;
    queue->inicio = queue->inicio->proximo;
    if (queue->inicio == NULL) {
        queue->fim = NULL; // se a fila ficar vazia após a remoção do elemento, o fim também é atualizado
    }
    free(temp);  // libera a memória alocada para temp
    return valor;
}

// consulta o valor do primeiro elemento da fila
int peek (Queue* queue) {
    if (queue->inicio == NULL) {
        printf("A fila esta vazia.\n");  // verifica se a fila está vazia
        return -1;
    }
    return queue->inicio->valor;
}

// verifica se a fila está vazia
int isEmpty (Queue* queue) {
    return queue->inicio == NULL;
}

// exibe todos os valores da fila
void printQueue (Queue* queue) {
    if (isEmpty(queue)) {
        printf("A fila está vazia.\n");  // verifica se a fila está vazia
        return;
    }
    printf("Fila: ");
    no* temp = queue->inicio;
    while (temp != NULL) {
        printf("%d ", temp->valor); 
        temp = temp->proximo;
    }
    printf("\n");
}

int main() {
    Queue queue;
    queue.inicio = NULL;  // inicializa o início da fila 
    queue.fim = NULL;  // inicializa o fim da fila

    // testando as funções da fila inserindo valores
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printQueue(&queue);  // exibe os valores na fila: 3 2 1
    printf("Elemento removido: %d\n", dequeue(&queue));  // exibe o elemento removido: 1
    printf("Elemento no inicio: %d\n", peek(&queue));  // exibe o elemento no início: 2
    printQueue(&queue);  // exibe os valores na fila: 2 1
    printf("Elemento removido: %d\n", dequeue(&queue));  // exibe o elemento removido: 2
    printf("Elemento removido: %d\n", dequeue(&queue));  // exibe o elemento removido: 3
    printQueue(&queue);  // exibe os valores na fila: vazia

    return 0;
}