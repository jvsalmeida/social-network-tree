#ifndef AMIZADE_TREE_H
# define AMIZADE_TREE_H

/**
* Função inserir _amizade
*
*	Esta função tem como objetivo inserir um usuário na árvore de amizades de um usuário. 
*	Há dois parâmetros de entrada, o primeiro é uma árvore de amizades e o segundo
*	é o identificador de um usuário. Esta é recursiva, pois a mesma é utilizada
*	para encontrar um nó vazio de modo a por um usuário neste.
*/
AMIZADE *inserir_amizade(AMIZADE *raiz, int id);

/**
* Função valor_min
*
*	Esta função tem objetivo achar o menor nó da árvore de amizades,
*	Seu único parâmetro é uma árvore de amizades.
*/
AMIZADE *valor_min(AMIZADE *node);

/**
* Função remover_amizade
*
*	Esta função tem como objetivo remover um usuário da árvore de amizades.
*	Nesta há dois parâmetros de entrada, o primeiro é uma árvore de amizades, e
*	o segundo é um identificador de um usuário. Esta é recursiva, pois utiliza ela mesma para
*	encontrar o nó a ser removido.
*/
AMIZADE *remover_amizade(AMIZADE *raiz, int id);

/**
* Função busca_amizade
*
*	Esta função tem como objetivo encontrar um nó específico da árvore de amizades.
*	Há dois parâmetros de entrada, o primeiro é uma árvore de amizades, e os segundo
*	é o identificador de um usuário. Esta é recursiva pois é utilizada a mesma dentro dela
*	para que esse nó seja encontrado.
*/
AMIZADE *busca_amizade(AMIZADE *raiz, int id);

/**
* Função em_ordem
*
*	Esta função tem como objetivo imprimir na tela a árvore de amizades.
*	Há apenas um parâmetro de entrada, que é uma árvore de amizades.
*	Esta é recursiva, de modo que é printado primeiro o filho da esquerda, depois
*	a raiz, e em seguida o filho da direita.
*/
void em_ordem(AMIZADE *raiz);

#endif