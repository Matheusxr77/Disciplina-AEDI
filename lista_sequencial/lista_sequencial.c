#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

// definição de tamanho máximo da fila
#define MAX 1000

// inicializando o campo partição da lista com o valor 0
void inicializar (struct lista *l) { 
    l->particao = 0;
}

// verifica se a lista está vazia
int vazia (struct lista *l) {
    return (l->particao == 0);
}

// verifica se a lista está cheia
int cheia (struct lista *l) {
    return (l->particao == MAX);
}

// adicionando elemento no início da lista
int inserirInicio (struct lista *l, int valor) {
    int i;
    if (l->particao < MAX) {  // verificar se a lista ainda tem espaço
        for (i = l->particao; i > 0; i--) {
            l->elementos[i] = l->elementos[i-1];  // deslocar os elementos para a direita
        }
        l->elementos[0] = valor;
        l->particao++;
        return 1;  // inserção bem-sucedida
    } else {
        return 0;  // inserção mal-sucedida
    }
}

// adicionando elemento no fim da lista
int inserirFim (struct lista *l, int valor) {
    if (l->particao < MAX) {  // verificar se a lista ainda tem espaço
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;  // inserção bem-sucedida
    } else {
        return 0;  // inserção mal-sucedida
    }
}

// adicionando elemento na posição específica
int inserirPosicao (struct lista *l, int valor, int posicao) {
    int i;
    if (l->particao < MAX) {  // verificar se a lista ainda tem espaço
        for (i = l->particao; i > posicao; i--) {
            l->elementos[i] = l->elementos[i - 1];
        }
        l->elementos[posicao] = valor;  // insere elementos na posição específica
        l->particao++;
        return 1;  // inserção bem-sucedida
    } else {
        return 0;  // inserção mal-sucedida
    }
}

// adicionando um novo elemento deixando a lista ordenada
int inserirOrdem (struct lista *l, int valor) {
    int i, j;
    if (l->particao < MAX) {  // verificar se a lista ainda tem espaço
        i = 0;
        while (i < l->particao && l->elementos[i] < valor) {
            i++;  // encontra a posição correta para inserção do valor
        }
        for (j = l->particao; j > i; j--) {
            l->elementos[j] = l->elementos[j - 1];  // desloca os elementos maiores para a direita
        }
        l->elementos[i] = valor;  // insere o valor na posição correta
        l->particao++;
        return 1;  // inserção bem-sucedida
    } else {
        return 0;  // inserção mal-sucedida
    }
}

// imprime a lista
void exibir (struct lista *l) {
    int i;
    for (i = 0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);  // impressão dos elementos
    }
    printf("\n");
}

// imprime a ordem contrária da lista
void reverso (struct lista *l) {
    int i;
    for (i = l->particao - 1; i >= 0; i--) {
        printf("[%d]", l->elementos[i]);  // impressão dos elementos de modo inverso
    }
    printf("\n");
}

// remove o primeiro elemento da lista
int removerInicio (struct lista *l) {
    int i;
    if (l->particao > 0) {  // verifica se a lista não está vazia
        for (i = 0; i < l->particao - 1; i++) {
            l->elementos[i] = l->elementos[i + 1];  // desloca os elementos à esquerda
        }
        l->particao--;
        return 1;  // remoção bem-sucedida
    } else {
        return 0;  // remoção mal-sucedida
    }
}

// remove o último elemento da lista
int removerFim (struct lista *l) {
    if (l->particao > 0) {
        l->particao--;
        return 1;  // remoção bem-sucedida
    } else {
        return 0;  // remoção mal-sucedida
    }
}

// remove o elemento em uma posição específica da lista
int removerPosicao (struct lista *l, int posicao) {
    int i;
    if (posicao >= 0 && posicao < l->particao) {  // rerifica se a posição está dentro dos limites da lista
        for (i = posicao; i < l->particao - 1; i++) {
            l->elementos[i] = l->elementos[i + 1];  // desloca os elementos à esquerda a partir da posição especificada
        }
        l->particao--;
        return 1;  // remoção bem-sucedida
    } else {
        return 0;  // remoção mal-sucedida
    }
}

// remove um valor específico da lista caso ele exista nela
int removerValor (struct lista *l, int valor) {
    int i, posicao = -1;
    for (i = 0; i < l->particao; i++) {  // procura a posição do valor na lista
        if (l->elementos[i] == valor) {
            posicao = i;
            break;
        }
    }
    if (posicao != -1) {  // verifica se o valor foi encontrado na lista
        for (i = posicao; i < l->particao - 1; i++) {
            l->elementos[i] = l->elementos[i + 1];  // desloca os elementos à esquerda a partir da posição encontrada
        }
        l->particao--;
        return 1;  // remoção bem-sucedida
    } else {
        return 0;  // remoção mal-sucedida
    }
}

// procura a existência de um determinado valor na lista
int procurar (struct lista *l, int n) {
    int i;
    for (i = 0; i < l->particao; i++) {
        if (l->elementos[i] == n) {
            return i;  // retorna a posição em que o valor é encontrado
        }
    }
    return -1;  // valor não encontrado na lista
}

// realiza a soma de todos os elementos presentes na lista
int somatorio (struct lista *l) {
    int i, soma = 0;
    for (i = 0; i < l->particao; i++) {
        soma += l->elementos[i];  // calcula a soma de todos os elementos
    }
    return soma;  // retorna o somatório
}

// retorna a quantidade de elementos presentes na lista
int tamanho (struct lista *l) {
    return l->particao;
}

// eleva ao quadrado todos os elementos da lista
void quadrado (struct lista *l) {
    int i;
    for (i = 0; i < l->particao; i++) {
        l->elementos[i] = l->elementos[i] * l->elementos[i];  // eleva ao quadrado cada elemento
    }
}

// calcula a quantidade de números primos presentes na lista
int qtdPrimos (struct lista *l) {
    int i, j, primo, contador = 0;
    for (i = 0; i < l->particao; i++) {
        primo = 1;
        for (j = 2; j <= l->elementos[i] / 2; j++) {  // verifica se o número é primo
            if (l->elementos[i] % j == 0) {
                primo = 0;  // não é primo
                break;
            }
        }
        if (primo && l->elementos[i] > 1) {
            contador++;  // incrementa ao contador um número primo maior que 1
        }
    }
    return contador;  // quantidade de números primos existentes na lista
}

// concatenação entre listas
int concatenar (struct lista *l1, struct lista *l2) {
    int i;
    if (l1->particao + l2->particao < MAX) {
        for (i = 0; i < l2->particao; i++) {
            inserirFim(l1, l2->elementos[i]);
        }
        return 1;  // concatenação bem-sucedida
    } else {
        return 0;  // concatenação mal-sucedida
    }
}

// fecha o programa
void sair() {
    exit(0);
}