#include <stdlib.h>
#include <stdio.h>
#define TAM 3

typedef struct pilha Pilha;
struct pilha{
    int topo;
    int Pilha[TAM];
};

Pilha* pilhaCria(){
    int i;
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if(p==NULL) exit(1);
    p->topo =0;
    for(i=0;i<TAM;i++){
        p->Pilha[i]=0;
    }
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

void imprimePinos(Pilha* pino1,Pilha*pino2,Pilha* pino3){
    int i;
    printf("Torre de Hanoi!\n");
    printf("Pino 1       Pino2        Pino3\n");
    for(i=0;i<TAM;i++){
        printf("%d          %d            %d\n",pino1->Pilha[TAM-i-1], pino2->Pilha[TAM-i-1], pino3->Pilha[TAM-i-1]);
    }
}
int inicializar(Pilha * pino1, int discos){
    int i;
    if(pino1->topo==TAM) return 0;
    if(discos+ pino1->topo<=TAM){
        for(i=0;i<TAM;i++){
            pino1->Pilha[i] = TAM -i;
        }
        pino1->topo = discos;
        return 1;
    }
    return 0;
}

void terminar(Pilha* pino1,Pilha*pino2,Pilha* pino3){
    free(pino1);
    free(pino2);
    free(pino3);
}

int main(void){
    int destino,posi,origem;
    Pilha* pino1,*pino2,*pino3;
    pino1 = pilhaCria();
    pino2 = pilhaCria();
    pino3 = pilhaCria();
    posi = inicializar(pino1,TAM);
    if(posi=0)
        printf("Nao foi possivel adicionar novos discos\n");
    else
        printf("Os dicos foram adicionados no pino1\n");
    imprimePinos(pino1,pino2,pino3);
    scanf("%d%d",&origem,&destino);
    while(origem !=0){
        if(origem ==1)
            if(destino==2)
                posi = moveDisc(pino1,pino2);
            else
                posi = moveDisc(pino1,pino3);
        else if(origem =2)
            if(destino ==1)
                posi = moveDisc(pino2,pino1);
            else
                posi = moveDisc(pino2,pino3);
        else
            if(destino ==2)
                posi = moveDisc(pino3,pino2);
            else
                posi = moveDisc(pino3,pino1);
        if(posi==0)
            printf("movimento invalido\n");
        imprimePinos(pino1,pino2,pino3);
        printf("Entre com as posicoes de origem e destino (utilize 0 0 para terminar): \n");
        scanf("%d%d",&origem,&destino);
    }
    terminar(pino1,pino2,pino3);
    return 0;
}