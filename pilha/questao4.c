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
void push (Stack* stack, int valor) {
    if (stack->topo == MAX - 1) {
        printf("Erro: a pilha esta cheia.\n");  // verifica se a pilha está cheia
    } else {
        stack->topo++;  // incrementa o topo da pilha
        stack->elementos[stack->topo] = valor;  // insere o valor no topo da pilha
    }
}

// remove o elemento do topo da pilha
int pop (Stack* stack) {
    int valor;
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return 0;
    } else {
        valor = stack->elementos[stack->topo];  // obtém o valor do topo da pilha
        stack->topo--;  // decrementa o topo da pilha
        return valor;  // retorna o valor removido do topo da pilha
    }
}

// verifica se a pilha está vazia
int isEmpty (Stack* stack) {
    return stack->topo == -1;  // retorna 1 se a pilha está vazia, caso contrário, retorna 0
}

// armazena os números da lista de fibonacci que serão armazenados na pilha
void fibonacciStack (int n) {
    Stack stack;
    stack.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)
    int i, a, b, proximo;
    a = 0; // valor inicial da sequência de Fibonacci
    b = 1; // segundo valor inicial da sequência de Fibonacci
    for (i = 0; i < n; i++) {  // loop para calcular e acumular os valores da sequência de fibonacci na pilha
        push(&stack, a); // armazena o valor atual na pilha
        proximo = a + b; // calcula o próximo valor da sequência
        a = b; // atualiza o valor atual
        b = proximo; // atualiza o próximo valor
    }
    printf("Sequencia de Fibonacci acumulada na pilha:\n");
    while (!isEmpty(&stack)) {
        printf("[%d]", pop(&stack));  // imprime os valores acumulados na pilha
    }
    printf("\n");
}

int main() {
    // declaração de variável
    int n;

    // interação com o usuário
    printf("Digite o nnmero de valores da sequencia de Fibonacci a serem acumulados: ");
    scanf("%d", &n);

    fibonacciStack(n);  // chama a função para expôr os valores da sequência de fibonacci acumulados na pilha

    return 0;
}