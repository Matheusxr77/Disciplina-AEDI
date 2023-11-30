#include <stdio.h>

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

// Função para calcular a média das cotações dos ativos em um dia
float calcularMediaCotacoes (struct ativo_dia ativos) {
    int i; 

    if (ativos.particao == 0) {
        printf("Não há cotações disponíveis.\n");
        return 0.0;
    }

    // Calcula a soma das cotações
    float soma = 0.0;
    for (i = 0; i < ativos.particao; i++) {
        soma += ativos.elementos[i].cotacao;
    }

    // Calcula a média das cotações
    float media = soma / ativos.particao;
    return media;
}

// Função principal
int main() {
    // Inicializando o conjunto de ativos em um dia
    struct ativo_dia ativos;

    ativos.particao = 5;
    ativos.elementos[0].cotacao = 10.0;
    ativos.elementos[1].cotacao = 12.0;
    ativos.elementos[2].cotacao = 11.5;
    ativos.elementos[3].cotacao = 13.0;
    ativos.elementos[4].cotacao = 11.8;

    // Chamando a função para calcular a média das cotações
    float media = calcularMediaCotacoes(ativos);

    printf("Média das cotações do dia: %.2f\n", media);

    return 0;
}