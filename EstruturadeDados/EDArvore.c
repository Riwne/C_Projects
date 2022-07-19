

#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
    
}VERTICE;


VERTICE * raiz = NULL; 
int tam = 0;



VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL; 
    }else if (x == aux->chave){
        return aux;
    }else if(x < aux->chave){ 
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{ 
        if(aux->dir == NULL){
            return aux;
        }else{
            return buscar(x, aux->dir);
        }
    }
}

void adicionar(int chave){
   VERTICE* aux = buscar(chave, raiz);
    if(aux != NULL && aux->chave == chave){
        //chave já existe na árvore!
        printf("insercao invalida!\n");
    }else{
        VERTICE* novo = malloc(sizeof(VERTICE));
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        if(aux == NULL){ 
            raiz = novo;
        }else if(chave < aux->chave){
            aux->esq = novo;
        }else{ 
            aux->dir = novo;
        }
    }
}

int altura_no (int chave){

return 0;
}

void in_ordem(VERTICE *aux){
    
    if(aux->esq != NULL){
        in_ordem(aux->esq);
    }
    
    printf("%d ", aux->chave);
    
    if(aux->dir != NULL){
        in_ordem(aux->dir);
    }
}


VERTICE* buscarNo(int chave, VERTICE *raiz){
    if(raiz == NULL){
        return NULL; 
    }else if (chave == raiz->chave){
        return raiz;
    }else if(chave < raiz->chave){ 
        if(raiz->esq == NULL){
            return raiz;
        }else{
            return buscar(chave, raiz->esq);
        }
    }else{ 
        if(raiz->dir == NULL){
            return raiz;
        }else{
            return buscar(chave, raiz->dir);
        }
    }
}

int SubAltura(VERTICE *raiz){
    if(raiz == NULL || raiz->dir == NULL && raiz->esq == NULL)
        return 0;
    else{
        int esq = 1 + SubAltura(raiz->esq);
        int dir = 1 + SubAltura(raiz->dir);
        if(esq > dir)
            return esq;
        else
            return dir;
        }
}

int altura_no(VERTICE *raiz, int chave){
    VERTICE *no = buscarNo(raiz, chave);
    if(no)
        return SubAltura(no);
    else
        return -1;
}


int main(){

    adicionar(8);
    adicionar(3);
    adicionar(10); 
    adicionar(6);
    adicionar(7);
    adicionar(4);
    adicionar(1);
    adicionar(14);
    adicionar(13);
    printf("\n Árvore in_ondem: \n");
    in_ordem(raiz);
    printf("\n Árvore altura do vertice: \n");
   

return 0;
}
