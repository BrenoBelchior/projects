#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
typedef struct NO {
	int dado;
	struct NO *esq;
	struct NO *dir;
	struct NO *pai;
} NO;
typedef struct ARVORE{
	NO *raiz;
}ARVORE;
ARVORE a;
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void arvore_insere(int valor);
void preOrdem(NO* raiz);
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}
void arvore_insere(int valor){
	NO* corrente = a.raiz;
	NO* pai;
	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		return;
	}
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				pai->dir = novoNo;
				return;
			}
		}
	}
}
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	inicializaArvore(a);
	
	arvore_insere(2);
	arvore_insere(1);
	arvore_insere(0);
	arvore_insere(8);
	arvore_insere(4);
	arvore_insere(9);
	arvore_insere(6);
	arvore_insere(9);
	
	printf("\tPre ordem: \n");
	preOrdem(a.raiz);
}