#include <stdlib.h>
#include <stdio.h>

struct noArv{
    char info;
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
noArv* arvCria(char c, noArv* sae,noArv*sad){
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
        printf("%c", arv->info);
        exibirEmOrdem(arv->dir);
    }
}
void exibirPreOrdem(noArv *arv){
    if(!arvVazia(arv)){
        printf("%c", arv->info);
        exibirPreOrdem(arv->esq);
        exibirPreOrdem(arv->dir);
    }
}
void exibirPosOrdem(noArv *arv){
    if(!arvVazia(arv)){
        exibirPreOrdem(arv->esq);
        exibirPreOrdem(arv->dir);
        printf("%c", arv->info);
    }
}

int main(void){
    noArv* a1 = arvCria('J',arvCriaVazia(),arvCriaVazia());
    noArv* a2 = arvCria('I',arvCriaVazia(),a1);
    noArv* a3 = arvCria('M',arvCriaVazia(),arvCriaVazia());
    noArv* a4 = arvCria('H',a3,a2);
    noArv* a5 = arvCria('D',a4,arvCriaVazia());
    noArv* a6 = arvCria('G',arvCriaVazia(),arvCriaVazia());
    noArv* a7 = arvCria('C',a6,a5);
    noArv* a8 = arvCria('L',arvCriaVazia(),arvCriaVazia());
    noArv* a9 = arvCria('K',arvCriaVazia(),a8);
    noArv* a10 = arvCria('F',arvCriaVazia(),arvCriaVazia());
    noArv* a11 = arvCria('E',a9,a10);
    noArv* a12 = arvCria('B',a11,a7);
    noArv* a13 = arvCria('A',a12,arvCriaVazia());
    printf("\nImpressao em ordem:\n");
    exibirEmOrdem(a13);
    printf("\nImpressao pos-ordem:\n");
    exibirPosOrdem(a13);
    printf("\nImpressao pre-ordem:\n");
    exibirPreOrdem(a13);
    printf("\nLiberando arvore!");
    liberaArv(a1);
    return 0;
}