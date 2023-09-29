include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da fila
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Definição da estrutura da fila
typedef struct Fila {
    No* frente; // Aponta para o elemento na frente da fila
    No* tras;   // Aponta para o elemento no final da fila
} Fila;

// Função para criar uma nova fila vazia
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = fila->tras = NULL;
    return fila;
}

// Função para inserir um elemento na fila (enfileirar)
void enfileirar(Fila* fila, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNo;
    } else {
        fila->tras->proximo = novoNo;
        fila->tras = novoNo;
    }
}

// Função para remover um elemento da fila (desenfileirar)
int desenfileirar(Fila* fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia\n");
        return -1; // Valor inválido para fila vazia
    }

    No* temp = fila->frente;
    int dado = temp->dado;

    fila->frente = fila->frente->proximo;

    // Se a fila ficar vazia após a remoção, atualize 'tras' também
    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    free(temp);
    return dado;
}

int main() {
    Fila* fila = criarFila();

    enfileirar(fila, 1);
    enfileirar(fila, 2);
    enfileirar(fila, 3);

    printf("Elemento removido: %d\n", desenfileirar(fila));
    printf("Elemento removido: %d\n", desenfileirar(fila));
    printf("Elemento removido: %d\n", desenfileirar(fila));

    // Tentando remover de uma fila vazia
    printf("Elemento removido: %d\n", desenfileirar(fila));

    free(fila); // Liberar a memória da fila

    return 0;
}
  
