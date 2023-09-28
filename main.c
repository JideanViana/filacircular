#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 3

int fila[TAMANHO];
int inicio = -1, fim = -1;


void inserir(int valor) {
    if ((fim + 1) % TAMANHO == inicio) {
        printf("\nFila cheia!\n");
        return;
    }

    if (inicio == -1) {
        inicio = 0;
        fim = 0;
    } else {
        fim = (fim + 1) % TAMANHO;
    }
    fila[fim] = valor;
    //printf("Elemento %d inserido na fila.\n", valor);
}

void remover() {
    if (inicio == -1) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    int valorRemovido = fila[inicio];

    if (inicio == fim) {
        inicio = -1;
        fim = -1;
    } else {
        inicio = (inicio + 1) % TAMANHO;
    }

    printf("\nElemento %d removido da fila.\n", valorRemovido);
}

int buscar(int valor) {
    if (inicio == -1) {
        printf("\nA fila esta vazia. Nenhum valor para buscar.\n");
        return -1;
    }

    int posicao = inicio;
    int contador = 0;

    do {
        if (fila[posicao] == valor) {
            printf("\nValor %d encontrado na posicao %d da fila.\n", valor, contador);
            return posicao;
        }

        posicao = (posicao + 1) % TAMANHO;
        contador++;
    } while (posicao != (fim + 1) % TAMANHO);

    printf("\nValor %d nao encontrado na fila.\n", valor);
    return -1;
}

void imprimir() {
    if (inicio == -1) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    printf("\nFila: ");
    int posicao = inicio;
    do {
        printf("%d ", fila[posicao]);
        posicao = (posicao + 1) % TAMANHO;
    } while (posicao != (fim + 1) % TAMANHO);

    printf("\n");
}

int main() {
    int opcao, valor;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Inserir \n");
        printf("2. Remover \n");
        printf("3. Buscar \n");
        printf("4. Imprimir \n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 2:
                remover();
                break;
            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                buscar(valor);
                break;
            case 4:
                imprimir();
                break;
            case 0:
                printf("Bye...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
