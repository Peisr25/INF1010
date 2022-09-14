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
void imprElem(Aluno* lista){
    int cont=1;
    Aluno* p = lista;
    while(p!=NULL){
        printf("Elemento: %d\n Nome: %s\n Matricula: %d\n Endereco: %s\n Telefone: %s\n",cont,p->nome,p->mtr,p->ender,p->tel);
        p=p->prox;
        cont++;
    }

}
int buscaElem(Aluno* lista,int mtr){
    int cont =0;
    Aluno* p =lista;
    while (p!=NULL&&p->mtr!=mtr){
        p = p->prox;
        cont++;
    }
    if(p==NULL){
        printf("elemento nao encontrado");
        return -1;
    }
    return cont;
    
}
int igualdadeDeElem(Aluno* lista, int mtr1,int mtr2){
    Aluno* p1,*p2=lista;
    while(p1!=NULL && p1->mtr!=p2->mtr){
        p2=p2->prox;
    }
    if(p2==NULL){
        printf("Nao ha igualdade!");
        return 0;
    }
    return 1;
}
int testaVazia(Aluno*lista){
    if(lista==NULL) return 1;
    return 0;
}
void liberaLista(Aluno* lista){
    Aluno *p,*ant;
    while(p!=NULL){
        ant =p;
        p=p->prox;
        free(ant);
    }
}
int main (void){
    int pos,igualdade,testeVazia;
    Aluno* lista;
    lista = criaLista();
    lista = insereElem(lista,2111291,"joao victor","rua umdois","21213213");
    lista = insereElem(lista,2111294,"joao lucas","rua tresquatro","21267453");
    lista = insereElem(lista,2111291,"joao paulo","rua cincoseis","21532322");
    lista = insereElem(lista,2111295,"joao paulo","rua cincoseis","21532322");
   // lista = removeElem(lista,2111291);
    printf("Impressao da lista:\n");
    imprElem(lista);
    pos = buscaElem(lista,2111296);
    printf("Posicao do elementro com matricula '2111291': %d",pos);
    igualdade = igualdadeDeElem(lista,2111291,2111291);
    testeVazia = testaVazia(lista);
    liberaLista(lista);
    return 0;
}   