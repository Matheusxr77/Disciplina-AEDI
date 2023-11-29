#include <stdio.h>
#include <stdlib.h>

// definição da estrutura do nó da fila
typedef struct no {
    int tamanho;
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
void enqueue (Queue* queue, int tamanho) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->tamanho = tamanho;  // copia o valor para o campo tamanho do nó
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
    int tamanho = temp->tamanho;  // salva o tamanho do disco
    queue->inicio = queue->inicio->proximo;
    if (queue->inicio == NULL) {
        queue->fim = NULL;  // verifica se a fila está vazia após a remoção
    }
    free(temp);  // libera a memória alocada para temp
    return tamanho;  // retornar o tamanho do disco removido
}

// exibe todos os valores da fila
void printQueue (Queue* queue) {
    if (isEmpty(queue)) {
        printf("\n");  // verifica se a fila está vazia
        return;
    }
    no* temp = queue->inicio;
    while (temp != NULL) {
        printf("%d ", temp->tamanho);  // percorre a fila e exibe cada elemento
        temp = temp->proximo;
    }
    printf("\n");
}

// exibe todos os valores da fila de modo reverso
void printReverseQueue (Queue* queue) {
    if (isEmpty(queue)) {
        printf("\n");  // verifica se a fila está vazia
        return;
    }
    no* temp = queue->inicio;
    int* array = (int*)malloc(sizeof(int));
    int i = 0;
    while(temp != NULL){
        array[i] = temp->tamanho;
        i++;
        temp = temp->proximo;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", array[j]);  // percorre a fila e exibe cada elemento da fila em ordem decrescente
    }
    free(array);  // Libera a memória alocada para o array
    printf("\n");
}

// função principal para resolver o problema da construção da torre
void solve (int* array, int tamanho) {
    int i;
    Queue torre;
    initializeQueue(&torre);  // inicializa as filas vazias
    int tamanhoMaximo = 0;
    for (i = 0; i < tamanho; i++) {
        if (array[i] > tamanhoMaximo) {
            tamanhoMaximo = array[i];  // encontra o tamanho máximo de disco fornecido
        }
    }
    for (i = 0; i < tamanho; i++) {
        if (array[i] == tamanhoMaximo) {  // processa os discos fornecidos
            printf("%d ", array[i]);
            Queue discosMenores;
            initializeQueue(&discosMenores);  // inicializa as filas vazias
            while (!isEmpty(&torre) && torre.inicio->tamanho < tamanhoMaximo) {
                int menorTamanho = dequeue(&torre);
                enqueue(&discosMenores, menorTamanho);
            }
            printReverseQueue(&discosMenores);  // imprime os discos menores em ordem decrescente
            tamanhoMaximo--;  // atualiza o tamanho máximo para o próximo disco a ser adicionado
        } else {
            enqueue(&torre, array[i]);  // adiciona o disco atual à fila
        }
    }
    printReverseQueue(&torre);  // imprime a torre restante (discos menores que o tamanho máximo)
}

int main() {
    int entrada;

    scanf("%d", &entrada);

    int* array = (int*)malloc(sizeof(int) * entrada);
    for (int i = 0; i < entrada; i++) {
        scanf("%d", &array[i]);  // recebe os valores dos discos para a torre
    }

    solve(array, entrada);

    free(array);  // libera a memória alocada para a array

    return 0;
}