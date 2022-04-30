#include "../lib/include.h"
#include "../lib/AmizadeTree.h"


AMIZADE *inserir_amizade(AMIZADE *raiz, int id) {
	if(raiz == NULL) {
		AMIZADE *new_raiz = (AMIZADE*) malloc (sizeof(AMIZADE));

		new_raiz -> id = id;
		new_raiz -> esq = NULL;
		new_raiz -> dir = NULL;

		return new_raiz;
	}


	if(id > raiz -> id) {
		raiz -> dir = inserir_amizade(raiz -> dir, id);
	} else if(id < raiz -> id) {
		raiz -> esq = inserir_amizade(raiz -> esq, id);
	} else {
		printf("Esse Elemento Já Existe Na Árvore\n");
	}

	return raiz;
}


AMIZADE *valor_min(AMIZADE *node) { 
    AMIZADE *atual = node; 
  
    while (atual && atual -> esq != NULL) 
        atual = atual -> esq; 
  
    return atual; 
} 


AMIZADE *remover_amizade(AMIZADE *raiz, int id) { 
 
    if (raiz == NULL)
    	return raiz; 
   
    if (id < raiz -> id) 
        raiz -> esq = remover_amizade(raiz -> esq, id); 
  
    else if (id > raiz -> id) 
        raiz -> dir = remover_amizade(raiz -> dir, id); 
  
    else { 
    
        if (raiz -> esq == NULL) { 
            AMIZADE *temp = raiz -> dir; 
            free(raiz); 
            return temp; 
        } 
        
        else if (raiz -> dir == NULL) { 
            AMIZADE *temp = raiz -> esq; 
            free(raiz); 
            return temp; 
        } 
  
        AMIZADE *temp = valor_min(raiz -> dir); 
  
        raiz -> id = temp -> id; 
   
        raiz -> dir = remover_amizade(raiz -> dir, temp -> id); 
    } 
    return raiz; 
}


AMIZADE *busca_amizade(AMIZADE *raiz, int id) {
	if (raiz == NULL || raiz -> id == id)
		return raiz;

	else if (id < raiz -> id)
		return busca_amizade(raiz -> esq, id);

	else
		return busca_amizade(raiz -> dir, id);
}


void em_ordem(AMIZADE *raiz) {
    if (raiz != NULL) {
        em_ordem(raiz -> esq);
        printf("%d ", raiz -> id);
        em_ordem(raiz -> dir);
    }
}