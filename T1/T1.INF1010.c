/*JULIANA JOAO VICTOR AMORIM */

#include <stdio.h>
#include <stdlib.h>
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