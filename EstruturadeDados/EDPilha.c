
// Riane Carla Gomes Alves
// Matrícula: 508771

// A opção pilha foi escolhida pois é útil já que irei
// armazenar uma informalção temporariamente que vou usar logo depois. 


#include <stdio.h>
#include <string.h>


typedef struct no{
    char consoante;
    struct no * prox;
}NO;

NO * inicio = NULL;

int novaletra(char consoante){
    NO *troca = (NO*) malloc(sizeof(NO));
troca->consoante = consoante;    
troca->prox = inicio;
    inicio =troca;
}


int apagar (){
    NO * aux = inicio;
    for(aux = inicio; aux != NULL; aux = aux->prox){
        inicio = inicio->prox;
        char lixo = aux->consoante;
        free(lixo);
    }
}

int imprimir(){
    NO * aux = inicio;
    for(aux = inicio; aux != NULL; aux = aux->prox){
        printf("%c", aux->consoante);
    }
 apagar 
();
}

int main(){
    char frase[50] = "\0";

    printf("Digite a frase:\n");
    scanf("%[^\n]s", frase);
    
    for (int i = 0; i < strlen(frase); i++){
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'u' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == ' '){
            printf("%c", frase[i]);
        }else{
            if(frase[i+1] == 'a' || frase[i+1] == 'e' || frase[i+1] == 'i'|| frase[i+1] == 'o' || frase[i+1] == 'u' || frase[i+1] ==' '){
                printf("%c", frase[i]); 
            }else{ 
                for(i; frase[i]!= 'a' && frase[i]!= 'e' && frase[i]!= 'i'&& frase[i]!= 'o' && frase[i]!= 'u' && frase[i]!= ' '; i++){
                    novaletra(frase[i]);
                }
                imprimir();
                printf("%c", frase[i]);
             apagar 
            ();
            }
        }
    }
}