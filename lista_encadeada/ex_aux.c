#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int num;
    struct no *prox;
};


No* criar_no(){
    No *novo = (No*)malloc(sizeof(No));
    return novo;
}


No* inserir_elemento_inicio(No* Lista, int dado){
    No *novo_no = criar_no();
    novo_no->num = dado;

    if(Lista == NULL){
        Lista = novo_no;
        novo_no->prox = NULL;
    }else{
        novo_no->prox = Lista;
        Lista = novo_no;
    }
    return Lista;
}


No* inserir_elemento_fim(No* Lista, int dado){
    No *novo_no = criar_no();
    novo_no->num = dado;

    if(Lista == NULL){
        Lista = novo_no;
        novo_no->prox = NULL;
    }else{
        No *aux = Lista;
        
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        novo_no->prox = NULL;
        aux->prox = novo_no;
    }
    return Lista;
}


void imprimir_lista(No* Lista){
    No *aux = Lista;
    
    while(aux != NULL){
        printf("%d ", aux->num);
        aux = aux->prox; 
    }
}


int main(){

    No *Lista = NULL;

    Lista = inserir_elemento_inicio(Lista, 5);
    Lista = inserir_elemento_inicio(Lista, 10);
    Lista = inserir_elemento_inicio(Lista, 15);
    Lista = inserir_elemento_inicio(Lista, 20);
    imprimir_lista(Lista);

    return 0;
}