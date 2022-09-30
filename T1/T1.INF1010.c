/*JULIANA JOAO VICTOR AMORIM */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 10

struct pilha
{
    int topo;
    char vet[TAM];
};
typedef struct pilha Pilha;

Pilha* pilhaCria(){
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL){
        printf("erro ao alocar pilha\n");
    }
    pilha->topo = "\0";
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

int shuting(Pilha* pilha){
    char aux;
    while(pilha->vet[pilha->topo]!='\0'){
        if(isalnum(pilha->vet[pilha->topo])){
            printf("%c",pilha->vet[pilha->topo]);
        }
        else if(pilha->vet[pilha->topo]=='('){
            pilhaPush(pilha,'(');
        }
        else if(pilha->vet[pilha->topo]==')'){
            while((aux = pilhaPop(pilha))!='('){
                printf("%c",aux)aa;
            }
        }
        else{
            while(prioridade(pilha->vet[pilha->topo]) >= prioridade('a')) printf("a");
        }
    }
}

int main(void){
    char teste[] = "3 + 2 x 3 = 9";

}