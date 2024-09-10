#include <stdio.h>
#include <stdlib.h>

#include "fila_est_circ.c"
#include "fila_encadeada.c"
#include "lista_est.c"
#include "pilha.c"


//   ********** PROGRAMA PRINCIPAL DE TESTES **********

void menuPrincipal(){
     int opcao;
    do{
        printf("Bem vindo ao programa de testes!\n");
        printf("Selecione a TAD a ser testada:\n");
        printf("1 - Fila Estatica Circular\n");
        printf("2 - Fila Encadeada\n");
        printf("3 - Lista Estatica\n");
        printf("4 - Pilha Duplamente Encadeada\n");
        printf("0 - Sair\n");
        scanf("%d%*c", &opcao);
        switch (opcao){
        case 1:
            menuFilaCirc();
            break;
        case 2:
            menuFilaEnc();
            break;
        case 3:
            menuLista();
            break;
        case 4:
            menuStack();
            break;
        case 0:
		    printf("Opcao escolhida: SAIR\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}

int main(){
    menuPrincipal();
    return 0;
}