#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[150];
    char telefone[15];
    char celular[15];
    char endereco[200];
    char aniversario[11];  // Incluindo espaço para a terminação nula
} Contato;

void inserirContato(Contato *agenda[], int *ocupados) {
    if (*ocupados < MAX_CONTATOS) {
        agenda[*ocupados] = (Contato *)malloc(sizeof(Contato));
        if (agenda[*ocupados]) {
            printf("Digite o nome: ");
            scanf(" %[^\n]", agenda[*ocupados]->nome);
            printf("Digite o telefone: ");
            scanf(" %[^\n]", agenda[*ocupados]->telefone);
            printf("Digite o celular: ");
            scanf(" %[^\n]", agenda[*ocupados]->celular);
            printf("Digite o endereco: ");
            scanf(" %[^\n]", agenda[*ocupados]->endereco);
            printf("Digite o aniversario: ");
            scanf(" %[^\n]", agenda[*ocupados]->aniversario);
            (*ocupados)++;
            printf("Contato inserido com sucesso!\n");
        } else {
            printf("Erro ao alocar memória para o contato.\n");
        }
    } else {
        printf("Agenda cheia! Não é possível adicionar mais contatos.\n");
    }
}

void visualizarContato(Contato *agenda[], int ocupados) {
    int posicao;
    printf("Digite a posição do contato que deseja visualizar (1 a %d): ", ocupados);
    scanf("%d", &posicao);

    if (posicao >= 1 && posicao <= ocupados) {
        printf("Nome: %s\n", agenda[posicao - 1]->nome);
        printf("Telefone: %s\n", agenda[posicao - 1]->telefone);
        printf("Celular: %s\n", agenda[posicao - 1]->celular);
        printf("Endereco: %s\n", agenda[posicao - 1]->endereco);
        printf("Aniversario: %s\n", agenda[posicao - 1]->aniversario);
    } else {
        printf("Posição inválida. Digite uma posição válida.\n");
    }
}

int main() {
    Contato *agenda[MAX_CONTATOS];
    int ocupados = 0;
    int opcao;

    for (int i = 0; i < MAX_CONTATOS; i++) {
        agenda[i] = NULL;
    }

    do {
        printf("\nOpções:\n");
        printf("1 - Inserir contato\n");
        printf("2 - Visualizar contato\n");
        printf("3 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirContato(agenda, &ocupados);
                break;
            case 2:
                visualizarContato(agenda, ocupados);
                break;
            case 3:
                printf("Saindo da agenda.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    // Liberar a memória alocada para os contatos
    for (int i = 0; i < ocupados; i++) {
        free(agenda[i]);
    }

    return 0;
}
