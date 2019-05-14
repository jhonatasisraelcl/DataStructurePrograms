//TITULO DO PROJETO: ArvoreBusca.c
//VERSÃO ou DATA:1.3 14/05/2019
//AUTORES:LAURENTINO, J.I.C.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

typedef struct node {
    int v;
    struct node *l;
    struct node *r;
}Node;

void adicionar(Node **node, int v);
int tsearch(Node* x, int v);
Node* newnode(int num);
int *newv (unsigned int n);
double tvtosec(struct timeval t);
void tprint(Node* x);
void tremove(Node* x);
 
int main (void){
    Node *node = NULL;
	srand(time(NULL)); 
	struct timeval a;
	struct timeval b;
	double tempo;
    int achou;
    int n, k, i, primeiro, aleatorio;

 	for(n = 1000; n <= 10000; n += 500){
 		tempo = 0;        
 		for(i = 0; i < 10000 ; i++){
            		for(k = 0; k < n; k++){
                		aleatorio = rand() % (n+1);
                		adicionar(&node, aleatorio);
                		if(k == 0){
                    			primeiro = aleatorio;
                		}
            		}
		 	gettimeofday(&b, NULL);
		    	achou = tsearch(node, primeiro); 
		    	achou = tsearch(node, (n*2)); 
		    	achou = tsearch(node, (rand() % (n+1))); 
		 	gettimeofday(&a, NULL);
		 	tempo  += tvtosec(a) - tvtosec(b);	            
            		tremove(node);
            		node = NULL;
	 	}
	 	fprintf(stderr, "%d %.20lf\n", n, tempo/10000 );
	 	printf("%d %.20lf\n", n, tempo/10000 );
	}
    return 0;
}

void adicionar(Node **n, int v) {
    Node *aux, *f;
    if(*n == NULL){(*n) = newnode(v);}
	else{
        aux = *n;
        while(aux != NULL){
            f = aux;
            if(aux->v < v){aux = aux->r;}
		else{aux = aux->l;}
        }
      (f->v < v) ? (f->r = newnode(v)) : (f->l = newnode(v));
    }
}

int tsearch(Node* x, int v){
    if(x != NULL){
        if(x->v == v){return 1;}
        else if(x->v < v){return tsearch(x->r, v);}
        else{return tsearch(x->l,v);}
    }else{return 0;}
}

Node* newnode(int num){
    Node* a = (Node*)malloc(sizeof(Node));
    a->v = num;
    a->l = NULL;
    a->r = NULL;
    return a;
}

double tvtosec(struct timeval t){return (double) t.tv_sec + t.tv_usec/(double)1e6;}

void tprint(Node* x){ 
    if(x != NULL){
        tprint(x->l);
        printf("%p %d %p %p \n", x , x->v, x->l, x->r);
        tprint(x->r);
    }
}

void tremove(Node* x){
    if(x != NULL){
        tremove(x->l);
        tremove(x->r);
        free(x);
    }
    return;
}
