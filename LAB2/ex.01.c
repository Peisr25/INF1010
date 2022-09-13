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
};
typedef struct aluno Aluno;

void insereDados(Aluno* vAlun,int mtr,char *nome,char *ender,char *tel){
    
    vAlun->mtr = mtr;
    strcpy(vAlun->nome,nome);
    strcpy(vAlun->ender,ender);
    strcpy(vAlun->tel,tel);
}

void removeElem(Aluno** vAlun,int n, int i){
    if (vAlun[i] != NULL){
        free(vAlun[i]);
        vAlun[i] = NULL;
    }
}

int buscaNome(int n, Aluno** vAlun, char* nome){
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(nome,vAlun[i]->nome)==0)
            return i; 
    }
    return -1;
}
int buscaMtr(int n, Aluno** vAlun, int mtr){
    int i;
    for (i=0; i<n; i++) {
        if (vAlun[i]->mtr==mtr)
            return i; 
    }
    return -1;
}

void removeAlun(Aluno**vAlun,int mtr){
    int pos;
    pos = buscaMtr(QTD,vAlun,mtr);
    if(pos == -1){
        printf("nao foi possivel encontrar o elemento a ser removido");
        return;
    }
    removeElem(vAlun,QTD,pos);
}
void atualizaElem(Aluno**vAlun, int mtr,char* novoNome){
    int pos;
    pos = buscaMtr(QTD,vAlun,mtr);
    strcpy(vAlun[pos]->nome,novoNome);
}

int main(void){
    int i;
    Aluno** vAlun = (Aluno**)malloc(QTD*sizeof(Aluno*));
    if(vAlun == NULL){
        printf("Nao foi possivel alocar o vetor!");
        exit(1);
    }
    for (i=0;i<QTD;i++){
        vAlun[i]=(Aluno*)malloc(sizeof(Aluno));

    }
    printf("inserindo dados no vetor!\n");
    insereDados(vAlun[0],005421,"jose carlos","rua doisum","215456487");
    insereDados(vAlun[1],2111295,"joao victor","rua umdois","219999222");
    insereDados(vAlun[2],2111296,"pedro lucas","rua tresquatro","214842512");
    insereDados(vAlun[3],2111297,"jullia","rua cincoseis","215456425");
    insereDados(vAlun[4],2111298,"luciana","rua seteoito","216545452");
    printf("Iniciando teste de busca\n");
    int resultBusc = buscaNome(QTD,vAlun,"jullia");
    printf("Posicao do elemento com nome jullia %d\n",resultBusc);
    printf("removendo aluno de matricula '2111298'\n");
    removeAlun(vAlun,2111298);
    printf("alterando o nome do aluno para pedro henrique\n");
    atualizaElem(vAlun,2111296,"pedro henrique");
}
      