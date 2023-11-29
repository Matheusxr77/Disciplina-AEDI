#include <stdio.h>
#include <stdlib.h>

// definição de tamanho máximo da fila
#define MAX 100

// definição da estrutura da fila
typedef struct {
    int elementos[MAX];
    int inicio;
    int fim;
} Queue;

// verifica se a fila está vazia
int isEmpty (Queue *queue) {
    return queue->inicio > queue->fim;  // Se início estiver à frente de fim
}

// adiciona um elemento no fim da fila
void enqueue (Queue *queue, int valor) {
    if (queue->fim == MAX - 1) {
        printf("A fila esta cheia.\n");  // verifica se a fila está cheia
        return;
    }
    queue->elementos[++queue->fim] = valor;  // incrementa o fim e adiciona o valor no final da fila
}

// remove um elemento do início da fila
int dequeue (Queue *queue) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia!\n");  // verifica se a fila está vazia
        return -1;
    }
    return queue->elementos[queue->inicio++];  // retorna o valor no início da fila e incrementa o início
}

// consulta o valor do primeiro elemento da fila
int peek (Queue *queue) {
    if (isEmpty(queue)) {
        printf("A fila esta vazia!\n");  // verifica se a fila está vazia
        return -1;
    }
    return queue->elementos[queue->inicio];  // retorna o valor no início da fila sem modificar o inicio
}

// exibe todos os valores da fila
void printQueue (Queue *queue) {
    int i;
    if (isEmpty(queue)) {
        printf("A fila esta vazia!\n");  
        return;
    }
    printf("Fila: ");
    for (i = queue->inicio; i <= queue->fim; i++) {
        printf("%d ", queue->elementos[i]);  
    }
    printf("\n");
}

int main() {
    Queue queue;
    queue.inicio = 0;  // inicializa o início da fila
    queue.fim = -1;  // inicializa o fim da fila

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