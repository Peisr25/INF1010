/*JULIANA JOAO VICTOR AMORIM */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 12

struct pilha
{
    int topo;
    char vet[TAM];
};
typedef struct pilha Pilha;

Pilha* pilhaCria(){
    int i;
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL){
        printf("erro ao alocar pilha\n");
    }
    for(i=0;i<TAM;i++){
      pilha->vet[i] = '\0';
    }
    pilha->topo = 0;
    return pilha;
}

int pilhaVazia(Pilha* pilha){
    if(pilha->topo==0){
        return 1;
    }
    return 0;
}

void pilhaPush(Pilha* pilha,char v){
    if(pilha->topo==TAM){
        printf("Pilha atingiu seu limite\n");
        exit(1);
    }
    pilha->vet[pilha->topo] = v;
    pilha->topo++;
}
char pilhaPop(Pilha* pilha){
    char v;
    if(pilhaVazia(pilha)){
        printf("Pilha Vazia\n");
        exit(1);
    }
    v = pilha->vet[pilha->topo-1];
    pilha->topo--;
    return v;
}
void pilhaLibera(Pilha* pilha){
    free(pilha);
}

int prioridade(char aux){
    if(aux == '(')
        return 0;
    if(aux == '+' || aux == '-')
        return 1;
    if(aux == '*' || aux == '/')
        return 2;
    return 0;
}

int shuting(char* exp){
    char aux;
    Pilha* pilha = pilhaCria();

    while(*exp!='\0'){
        if(isalnum(*exp)){
            printf("%c",*exp);
        }
        else if(*exp =='('){
            pilhaPush(pilha,*exp);
        }
        else if(*exp ==')'){
            while((aux = pilhaPop(pilha)) != '('){
                printf("%c",aux);
            }
        }
        //else if(*exp == ' ') *exp++;
        else{
            while(prioridade(pilha->vet[pilha->topo]) >= prioridade(*exp)) 
                printf("%c",pilhaPop(pilha));
            pilhaPush(pilha,*exp);
        }
        *exp++;
    }
    while (pilha->topo != -1)
    {
        printf("%c",pilhaPop(pilha));
    }
    return 0;
    
}

int main(void){
    char teste[] = "2+(3x(8-4))";
    int ret = shuting(&teste);
    return 0;
}