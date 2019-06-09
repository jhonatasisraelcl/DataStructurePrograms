
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

typedef struct lista {
    int numero;
    struct lista *prox;
}Lista;

Lista* criar_no(int num);
void adicionar(Lista **raiz, int num);
void print(Lista *raiz);
int buscar(Lista *raiz, int num);
void tremove(Lista *raiz);
double tvtosec(struct timeval t);

int main (void) {
  Lista *raiz = NULL;
  srand(time(NULL));
	struct timeval a;
	struct timeval b;
	double tempo;
    int i, aleatorio, k, n, achou, primeiro;
 	for(n = 1000; n <= 10000; n += 500){      
 		tempo = 0;
 		for(i = 0; i < 10000 ; i++){

            for(k = 0; k < n; k++){
                aleatorio = rand() % (n+1);
                adicionar(&raiz, aleatorio);
                if(k == n-1){
                    primeiro = aleatorio;
                }
            }
		 	gettimeofday(&b, NULL);
            achou = buscar(raiz, primeiro); 
		 	gettimeofday(&a, NULL);
		 	tempo  += tvtosec(a) - tvtosec(b);
            tremove(raiz);
            raiz = NULL;
	 	}
	 	fprintf(stderr, "%d %.20lf\n", n, tempo/10000 );
	 	printf("%d %.20lf\n", n, tempo/10000 );
    }   
}

Lista* criar_no(int num){
    Lista* no = (Lista*)malloc(sizeof(Lista));
    no->numero = num;
    no->prox = NULL;
    return no;
}
void adicionar(Lista **raiz, int num){
    Lista* no = criar_no(num);
    no->prox = (*raiz);
    *raiz = no;
}

void print(Lista *raiz){
    if(raiz != NULL){
        printf("\nEndereço: %p Valor: %d Próximo nó: %p\n", raiz, raiz->numero, raiz->prox);
        print(raiz->prox);
    }
}

int buscar(Lista *raiz, int num){
    if(raiz == NULL) return 0;
    else if (raiz->numero == num) return 1;
    else buscar(raiz->prox, num);
}

void tremove(Lista *raiz){
    if(raiz != NULL){
        tremove(raiz->prox);
        free(raiz);
    }
    return;
}

double tvtosec(struct timeval t){
  return (double) t.tv_sec + t.tv_usec/(double)1e6;
}
