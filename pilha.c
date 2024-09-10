#include <stdio.h>
#include <stdlib.h>

//   **********IMPLEMENTAÇÃO DE PILHA DUPLAMENTE ENCADEADA **********


typedef struct _noo{
    int elem;
    struct _noo *prox;
    struct _noo *ant;

} t_noo;

typedef struct{
    int topo;
    t_noo *fim;
} t_pilha_dup_enc;

t_pilha_dup_enc* createStack(){
    t_pilha_dup_enc *pilha = (t_pilha_dup_enc*) malloc(sizeof(t_pilha_dup_enc));
    pilha->fim = NULL;
    pilha->topo = -1;
    return pilha;
}

void limp(t_pilha_dup_enc *pilha){
    pilha->topo= -1;
    pilha->fim = NULL;
}

int isEmptyStack(t_pilha_dup_enc *pilha){
    return pilha->topo == -1;
}

void push(t_pilha_dup_enc *pilha, int elem){
    t_noo *noo = (t_noo*) malloc(sizeof(t_noo));
    noo->elem = elem;
    noo->prox = NULL;
    if(isEmptyStack(pilha)){
        noo->ant = NULL;
    }
    else{
        noo->ant = pilha->fim;
        pilha->fim->prox = noo;
    }
    pilha->fim = noo;  
    pilha->topo++;
}

int pop(t_pilha_dup_enc *pilha){
    if(!isEmptyStack(pilha)){
        t_noo *aux = pilha->fim;
        if(pilha->topo != 0){
            aux->ant->prox = NULL;
        }
        pilha->fim = aux->ant;
        pilha->topo--;
        free(aux);
        return 1;
    }
    return 0;
}
int top(t_pilha_dup_enc *pilha){
    return pilha->fim->elem;
}

int sizeStack(t_pilha_dup_enc *pilha){
    int size = pilha->topo + 1;
    return size;
}

void printStack(t_pilha_dup_enc *pilha){
    if(isEmptyStack(pilha)){
        printf("PILHA VAZIA!\n");
    }
    t_noo *noo = pilha->fim;
    while(noo != NULL){
        printf("%d\n",noo->elem);
        noo=noo->ant;
    }
}

void menuStack(){
    int opcao;
    do{
        printf("Implementacao de fila encadeada\n");
        printf("1 - Criar Pilha\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir\n");
        printf("5 - Ver elemento do topo da pilha\n");
        printf("6 - Ver quantidade de elementos na pilha\n");
        printf("7 - Limpar pilha\n");
        printf("0 - Sair\n");
        scanf("%d%*c", &opcao);
        int elem;
        t_pilha_dup_enc *pilha;
        switch (opcao){
        case 1:
            pilha = createStack();
            break;
        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d%*c", &elem);
            push(pilha,elem);
            break;
        case 3:
            if(pop(pilha)){
                printf("Removendo o elemento...\n");
            }
            else{
                printf("ERRO, PILHA VAZIA!\n");
            }
            break;
        case 4:
            printf("Imprimindo pilha...\n");
            printStack(pilha);
            break;
        case 5:
            if(!isEmptyStack(pilha)){
                printf("Elemento do topo: %d\n",top(pilha));
            }
            else{
                printf("ERRO, PILHA VAZIA!\n");
            }
            break;
        case 6:
            printf("Numero de elementos da pilha: %d\n",sizeStack(pilha));
            break;
        case 7:
            limp(pilha);
            break;
        case 0:
		    printf("Opcao escolhida: SAIR\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}