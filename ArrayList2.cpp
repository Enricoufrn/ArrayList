// ArrayList2.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdio.h>
#include <stdlib.h>

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

struct arraylist* inicializar(int capacidade);
int obterElementoEmPosicao(struct arraylist* lista, int posicao);
void duplicarCapacidade(struct arraylist* lista);
void inserirElementoNoFim(struct arraylist* lista, int valor);
void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao);
void atualizarElemento(struct arraylist* lista, int valor, int posicao);
void removerElementoNoFim(struct arraylist* lista);
void removerElementoEmPosicao(struct arraylist* lista, int posicao);
void exibirLista(struct arraylist* lista);

int main()
{
    struct arraylist* list = inicializar(3);
    inserirElementoNoFim(list, 1);
    inserirElementoNoFim(list, 2);
    inserirElementoNoFim(list, 3);
    inserirElementoNoFim(list, 4);
    exibirLista(list);
    printf("\n");
    printf("quantidade = %i || capacidade = %i\n",list->qtdade,list->capacidade);
    inserirElementoEmPosicao(list, -10, 2);
    exibirLista(list);
    printf("\n");
    printf("elemento da posicao 1: %i\n", obterElementoEmPosicao(list, 1));
    printf("mudando o elemento da posicao 3 para '-50'\n");
    atualizarElemento(list, -50, 3);
    exibirLista(list);
    printf("\n");
    removerElementoEmPosicao(list, 0);
    exibirLista(list);
    printf("\n");
    removerElementoNoFim(list);
    exibirLista(list);
    printf("\n");
}

struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

int obterElementoEmPosicao(arraylist* lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->qtdade) {
        return lista->vetor[posicao];
    }
}

void duplicarCapacidade(arraylist* lista)
{
    lista->capacidade *= 2;
    int* aux = lista->vetor;
    if ((lista->vetor = (int*)realloc(lista->vetor, sizeof(int) * lista->capacidade)) == NULL) {
        free(aux);
    }
}

void inserirElementoNoFim(arraylist* lista, int valor)
{
    if (lista->qtdade == lista->capacidade) {
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade += 1;
}

void inserirElementoEmPosicao(arraylist* lista, int valor, int posicao)
{
    if (posicao >= 0 && posicao <= lista->qtdade) {
        if (lista->qtdade == lista->capacidade) {
            duplicarCapacidade(lista);
        }
        for (int i = lista->qtdade; i > posicao; i--) {
            lista->vetor[i] = lista->vetor[i - 1];
        }
        lista->vetor[posicao] = valor;
        lista->qtdade++;
    }
}

void atualizarElemento(arraylist* lista, int valor, int posicao)
{
    if (posicao >= 0 && posicao <= lista->qtdade) {
        lista->vetor[posicao] = valor;
    }
}

void removerElementoNoFim(arraylist* lista)
{
    lista->qtdade--;
}

void removerElementoEmPosicao(arraylist* lista, int posicao)
{
    if (posicao >= 0 && posicao <= lista->qtdade) {
        for (int i = posicao; i < lista->qtdade; i++) {
            lista->vetor[i] = lista->vetor[i + 1];
        }
        lista->qtdade--;
    }
}

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1) {
            printf(", ");
        }
    }
    printf("]");
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
