#include <stdio.h>
#include <stdlib.h>

struct seba{
	int valor;
	struct seba *dir;
	struct seba *esq;
};

typedef struct seba Arvore;

Arvore *criar(){
	return NULL;
}

Arvore *inserir(Arvore *raiz, int x){

	if(raiz == NULL){
		Arvore *aux=(Arvore*)malloc(sizeof(Arvore));		
		aux->valor=x;
		aux->dir=NULL;
		aux->esq=NULL;

		return aux;
	}else{
		if(x < raiz->valor){
			raiz->esq = inserir(raiz->esq, x);
			printf("\nO %d foi inserido a esquerda do %d\n", x, raiz->valor);
		
		}else if(x > raiz->valor){
			raiz->dir = inserir(raiz->dir, x);
			printf("\nO %d foi inserido a direita do %d\n", x, raiz->valor);

		}else{
			//Opcional
			printf("\nO %d ja existe\n",x);
		}
	
	}

	
	return raiz;

}


Arvore *busca(Arvore *raiz, int x)
{
    if (raiz != NULL)
    {
        if (raiz->valor == x)
            return NULL;
        else
        {
            if (x > raiz->valor)
                return busca(raiz->dir, x);
            else
                return busca(raiz->esq, x);
        }
    }
    return NULL;
}

void imprimirNaOrdem(Arvore *raiz){
	if(raiz!=NULL){
		imprimirNaOrdem(raiz->esq);
		printf(" %d ",raiz->valor);
		imprimirNaOrdem(raiz->dir);
	}

}

void imprimirNaPosOrdem(Arvore *raiz){
	if(raiz !=NULL){
		imprimirNaPosOrdem(raiz->esq);
		imprimirNaPosOrdem(raiz->dir);
		printf(" %d ", raiz->valor);		
	}
}


int main(){
	Arvore *raiz=criar();
	raiz=inserir(raiz,9);
	raiz=inserir(raiz,15);
	raiz=inserir(raiz,17);
	raiz=inserir(raiz,11);
	raiz=inserir(raiz,5);

	printf("\n");
	
	imprimirNaOrdem(raiz);
	printf("\n");

	return 0;
}
