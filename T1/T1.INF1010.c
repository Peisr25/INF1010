/*JULIANA JOAO VICTOR AMORIM */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 12

struct pilha
{
    int topo;
    char vet[TAM];
};
typedef struct pilha Pilha;

Pilha* pilhaCria(){
    int i;
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha == NULL){
        printf("erro ao alocar pilha\n");
    }
    for(i=0;i<TAM;i++){
      pilha->vet[i] = '\0';         //Loop para inicializar todos os elementos do vetor
    }
    pilha->topo = 0;
    return pilha;
}

int pilhaVazia(Pilha* pilha){
    if(pilha->topo==0){
        return 1;
    }
    return 0;
}

void pilhaPush(Pilha* pilha,char v){
    if(pilha->topo==TAM){
        printf("Pilha atingiu seu limite\n");
        exit(1);
    }
    pilha->vet[pilha->topo] = v;
    pilha->topo++;
}
char pilhaPop(Pilha* pilha){
    char v;
    v = pilha->vet[pilha->topo-1];
    pilha->topo--;
    return v;
}
void pilhaLibera(Pilha* pilha){
    free(pilha);
}

int prioridade(char aux){           //Função para calcular a prioridade do simbolo
    if(aux == '(')
        return 0;
    if(aux == '+' || aux == '-')
        return 1;
    if(aux == '*' || aux == '/')
        return 2;
    return 0;
}

void shuting(char* exp,char* ret){
    char aux,retorno[TAM]={"\0"};
    Pilha* pilha = pilhaCria();
    //retorno = (char*)malloc(sizeof(char)*TAM);
    while(*exp!='\0'){
        if(isalnum(*exp)){          // verifica se é numero, printa e add na string de retorno
            printf("%c",*exp);
            strncat(retorno,exp,1);
        }
        else if(*exp =='('){        // verifica se é ( e add na pilha de operações
            pilhaPush(pilha,*exp);
        }
        else if(*exp ==')'){
            while((aux = pilhaPop(pilha)) != '('){      //verifica se é ) e remove da pilha add na string de retorno
                printf("%c",aux);
                strncat(retorno,&aux,1);
            }
        }
        else{
            while(prioridade(pilha->vet[pilha->topo]) >= prioridade(*exp)) { //Calcula a prioridade dos sinais 
                char temp = pilhaPop(pilha); //Remove da pilha de operações e add na string de retorno
                printf("%c",temp);
                strncat(retorno,&temp,1);

            }
            pilhaPush(pilha,*exp);
        }
        *exp++; //Anda com a string da expressão
    }
    while (pilha->topo != -1) //Finaliza desempilhando o restante e add na string de retorno
    {
        char temp1 = pilhaPop(pilha);
        printf("%c",temp1);
        strncat(retorno,&temp1,1);
    }
    strcpy(ret,retorno);
}

int main(void){
    char teste[] = "2+(3x(8-4))";
    char aa[TAM];
    shuting(&teste,&aa);
    printf("\nTeste: %s\n",aa);
    return 0;
}