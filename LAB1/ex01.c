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

int main(void){
    Aluno* vAlun = (Aluno*)malloc(sizeof(Aluno)*QTD);
    insereDados(vAlun[1],2111295,"joao victor","rua umdois","219999222");
    insereDados(vAlun[2],2111295,"joao victor","rua umdois","219999222");

    return 0;
}

void insereDados(Aluno* vAlun,int mtr,char *nome,char*ender,char*tel){
    vAlun->mtr = mtr;
    strcpy(vAlun->nome,nome);
    strcpy(vAlun->ender,ender);
    strcpy(vAlun->tel,tel);
}
