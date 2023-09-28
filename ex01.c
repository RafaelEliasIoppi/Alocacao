#include <stdio.h>
#include <stdlib.h>  // Incluindo para malloc e free

typedef struct {
    char nome[40];
    char telefone[15];
} contato;

int main(int argc, char *argv[]) {
    contato *teste;

    // Aloque memória para a estrutura contato e verifique se a alocação foi bem-sucedida
    teste = (contato *)malloc(sizeof(contato));
    if (teste == 0) { 
        printf("Erro ao alocar memória. O programa continuará, mas o uso da memória alocada pode causar falhas.\n");
    } else {
        printf("Digite seu nome: ");
        fgets(teste->nome, sizeof(teste->nome), stdin);

        // Remova o caractere de nova linha da entrada do nome
        size_t len = strlen(teste->nome);
        if (len > 0 && teste->nome[len - 1] == '\n') {
            teste->nome[len - 1] = '\0';
        }

        strcpy(teste->telefone, "1234567");

        printf("Nome = %s\nTelefone = %s\n", teste->nome, teste->telefone);

        // Libere a memória alocada
        free(teste);
    }

    return 0;
}
