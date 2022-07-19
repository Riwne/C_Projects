//@Riwne

#include<stdio.h>
#include<stdlib.h>

typedef struct vertice{
    int chave;
    struct vertice * dir;
    struct vertice * esq;
}VERTICE;

VERTICE * raiz = NULL; //vazia!!!!
int tam = 0;

int nivel(int x, VERTICE *aux){
   if (x == aux->chave){
        return 0;
    }else if(x < aux->chave){ //esq
        if(aux->esq == NULL){
            printf("valor inesistente\n");
            return 0;
        }else{
            return nivel(x, aux->esq) + 1;
        }
    }else{ //dir
        if(aux->dir == NULL){
            printf("valor inesistente\n");
            return 0;
        }else{
            return nivel(x, aux->dir) + 1;
        }
    }
}

VERTICE* buscar(int x, VERTICE *aux){
    if(aux == NULL){
        return NULL; //vazia
    }else if (x == aux->chave){
        return aux;
    }else if(x < aux->chave){ //esq
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(x, aux->esq);
        }
    }else{ //dir
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
        if(aux == NULL){ //vazia
            raiz = novo;
        }else if(chave < aux->chave){//esq
            aux->esq = novo;
        }else{ //dir
            aux->dir = novo;
        }
    }
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

VERTICE* buscarNo(int chave, VERTICE *aux){
    if(aux == NULL){
        return NULL; 
    }else if (chave == aux->chave){
        return aux;
    }else if(chave < aux->chave){ 
        if(aux->esq == NULL){
            return aux;
        }else{
            return buscar(chave, aux->esq);
        }
    }else{ 
        if(aux->dir == NULL){
            return aux;
        }else{
            return buscar(chave, aux->dir);
        }
    }
}

int SubAltura(VERTICE *aux){
    if(aux == NULL || aux->dir == NULL && aux->esq == NULL)
        return 0;
    else{
        int esq = 1 + SubAltura(aux->esq);
        int dir = 1 + SubAltura(aux->dir);
        if(esq > dir) return esq;
        else return dir;
    }
}

int altura_no(int chave){
    VERTICE * no = buscarNo(chave, raiz);
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
    adicionar(9);
    adicionar(12);
    adicionar(20);
    adicionar(17);
    adicionar(21);
    adicionar(32);
    adicionar(25);
    adicionar(12);
    adicionar(18);
    adicionar(22);
    adicionar(16);
    printf("\n Arvore in_ondem: \n");
    in_ordem(raiz);
    printf("\n");
    printf("\n Arvore altura do vertice: %d\n", altura_no(8));
    printf("\n Arvore altura do vertice: %d\n", altura_no(4));
    printf("\n Arvore altura do vertice: %d\n", altura_no(1));
    printf("\n Arvore altura do vertice: %d\n", altura_no(10));
    printf("\n Arvore altura do vertice: %d\n", altura_no(14));
    printf("\n Arvore nível do vertice: %d\n", nivel(13, raiz));
    printf("\n Arvore nível do vertice: %d\n", nivel(6, raiz));
    printf("\n Arvore nível do vertice: %d\n", nivel(3, raiz));
    printf("\n Arvore nível do vertice: %d\n", nivel(4, raiz));
    printf("\n Arvore nível do vertice: %d\n", nivel(1, raiz));
return 0;
}
