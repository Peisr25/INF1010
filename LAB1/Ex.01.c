//JOAO VICTOR DE OLIVEIRA AMORIM 2111295

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

int tamStr(char string[]){
    if (string[0] =='\0')
        return 0;
    return 1+tamStr(&string[1]);
}
void imprimeStr(char string[]){
    if(string[0]=='\0')
        return;
    printf("%c",string[0]);
    return imprimeStr(string+1);

}

int main(void){
    int i;
    char nome[] = "jose carlos";
    Aluno** vAlun = (Aluno**)malloc(QTD*sizeof(Aluno*));
    if(vAlun == NULL){
        printf("Nao foi possivel alocar o vetor!");
        exit(1);
    }   
    for (i=0;i<QTD;i++){
        vAlun[i]=(Aluno*)malloc(sizeof(Aluno));
        if(vAlun[i]==NULL){
            printf("Nao foi possivel alocar o elemento!");
            exit(1);
        }

    }
    insereDados(vAlun[0],005421,"jose carlos","rua doisum","215456487");
    insereDados(vAlun[1],2111295,"joao victor","rua umdois","219999222");
    insereDados(vAlun[2],2111295,"pedro lucas","rua tresquatro","214842512");
    insereDados(vAlun[3],2111295,"jullia","rua cincoseis","215456425");
    insereDados(vAlun[4],2111295,"luciana","rua seteoito","216545452");
      
      
    int tam = tamStr(nome);
    printf("Tamanho da string 'jose carlos': %d\n",tam);
    printf("Teste da funcao imprimeStr:\n");
    imprimeStr(nome);
    return 0;
}