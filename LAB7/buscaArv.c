#include <stdlib.h>
#include <stdio.h>

struct noArv{
    int info;
    struct noArv* pai;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv noArv;

int maxi(int a, int b){
    return (a >= b ) ? a : b;
}

int alturaArv(noArv* arv){
    if(arv == NULL){
        return 0;
    }
    return 1 + maxi(alturaArv(arv->esq),alturaArv(arv->dir));
}


int verificaBalanceada(noArv* arv){
    int altEsq, altDir;
    if(arv==NULL) return 1;
    altEsq = alturaArv(arv->esq);
    altDir = alturaArv(arv->dir);
    if (abs(altEsq-altDir) <= 1 && verificaBalanceada(arv->esq) && verificaBalanceada(arv->dir)){
        return 1;
    }
    return 0;

}
noArv* arvCriaVazia(void){
    return NULL;
}
int arvVazia(noArv* arv){

    return arv==NULL;

}
int arvPertence(noArv* arv, int c){
    if(arvVazia(arv)) return 0;
    else{
        return arv->info ==c || 
        arvPertence(arv->esq,c)||
        arvPertence(arv->dir,c);
    }

}
void arvImprime(noArv* arv){
    if(!arvVazia(arv)){
        printf("%d",arv->info);
        arvImprime(arv->esq);
        arvImprime(arv->dir);
    }
}
noArv* liberaArv(noArv* arv){
    if(!arvVazia(arv)){
        liberaArv(arv->esq);
        liberaArv(arv->dir);
        free(arv);
    }
    return NULL;
}
void exibirEmOrdem(noArv *arv){
    if(!arvVazia(arv)){
        exibirEmOrdem(arv->esq);
        printf("%d", arv->info);
        exibirEmOrdem(arv->dir);
    }
}
void exibirPreOrdem(noArv *arv){
    if(!arvVazia(arv)){
        printf("%d", arv->info);
        exibirPreOrdem(arv->esq);
        exibirPreOrdem(arv->dir);
    }
}
void exibirPosOrdem(noArv *arv){
    if(!arvVazia(arv)){
        exibirPreOrdem(arv->esq);
        exibirPreOrdem(arv->dir);
        printf("%d", arv->info);
    }

}
noArv* buscaArv(noArv* arv,int v){
    if (arv == NULL) return NULL;
    else if (arv->info > v){
        return buscaArv(arv->esq,v);
    }
    else if(arv->info < v){
        return buscaArv(arv->esq,v);
    }
    else return arv;
}

noArv* insereElem(noArv* arv,int v){
    if(arv ==NULL){
        arv = (noArv*)malloc(sizeof(noArv));
        arv->info = v;
        arv->esq = arv->dir = NULL;
        arv->pai = NULL;
    }
    else if(v< arv->info){
        noArv* filhoEsq = insereElem(arv->esq,v);
        arv->esq = filhoEsq;
        filhoEsq->pai = arv;
    }
    else if(v>arv->info){
        noArv* filhoDir = insereElem(arv->dir,v);
        arv->dir = filhoDir;
        filhoDir->pai = arv;
    }
    return arv;
}
noArv* retiraElem(noArv* arv,int val){
    if( arv ==NULL) 
        return NULL;
    else if(val<arv->info)
        arv->esq = retiraElem(arv->esq,val);
    else if(val>arv->info)
        arv->dir = retiraElem(arv->dir,val);
    else{
        if(arv->esq==NULL&&arv->dir==NULL){
            free(arv);
            arv = NULL;
        }
        else if(arv->esq ==NULL){
            noArv* t = arv;
            arv= arv->dir;
            arv->pai = t->pai;
            free(t);
        }
        else if( arv->dir ==NULL){
            noArv* t = arv;
            arv = arv->esq;
            arv->pai =t->pai;
            free(t);
        }
        else{
            noArv* sucessor = arv->dir;
            while(sucessor->esq!=NULL){
                sucessor = sucessor->esq;
            }
            arv->info = sucessor->info;
            sucessor->info = val;
            if(sucessor->pai->esq==sucessor)
                sucessor->pai->esq=sucessor->dir;
            else
                sucessor->pai->dir=sucessor->dir;
            if(sucessor->dir!=NULL)sucessor->dir->pai=sucessor->pai;
            //ant->esq =NULL;
            free(sucessor);
        }
    }
    return arv;
}
int main(void){
    noArv* arv = arvCriaVazia();
    arv = insereElem(arv,15);
    arv = insereElem(arv,10);
    arv = insereElem(arv,20);
    arv = insereElem(arv,5);
    arv = insereElem(arv,18);
    arv = insereElem(arv,25);
    arv = insereElem(arv,16);
    arv = insereElem(arv,19);
    arv = insereElem(arv,22);
    arv = insereElem(arv,30);
    arv = insereElem(arv,21);
    exibirEmOrdem(arv);
    printf("\ninserindo elementos 3,7,13,17,29\n");
    arv = insereElem(arv,3);
    arv = insereElem(arv,7);
    arv = insereElem(arv,13);
    arv = insereElem(arv,17);
    arv = insereElem(arv,29);
    exibirEmOrdem(arv);
    printf("\nremovendos os elementos: 5,15,16,18,22\n");
    arv = retiraElem(arv,5);
    arv = retiraElem(arv,15);
    arv = retiraElem(arv,26);
    arv = retiraElem(arv,18);
    arv = retiraElem(arv,22);
    exibirEmOrdem(arv);
    int verfBalanc = verificaBalanceada(arv);
    printf("\nTeste Balanceamento:\n0: nao balanceada 1: balanceada\nResultado: %d",verfBalanc);
    return 0;
}