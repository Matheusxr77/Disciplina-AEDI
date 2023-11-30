#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição de tamanho máximo da pilha
#define MAX 100

// definição da estrutura da pilha
typedef struct {
    char elementos[MAX];
    int topo;
} Stack;

// insere um elemento no topo da pilha
void push (Stack *stack, char valor) {
    if (stack->topo == MAX - 1) {
        printf("Erro: a pilha esta cheia.\n");  // verifica se a pilha está cheia
    } else {
        stack->topo++;  // incrementa o topo da pilha
        stack->elementos[stack->topo] = valor;  // insere o valor no topo da pilha
    }
}

// remove o elemento do topo da pilha
char pop (Stack *stack) {
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return '\0';
    } else {
        char valor = stack->elementos[stack->topo];  // obtém o valor do topo da pilha
        stack->topo--;  // decrementa o topo da pilha
        return valor;  // retorna o item removido do topo da pilha
    }
}

// verifica se a pilha está vazia
int isEmpty (Stack *stack) {
    return stack->topo == -1;  // retorna 1 se a pilha está vazia, caso contrário, retorna 0
}

// verificar se par de caracteres corresponde
int isCorresponding (char abrir, char fechar) {
    if (abrir == '(' && fechar == ')') {
        return 1;
    } else if (abrir == '[' && fechar == ']') {
        return 1;
    } else if (abrir == '{' && fechar == '}') {
        return 1;
    } else {
        return 0;
    }
}

// verifica se a expressão está bem balanceada
int isBalanced (char *expressao) {
    int i, length;
    Stack stack;
    stack.topo = -1;
    length = strlen(expressao);
    for (i = 0; i < length; i++) {
        char current = expressao[i];
        if (current == '(' || current == '[' || current == '{') {  // se for um caractere de abertura, insere na pilha
            push(&stack, current);
        } else if (current == ')' || current == ']' || current == '}') {  // se for um caractere de fechamento, verifica correspondência com o topo da pilha
            if (isEmpty(&stack)) {
                return 0;  // se a pilha estiver vazia, a expressão não está balanceada
            } else {
                char topo = pop(&stack);
                if (!isCorresponding(topo, current)) {
                    return 0;  // se o par não corresponder, a expressão não está balanceada
                }
            }
        }
    }
    return isEmpty(&stack);  // se a pilha não estiver vazia no final, a expressão não está balanceada
}

int main() {
    // declaração de variável
    char expressao[MAX];

    // interação com o usuário
    printf("Digite uma expressao numerica: ");
    fgets(expressao, MAX, stdin);

    if (isBalanced(expressao)) {
        printf("Os parenteses, colchetes e chaves estao bem balanceados!\n");  // expressão balanceada
    } else {
        printf("Os parenteses, colchetes e chaves nao estao bem balanceados!\n");  // expressão não balanceada
    }

    return 0;
}