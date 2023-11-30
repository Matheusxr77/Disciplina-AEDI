#include <stdio.h>
#include <string.h>

// definição de tamanho máximo da pilha
#define MAX 1000

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
        char valor = stack->elementos[stack->topo];
        stack->topo--;  // decrementa o topo da pilha
        return valor;  // retorna o item removido do topo da pilha
    }
}

// reoganiza os livros presentes na biblioteca
void rearrange (char* biblioteca) {
    int entre = 0; // variável para controlar se está entre / e \ ou \ e / (barras internas)
    int j = 0;
    int i;
    Stack fora;  // pilha para caracteres fora das barras
    Stack dentro;  // pilha para caracteres entre / e \ ou \ e / (barras internas)
    fora.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)
    dentro.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)
    for (i = 0; i < strlen(biblioteca); i++) {  // percorre a string da biblioteca
        if (biblioteca[i] == '/') { 
            if (entre) {  // se encontramos a barra inicial, esvaziamos a pilha interna para reverter a ordem dos caracteres
                while (dentro.topo != -1) {
                    push(&fora, pop(&dentro));
                }
            }
            entre = 1;
        } else if (biblioteca[i] == '\\') {
            while (dentro.topo != -1) {  // se encontramos a barra final, esvaziamos a pilha interna sem reverter a ordem dos caracteres
                push(&fora, pop(&dentro));
            }
            entre = 0;
        } else {
            push(&dentro, biblioteca[i]);  // empilha o caractere se estiver fora das barras ou entre / e \ ou \ e / (barras internas)
        }
    }
    while (fora.topo != -1) {  // atualiza a string da biblioteca com os caracteres rearranjados
        biblioteca[j++] = pop(&fora);
    }
    biblioteca[j] = '\0';
}

int main() {
    // declaração de variável
    char biblioteca[MAX];

    // recebendo valor
    scanf("%s", biblioteca);

    // chamada da função
    rearrange(biblioteca);

    // imprimindo a saída da função
    printf("%s\n", biblioteca);

    return 0;
}