#include <stdio.h>
#include <stdlib.h>

// definição de tamanho máximo da pilha
#define MAX 100

// definição da estrutura da pilha
typedef struct {
    int elementos[MAX];
    int topo;
} Stack;

// insere um elemento no topo da pilha
void push (Stack *stack, int valor) {
    if (stack->topo == MAX - 1) {
        printf("Erro: a pilha esta cheia.\n");  // verifica se a pilha está cheia
    } else {
        stack->topo++;  // incrementa o topo da pilha
        stack->elementos[stack->topo] = valor;  // insere o valor no topo da pilha
    }
}

// remove o elemento do topo da pilha
int pop (Stack *stack) {
    int valor;
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return -1;
    } else {
        valor = stack->elementos[stack->topo];  // obtém o valor do topo da pilha
        stack->topo--;  // decrementa o topo da pilha
        return valor;  // retorna o valor removido do topo da pilha
    }
}

// retorna o valor do elemento no topo da pilha
int top (Stack *stack) {
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return -1;
    } else {
        return stack->elementos[stack->topo];  // retorna o valor do topo da pilha
    }
}

// verifica se a pilha está vazia
int isEmpty (Stack *stack) {
    return stack->topo == -1;  // retorna 1 se a pilha está vazia, caso contrário, retorna 0
}

// exibe todos os valores da pilha 
void printfStack (Stack *stack) {
    int i;
    if (isEmpty(stack)) {
        printf("A pilha esta vazia.\n");  // verifica se a pilha está vazia
    } else {
        printf("Valores na pilha: ");
        for (i = stack->topo; i >= 0; i--) {
            printf("%d ", stack->elementos[i]);  // exibe os valores da pilha em ordem do topo ao fundo
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    stack.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)

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