#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#define QTD 5

struct aluno
{
    int mtr;
    char nome[81];
    char end[121];
    char num[21];
};
typedef struct aluno Aluno;

int main(void){
    int i;
    Aluno* vAlun = (Aluno*)malloc(sizeof(Aluno)*QTD);
    Aluno** vAlun[QTD];
    for (i=0;i<QTD;i++){
        vAlun[i] = *(vAlun[i]);
    }
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


/*
int main() {
  
  Aluno* struc = malloc(sizeof(Aluno));
  //Aluno* str[1];
  Aluno** vAlun[5];
  vAlun[0] = struc;
  vAlun[0].mtr = 100;
  //str[0]= malloc(sizeof(Aluno));
  return 0;
}
*/