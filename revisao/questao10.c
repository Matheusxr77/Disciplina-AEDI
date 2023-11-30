#include <stdio.h>
#include <limits.h>

// Definindo a estrutura para representar um ativo
struct ativo {
    char codigo[6];
    char horario[6];
    float cotacao;
};

// Definindo a estrutura para representar um conjunto de ativos em um dia
struct ativo_dia {
    struct ativo elementos[1000];
    int particao;
};

// Função para calcular o lucro máximo teórico com uma única transação
float calcularLucroMaximo (struct ativo_dia ativos) {
    int i;

    if (ativos.particao < 2) {
        printf("Não há cotações suficientes para calcular o lucro máximo.\n");
        return 0.0;
    }

    float lucroMaximo = 0.0;
    float precoCompra = ativos.elementos[0].cotacao;

    for (i = 1; i < ativos.particao; i++) {
        float precoVenda = ativos.elementos[i].cotacao;
        float lucro = (precoVenda - precoCompra) * 10000; // Multiplica por 10000 para lidar com casas decimais
        if (lucro > lucroMaximo) {
            lucroMaximo = lucro;
        }
        if (precoCompra > precoVenda) {
            precoCompra = precoVenda;
        }
    }

    return lucroMaximo;
}

// Função principal
int main() {
    // Inicializando o conjunto de ativos em um dia
    struct ativo_dia ativos;

    ativos.particao = 5;
    ativos.elementos[0].cotacao = 12.81;
    ativos.elementos[1].cotacao = 12.60;
    ativos.elementos[2].cotacao = 12.50;
    ativos.elementos[3].cotacao = 12.84;
    ativos.elementos[4].cotacao = 12.70;

    // Chamando a função para calcular o lucro máximo teórico
    float lucroMaximo = calcularLucroMaximo(ativos);

    printf("Lucro máximo teórico: %.2f\n", lucroMaximo);

    return 0;
}