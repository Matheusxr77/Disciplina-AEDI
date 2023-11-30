#include <stdio.h>
#include <stdlib.h>
#include "sequencial.h"

// definindo o tamanho máximo da lista
#define MAX 1000

// inicialização da lista
void inicializar (struct lista *l) {
    l->particao = 0;
}

// inserir o elemento no fim da lista
int inserirFim (struct lista *l, int valor) {
    if (l->particao < MAX) { // verificar se há espaço disponível na lista
        l->elementos[l->particao] = valor; // inserir o valor no final da lista
        l->particao++; // incrementar o tamanho da partição
        return 1; // inserção bem sucedida
    } else {
        return 0; // inserção mal sucedida
    }
}

// inserir o elemento no início da lista
int inserirInicio (struct lista *l, int valor) {
    int i;
    if (l->particao < MAX) {  // verificar se há espaço disponível na lista
        for (i=l->particao; i >0; i--) {
            l->elementos[i] = l->elementos[i-1];  // deslocar todos os elementos para a direita
        }
        l->elementos[0] = valor;  // inserir o valor no início da lista
        l->particao++;  // incrementar o tamanho da partição
        return 1;  // inserção bem sucedida
    } else {
        return 0;  // inserção mal sucedida
    }
}

// exibir a lista 
void exibir (struct lista *l) {
    int i;
    for (i=0; i < l->particao; i++) {
        printf("[%d]", l->elementos[i]);  // imprimir cada elemento da lista
    }
    printf("\n");  // pular uma linha após a exibição dos elementos
}

// concatenar duas listas 
int concatenar (struct lista *l1, struct lista *l2) {
    int i;
    if (l1->particao + l2->particao < MAX) {  // verifica se resulta em um tamanho menor que o limite
        for (i=0; i < l2->particao; i++) {
            inserirFim(l1, l2->elementos[i]);  // inserir o elemento da segunda lista no final da primeira 
        }
        return 1;  // concatenação bem sucedida
    } else {
        return 0;  // concatenação mal sucedida
    }
}

// trocar dois elementos de posição na lista
void troca (struct lista *l, int posicao1, int posicao2) {
    int temp = l->elementos[posicao1];  // armazenar temporariamente o valor do elemento na posição 1
    l->elementos[posicao1] = l->elementos[posicao2];  // substituir o elemento da posição 1 para 2
    l->elementos[posicao2] = temp;  // substituir o elemento na posição 2 pelo valor temporário armazenado
}

// ordenar a lista utilizando o algoritmo Bubble Sort
void bubbleSort (struct lista *l) {
    int i, j, trocou;
    for (i=0; i < l->particao - 1; i++ ) {  // percorrer a lista várias vezes (até que não ocorram trocas)
        trocou = 0;  // controlar se ocorreu troca nessa passagem
        for (j=l->particao - 1; j>i; j--) {  // percorrer a lista do fim ao início
            if (l->elementos[j] < l->elementos[j-1]) {  // comparando o elemento com o seu antecessor
                troca(l, j, j-1);  // caso estejam fora de ordem, troca os elementos de posição
                trocou = 1;  // indicar que houve troca nesta passagem
            }
        }
        if (!trocou) {  // se não houve trocas nesta passagem, a lista já está ordenada
            break;
        }
    }
}

// ordenar a lista utilizando o algoritmo Selection Sort
void selectionSort (struct lista *l) {
    int i, posicao;
    for (i=0; i < l->particao - 1; i++) {  // percorrer a lista para selecionar o menor elemento
        posicao = procurarMenor(l, i);  // encontrar a posição do menor elemento não ordenado
        troca(l, i, posicao);  // trocar o menor elemento encontrado com o elemento na posição
    }
}

// encontrar a posição do menor elemento não ordenado na lista
int procurarMenor (struct lista *l, int inicio) {
    int posicao = inicio, i;
    for (i=inicio+1; i < l->particao; i++) {  // percorrer a lista a partir da posição "inicio + 1"
        if (l->elementos[i] < l->elementos[posicao]){  // comparar o elemento atual com o elemento na posição
            posicao = i;  // atualizar a posição do menor elemento encontrado
        }
    }
    return posicao;  // retornar a posição do menor elemento
}

// ordenar a lista utilizando o algoritmo Insertion Sort
int insertionSort (struct lista *l) {
    int i;
    for (i=1; i < l->particao; i++) {  // percorrer a lista a partir do segundo elemento
        inserirOrdem(l, l->elementos[i], i);  // inserir o elemento atual na posição correta
    }
}

// considerar que a lista de entrada já se encontra ordenada
void inserirOrdem (struct lista *l, int valor, int limite) {
    int i, posicao;
    for (i=0; i <= limite; i++) {  // procurar a posição onde o elemento será inserido
        if (valor < l->elementos[i]) {
            posicao = i;  // encontrar a posição onde o elemento será inserido
            break;
        }
    }
    for (i=limite; i > posicao; i--) {  // deslocar para direita os elementos a partir daquela posição
        l->elementos[i] = l->elementos[i-1];  // deslocar elemento para a direita
    }
    l->elementos[posicao] = valor;  // insere o elemento na posição encontrada
}