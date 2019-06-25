
#include<stdio.h>
#define max 50
#define nulo 0
#define infinito max-1

enum booleano {false,true};

int grafo[max][max];
int distancia[max];

int vertices, arestas;
int custo=0;

int main(){
  int i; 
  limpa_grafo();
  ler_grafo();
  mostra_grafo();
  DFS(0);
  for (i=0;i<vertices;i++){printf("[%d]",distancia[i]);}
  printf("\n");
}

void limpa_grafo(){
	int i,j;
	for (i=0;i<vertices;i++)
	  for (j=0;j<vertices;j++) grafo[i][j]=nulo;
}

void mostra_grafo(){
	int i,j;
	for (i=0;i<vertices;i++){
	  for (j=0;j<vertices;j++){
	     if (grafo[i][j]==nulo)printf(". ");
             else printf("* ");
	  }
	  printf("\n");
	}
}

void ler_grafo(){
	int i,j,a,b;
	scanf("%d %d",&vertices, &arestas);
        for (j=0;j<arestas;j++){
          scanf("%d %d",&a,&b);
          grafo[a-1][b-1]=1;
          grafo[b-1][a-1]=1;
        }
}

int grau(int n){
	int i,ocorrencias;
	for (i=0;i<vertices;i++)
	  if (grafo[n][i]) ocorrencias++;
	return(ocorrencias);
}
void visitaDFS(int n){
	int i;
	distancia[n]=custo;
	for (i=0;i<vertices;i++)
	if ( (grafo[n][i]) && (custo<distancia[i]) ){
		custo++;		
		printf("visitando %d a partir de %d. custo= %d \n",i,n,custo);
		visitaDFS(i);
		custo--;
	}
}

void DFS(int source){
  int i;
  printf("Inicializando uma DFS em %d\n",source);
  for(i=0;i<vertices;i++){distancia[i]=infinito;}
  distancia[source]=0;
  custo=0;
  for(i=0;i<vertices;i++)
  if  ( (grafo[source][i]) && (custo<distancia[i])){    
    printf("visitando %d a partir de %d . custo= %d \n",i,source,custo);
    custo++;
    visitaDFS(i);
    custo--;
  }
}

