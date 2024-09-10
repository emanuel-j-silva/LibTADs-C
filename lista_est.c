#include <stdio.h>
#include <stdlib.h>

//   **********IMPLEMENTAÇÃO DE LISTA ESTÁTICA **********

typedef int t_elem;

typedef struct{
    int n;
    int max;
    t_elem *itens;
} t_lista;

t_lista* createList(int tam){
    t_lista *lista = (t_lista*) malloc(sizeof(t_lista));
    lista->n = 0;
    lista->max = tam;
    lista->itens = (t_elem*) malloc(sizeof(t_elem) * tam);
    return lista;
}

int isEmpty(t_lista *lista){
    return lista->n == 0;
}

int isFull(t_lista *lista){
    return lista->n == lista->max;
}

int ssize(t_lista *lista){
    return lista->n;
}

int append(t_lista *lista, t_elem elem){
    if(!isFull(lista)){
        lista->itens[lista->n] = elem;
        lista->n++;
        return 1;
    }
    return 0; 
}

int insert(t_lista *lista, int index, t_elem elem){
    int i;
    if(!isFull(lista) && index < lista->n){
        for(i= lista->n-1; i>= index;i--){
            lista->itens[i+1] = lista->itens[i]; 
        }
        lista->itens[index] = elem;
        lista->n++;
        return 1;
    }
    return 0;
}

int update(t_lista *lista, int index, t_elem elem){
    if(!isEmpty(lista) && index < lista->n){
        lista->itens[index] = elem;
        return 1;
    }
    return 0;
}

int removeByIndex(t_lista *lista, int index){
    if(!isEmpty(lista) && index < lista->n){
        int i;
        for(i=index; i < lista->n-1;i++){
            lista->itens[i] = lista->itens[i+1];
        }
        lista->n--;
        return 1;
    }
    return 0;
}
int indexOf(t_lista *lista, t_elem elem){
    if(!isEmpty(lista)){
        int i=0;
        int achou=0;
        while(achou == 0 && i < lista->n){
            if(lista->itens[i] == elem){
                achou = 1;
            }
            i++;
        }
        if(achou == 1){
            return i-1;
        }
        return -1;
    }
    return -1;   
}

int removeByElement(t_lista *lista, t_elem elem){
    if(!isEmpty(lista)){
        if(indexOf(lista,elem) == -1){
            return 0;
        }
        else{
            int i;
            for(i=indexOf(lista,elem); i < lista->n-1;i++){
                lista->itens[i] = lista->itens[i+1];
            }
            lista->n--;
            return 1;
        }
    }
    return 0;
}

int get(t_lista *lista, int index){
    if(!isEmpty(lista) && index < lista->n){
        return lista->itens[index];
    }
    return -1;
}

int count(t_lista *lista, t_elem elem){
    int cont=0;
    int i;
    if(!isEmpty(lista)){
        for(i=0; i < lista->n;i++){
            if(lista->itens[i] == elem){
                cont++;
            }
        }
    }
    return cont;
}

void printa(t_lista *lista){
    int i;
    for(i=0;i<lista->n;i++){
        printf("%d\n",lista->itens[i]);
    }
    printf("\n");
}

void cclear(t_lista *lista){
    free(lista->itens);
    lista->n = 0;
}

void menuLista(){
    int opcao;
    do{
        printf("Implementacao de lista estatica\n");
        printf("1 - Criar Lista\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir pelo indice\n");
        printf("4 - Atualizar elemento\n");
        printf("5 - Remover pelo indice\n");
        printf("6 - Remover pelo elemento\n");
        printf("7 - Encontrar indice do elemento\n");
        printf("8 - Encontrar elemento pelo indice\n");
        printf("9 - Contar ocorrencias de um elemento\n");
        printf("10 - Imprimir\n");
        printf("11 - Mostrar numero de elementos na lista\n");
        printf("12 - Limpar lista\n");
        printf("0 - Sair\n");
        scanf("%d%*c", &opcao);
        int tam;
        int elem;
        int index;
        t_lista *lista;
        switch (opcao){
        case 1:
            printf("Digite o tamanho da lista: ");
            scanf("%d%*c",&tam);
            lista = createList(tam);
            break;
        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d%*c", &elem);
            if(append(lista,elem)){
                printf("Inseriu com sucesso!\n");
            }
            else{
                printf("LISTA CHEIA!\n");
            }
            break;
        case 3:
            printf("Digite o indice para inserir: ");
            scanf("%d%*c",&index);
            printf("Digite o elemento a ser inserido: ");
            scanf("%d%*c",&elem);
            if(insert(lista,index,elem)){
                printf("Inseriu com sucesso!\n");
            }
            else{
                printf("Algo deu errado, tente novamente.\n");
            }
            break;
        case 4:
            printf("Digite o indice a ser atualizado: ");
            scanf("%d%*c",&index);
            printf("Digite o novo elemento: ");
            scanf("%d%*c",&elem);
            if(update(lista,index,elem)){
                printf("Atualizou com sucesso!\n");
            }
            else{
                printf("Algo deu errado, tente novamente.\n");
            }
            break;
        case 5:
            printf("Digite o indice a ser removido: ");
            scanf("%d%*c",&index);
            if(removeByIndex(lista,index)){
                printf("Removeu com sucesso!\n");
            }
            else{
                printf("Algo deu errado, tente novamente.\n");
            }
            break;
        case 6:
            printf("Digite o elemento a ser removido: ");
            scanf("%d%*c",&elem);
            if(removeByElement(lista,elem)){
                printf("Removeu com sucesso!\n");
            }
            else{
                printf("Elemento nao encontrado, tente novamente!\n");
            }
            break;
        case 7:
            printf("Digite o elemento a ser procurado: ");
            scanf("%d%*c",&elem);
            if(indexOf(lista,elem) == -1){
                printf("Elemento nao encontrado!\n");
            }
            else{
                printf("%d - indice %d\n",lista->itens[indexOf(lista,elem)],indexOf(lista,elem));
            }
            break;
        case 8:
            printf("Digite o indice: ");
            scanf("%d%*c",&index);
            if(get(lista,index) == -1){
                printf("Algo deu errado, tente novamente!\n");
            }
            else{
                printf("Elemento do indice %d: %d",index,lista->itens[index]);
            }
            break;
        case 9:
            printf("Digite o elemento procurado: ");
            scanf("%d%*c",&elem);
            printf("Ocorrencias do numero %d: %d",elem,count(lista,elem));
            break;
        case 10:
            printf("Imprimindo lista...\n");
            printa(lista);
            break;
        case 11:
            printf("Numero de elementos da lista: %d\n",ssize(lista));
            break;
        case 12:
            printf("Limpando lista...\n");
            cclear(lista);
            break;
        case 0:
		    printf("Opcao escolhida: SAIR\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    }while(opcao!=0);
}
