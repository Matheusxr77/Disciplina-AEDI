#ifndef SEQUENCIAL_H
#define SEQUENCIAL_H

// definindo o tamanho máximo da lista
#define MAX 1000

// definição da estrutura da lista
struct lista {
    int elementos[MAX];
    int particao;
};

// declaração das funções
void inicializar (struct lista *l);
int inserirFim (struct lista *l, int valor);
int inserirInicio (struct lista *l, int valor);
void exibir (struct lista *l);
int concatenar (struct lista *l1, struct lista *l2);
void troca (struct lista *l, int posicao1, int posicao2);
void bubbleSort (struct lista *l);
void selectionSort (struct lista *l);
int procurarMenor (struct lista *l, int inicio);
int insertionSort (struct lista *l);
void inserirOrdem (struct lista *l, int valor, int limite);

#endif