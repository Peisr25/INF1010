//JOAO VICTOR DE OLIVEIRA AMORIM 2111295

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void remove(Aluno** vAlun,int n, int i){
    if (i<0 || i>=n){
        printf("Indice nao existe\n");
        exit(1);
    }
    if (vAlun[i] != NULL){
        free(vAlun[i]);
        vAlun[i] = NULL;
    }
}

int busca (int n, int* vet, int elem){
    int i;
    for (i=0; i<n; i++) {
        if (elem == vet[i])
            return i; 
    }

return -1;
}

int busca()

int main(void){
    int i;
    char nome[] = "jose carlos";
    Aluno** vAlun = (Aluno**)malloc(QTD*sizeof(Aluno*));
    for (i=0;i<QTD;i++){
        vAlun[i]=(Aluno*)malloc(sizeof(Aluno));

    }
    insereDados(vAlun[0],005421,"jose carlos","rua doisum","215456487");
    insereDados(vAlun[1],2111295,"joao victor","rua umdois","219999222");
    insereDados(vAlun[2],2111295,"pedro lucas","rua tresquatro","214842512");
    insereDados(vAlun[3],2111295,"jullia","rua cincoseis","215456425");
    insereDados(vAlun[4],2111295,"luciana","rua seteoito","216545452");
}
      