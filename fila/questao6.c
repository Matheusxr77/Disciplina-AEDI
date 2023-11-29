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

// inicializa uma fila vazia
void initializeQueue (Queue* queue) {
    queue->inicio = NULL;
    queue->fim = NULL;
}

// verifica se a lista está vazia
int isEmpty (Queue* queue) {
    return queue->inicio == NULL;
}

// adiciona um elemento no fim da fila
void enqueue (Queue* queue, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;  // copia o valor para o valor do nó
    novoNo->proximo = NULL;
    if (isEmpty(queue)) {
        queue->inicio = queue->fim = novoNo;  // se a fila estiver vazia, o novo nó se torna tanto o início quanto o fim da fila
    } else {
        queue->fim->proximo = novoNo;  // se a fila não estiver vazia, o novo nó é adicionado ao fim da fila
        queue->fim = novoNo;
    }
}

// remove um elemento do início da fila
int dequeue (Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila esta vazia.\n");  // verifica se a fila está vazia
        return -1;
    }
    no* temp = queue->inicio;  // copia o valor do primeiro nó para o inicio
    int valor = temp->valor;  // salva o valor
    queue->inicio = queue->inicio->proximo;
    if (queue->inicio == NULL) {
        queue->fim = NULL;  // verifica se a fila está vazia após a remoção
    }
    free(temp);  // libera a memória alocada para temp
    return valor;
}

// retorna o valor do primeiro nó da fila
int inicio (Queue* queue) {
    if (isEmpty(queue)) {
        printf("Erro: a fila esta vazia.\n");  // verifica se a fila está vazia
        return -1;
    }
    return queue->inicio->valor;  // retorna o valor do primeiro nó da fila
}

// encontra o tempo mínimo necessário para esvaziar ambas as filas
int findMinTime (int* listaA, int* listaB, int tamanho) {
    int i;
    Queue queueA, queueB;
    initializeQueue(&queueA);  // inicializa a fila A
    initializeQueue(&queueB);  // inicializa a fila B
    for (i = 0; i < tamanho; i++) {  
        enqueue(&queueA, listaA[i]);  // preenche a fila com os elementos da lista A
        enqueue(&queueB, listaB[i]);  // preenche a fila com os elementos da lista B
    }
    int tempo = 0;
    while (!isEmpty(&queueA) && !isEmpty(&queueB)) {
        if (inicio(&queueA) == inicio(&queueB)) {  // se os primeiros elementos das duas filas são iguais, remover os elementos e avançar para o próximo
            dequeue(&queueA);  // remove o primeiro elemento de A
            dequeue(&queueB);  // remove o primeiro elemento de B
            tempo++;
        } else {
            int tempoRotacao = 0;  // girar a fila A no sentido horário
            while (inicio(&queueA) != inicio(&queueB)) {
                int elemento = dequeue(&queueA);
                enqueue(&queueA, elemento);  // insere o elemento removido no final de A
                tempoRotacao++;
                if (tempoRotacao == tamanho) {
                    printf("Nao e possivel esvaziar ambas as listas.\n");  // caso especial: Se a fila A já foi totalmente girada sem encontrar um elemento correspondente, significa que não é possível esvaziar ambas as listas
                    return -1;
                }
            }
            tempo += tempoRotacao;  // incrementa o tempo necessário para cada operação
        }
    }
    return tempo;
}

int main() {
    int tamanho, i;

    scanf("%d", &tamanho);

    int* listaA = (int*)malloc(sizeof(int) * tamanho);
    int* listaB = (int*)malloc(sizeof(int) * tamanho);

    for (i = 0; i < tamanho; i++) {
        scanf("%d", &listaA[i]);  // armazenando os valores na lista A
    }
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &listaB[i]);  // armazenando os valores na lista B
    }

    int tempoMinimo = findMinTime(listaA, listaB, tamanho);

    printf("%d\n", tempoMinimo);  // imprime o tempo mínimo para esvaziar as filas

    free(listaA);  // libera a memória alocada para a array
    free(listaB);  // libera a memória alocada para a array

    return 0;
}