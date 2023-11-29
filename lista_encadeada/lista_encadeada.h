#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef int tipo;

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef no* lista;

int inserirInicio(lista* l, int valor);
int inserirFim(lista* l, int valor);
int inserirPosicao(lista* l, int valor, int posicao);
int inserirOrdem(lista* l, int valor);
void exibir(lista l);
void reverso(lista l);
lista removerInicio(lista* l);
lista removerFim(lista* l);
int removerPosicao(lista* l, int posicao);
int removerValor(lista* l, int valor);
int procurar(lista l, int n);
int somatorio(lista l);
int tamanho(lista l);
void quadrado(lista l);
int qtdPrimos(lista l);
void sair();

#endif