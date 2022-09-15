#include <stdlib.h>
#include <stdio.h>
#define TAM 3

typedef struct pilha Pilha;
struct pilha{
    int topo;
    int Pilha[TAM];
};

Pilha* pilhaCria(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p==NULL) exit(1);
    p->topo =0;
    return p;
}
void pilhaInsere(Pilha* p,int val){
    if(p->topo==TAM){
        printf("Pilha atingiu sua capaciadade maxima\n");
        exit(1);
    }
    p->Pilha[p->topo]=val;
    p->topo++;
}
int moveDisc(Pilha* pilha1,Pilha* pilha2){
    int disco;
    if(pilha2->topo<=TAM){
        disco = pilha1->Pilha[pilha1->topo-1];
        pilha1->Pilha[pilha1->topo-1]=0;
        pilha1->topo--;
        pilha2->Pilha[pilha1->topo]= disco;
        pilha2->topo++;
        return 1;
    }
    return 0;

}
int pilhaRemove(Pilha*p){
    int val;
    if(p->topo==0){
        printf("Pilha esta vazia\n");
        exit(1);
    }
    val = p->Pilha[p->topo-1];
    p->topo--;
    return val;
}
/*int inicializar(Pilha * pino1, int discos){

}*/

int main(void){
    Pilha* pino1;
    pino1 = pilhaCria();
}