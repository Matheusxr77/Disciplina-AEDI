#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

int main (int argc, char* argv[]) {
    // declaração de variáveis
    int n, opcao, valor, posicao;

    // declaração da lista
    lista listaInicial = NULL;
    
    // declarando listas de remoção
    lista removidoInicio = NULL;
    lista removidoFim = NULL;

    // recebendo os elementos da lista com o usuário
    printf("Digite os elementos da lista (-1 para encerrar):\n");
    do {
        scanf("%d", &valor);
        if (valor != -1) {
            if (inserirFim(&listaInicial, valor) == 1) {
                printf("Elemento inserido com sucesso!\n");
            } else {
                printf("Falha ao inserir elemento. Lista cheia!\n");
            }
        }
    } while(valor != -1);

    while(1) {
        // menu para o usuário escolher o que deseja que o programa faça
        printf("\n=============== MENU ===============\n");
        printf("1. Inserir elemento no inicio da lista\n");
        printf("2. Inserir elemento no fim da lista\n");
        printf("3. Inserir elemento na posicao escolhida\n");
        printf("4. Inserir elemento em ordem\n");
        printf("5. Exibir lista\n");
        printf("6. Exibir lista em ordem reversa\n");
        printf("7. Remover elemento do inicio da lista\n");
        printf("8. Remover elemento do fim da lista\n");
        printf("9. Remover elemento de uma posicao especifica\n");
        printf("10. Remover elemento de acordo com valor\n");
        printf("11. Procurar elemento na lista\n");
        printf("12. Calcular somatorio dos elementos\n");
        printf("13. Calcular tamanho da lista\n");
        printf("14. Elevar ao quadrado todos os elementos\n");
        printf("15. Calcular quantidade de numeros primos\n");
        printf("16. Sair\n");

        printf("\nEscolha uma opcao: ");

        // recebendo a opção escolhida pelo usuário
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // inserir elemento no inicio da lista
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if (inserirInicio(&listaInicial, valor) == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;
            
            case 2:
                // inserir elemento no fim da lista
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if (inserirFim(&listaInicial, valor) == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;
            
            case 3:
                // inserir elemento na posicao escolhida
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                if (inserirPosicao(&listaInicial, valor, posicao) == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Posicao invalida!\n");
                }
                break;

            case 4:
                // inserir elemento em ordem
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if (inserirOrdem(&listaInicial, valor) == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;

            case 5:
                // exibir lista
                printf("Lista: ");
                exibir(listaInicial);
                break;
            
            case 6:
                // exibir lista em ordem reversa
                printf("Lista reversa: ");
                reverso(listaInicial);
                printf("\n");
                break;
            
            case 7:
                // remover elemento do inicio da lista
                removidoInicio = removerInicio(&listaInicial);
                if (removidoInicio != NULL) {
                    printf("Elemento removido do inicio: %d\n", removidoInicio->valor);
                    free(removidoInicio);
                } else {
                    printf("Nao foi possivel remover elemento. Lista vazia!\n");
                }
                break;

            case 8:
                // remover elemento do fim da lista
                removidoFim = removerFim(&listaInicial);
                if (removidoFim != NULL) {
                    printf("Elemento removido do fim: %d\n", removidoFim->valor);
                    free(removidoFim);
                } else {
                    printf("Nao foi possivel remover elemento. Lista vazia!\n");
                }
                break;

            case 9:
                // remover elemento de uma posicao especifica
                printf("Digite a posicao: ");
                scanf("%d", &posicao);
                if (removerPosicao(&listaInicial, posicao) == 1) {
                    printf("Elemento removido da posicao %d\n", posicao);
                } else {
                    printf("Nao foi possivel remover elemento. Posicao invalida!\n");
                }
                break;

            case 10:
                // remover elemento de acordo com valor
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (removerValor(&listaInicial, valor) == 1) {
                    printf("Elemento removido com valor %d\n", valor);
                } else {
                    printf("Nao foi possivel remover elemento. Valor nao encontrado!\n");
                }
                break;

            case 11:
                // procurar elemento na lista
                printf("Digite o valor: ");
                scanf("%d", &valor);
                posicao = procurar(listaInicial, valor);
                if (posicao != -1) {
                    printf("Elemento encontrado na posicao %d\n", posicao);
                } else {
                    printf("Elemento nao encontrado!\n");
                }
                break;

            case 12:
                // calcular somatorio dos elementos
                printf("Somatorio: %d\n", somatorio(listaInicial));
                break;
            
            case 13:
                // calcular tamanho da lista
                printf("Tamanho da lista: %d\n", tamanho(listaInicial));
                break;
            
            case 14:
                // elevar ao quadrado todos os elementos
                quadrado(listaInicial);
                printf("Elementos elevados ao quadrado!\n");
                break;
            
            case 15:
                // calcular quantidade de numeros primos
                printf("Quantidade de numeros primos: %d\n", qtdPrimos(listaInicial));
                break;
            
            case 16:
                // sair do programa
                sair();
                break;
            
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}