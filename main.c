#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int num;
    struct node* prox;
}pilha;

pilha * createStack(){

    pilha * novaPilha = (pilha*)malloc(sizeof(pilha));

    novaPilha -> prox = NULL;

    return novaPilha;

}
void push(int num, pilha *topo){

    pilha * p = topo -> prox;

    pilha *novoNo = (pilha*)malloc(sizeof(pilha));

    if( !novoNo ) exit( 0 );

    novoNo -> num = num;

    novoNo -> prox = NULL;

    topo -> prox = novoNo;

    if( p ) novoNo -> prox = p;


}
int pop(pilha *topo){

    pilha * p = topo -> prox;

    if(!p) exit(0);

    topo -> prox = p -> prox;

    int num = p -> num;

    free(p);

    return (num);

}
void showStack( pilha *topo ){


    pilha *p = topo->prox;
    if(!p) {
        printf("\npilha vazia");
        exit(0);
    }

    printf("\npilha: ");

    while( p ){

        printf("%d", p -> num );

        if( p -> prox ) printf( "," );

        p = p -> prox;

    }

}
void cleanStack(pilha *topo){               //remove all elements of stack

    pilha * p = topo -> prox,*temp;

    if(p){

        while( p ){

            temp = p;

            p = p -> prox;

            free( temp );

        }
        topo -> prox = NULL;
    }

}
void populaPilha( pilha *topo , int num ){

    srand( time( NULL ) );

    for ( int i = 0; i < num ; ++i ) {

        push( rand( ) % 10 , topo );

    }

}



int main() {

    pilha * nova = createStack();

    populaPilha(nova,10);

    showStack(nova);

    printf( "\nvalor removido: %d ", pop( nova ) );

    showStack(nova);

    cleanStack(nova);

    showStack(nova);

    free(nova);

    return 0;
}
