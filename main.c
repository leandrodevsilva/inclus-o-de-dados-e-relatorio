#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 50

// Estrutura para armazenar informacoes do usuario
struct Usuario {
    char nome[50];
    char senha[50];
};

// Estrutura para armazenar informacoes do cliente
struct Cliente {
    char nome[100];
    int matricula_responsavel;
    char empresa[100];
    char cnpj[20];
    char setor[100];
    char telefone[20];
    char endereco[200];
    char email[100];
    char data_abertura[20];
    float residuos_quantidade[12];
    float residuos_custo[12];
};

// Funcao para login
int login(struct Usuario *usuario) {
    char nome[50], senha[50];

    printf("Digite o nome de usuario: ");
    scanf("%s", nome);
    printf("Digite a senha: ");
    scanf("%s", senha);

    if (strcmp(usuario->nome, nome) == 0 && strcmp(usuario->senha, senha) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Funcao para cadastro de usuario
void cadastrarUsuario(struct Usuario *usuario) {
    printf("Digite o nome de usuario: ");
    scanf("%s", usuario->nome);
    printf("Digite a senha: ");
    scanf("%s", usuario->senha);
}

// Funcao para cadastro de cliente
void cadastrarCliente(struct Cliente *cliente) {
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente->nome); // Permite espaços no nome

    printf("Digite a matricula do responsavel: ");
    scanf("%d", &cliente->matricula_responsavel);

    printf("Digite o nome da empresa: ");
    scanf(" %[^\n]", cliente->empresa); // Permite espaços no nome da empresa

    printf("Digite o CNPJ: ");
    scanf("%s", cliente->cnpj);

    printf("Digite o telefone: ");
    scanf("%s", cliente->telefone);

    printf("Digite o endereco (exemplo: Rua das Flores 123): ");
    scanf(" %[^\n]", cliente->endereco); // Permite letras, espaços e numeros no endereco

    printf("Digite o email: ");
    scanf("%s", cliente->email);

    printf("Digite a data de abertura: ");
    scanf("%s", cliente->data_abertura);
}

// Funcao para atualizar dados mensais
void atualizarDadosMensais(struct Cliente *cliente) {
    int mes;
    float quantidade, custo;

    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    printf("Digite a quantidade de residuos para o mes %d: ", mes);
    scanf("%f", &quantidade);
    printf("Digite o custo para o mes %d: ", mes);
    scanf("%f", &custo);

    cliente->residuos_quantidade[mes - 1] = quantidade;
    cliente->residuos_custo[mes - 1] = custo;
}

// Funcao para gerar relatorio individual
void gerarRelatorioIndividual(struct Cliente *cliente) {
    printf("Relatorio Individual para: %s\n", cliente->nome);
    for (int i = 0; i < 12; i++) {
        printf("Mes %d: Quantidade: %.2f, Custo: %.2f\n", i + 1, cliente->residuos_quantidade[i], cliente->residuos_custo[i]);
    }
}

// Funcao para gerar relatorio global
void gerarRelatorioGlobal(struct Cliente clientes[], int totalClientes) {
    float totalQuantidade = 0, totalCusto = 0;

    for (int i = 0; i < totalClientes; i++) {
        for (int j = 0; j < 12; j++) {
            totalQuantidade += clientes[i].residuos_quantidade[j];
            totalCusto += clientes[i].residuos_custo[j];
        }
    }

    printf("Relatorio Global\n");
    printf("Total de residuos: %.2f\n", totalQuantidade);
    printf("Custo total: %.2f\n", totalCusto);
}

int main() {
    struct Usuario usuario;
    struct Cliente clientes[MAX_CLIENTES];
    int totalClientes = 0;
    int logado = 0;
    int escolha;

    do {
        printf("\nBem-vindo ao sistema de gestao de residuos!\n");
        printf("1. Login\n");
        printf("2. Cadastrar Usuario\n");
        printf("3. Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            if (!logado) {
                logado = login(&usuario);
                if (logado) {
                    printf("Login bem-sucedido!\n");
                } else {
                    printf("Falha no login. Tente novamente.\n");
                }
            } else {
                printf("Voce ja esta logado.\n");
            }
            break;
        case 2:
            cadastrarUsuario(&usuario);
            printf("Usuario cadastrado com sucesso!\n");
            break;
        case 3:
            printf("Saindo... Obrigado!\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }

        if (logado) {
            do {
                printf("\nO que gostaria de fazer?\n");
                printf("1. Cadastrar Cliente\n");
                printf("2. Atualizar Dados Mensais\n");
                printf("3. Gerar Relatorio Individual\n");
                printf("4. Gerar Relatorio Global\n");
                printf("5. Sair\n");
                printf("Digite sua escolha: ");
                scanf("%d", &escolha);

                switch (escolha) {
                case 1:
                    cadastrarCliente(&clientes[totalClientes]);
                    totalClientes++;
                    break;
                case 2:
                    if (totalClientes > 0) {
                        atualizarDadosMensais(&clientes[totalClientes - 1]);
                    } else {
                        printf("Nenhum cliente cadastrado.\n");
                    }
                    break;
                case 3:
                    if (totalClientes > 0) {
                        gerarRelatorioIndividual(&clientes[totalClientes - 1]);
                    } else {
                        printf("Nenhum cliente cadastrado.\n");
                    }
                    break;
                case 4:
                    gerarRelatorioGlobal(clientes, totalClientes);
                    break;
                case 5:
                    printf("Saindo... Obrigado!\n");
                    logado = 0;
                    break;
                default:
                    printf("Opcao invalida. Tente novamente.\n");
                }
            } while (logado && escolha != 5);
        }

    } while (escolha != 3);

    return 0;
}
