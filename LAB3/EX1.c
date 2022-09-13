//JOAO VICTOR DE OLIVEIRA AMORIM 2111295
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define QTD 5
struct aluno
{
    int mtr;
    char nome[81];
    char ender[121];
    char tel[21];
    struct aluno *prox;
};
typedef struct aluno Aluno;

Aluno* criaLista(void){
    return NULL;
}

Aluno* insereElem(Aluno* lista,int mtr, char*nome,char*ender,char*tel){
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if(novo == NULL){
        printf("erro ao alocar novo elemento da lista!");
        exit(1);
    }
    strcpy(novo->ender,ender);
    strcpy(novo->nome,nome);
    strcpy(novo->tel,tel);
    novo->mtr = mtr;
    novo->prox = lista;
    return novo;
}

Aluno* atualizaElem(Aluno* lista,int mtr,char*nome){
    Aluno* p=lista;
    while(p!=NULL&&p->mtr!=mtr){
        p=p->prox;
    }
    if(p==NULL) return lista;
    
    strcpy(p->nome,nome);
    return lista;
}
Aluno* removeElem(Aluno*lista,int mtr){
    Aluno* p = lista;
    Aluno* ant = NULL;
    while (p!=NULL&&p->mtr!=mtr){
        ant = p;
        p=p->prox;
    }
    if(p==NULL) return lista;
    if(ant==NULL) lista = p->prox;
    else ant->prox = p->prox;
    free(p);
    return lista;
}

int main (void){
    Aluno* lista;
    lista = criaLista();
    lista = insereElem(lista,2111291,"joao victor","rua umdois","21213213");
    lista = insereElem(lista,2111294,"joao lucas","rua tresquatro","21267453");
    lista = insereElem(lista,2111296,"joao paulo","rua cincoseis","21532322");
    lista = removeElem(lista,2111296);
    return 0;
}