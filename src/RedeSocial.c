#include "../lib/include.h"
#include "../lib/RedeSocial.h"


PESSOA *inserir_usuario(PESSOA *raiz, int id) {
	if(raiz == NULL) {
		PESSOA *new_raiz = (PESSOA*) malloc (sizeof(PESSOA));

		new_raiz -> id = id;
		new_raiz -> esq = NULL;
		new_raiz -> dir = NULL;
        new_raiz -> aponta = NULL;

        printf("Digite seu nome:\n");
        scanf(" %[^\n]%*c", new_raiz -> nome);
        printf("\n");

		return new_raiz;
	}


	if(id > raiz -> id) {
		raiz -> dir = inserir_usuario(raiz -> dir, id);
	} else if(id < raiz -> id) {
		raiz -> esq = inserir_usuario(raiz -> esq, id);
	} else {
		printf("Esse Elemento Já Existe Na Árvore\n");
	}

	return raiz;
}


PESSOA *valor_minimo(PESSOA *raiz) { 
    PESSOA *atual = raiz; 

    while (atual && atual -> esq != NULL) 
        atual = atual -> esq;

    return atual; 
} 

PESSOA *remover_usuario(PESSOA *raiz, int id) { 
     
    if (raiz == NULL)
    	return raiz; 

    if (id < raiz -> id) 
        raiz -> esq = remover_usuario(raiz -> esq, id); 
  
    else if (id > raiz -> id) 
        raiz -> dir = remover_usuario(raiz -> dir, id); 
   
    else { 
        
        if (raiz -> esq == NULL) { 
            PESSOA *temp = raiz -> dir; 
            free(raiz); 
            return temp; 
        } 
        
        else if (raiz -> dir == NULL) { 
            PESSOA *temp = raiz -> esq; 
            free(raiz); 
            return temp; 
        } 
  
        PESSOA *temp = valor_minimo(raiz -> dir); 
  
        raiz -> id = temp -> id; 
  
        raiz -> dir = remover_usuario(raiz -> dir, temp -> id); 
    } 
    return raiz; 
}


PESSOA *busca_usuario(PESSOA *raiz, int id) {
	if (raiz == NULL || raiz -> id == id)
		return raiz;

	else if (id < raiz -> id)
		return busca_usuario(raiz -> esq, id);

	else
		return busca_usuario(raiz -> dir, id);

}