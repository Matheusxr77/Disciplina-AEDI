#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// inicializando a lista vazia
void inicializar (lista *l) {
    *l = NULL;
}

// verifica se a lista está vazia
int vazia (lista *l) {
    return (l == NULL);
}

// adicionando elemento no início da lista
int inserirInicio (lista* l, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        return 0;  // inserção mal-sucedida
    }
    novoNo->valor = valor;
    novoNo->proximo = *l;
    *l = novoNo;
    return 1;  // inserção bem-sucedida
}

// adicionando elemento no fim da lista
int inserirFim (lista* l, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        return 0;  // inserção mal-sucedida
    }
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (*l == NULL) {
        *l = novoNo;
    } else {
        no* atual = *l;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNo;
    }
    return 1;  // inserção bem-sucedida
}

// adicionando elemento na posição específica
int inserirPosicao (lista* l, int valor, int posicao) {
    if (posicao < 0) {
        return 0;  // inserção mal-sucedida
    }
    if (posicao == 0) {
        return inserirInicio(l, valor);  // reutiliza a função para inserir no início
    }
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        return 0;  // inserção mal-sucedida
    }
    novoNo->valor = valor;
    no* atual = *l;
    int contador = 0;
    while (atual != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }
    if (atual == NULL) {
        free(novoNo);
        return 0;  // inserção mal-sucedida
    }
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
    return 1;  // inserção bem-sucedida
}

// adicionando um novo elemento deixando a lista ordenada
int inserirOrdem (lista* l, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo == NULL) {
        return 0;  // inserção mal-sucedida
    }
    novoNo->valor = valor;
    if (*l == NULL || valor < (*l)->valor) {
        novoNo->proximo = *l;
        *l = novoNo;
    } else {
        no* atual = *l;
        while (atual->proximo != NULL && atual->proximo->valor < valor) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
    return 1;  // inserção bem-sucedida
}

// imprime a lista
void exibir (lista l) {
    no* atual = l;
    while (atual != NULL) {
        printf("[%d]", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// imprime a ordem contrária da lista
void reverso (lista l) {
    if (l == NULL) {
        return;
    }
    reverso(l->proximo);
    printf("[%d]", l->valor);
}

// remove o primeiro elemento da lista
lista removerInicio (lista* l) {
    if (*l == NULL) {
        return NULL;
    }
    no* removido = *l;
    *l = (*l)->proximo;
    removido->proximo = NULL;
    return removido;
}

// remove o último elemento da lista
lista removerFim (lista* l) {
    if (*l == NULL) {
        return NULL;
    }
    if ((*l)->proximo == NULL) {
        return removerInicio(l);  // reutiliza a função para remover o início
    }
    no* atual = *l;
    while (atual->proximo->proximo != NULL) {
        atual = atual->proximo;
    }
    no* removido = atual->proximo;
    atual->proximo = NULL;
    return removido;  // remoção bem-sucedida
}

// remove o elemento em uma posição específica da lista
int removerPosicao (lista* l, int posicao) {
    if (posicao < 0 || *l == NULL) {
        return 0;  // remoção mal-sucedida
    }
    if (posicao == 0) {
        removerInicio(l);  // reutiliza a função para remover o início
        return 1;  // remoção bem-sucedida
    }
    no* atual = *l;
    int contador = 0;
    while (atual->proximo != NULL && contador < posicao - 1) {
        atual = atual->proximo;
        contador++;
    }
    if (atual->proximo == NULL) {
        return 0;  // remoção mal-sucedida
    }
    no* removido = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    removido->proximo = NULL;
    free(removido);
    return 1;  // remoção bem-sucedida
}

// remove um valor específico da lista caso ele exista nela
int removerValor (lista* l, int valor) {
    if (*l == NULL) {
        return 0;  // remoção mal-sucedida
    }
    if ((*l)->valor == valor) {
        removerInicio(l);  // reutiliza a função para remover o início
        return 1;  // remoção bem-sucedida
    }
    no* atual = *l;
    while (atual->proximo != NULL && atual->proximo->valor != valor) {
        atual = atual->proximo;
    }
    if (atual->proximo == NULL) {
        return 0;  // remoção mal-sucedida
    }
    no* removido = atual->proximo;
    atual->proximo = atual->proximo->proximo;
    removido->proximo = NULL;
    free(removido);
    return 1;  // remoção bem-sucedida
}

// procura a existência de um determinado valor na lista
int procurar (lista l, int n) {
    int posicao = 0;
    no* atual = l;
    while (atual != NULL) {
        if (atual->valor == n) {
            return posicao;  // posição que o item procurado se encontra
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;  // valor não encontrado na lista
}

// realiza a soma de todos os elementos presentes na lista
int somatorio (lista l) {
    int soma = 0;
    no* atual = l;
    while (atual != NULL) {
        soma += atual->valor;
        atual = atual->proximo;
    }
    return soma;  // retorna o somatório
}

// retorna a quantidade de elementos presentes na lista
int tamanho (lista l) {
    int tamanho = 0;
    no* atual = l;
    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }
    return tamanho;  // retorna o tamanho da lista
}

// eleva ao quadrado todos os elementos da lista
void quadrado (lista l) {
    no* atual = l;
    while (atual != NULL) {
        atual->valor = atual->valor * atual->valor;
        atual = atual->proximo;
    }
}

// calcula a quantidade de números primos presentes na lista
int qtdPrimos (lista l) {
    int count = 0;
    lista atual = l;
    while (atual != NULL) {  
        int valor = atual->valor;
        int primo = 1;
        if (valor <= 1) {
            primo = 0;  // não é primo
        } else {
            for (int i = 2; i <= valor / 2; i++) {
                if (valor % i == 0) {
                    primo = 0;
                    break;
                }
            }
        }
        if (primo == 1) {
            count++; // incrementa ao contador um número primo maior que 1
        }
        atual = atual->proximo;
    }
    return count;  // quantidade de números primos existentes na lista
}

// fecha o programa
void sair() {
    exit(0);
}