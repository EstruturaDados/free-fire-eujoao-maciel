#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ITENS 10
#define MAX_COMPONENTES 20

// ------------------- Structs -------------------
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

// ------------------- Vetor -------------------
Item mochilaVetor[MAX_ITENS];
int contadorVetor = 0;

// Inserir item no vetor
void inserirItemVetor() {
    if (contadorVetor >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return;
    }
    printf("Nome: ");
    scanf(" %[^\n]", mochilaVetor[contadorVetor].nome);
    printf("Tipo: ");
    scanf(" %[^\n]", mochilaVetor[contadorVetor].tipo);
    printf("Quantidade: ");
    scanf("%d", &mochilaVetor[contadorVetor].quantidade);
    contadorVetor++;
}

// Remover item do vetor
void removerItemVetor() {
    if (contadorVetor == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para remover: ");
    scanf(" %[^\n]", nome);
    int encontrado = 0;
    for (int i = 0; i < contadorVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < contadorVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            contadorVetor--;
            encontrado = 1;
            printf("Item removido!\n");
            break;
        }
    }
    if (!encontrado) printf("Item nao encontrado!\n");
}

// Listar itens do vetor
void listarItensVetor() {
    if (contadorVetor == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    for (int i = 0; i < contadorVetor; i++) {
        printf("%d. %s | %s | %d\n", i+1, mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
    }
}

// Busca sequencial no vetor
void buscarSequencialVetor() {
    if (contadorVetor == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nome);
    int comparacoes = 0;
    for (int i = 0; i < contadorVetor; i++) {
        comparacoes++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Encontrado: %s | %s | %d\n", mochilaVetor[i].nome, mochilaVetor[i].tipo, mochilaVetor[i].quantidade);
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// Ordenação por nome (Bubble Sort)
void ordenarVetor() {
    int comparacoes = 0;
    for (int i = 0; i < contadorVetor - 1; i++) {
        for (int j = 0; j < contadorVetor - i - 1; j++) {
            comparacoes++;
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j+1].nome) > 0) {
                Item temp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j+1];
                mochilaVetor[j+1] = temp;
            }
        }
    }
    printf("Vetor ordenado por nome! Comparacoes: %d\n", comparacoes);
}

