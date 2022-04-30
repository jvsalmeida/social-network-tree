#ifndef INCLUDE_H
# define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/**
* Struct da árvore de amizades
*
*	Nessa struct há um indentificador(chave) do tipo 'int', e dois ponteiros 
*	do tipo 'AMIZADE', sendo que um destes aponta para o filho da esquerda
*	e o outro para o filho da direita.
*/
typedef struct amizade{
	int id; /**< Identificador. */
	struct amizade *esq; /**< Ponteiro para o filho da esquerda. */
	struct amizade *dir; /**< Ponteiro para o filho da direita. */
}AMIZADE;

/**
* Struct da árvore de usuários
*
*	Nessa struct há um identificador para cada nó, do tipo 'int',
*	um string para armazenar o nome dos usuários, dois ponteiros do tipo 'PESSOA',
*	um apontando para o filho da esquerda e o outro para o filho da direita,
*	e um outro ponteiro do tipo 'AMIZADE' que aponta para a árvore de amizades.
*/
typedef struct pessoa{
	int id; /**< Identificador. */
	char nome[50]; /**< String que contém o nome do usuário. */
	struct pessoa *esq; /**< Ponteiro para o filho da esquerda. */
	struct pessoa *dir; /**< Ponteiro para o filho da direita. */
	AMIZADE *aponta; /**< Ponteiro para a árvore de amizades. */
}PESSOA;

#endif