#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// definição de tamanho máximo da pilha
#define MAX 100

// definição de tamanho máximo da pilha
typedef struct {
    int elementos[MAX];
    int topo;
} Stack;

// insere um elemento no topo da pilha
void push (Stack* stack, int valor) {
    if (stack->topo == MAX - 1) {
        printf("Erro: a pilha esta cheia.\n");  // verifica se a pilha está cheia
        return;
    }
    stack->topo++;  // incrementa o topo da pilha
    stack->elementos[stack->topo] = valor;  // insere o valor no topo da pilha
}

// remove e retorna o elemento do topo da pilha
int pop (Stack* stack) {
    int valor;
    if (stack->topo == -1) {
        printf("Erro: a pilha esta vazia.\n");  // verifica se a pilha está vazia
        return -1;
    }
    valor = stack->elementos[stack->topo];  // obtém o valor do topo da pilha
    stack->topo--;  // decrementa o topo da pilha
    return valor;  // retorna o valor removido do topo da pilha
}

// verifica se a pilha está vazia
int isEmpty (Stack *stack) {
    return stack->topo == -1;  // retorna 1 se a pilha está vazia, caso contrário, retorna 0
}

// determina os chocolates vendidos por minuto
int* solution (int minutos, int* caixas, int* saida) {
    int i;
    int* chocolatesVendidos = (int*)malloc(sizeof(int) * minutos);  // aloca espaço para o array de chocolates vendidos
    Stack stack;
    stack.topo = -1;  // inicializa o topo da pilha como -1 (pilha vazia)
    *saida = 0;  // inicializa o tamanho do array de chocolates vendidos
    for (i = 0; i < minutos; i++) {
        if (caixas[i] == 0) {
            if (!isEmpty(&stack)) {
                chocolatesVendidos[*saida] = pop(&stack);  // adiciona o número de chocolates do topo à lista de vendidos
                (*saida)++;
            }
        } else {
            push(&stack, caixas[i]);  // adiciona a nova caixa de chocolates ao topo da pilha
        }
    }
    return chocolatesVendidos;  // retorna um array dinamicamente alocado contendo os chocolates vendidos
}

int main() {
    // declaração de variáveis
    int saida, minutos, i;

    // interação com o usuário
    scanf("%d", &minutos);

    int* caixas = (int*)malloc(sizeof(int) * minutos);  // aloca espaço para o array de caixas
    for (i = 0; i < minutos; i++) {
        scanf("%d", &caixas[i]);
    }

    int* saidaFinal = solution(minutos, caixas, &saida);  // chama a função solution() para obter os chocolates vendidos
    for (i = 0; i < saida; i++) {
        printf("%d ", saidaFinal[i]);  // imprime os chocolates vendidos
    }

    free(caixas);  // libera a memória alocada para a array
    free(saidaFinal);  // libera a memória alocada para a array

    return 0;
}