#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define QTD 5

struct aluno
{
    int *mtr;
    char *nome[81];
    char *end[121];
    char *num[21];
};
typedef struct aluno Aluno;

int main(void){
    Aluno** vAlun =(Aluno*)malloc(sizeof(Aluno)*QTD);
    //insereDados(vAlun,2111295,"joao victor","barao do flamengo","21969214705");
    


    return 0;
}

/*Aluno* criaVet(){
    Aluno* vAlunos = (Aluno*)malloc(sizeof(Aluno*));
    return vAlunos;
}*/
void insereDados(Aluno* vAlun,int mtr,char*nome,char* end,char* num){
    vAlun->mtr=mtr;
    strcpy(vAlun->nome,nome);
    strcpy(vAlun->end,end);
    strcpy(vAlun->num,num);

}