#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define MAX 1000

struct lista {
    int elementos[MAX];
    int particao;
};

void inicializar(struct lista *l);
int inserirInicio(struct lista *l, int valor);
int inserirFim(struct lista *l, int valor);
int inserirPosicao(struct lista *l, int valor, int posicao);
int inserirOrdem(struct lista *l, int valor);
void exibir(struct lista *l);
void reverso(struct lista *l);
int removerInicio(struct lista *l);
int removerFim(struct lista *l);
int removerPosicao(struct lista *l, int posicao);
int removerValor(struct lista *l, int valor);
int procurar(struct lista *l, int n);
int somatorio(struct lista *l);
int tamanho(struct lista *l);
void quadrado(struct lista *l);
int qtdPrimos(struct lista *l);
int concatenar(struct lista *l1, struct lista *l2);
void sair();

#endif