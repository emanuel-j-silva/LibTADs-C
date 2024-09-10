#include <stdio.h>
#include <stdlib.h>

//   **********IMPLEMENTAÇÃO DE FILA ENCADEADA **********

typedef struct _no{
    int elem;
    struct _no *prox;
} t_no;

typedef struct{
    int n;
    t_no *inicio;
    t_no *fim;
} t_fila_enc;

t_fila_enc* criar(){
    t_fila_enc *fila_enc = (t_fila_enc*) malloc(sizeof(t_fila_enc));
    fila_enc->n = 0;
    fila_enc->inicio = NULL;
    fila_enc->fim = NULL;
    return fila_enc;
}

void limpar(t_fila_enc *fila_enc){
    fila_enc->n = 0;
    fila_enc->inicio = NULL;
    fila_enc->fim = NULL;
}

int vaziaa(t_fila_enc *fila_enc){
    return fila_enc->n == 0;
}

void inn(t_fila_enc *fila_enc, int elem){
    t_no *no = (t_no*) malloc(sizeof(t_no));
    no->elem = elem;
    no->prox = NULL;
    if(vaziaa(fila_enc)){
        fila_enc->inicio = no;
        fila_enc->fim = no;
    }
    else{
        fila_enc->fim->prox = no;
        fila_enc->fim = no;
    }
    fila_enc->n++;
}

int outt(t_fila_enc *fila_enc){
    if(!vaziaa(fila_enc)){
        fila_enc->inicio = fila_enc->inicio->prox;
        fila_enc->n--;
        return 1;
    }
    return 0;
}

void printar(t_fila_enc *fila_enc){
    if(vaziaa(fila_enc)){
        printf("FILA VAZIA!\n");
    }
    else{
        t_no *no = fila_enc->inicio;
        while (no != NULL){
            printf("%d\n", no->elem);
            no = no->prox;
        }
    }
}

int sizee(t_fila_enc *fila_enc){
    return fila_enc->n;
}

void frontt(t_fila_enc *fila_enc){
    if(vaziaa(fila_enc)){
        printf("FILA VAZIA!\n");
    }
    else{
        printf("%d\n",fila_enc->inicio->elem);
    }
}

void menuFilaEnc(){
    int opcao;
    do{
        printf("Implementacao de fila encadeada\n");
        printf("1 - Criar Fila\n");
        printf("2 - Inserir\n");
        printf("3 - Remover\n");
        printf("4 - Imprimir\n");
        printf("5 - Ver quantidade de elementos da fila\n");
        printf("6 - Limpar fila\n");
        printf("7 - Ver elemento do inicio da fila\n");
        printf("0 - Sair\n");
        scanf("%d%*c", &opcao);
        int elem;
        t_fila_enc *fila_enc;
        switch (opcao){
        case 1:
            fila_enc = criar();
            break;
        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d%*c", &elem);
            inn(fila_enc,elem);
            break;
        case 3:
            printf("Removendo o elemento...");
            outt(fila_enc);
            break;
        case 4:
            printf("Imprimindo fila...\n");
            printar(fila_enc);
            break;
        case 5:
            printf("Imprimindo tamanho da fila...\n");
            printf("Quantidade de elementos na fila: %d\n", sizee(fila_enc));
            break;
        case 6:
            printf("Limpando fila...\n");
            limpar(fila_enc);
            break;
        case 7:
            printf("Exibindo inicio da fila...\n");
            frontt(fila_enc);
            break;
        case 0:
		    printf("Opcao escolhida: SAIR\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}

