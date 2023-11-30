#include <stdio.h>
#include <stdlib.h>
#include "sequencial.h"

int main (int argc, char *argv) {
    // declaração da lista
    struct lista l1;

    // inicialização da lista
    inicializar(&l1);

    // inserir itens na lista 
    inserirInicio(&l1, 7);
    inserirInicio(&l1, 17);
    inserirInicio(&l1, 1);
    
    // método de ordenação escolhido
    insertionSort(&l1);

    // exibir a lista
    exibir(&l1);

    // sair do programa
    exit(0);
}