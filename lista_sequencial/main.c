#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

int main (int argc, char *argv) {
    // declaração de variáveis
    int n, opcao, valor, posicao, resultado;

    // declaração da lista
    struct lista listaInicial;
    inicializar(&listaInicial);
    
    // recebendo os elementos da lista com o usuário
    printf("Digite os elementos da lista (-1 para encerrar):\n");
    do {
        scanf("%d", &valor);
        if (valor != -1) {
            resultado = inserirFim(&listaInicial, valor);
            if (resultado) {
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
                resultado = inserirInicio(&listaInicial, valor);
                if (resultado == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;

            case 2:
                // inserir elemento no fim da lista
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                resultado = inserirFim(&listaInicial, valor);
                if (resultado == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;
            
            case 3:
                // inserir elemento na posicao escolhida
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                printf("Digite a posicao de insercao: ");
                scanf("%d", &posicao);
                resultado = inserirPosicao(&listaInicial, valor, posicao);
                if (resultado == 1) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Falha ao inserir valor. Lista cheia ou posição invalida!\n");
                }
                break;
            
            case 4:
                // inserir elemento em ordem
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                resultado = inserirOrdem(&listaInicial, valor);
                if (resultado) {
                    printf("Valor inserido com sucesso!\n");
                } else{
                    printf("Falha ao inserir valor. Lista cheia!\n");
                }
                break;
            
            case 5:
                // exibir lista
                printf("Lista armazenada: ");
                exibir(&listaInicial);
                break;
            
            case 6:
                // exibir lista em ordem reversa
                printf("Lista em ordem reversa: ");
                reverso(&listaInicial);
                break;
            
            case 7:
                // remover elemento do inicio da lista
                resultado = removerInicio(&listaInicial);
                if (resultado) {
                    printf("Elemento removido do inicio da lista!\n");
                } else {
                    printf("Falha ao remover elemento. Lista vazia!\n");
                }
                break;
            
            case 8:
                // remover elemento do fim da lista
                resultado = removerFim(&listaInicial);
                if (resultado) {
                    printf("Elemento removido do inicio da lista!\n");
                } else {
                    printf("Falha ao remover elemento. Lista vazia!\n");
                }
                break;
            
            case 9:
                // remover elemento de uma posicao especifica
                printf("Digite a posicao do elemento a ser removido: ");
                scanf("%d", &posicao);
                resultado = removerPosicao(&listaInicial, posicao);
                if (resultado) {
                    printf("Elemento removido da posição %d!\n", posicao);
                } else {
                    printf("Falha ao remover elemento. Posicao invalida!\n");
                }
                break;
            
            case 10:
                // remover elemento de acordo com valor
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                resultado = removerValor(&listaInicial, valor);
                if (resultado) {
                    printf("Elemento removido com sucesso!\n");
                } else {
                    printf("Falha ao remover elemento. Valor nao encontrado!\n");
                }
                break;
            
            case 11:
                // procurar elemento na lista
                printf("Digite o elemento que deseja procurar na lista: ");
                scanf("%d", &n);
                resultado = procurar(&listaInicial, n);
                if (resultado != -1) {
                    printf("O elemento %d esta na posicao: %d", n, resultado);
                } else {
                    printf("O valor nao foi encontrado na lista");
                }
                break;
            
            case 12:
                // calcular somatorio dos elementos
                printf("Somatorio dos elementos: %d\n", somatorio(&listaInicial));
                break;
            
            case 13:
                // calcular tamanho da lista
                printf("Tamanho da lista: %d\n", tamanho(&listaInicial));
                break;
            
            case 14:
                // elevar ao quadrado todos os elementos
                quadrado(&listaInicial);
                printf("Elementos elevados ao quadrado!\n");
                break;
            
            case 15:
                // calcular quantidade de numeros primos
                printf("Quantidade de numeros primos: %d\n", qtdPrimos(&listaInicial));
                break;
            
            case 16:
                // sair do programa
                sair();
                break;
            
            default:
                printf("Opção invalida, por favor, escolha uma opcao valida.\n");
                break;
        }
    }

    return 0;
}