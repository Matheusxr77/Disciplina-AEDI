#include <stdio.h>
#include <stdlib.h>

// definição da estrutura do nó da pilha
typedef struct no {
    int valor;
    struct no* proximo;
} no;

// definição da estrutura da pilha
typedef struct {
    no* topo;
} Stack;

// insere um elemento no topo da pilha
void push (Stack* stack, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->proximo = stack->topo;  // incrementa o topo da pilha
    stack->topo = novoNo;  // insere o valor no topo da pilha
}

// remove o elemento do topo da pilha
int pop (Stack* stack) {
    int valor;
    if (stack->topo == NULL) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return -1;
    }
    valor = stack->topo->valor;  // obtém o valor do topo da pilha
    no* temp = stack->topo;  // cria uma variável auxiliar para armazenar o valor
    stack->topo = stack->topo->proximo;  // atribui o valor do topo da pilha para o próximo
    free(temp);  // libera a memória alocada na variável auxiliar
    return valor;  // retorna o valor do elemento removido do topo
}

// retorna o valor do elemento no topo da pilha
int top (Stack* stack) {
    if (stack->topo == NULL) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return -1;
    }
    return stack->topo->valor;  // retorna o valor do topo da pilha
}

// verifica se a pilha está vazia
int isEmpty (Stack* stack) {
    return stack->topo == NULL;
}

// exibe todos os valores da pilha 
void printfStack (Stack* stack) {
    if (isEmpty(stack)) {
        printf("A pilha esta vazia.\n");  // verifica se a pilha está vazia
    } else {
        printf("Valores na pilha: ");
        no* current = stack->topo;
        while (current != NULL) {
            printf("%d ", current->valor);  // exibe os valores da pilha em ordem do topo ao fundo
            current = current->proximo;
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    stack.topo = NULL;  // inicializa o topo da pilha como -1 (pilha vazia)

    // testando as funções da pilha inserindo valores
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printfStack(&stack);  // exibe os valores na pilha: 3 2 1
    printf("Elemento do topo: %d\n", top(&stack));  // exibe os elemento do topo: 3
    printf("Elemento removido do topo: %d\n", pop(&stack));  // exibe o elemento removido do topo: 3
    printfStack(&stack);  // exibe os valores na pilha: 2 1
    printf("Elemento removido do topo: %d\n", pop(&stack));  // exibe o elemento removido do topo: 2
    printf("Elemento removido do topo: %d\n", pop(&stack));  // exibe o elemento removido do topo: 1
    printfStack(&stack);  // exibe os valores na pilha: vazia
    
    return 0;
}