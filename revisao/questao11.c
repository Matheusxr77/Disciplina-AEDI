#include <stdio.h>
#include <string.h>

// Estrutura para representar um funcionário
struct Funcionario {
    char Nome[50];
    char Cpf[12];
    char DataAdmissao[11]; // No formato "dd/mm/yyyy"
    float Salario;
};

// Função para cadastrar um novo funcionário
void cadastrarFuncionario (struct Funcionario funcionarios[], int *indice) {
    if (*indice < 50) {
        struct Funcionario novoFuncionario;

        printf("Digite o nome do funcionário: ");
        scanf("%s[^\n]", novoFuncionario.Nome);

        printf("Digite o CPF do funcionário: ");
        scanf("%s", novoFuncionario.Cpf);

        printf("Digite a data de admissão (dd/mm/yyyy): ");
        scanf("%s", novoFuncionario.DataAdmissao);

        printf("Digite o salário do funcionário: ");
        scanf("%f", &novoFuncionario.Salario);

        funcionarios[*indice] = novoFuncionario;
        (*indice)++;
        printf("Funcionário cadastrado com sucesso!\n");
    } else {
        printf("Limite de funcionários atingido. Não é possível cadastrar mais funcionários.\n");
    }
}

// Função para listar todos os funcionários cadastrados
void listarFuncionarios (const struct Funcionario funcionarios[], int indice) {
    int i;

    if (indice == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }

    printf("LISTA DE FUNCIONÁRIOS\n");
    for (i = 0; i < indice; i++) {
        printf("Nome: %s\n", funcionarios[i].Nome);
        printf("CPF: %s\n", funcionarios[i].Cpf);
        printf("Data de Admissão: %s\n", funcionarios[i].DataAdmissao);
        printf("Salário: %.2f\n", funcionarios[i].Salario);
        printf("\n");
    }
}

// Função principal
int main() {
    struct Funcionario funcionarios[50];
    int indice = 0;
    int opcao;

    do {
        printf("\nMENU\n");
        printf("Digite 1 para cadastrar um funcionário\n");
        printf("Digite 2 para listar os funcionários\n");
        printf("Digite 3 para sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarFuncionario(funcionarios, &indice);
                break;
            case 2:
                listarFuncionarios(funcionarios, indice);
                break;
            case 3:
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}