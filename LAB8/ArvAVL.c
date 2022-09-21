#include <stdio.h>
#include <stdlib.h>
struct avl
{
    int info;
    int fatorBalan;
    struct arvAVL *pai;
    struct arvAVL *esq;
    struct arvAVL *dir;
};
typedef struct avl arvAVL;

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
                if(arv->fatorBalan == -1){
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
                if(arv->fatorBalan==-1) arv = rotEsq(arv);
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
arvAVL* rotEsq(arvAVL* arv){
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

arvAVL* removeAvl2(arvAVL* arv,int info,int *delta){
    if(!arv) return NULL;
    else if(info<arv->info){
        arv->esq = removeAvl2(arv->esq,info,delta);
        arv->fatorBalan -=*delta;
        if(arv->fatorBalan==2){
            if(arv->fatorBalan==1){
                arv = rotEsq(arv);
                *delta = -1;
            }
            else if(arv->fatorBalan == 0){
                arv = rotEsq(arv);
                *delta = 0;
            }
            else if(arv->dir == -1){
                arv = rotDirEsq(arv);
                *delta = -1;
            }
        }
        else{
         *delta = ((arv->fatorBalan==1) ? 0 : -1);
        }
    }
    //else if(info > arv->info)
    else{
        if(arv->esq == NULL && arv->dir == NULL){
            free(arv);
            *delta = -1;
            arv = NULL;
        }
    }
    return arv;

}
arvAVL* removeAvl(arvAVL* arv, int info){
    int delta = 0;
    return removeAvl2(arv,info,&delta);

}

int main(void){
    arvAVL* arv = arvCriaVazia();
    arv = insere(arv,15);
    arv = insere(arv,10);
    arv = insere(arv,20);
    arv = insere(arv,5);
    arv = insere(arv,18);
    arv = insere(arv,25);
    arv = insere(arv,16);
    arv = insere(arv,19);
    arv = insere(arv,22);
    arv = insere(arv,30);
    arv = insere(arv,21);
    printf("Arvore criada!\n");
    printf("Inserindo elementos: 9,13 e 23\n");
    arv = insere(arv,9);
    arv = insere(arv,13);
    arv = insere(arv,23);
    printf("Removendo elementos: 10,18,22\n");
    arv = removeAvl(arv,10);
    arv = removeAvl(arv,18);
    arv = removeAvl(arv,22);

    return 0;
}
