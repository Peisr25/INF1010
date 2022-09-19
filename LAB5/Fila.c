#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define TAM 3

typedef struct fila Fila;
struct fila{
    int n;
    int ini;
    int numPedidos[TAM];
    char *vetPedidos[TAM];
};

Fila* filaCria(void){
    int i;
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if(f==NULL){
        printf("Erro ao alocar fila na memoria!");
        exit(1);
    }
    for(i=0;i<TAM;i++){
      f->numPedidos[i]=0;
      f->vetPedidos[i]="\0";
    }
    f->n=0;
    f->ini=0;
    return f;
}

int filaVazia(Fila* fila){
    if(fila->vetPedidos[fila->ini]==0){
        return 1;
    }
    return 0;
    
}

void filaInsere(Fila* f,int numPedido,char* pedido){
    int fim;
    if(f->n==TAM){
        printf("Capacidade esgotada!");
        exit(1);
    }
    fim = (f->ini+f->n) % TAM;
    f->numPedidos[fim] = numPedido;
    f->vetPedidos[fim] = pedido;
    f->n++;

}

char* filaRetira(Fila*filaPedidos,int* numPedido){
    int numPedidoRetirado;
    char* pedidoRetirado;
    if(filaVazia(filaPedidos)){
        printf("Fila esta vazia");
        exit(1);
    }
    numPedidoRetirado = filaPedidos->numPedidos[filaPedidos->ini];
    filaPedidos->numPedidos[filaPedidos->ini]=0;
    pedidoRetirado = filaPedidos->vetPedidos[filaPedidos->ini];
    filaPedidos->vetPedidos[filaPedidos->ini]="\0";
    filaPedidos->ini = (filaPedidos->ini+1)%TAM;
    filaPedidos->n--;
    *(numPedido)=numPedidoRetirado;
    return pedidoRetirado;
}

void imprimeFilas(Fila* f){
    int i;
    if(filaVazia(f)){
        printf("Fila esta vazia\n");
        exit(1);
    }
    printf("\n%-10s NOME DO PRATO\n","NUMERO");
    for(i=0;i<TAM;i++){  
      printf("%-10d %s\n",f->numPedidos[i],f->vetPedidos[i]);
    }
}

int main(void){ 
    char* pedidoRetirado,*pedidoRetirado1,*pedidoRetirado2;
    int numPedidoRet,numPedidoRet1,numPedidoRet2;
    Fila* filaCozinha = filaCria();
    Fila* filaEntrega = filaCria();
    filaInsere(filaCozinha,1,"batata frita");
    filaInsere(filaCozinha,2,"gurjao de frango");
    filaInsere(filaCozinha,3,"nugget");
    printf("\n----------FILA COZINHA----------");
    imprimeFilas(filaCozinha);
    printf("\n----------FILA ENTREGA----------");
    imprimeFilas(filaEntrega);
    printf("\n---------MOVENDO PEDIDOS PARA ENTREGA---------\n");
    
    pedidoRetirado = filaRetira(filaCozinha,&numPedidoRet);
    filaInsere(filaEntrega,numPedidoRet,pedidoRetirado);
    printf("\n----------FILA COZINHA----------");
    imprimeFilas(filaCozinha);
    printf("\n----------FILA ENTREGA----------");
    imprimeFilas(filaEntrega);
    pedidoRetirado1 = filaRetira(filaCozinha,&numPedidoRet1);
    filaInsere(filaEntrega,numPedidoRet1,pedidoRetirado1);
    printf("\n----------FILA COZINHA----------");
    imprimeFilas(filaCozinha);
    printf("\n----------FILA ENTREGA----------");
    imprimeFilas(filaEntrega);

    pedidoRetirado2 = filaRetira(filaCozinha,&numPedidoRet2);
    filaInsere(filaEntrega,numPedidoRet2,pedidoRetirado2);
    printf("\n----------FILA COZINHA----------");
    imprimeFilas(filaCozinha);
    printf("\n----------FILA ENTREGA----------");
    imprimeFilas(filaEntrega);
    
    return 0;
}