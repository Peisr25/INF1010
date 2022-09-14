#include <stdlib.h>
#include <stdio.h>
#define TAM 3

typedef struct pilha Pilha;
struct pilha{
    int topo;
    int Pilha[TAM];
}

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
    p->vet[p->topo]=val;
    p->topo++;
}
int pilhaRemove(Pilha*p){
    int val;
    if(p->topo==0){
        printf("Pilha esta vazia\n");
        exit(1);
    }
    v = p->vet[p->topo-1];
    p->topo--;
    return val;
}
/*int inicializar(Pilha * pino1, int discos){

}*/

int main(void){
    

}