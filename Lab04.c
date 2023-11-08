#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg* prox;
};

typedef struct reg celula;

void imprimeLista(celula* lista) {
    celula* atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
}

size_t calculaTamanhoCelula() {
    return sizeof(celula);
}

celula* insereElemento(celula* lista, int valor) {
    celula* novaCelula = (celula*)malloc(sizeof(celula));
    if (novaCelula == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    novaCelula->conteudo = valor;
    novaCelula->prox = lista;
    return novaCelula;
}

void liberaLista(celula* lista) {
    celula* atual = lista;
    while (atual != NULL) {
        celula* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

int main() {
    celula* lista = NULL;

    // Criando três instâncias da célula
    lista = insereElemento(lista, 1);
    lista = insereElemento(lista, 2);
    lista = insereElemento(lista, 3);

    // Imprimindo os valores da lista
    imprimeLista(lista);

    // Calculando o tamanho de uma instância da célula
    size_t tamanhoCelula = calculaTamanhoCelula();
    printf("Tamanho de uma célula: %lu bytes\n", tamanhoCelula);

    // Removendo elementos da lista e liberando memória
    liberaLista(lista);
    lista = NULL;

    return 0;
}
