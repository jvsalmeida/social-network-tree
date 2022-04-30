#ifndef REDESOCIAL_H
# define REDESOCIAL_H

/**
* Função inserir_usuário
*
*	Esta função tem como objetivo inserir um usuário na árvore de usuários.
*	Há dois parâmetros de entrada, a árvore em si, e o identificador do usuário a ser inserido.
*	Esta função é recursiva, pois a mesma é utilizada para encontrar um lugar vazio onde um novo usuário poderá ser inserido,
*	e é nela que é lido o nome do usuário.
*/
PESSOA *inserir_usuario(PESSOA *raiz, int id); // ler nome

/**
* Função valor_minimo
*
*	Esta função tem como objetivo achar o menor nó da árvore.
*	Há apenas um parâmetro de entrada, que é a árvore de usuários
*/
PESSOA *valor_minimo(PESSOA *node);

/**
* Função remover_usuário
*
*	Esta função tem como objetivo remover um usuário da árvore de usuários.
*	Há dois parâmetros de entrada, o primeiro é árvore de usuários e o segundo
*	é o identificador do usuário a ser removido. Esta é recursiva, pois ela utiliza a função 
*	dentro dela mesma para que o nó a ser removido seja achado.
*/
PESSOA *remover_usuario(PESSOA *raiz, int id);

/**
* Função busca_usuário
*
*	Esta função tem como objetivo achar o nó da árvore de usuários em que um usuário
*	especifico se encontra.
*	Há dois parâmetros de entrada, o primeiro é a árvore de usuários, e o segundo é o 
*	identificador do usuário. Esta é recursiva, pois a função é utilizada dentro da mesma
*	para encontrar onde o usuário se encontra.
*/
PESSOA *busca_usuario(PESSOA *raiz, int id);

#endif