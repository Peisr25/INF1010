#include <stdlib.h>
#include <stdio.h>

struct noArv{
    int info;
    struct noArv* pai;
    struct noArv* esq;
    struct noArv* dir;
};

typedef struct noArv noArv;

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

noArv* arvCria(int c, noArv* sae,noArv*sad){
    noArv* arv = (noArv*)malloc(sizeof(noArv));
        if (arv==NULL){
            printf("Nao foi possivel alocar a arvore");
            exit(1);
        }
    arv->info = c;
    arv->esq = sae;
    arv->dir = sad;
    return arv;
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
    }
    else if(v< arv->info){
        arv->esq = insereElem(arv->dir,v);
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
            free(sucessor);
        }
    }
    return arv;
}
int main(void){
    /*noArv* a1 = arvCria(21,arvCriaVazia(),arvCriaVazia());
    noArv* a2 = arvCria(22,a1,arvCriaVazia());
    noArv* a3 = arvCria(30,arvCriaVazia(),arvCriaVazia());
    noArv* a4 = arvCria(25,a2,a3);
    noArv* a5 = arvCria(16,arvCriaVazia(),arvCriaVazia());
    noArv* a6 = arvCria(19,arvCriaVazia(),arvCriaVazia());
    noArv* a7 = arvCria(18,a5,a6);
    noArv* a8 = arvCria(20,a7,a4);
    noArv* a9 = arvCria(5,arvCriaVazia(),arvCriaVazia());
    noArv* a10 = arvCria(10,a9,arvCriaVazia());
    noArv* a11 = arvCria(15,a10,a8);*/
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

    //printf("\nImpressao pos-ordem:\n");
    //exibirPosOrdem(a11);
    //printf("\nImpressao pre-ordem:\n");
    //exibirPreOrdem(a11);
    //arvImprime(a13);
    return 0;
}