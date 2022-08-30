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
    int i;
    char nome[] = "jose carlos";
    // Aluno** vAlun = (Aluno**)malloc(QTD*sizeof(Aluno*));
    //  for (i=0;i<QTD;i++){
    //      vAlun[i]=(Aluno*)malloc(sizeof(Aluno));

    //  }
     int tam = tamStr(nome);
     printf(tam);
     imprimeStr(nome)
    //vAlun[0]=(Aluno*)malloc(sizeof(Aluno));
    //insereDados(vAlun[0],2111295,"joao victor","rua umdois","219999222");
    //insereDados(vAlun[1],0011295,"joao owsei","rua doisum","219999222");

    return 0;
}

void insereDados(Aluno** vAlun,int i,int mtr,char *nome,char*ender,char*tel){
    
    vAlun->mtr = mtr;
    strcpy(vAlun->nome,nome);
    strcpy(vAlun->ender,ender);
    strcpy(vAlun->tel,tel);
}

int tamStr(char string[]){
    if (string[0] =='\0')
        return 0;
    return 1+tamStr(&string[1]);
}
void imprimeStr(char string[]){
    if(string[0]=='\0')
        return;
    printf('%c',string[0]);
    return string[0]+1;

}