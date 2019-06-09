//TITULO DO PROJETO: ArvoreBinariaInsercao.c
//VERSÃO ou DATA:1.0 14/05/2019
//AUTORES:LAURENTINO, J.I.C.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

typedef struct tree{
    struct tree *p;
    struct tree *r;
    struct tree *l;
    int v;
    unsigned int h;
}Tree;

Tree* newnode(int num);
void adicionar(Tree **raiz, int v, Tree* pai, Tree** RaizOriginal);
void tprint( Tree* x);
void verifica(Tree* n, Tree** RaizOriginal);
int mod(int i);
unsigned int alturaArvore(Tree *a);
unsigned int maxAlt(int no1, int no2);
void balancear(Tree* n, Tree** RaizOriginal);
void re(Tree* x);
void rd(Tree* x);
int buscar(Tree* raiz, int n);
double tvtosec(struct timeval t);
void tremove(Tree* x);

int main (void) {
	Tree* raiz = NULL;
	srand(time(NULL));
	struct timeval a;
	struct timeval b;
	double tempo;
	int i, aleatorio, k, n, achou;
 	for(n = 1000; n <= 10000; n += 1000){
		tempo = 0;
 		for(i = 0; i < 100 ; i++){
			for(k = 0; k < n; k++){
				aleatorio = rand() % (n+1);
				if(buscar(raiz, aleatorio) != 1) adicionar(&raiz, aleatorio, NULL, &raiz);
			}
			gettimeofday(&b, NULL);
			achou = buscar(raiz, (n*2)); 
		 	gettimeofday(&a, NULL);
		 	tempo  += tvtosec(a) - tvtosec(b);
			tremove(raiz);
			raiz = NULL;
		}
	 	fprintf(stderr, "%d %.20lf\n", n, tempo/100 );
	 	printf("%d %.20lf\n", n, tempo/100 );
	}
}

void adicionar(Tree **raiz, int v, Tree* pai, Tree** raizOriginal){
    Tree *n = newnode(v);
    if(*raiz == NULL){
        n->p = pai;
        *raiz = n;
        verifica(n, raizOriginal);   
    }
    else if ((*raiz)-> v > n->v){adicionar(&((*raiz)-> l),n->v,*raiz,raizOriginal);}
    else{adicionar(&((*raiz)-> r),n->v,*raiz,raizOriginal);}
} 

Tree* newnode(int num){
    Tree* a = (Tree*)malloc(sizeof(Tree));
    a->v = num;
    a->l = NULL;
    a->r = NULL;
    a->p = NULL;
    a->h = 1;
    return a;
}

void tprint( Tree* x){
    if(x != NULL){
        tprint(x->l);
        printf("Endereço: %p Valor: %d Esquerda: %p Direita: %p Pai: %p \n", x , x->v, x->l, x->r, x->p);
        tprint(x->r);
    }
}

void verifica(Tree* n, Tree** RaizOriginal){   
	while (n != NULL){
		n->h =(alturaArvore(n));
                if (mod(alturaArvore(n->r) - alturaArvore(n->l)) > 1) {
			balancear(n,RaizOriginal); 
		}
		n = n->p;   
	}
}
int mod(int i){return i > 0 ? i : -i;}

unsigned int alturaArvore(Tree *a){
	if (a == NULL) return 0;
	return maxAlt(alturaArvore(a->l), alturaArvore(a->r)) + 1;
}

unsigned int maxAlt(int no1, int no2){return (no1 > no2 ) ? no1 : no2;}

void balancear(Tree* n, Tree** RaizOriginal){
	int dp = alturaArvore(n->r) - alturaArvore(n->l);
	int df;
	if(n->h != dp){
		if (dp == 2){
			df = alturaArvore(n->r->r) - alturaArvore(n->r->l);
			if (df == -1){
                rd(n->r);
                n->r->h = alturaArvore(n->r);
                re(n);
                if (n == *RaizOriginal)
                    *RaizOriginal = n->p;
                    n->h =( alturaArvore(n));
                } else {
                    re(n);
                    if (n == *RaizOriginal)						    
                    *RaizOriginal = n->p;
                    n->h =(alturaArvore(n));
               }
         }else if (dp == -2) {
		df = alturaArvore(n->l->r) - alturaArvore(n->l->l);
		if (df <= 0){
                rd(n);
                if (n == *RaizOriginal)
			*RaizOriginal = n->p;
			n->h =( alturaArvore(n));
		} else {
			re(n->l);
			n->l->h = alturaArvore(n->l);
			n->h =( alturaArvore(n));
		}
	}
    }
}

void re(Tree* x){
    Tree *y = x->r;
    Tree *b = y->l;

    if(x->p != NULL){
        if(x->p->r == x){
            x->p->r = y;
        }else{
            x->p->l = y;
        }
    }
    y->p = x->p;
    x->p = y;
    y->l = x;
    if(b!=NULL)
		b->p = x;
    x->r = b;
}

void rd(Tree* x){
    Tree *y = x->l;
    Tree *b = y->r;
    if(x->p != NULL){
        if(x->p->l == x){
            x->p->l = y;
        }else{
            x->p->r = y;
        }
    }
    y->p = x->p;
    x->p = y;
    y->r = x;
	if(b!=NULL)
		b->p = x;
    x->l = b; 
}

int buscar(Tree* raiz,int n){
    if(raiz == NULL) return 0;
    if(raiz->v == n)
        return 1;
    else if ((raiz)->v > n)
        return buscar((raiz->l),n);
    else
        return buscar((raiz->r),n);
    return 0;
}

double tvtosec(struct timeval t){
  return (double) t.tv_sec + t.tv_usec/(double)1e6;
}

void tremove(Tree* x){
    if(x != NULL){
        tremove(x->l);
        tremove(x->r);
        free(x);
    }
    return;
}