// Busca binária no vetor
void buscarBinariaVetor() {
    if (contadorVetor == 0) {
        printf("Mochila vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para busca binaria: ");
    scanf(" %[^\n]", nome);
    int inicio = 0, fim = contadorVetor - 1, comparacoes = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim)/2;
        comparacoes++;
        int cmp = strcmp(mochilaVetor[meio].nome, nome);
        if (cmp == 0) {
            printf("Encontrado: %s | %s | %d\n", mochilaVetor[meio].nome, mochilaVetor[meio].tipo, mochilaVetor[meio].quantidade);
            printf("Comparacoes: %d\n", comparacoes);
            return;
        } else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// ------------------- Lista Encadeada -------------------
No* cabeca = NULL;

// Inserir item na lista
void inserirItemLista() {
    No* novo = (No*) malloc(sizeof(No));
    printf("Nome: ");
    scanf(" %[^\n]", novo->dados.nome);
    printf("Tipo: ");
    scanf(" %[^\n]", novo->dados.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);
    novo->proximo = cabeca;
    cabeca = novo;
}

// Remover item da lista
void removerItemLista() {
    if (!cabeca) {
        printf("Lista vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para remover: ");
    scanf(" %[^\n]", nome);
    No *atual = cabeca, *anterior = NULL;
    while (atual) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior) anterior->proximo = atual->proximo;
            else cabeca = atual->proximo;
            free(atual);
            printf("Item removido!\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item nao encontrado!\n");
}

// Listar itens da lista
void listarItensLista() {
    if (!cabeca) {
        printf("Lista vazia!\n");
        return;
    }
    No* atual = cabeca;
    int i = 1;
    while (atual) {
        printf("%d. %s | %s | %d\n", i, atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
        atual = atual->proximo;
        i++;
    }
}

// Busca sequencial na lista
void buscarSequencialLista() {
    if (!cabeca) {
        printf("Lista vazia!\n");
        return;
    }
    char nome[30];
    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nome);
    No* atual = cabeca;
    int comparacoes = 0;
    while (atual) {
        comparacoes++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Encontrado: %s | %s | %d\n", atual->dados.nome, atual->dados.tipo, atual->dados.quantidade);
            printf("Comparacoes: %d\n", comparacoes);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item nao encontrado! Comparacoes: %d\n", comparacoes);
}

// ------------------- Componentes da Torre -------------------
Componente torre[MAX_COMPONENTES];
int contadorComponentes = 0;

// Cadastro
void cadastrarComponentes() {
    int n;
    printf("Quantos componentes cadastrar (max 20): ");
    scanf("%d", &n);
    if (n > MAX_COMPONENTES) n = MAX_COMPONENTES;
    for (int i = 0; i < n; i++) {
        printf("Nome do componente: ");
        scanf(" %[^\n]", torre[i].nome);
        printf("Tipo: ");
        scanf(" %[^\n]", torre[i].tipo);
        printf("Prioridade (1-10): ");
        scanf("%d", &torre[i].prioridade);
    }
    contadorComponentes = n;
}

// Bubble Sort por nome
void bubbleSortNome() {
    int comparacoes = 0;
    clock_t inicio = clock();
    for (int i = 0; i < contadorComponentes -1; i++) {
        for (int j = 0; j < contadorComponentes - i -1; j++) {
            comparacoes++;
            if (strcmp(torre[j].nome, torre[j+1].nome) > 0) {
                Componente temp = torre[j];
                torre[j] = torre[j+1];
                torre[j+1] = temp;
            }
        }
    }
    clock_t fim = clock();
    printf("Bubble Sort por nome concluido! Comparacoes: %d, Tempo: %.6f s\n", comparacoes, (double)(fim-inicio)/CLOCKS_PER_SEC);
}

// Insertion Sort por tipo
void insertionSortTipo() {
    int comparacoes = 0;
    clock_t inicio = clock();
    for (int i = 1; i < contadorComponentes; i++) {
        Componente key = torre[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (strcmp(torre[j].tipo, key.tipo) > 0) {
                torre[j+1] = torre[j];
                j--;
            } else break;
        }
        torre[j+1] = key;
    }
    clock_t fim = clock();
    printf("Insertion Sort por tipo concluido! Comparacoes: %d, Tempo: %.6f s\n", comparacoes, (double)(fim-inicio)/CLOCKS_PER_SEC);
}

// Selection Sort por prioridade
void selectionSortPrioridade() {
    int comparacoes = 0;
    clock_t inicio = clock();
    for (int i = 0; i < contadorComponentes -1; i++) {
        int min_idx = i;
        for (int j = i+1; j < contadorComponentes; j++) {
            comparacoes++;
            if (torre[j].prioridade < torre[min_idx].prioridade) min_idx = j;
        }
        Componente temp = torre[i];
        torre[i] = torre[min_idx];
        torre[min_idx] = temp;
    }
    clock_t fim = clock();
    printf("Selection Sort por prioridade concluido! Comparacoes: %d, Tempo: %.6f s\n", comparacoes, (double)(fim-inicio)/CLOCKS_PER_SEC);
}

// Busca binária por nome
void buscaBinariaNome() {
    char nome[30];
    printf("Nome do componente para busca binaria: ");
    scanf(" %[^\n]", nome);
    int inicio = 0, fim = contadorComponentes-1, comparacoes = 0;
    while (inicio <= fim) {
        int meio = (inicio + fim)/2;
        comparacoes++;
        int cmp = strcmp(torre[meio].nome, nome);
        if (cmp == 0) {
            printf("Componente encontrado: %s | %s | %d\n", torre[meio].nome, torre[meio].tipo, torre[meio].prioridade);
            printf("Comparacoes: %d\n", comparacoes);
            return;
        } else if (cmp < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    printf("Componente nao encontrado! Comparacoes: %d\n", comparacoes);
}

// Mostrar componentes
void mostrarComponentes() {
    printf("\nComponentes:\n");
    for (int i = 0; i < contadorComponentes; i++) {
        printf("%d. %s | %s | %d\n", i+1, torre[i].nome, torre[i].tipo, torre[i].prioridade);
    }
}

// ------------------- Menu -------------------
int main() {
    int opcao;
    do {
        printf("\n--- Sistema de Mochila e Torre ---\n");
        printf("1 - Vetor (lista sequencial)\n2 - Lista encadeada\n3 - Componentes da torre\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            int sub;
            do {
                printf("\n--- Vetor ---\n1-Inserir 2-Remover 3-Listar 4-Busca sequencial 5-Ordenar 6-Busca binaria 0-Voltar\nEscolha: ");
                scanf("%d", &sub);
                switch(sub) {
                    case 1: inserirItemVetor(); break;
                    case 2: removerItemVetor(); break;
                    case 3: listarItensVetor(); break;
                    case 4: buscarSequencialVetor(); break;
                    case 5: ordenarVetor(); break;
                    case 6: buscarBinariaVetor(); break;
                }
            } while(sub != 0);
        } else if (opcao == 2) {
            int sub;
            do {
                printf("\n--- Lista Encadeada ---\n1-Inserir 2-Remover 3-Listar 4-Busca sequencial 0-Voltar\nEscolha: ");
                scanf("%d", &sub);
                switch(sub) {
                    case 1: inserirItemLista(); break;
                    case 2: removerItemLista(); break;
                    case 3: listarItensLista(); break;
                    case 4: buscarSequencialLista(); break;
                }
            } while(sub != 0);
        } else if (opcao == 3) {
            int sub;
            do {
                printf("\n--- Componentes da Torre ---\n1-Cadastrar 2-Bubble sort (nome) 3-Insertion sort (tipo) 4-Selection sort (prioridade) 5-Busca binaria (nome) 6-Mostrar 0-Voltar\nEscolha: ");
                scanf("%d", &sub);
                switch(sub) {
                    case 1: cadastrarComponentes(); break;
                    case 2: bubbleSortNome(); break;
                    case 3: insertionSortTipo(); break;
                    case 4: selectionSortPrioridade(); break;
                    case 5: buscaBinariaNome(); break;
                    case 6: mostrarComponentes(); break;
                }
            } while(sub != 0);
        }
    } while(opcao != 0);
    return 0;
}
