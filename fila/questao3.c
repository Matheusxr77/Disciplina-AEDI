#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição da estrutura do nó da fila
typedef struct no {
    char dados[100];  // dados do nó (elemento conjunto)
    struct no* proximo;
} no;

// definição da estrutura da fila
typedef struct {
    no* inicio;
    no* fim;
} Queue;

// adiciona um elemento no fim da fila
void enqueue (Queue* queue, const char* valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    strcpy(novoNo->dados, valor);  // copia o valor para o campo data do nó
    novoNo->proximo = NULL;
    if (queue->fim == NULL) {
        queue->inicio = queue->fim = novoNo;  // se a fila estiver vazia, o novo nó se torna tanto o início quanto o fim da fila
    } else {
        queue->fim->proximo = novoNo;  // se a fila não estiver vazia, o novo nó é adicionado ao fim da fila
        queue->fim = novoNo;
    }
}

// remove um elemento do início da fila
void dequeue (Queue* queue, char* valor) {
    if (queue->inicio == NULL) {
        printf("A fila está vazia.\n");  // verifica se a fila está vazia
        valor[0] = '\0';
        return;
    }
    strcpy(valor, queue->inicio->dados);  // copia o valor do primeiro nó para o valor de retorno
    no* temp = queue->inicio;
    queue->inicio = queue->inicio->proximo;
    if (queue->inicio == NULL) {
        queue->fim = NULL; // se a fila ficar vazia após a remoção do elemento, o fim também é atualizado
    }
    free(temp);  // libera a memória alocada para temp
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
        printf("%s ", temp->dados);  // percorre a fila e exibe cada elemento
        temp = temp->proximo;
    }
    printf("\n");
}

// pega as listas e realiza a intercalação entre elas
void controlQueues (Queue* L1, Queue* L2, Queue* L3) {
    L3->inicio = NULL;  // inicializa o início da fila 
    L3->fim = NULL;  // inicializa o fim da fila 
    no* temp1 = L1->inicio;  // ponteiro para percorrer a lista L1
    no* temp2 = L2->inicio; // ponteiro para percorrer a lista L2
    while (temp1 != NULL && temp2 != NULL) {
        enqueue(L3, temp1->dados);  // adiciona o elemento da fila L1 em L3
        enqueue(L3, temp2->dados);  // adiciona o elemento da fila L2 em L3
        temp1 = temp1->proximo;
        temp2 = temp2->proximo;
    }
    while (temp1 != NULL) {
        enqueue(L3, temp1->dados);  // se a primeira fila ainda tiver elementos
        temp1 = temp1->proximo;
    }
    while (temp2 != NULL) {
        enqueue(L3, temp2->dados);  // se a segunda fila ainda tiver elementos
        temp2 = temp2->proximo;
    }
}

int main() {
    Queue L1, L2, L3;
    L1.inicio = NULL;  // inicializa o início da fila 
    L1.fim = NULL;  // inicializa o fim da fila 
    L2.inicio = NULL;  // inicializa o início da fila 
    L2.fim = NULL;  // inicializa o fim da fila 
    L3.inicio = NULL;  // inicializa o início da fila 
    L3.fim = NULL;  // inicializa o fim da fila 

    int n, i;
    char valor[100];

    // interação com o usuário
    printf("Informe a quantidade de elementos da fila L1: ");
    scanf("%d", &n);
    printf("Informe os elementos da fila L1: ");
    for (i = 0; i < n; i++) {
        scanf("%s", valor);
        enqueue(&L1, valor);
    }
    printf("Informe a quantidade de elementos da fila L2: ");
    scanf("%d", &n);
    printf("Informe os elementos da fila L2: ");
    for (i = 0; i < n; i++) {
        scanf("%s", valor);
        enqueue(&L2, valor);
    }

    controlQueues(&L1, &L2, &L3);
    printQueue(&L3);

    return 0;
}