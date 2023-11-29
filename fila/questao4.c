#include <stdio.h>
#include <stdlib.h>

// definição da estrutura do nó da fila
typedef struct no {
    unsigned long long int dados;  // armazena o número binário
    struct no* proximo;
} no;

// definição da estrutura da fila
typedef struct {
    no* inicio; 
    no* fim; 
} Queue;

// adiciona um elemento no fim da fila
void enqueue (Queue* queue, unsigned long long int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->dados = valor;  // copia o valor para o campo data do nó
    novoNo->proximo = NULL;
    if (queue->fim == NULL) {
        queue->inicio = queue->fim = novoNo;  // se a fila estiver vazia, o novo nó se torna tanto o início quanto o fim da fila
    } else {
        queue->fim->proximo = novoNo;  // se a fila não estiver vazia, o novo nó é adicionado ao fim da fila
        queue->fim = novoNo;
    }
}

// remove um elemento do início da fila
unsigned long long int dequeue (Queue* queue) {
    if (queue->inicio == NULL) {
        return 0;  // verifica se a fila está vazia
    }
    unsigned long long int valor = queue->inicio->dados;  // copia o valor do primeiro nó para o valor de retorno
    no* temp = queue->inicio;
    queue->inicio = queue->inicio->proximo;
    if (queue->inicio == NULL) {
        queue->fim = NULL; // se a fila ficar vazia após a remoção do elemento, o fim também é atualizado
    }
    free(temp);  // libera a memória alocada para temp
    return valor;
}

// imprime os números binários de 1 a n utilizando uma fila
void binaryNumbers (unsigned long long int numero) {
    Queue queue;
    queue.inicio = NULL;  // inicializa o início da fila 
    queue.fim = NULL;  // inicializa o fim da fila 
    enqueue(&queue, 1);  // adiciona o número binário inicial (1) na fila
    for (unsigned long long int i = 0; i < numero; i++) {
        unsigned long long int removeBinario = dequeue(&queue);  // remove o número binário da fila
        printf("%llu ", removeBinario);  // Imprime o número binário
        enqueue(&queue, removeBinario * 10);  // adiciona o número atual multiplicado por 10 e acrescido de 0
        enqueue(&queue, removeBinario * 10 + 1);  // adiciona o número atual multiplicado por 10 e acrescido de 1
    }
}

int main() {
    unsigned long long int numero;

    // interação com o usário
    printf("Digite o valor de n: ");
    scanf("%llu", &numero);

    printf("Numeros binarios de 1 a %llu: ", numero);
    binaryNumbers(numero);

    return 0;
}