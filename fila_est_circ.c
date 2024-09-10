#include <stdio.h>
#include <stdlib.h>

//   **********IMPLEMENTAÇÃO DE FILA COM VETOR ESTÁTICO E CIRCULAR**********

typedef int t_elem;

typedef struct{
    int n;
    int inicio;
    int fim;
    int max;
    t_elem *itens;
} t_fila;

t_fila* create(int tam){
    t_fila *fila = (t_fila*) malloc(sizeof(t_fila));
    fila->n = 0;
    fila->inicio = 0;
    fila->fim = 0;
    fila->max = tam;
    fila->itens = (t_elem*) malloc (sizeof(t_elem) * tam);
    return fila;
}

void clear(t_fila *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->n = 0;
}

int vazia(t_fila *fila){
    return fila->n == 0;
}

void in(t_fila *fila, t_elem elem){
    fila->itens[fila->fim] = elem;
    fila->fim = (fila->fim+1) % fila->max;
    fila->n++;
}

int out(t_fila *fila, t_elem *elem){
    if(!vazia(fila)){
        *elem = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio+1) % fila->max;
        fila->n--;
        return 1;
    }
    return 0;
}
void print(t_fila *fila){
    int i=0;
    for(i = fila->inicio;i != fila->fim; i=(i+1) % fila->max){
        printf("%d\n",fila->itens[i]);
    }
    printf("\n");
}

int size(t_fila *fila){
    return fila->n;
}

void front(t_fila *fila){
    if(vazia(fila)){
        printf("FILA VAZIA!\n");
    }
    else{
        printf("%d\n",fila->itens[fila->inicio]);
    }
}

void menuFilaCirc(){
    int opcao;
    do{
        printf("Implementacao de fila\n");
        printf("1 - Criar Fila\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir\n");
        printf("5 - Ver quantidade de elementos da fila\n");
        printf("6 - Limpar fila\n");
        printf("7 - Ver elemento do inicio da fila\n");
        printf("0 - Sair\n");
        scanf("%d%*c", &opcao);
        int tam;
        int elem;
        int x;
        t_fila *fila;
        switch (opcao){
        case 1:
            printf("Digite o tamanho da fila: ");
            scanf("%d%*c", &tam);
            fila = create(tam);
            break;
        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d%*c", &elem);
            in(fila,elem);
            break;
        case 3:
            printf("Removendo o elemento...");
            out(fila,&x);
            break;
        case 4:
            printf("Imprimindo fila...\n");
            print(fila);
            break;
        case 5:
            printf("Imprimindo tamanho da fila...\n");
            printf("Quantidade de elementos na fila: %d\n", size(fila));
            break;
        case 6:
            printf("Limpando fila...\n");
            clear(fila);
            break;
        case 7:
            printf("Exibindo inicio da fila...\n");
            front(fila);
            break;
        case 0:
		    printf("Opcao escolhida: SAIR\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}
