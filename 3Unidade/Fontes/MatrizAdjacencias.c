//TITULO DO PROJETO: MatrizAdjacencias.c
//VERSÃO ou DATA:1.0 25/06/2019
//AUTORES:LAURENTINO, J.I.C.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int quantidade_arestas();
void preencher_vetor(int *vetor, int arestas);
void adicionar ( int arestas , int *vetor, int matriz[arestas][arestas]);
int verifica_posicao_chave(int *vetor, int valor, int arestas) ;
void exibir(int arestas, int *vetor, int matriz[arestas][arestas]);

int main (void){
    int i, j, arestas;
    arestas = quantidade_arestas();
    int matriz[arestas][arestas];
    int vetor_posicoes[arestas];
    
	for(i = 0; i < arestas; i++)
		for(j = 0; j < arestas; j++)
            matriz[i][j] = 0;
            
    preencher_vetor(vetor_posicoes, arestas);
    adicionar(arestas, vetor_posicoes, matriz);
    exibir(arestas, vetor_posicoes, matriz);
    return 0;
}

int quantidade_arestas(){    
    FILE *arq;
    arq = fopen("grafo.txt", "r");
    char linha[100], *resultado;
    int contador = 0;

    while(!feof(arq)){
        resultado = fgets(linha, 100, arq);
        if(strcmp (linha, "#\n") == 0) break;
        else contador++;
    }
    fclose(arq);
    return contador;
}

void preencher_vetor(int *vetor, int arestas){    
    FILE *arq;
    arq = fopen("grafo.txt", "r");
    char linha[100], *resultado;
    int contador = 0;

    while(contador < arestas){
        resultado = fgets(linha, 100, arq);
        vetor[contador] = atoi(linha);
        contador++;
    }
    fclose(arq);
}

void adicionar (int arestas , int *vetor, int matriz[arestas][arestas]){    
    FILE *arq;
    arq = fopen("grafo.txt", "r");
    char linha[100], *resultado, *split;
    int  contador = 0, contador_linha = 0, chave, valor, posicao_chave, posicao_valor;
    while(!feof(arq)){
        resultado = fgets(linha, 100, arq);
        if(contador > arestas){            
            contador_linha = 0;
            split = strtok(linha, " ");
            while (split != NULL){
                if(contador_linha == 0){chave = atoi(split);}
                else{valor = atoi(split);}
                contador_linha++;
                split = strtok (NULL, " ");
            }
            posicao_chave = verifica_posicao_chave(vetor, chave , arestas);
            posicao_valor = verifica_posicao_chave(vetor, valor , arestas);
            matriz[posicao_chave][posicao_valor] = 1;
        }
        contador++;
    }
    fclose(arq);
}

int verifica_posicao_chave(int *vetor, int valor, int arestas) {
    int i;
    for(i = 0; i < arestas; i++){
        if(vetor[i] == valor){return i;}
    }
}

void exibir(int arestas, int *vetor, int matriz[arestas][arestas]){
    int i, j, k;
    printf("     ");
    for(k=0; k < arestas; k++) printf("[%d] ", vetor[k]);
    printf("\n");
    for(i = 0; i < arestas; i++){
        printf("[%d]", vetor[i]);
        for(j = 0; j < arestas; j++){printf("   %d ", matriz[i][j]);}
        printf("\n");
    }   
}
