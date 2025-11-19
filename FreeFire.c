#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

Item mochila[MAX_ITENS];
int contador = 0;

void inserirItem() {
    if (contador >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }
    printf("Nome do item: ");
    scanf(" %[^\n]", mochila[contador].nome);
    printf("Tipo do item: ");
    scanf(" %[^\n]", mochila[contador].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochila[contador].quantidade);
    contador++;
}

void removerItem() {
    if (contador == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para remover: ");
    scanf(" %[^\n]", nome);
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < contador - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            contador--;
            encontrado = 1;
            printf("Item removido!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Item nao encontrado!\n");
    }
}

void listarItens() {
    if (contador == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    for (int i = 0; i < contador; i++) {
        printf("Item %d: %s | Tipo: %s | Quantidade: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void buscarItem() {
    if (contador == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nome);
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item nao encontrado!\n");
    }
}

int main() {
    int opcao;
    do {
        printf("\n1 - Inserir item\n2 - Remover item\n3 - Listar itens\n4 - Buscar item\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
    } while(opcao != 0);
    return 0;
}
