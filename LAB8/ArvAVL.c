#include <stdio.h>
#include <stdlib.h>
struct arvAVL
{
    int info;
    int fatorBalan;
    struct arvAVL *pai;
    struct arvAVL *esq;
    struct arvAVL *dir;
};
typedef struct arvAVL arvAVL;

arvAVL* rotDir(arvAVL* arv);
arvAVL* rotEsq(arvAVL* arv);
arvAVL* rotEsqDir(arvAVL* arv);
arvAVL* rotDirEsq(arvAVL* arv);

arvAVL* arvCriaVazia(void){
    return NULL;
}

arvAVL* insere2(arvAVL* arv,int info,int* cresceu){
    if(arv==NULL){
        arv = (arvAVL*)malloc(sizeof(arvAVL));
        arv->esq = arv->dir = NULL;
        arv->info = info;
        arv->fatorBalan = 0;
        *cresceu = 1;
    }
    else if(arv->info>info){
        arv->esq = insere2(arv->esq,info,cresceu);
        if(cresceu){
            switch (arv->fatorBalan)
            {
            case 1:
                arv->fatorBalan = 0;
                *cresceu=0;
                break;
            
            case 0:
                arv->fatorBalan = -1;
                break;
            case -1:
                if(arv->esq->fatorBalan==-1){
                    arv = rotDir(arv);
                }
                else{
                    arv = rotEsqDir(arv);
                }
                *cresceu = 0;
                break; 
            }
        }
    }
    else if( arv->info<info){
        arv->dir = insere2(arv->dir,info,cresceu);
        if(arv==NULL){
        arv = (arvAVL*)malloc(sizeof(arvAVL));
        arv->esq = arv->dir = NULL;
        arv->info = info;
        arv->fatorBalan = 0;
        *cresceu = 1;
    }
    else if(arv->info>info){
        arv->esq = insere2(arv->esq,info,cresceu);
        if(cresceu){
            switch (arv->fatorBalan)
            {
            case 1:
                arv->fatorBalan = 0;
                *cresceu=0;
                break;
            
            case 0:
                arv->fatorBalan = -1;
                break;
            case -1:
                if(arv->dir->fatorBalan==-1) arv = rotEsq(arv);
                    else arv = rotDirEsq(arv);
                *cresceu = 0;
                break; 
            }
        }
    }
    return arv;
}

arvAVL* insere(arvAVL* arv,int info){
    int cresceu = 0;
    return insere2(arv,info,&cresceu);
}

arvAVL* rotDir(arvAVL* arv){
    arvAVL* pai = arv->pai;
    arvAVL* t = arv->esq;
    arvAVL* m = arv->dir;
    t->dir = arv;
    arv->pai = t;
    arv->esq = m;
    if(m){
        m->pai = arv;
    }
    t->pai = pai;
    if(pai){
        if(pai->dir==arv){
            pai->dir = t;
        }
        else{
            pai->esq = t;
        }
    }
    t->fatorBalan = arv->fatorBalan = 0;
    return t;
}
arvAVL* rotEsq(arvAVL* arv, int info,int* cresceu){
    arvAVL* pai = arv->pai;
    arvAVL* t = arv->dir;
    arvAVL* m = arv->esq;
    t->esq = arv;
    arv->pai = t;
    arv->dir = m;
    if(m){
        m->pai = arv;
    }
    t->pai = pai;
    if(pai){
        if(pai->dir==arv){
            pai->dir = t;
        }
        else{
            pai->esq = t;
        }
    }
    t->fatorBalan = arv->fatorBalan = 0;
    return t;
}
arvAVL* rotDirEsq(arvAVL* arv){
    arvAVL* t = arv->dir;
    arvAVL* s = t->esq;
    arvAVL* t2=  s->esq;
    arvAVL* t3 = s->dir;
    s->esq = arv;
    s->dir = t;
    arv->dir = t2;
    t->esq = t3;
    arv->fatorBalan = (s->fatorBalan==1) ? -1 : 0;
    t->fatorBalan = (s->fatorBalan==-1)? 1 : 0;
    s->fatorBalan = 0;
    return s;
}

arvAVL* rotEsqDir(arvAVL *arv) {
    arvAVL *t = arv->dir;
    arvAVL *s = t->esq;
    arvAVL *T2 = s->esq;
    arvAVL *T3 = s->dir;
    s->esq = arv;
    s->dir = t;
    arv->dir = T2; 
    t->esq = T3;
    arv->fatorBalan = (s->fatorBalan==1) ? -1 : 0;
    t->fatorBalan = (s->fatorBalan==-1) ? 1 : 0;
    s->fatorBalan = 0;
    return s;
}
