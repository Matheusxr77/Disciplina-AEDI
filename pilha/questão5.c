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
void push (Stack* stack, char valor) {
    if (stack->topo == MAX - 1) {
        printf("Erro: a pilha esta cheia.\n");  // verifica se a pilha está cheia
    } else {
        stack->topo++;  // incrementa o topo da pilha
        stack->elementos[stack->topo] = valor;  // insere o valor no topo da pilha
    }
}

// remove o elemento do topo da pilha
char pop (Stack* stack) {
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return '\0';
    } else {
        char valor = stack->elementos[stack->topo];  // obtém o valor do topo da pilha
        stack->topo--;  // decrementa o topo da pilha
        return valor;  // retorna o item removido do topo da pilha
    }
}

// remove espaços em branco
void removeSpaces (char* string) {
    int i, j;
    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}

// observa se a string adicionada é um palíndromo
int isPalindrome (char* string) {
    int i;
    Stack stack;
    stack.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)
    for (i = 0; i < strlen(string); i++) {
        push(&stack, string[i]);  // insere os caracteres não vazios na pilha
    }
    for (i = 0; i < strlen(string); i++) {
        char c = pop(&stack);  // compara os caracteres da pilha com os da string original
        if (c != string[i]) {
            return 0;  // não é um palíndromo
        }
    }
    return 1;  // é um palíndromo
}

int main() {
    // declaração de variável
    char string[MAX];

    // interação com o usuário
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';  // remove o caractere de nova linha no final da string
    
    removeSpaces(string);  // Remove os espaços em branco da string

    if (isPalindrome(string)) {
        printf("A string e um palindromo!\n");  // a string é um palíndromo
    } else {
        printf("A string nao e um palindromo!\n");  // a string não é um palíndromo
    }

    return 0;
}