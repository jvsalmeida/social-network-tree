#ifndef FUNCOES_H
# define FUNCOES_H

/**
* Função mostrar_perfil
*
*	Esta função tem como objetivo mostrar as informações do usuário.
*	Há dois parâmetros de entrada, o primeiro é a árvore de usuários que é do tipo 'PESSOA', 
*	o outro é o identificador do nó que é do tipo 'int'.
*	Nela há o uso de outras funções, como a busca_usuario e em_ordem.
*	Esta primeira é utilizada para achar o nó da árvore em que o usuário está inserido,
*	após isso, o nome, o id e as amizades do indivíduo são mostrados.
*/
void mostrar_perfil(PESSOA *raiz, int id);

/**
* Função adicionar_amizade
*
*	Esta função tem como objetivo tornar dois usuários amigos.
* 	Há três parâmetros de entrada, o primeiro é a árvore de usuários que é do tipo 'PESSOA',
*	o segundo e o terceiro são identificadores do tipo 'int', cada um referente a um dos usuários.
*	Assim, é utilizada a função busca_usuario para indentificar em qual nó da árvore estão os usuários,
*	se eles não forem amigos, então a função inserir_amizade é usada para torná-los amigos.
*/
void adicionar_amizade(PESSOA *raiz, int id_1, int id_2);


/**
* Função excluir_amizade
*
*	Esta função tem como objetivo desfazer a amizade entre dois usuários.
*	Há três parâmetros de entrada, o primeiro é a árvore de usuários que é do tipo 'PESSOA',
*	o segundo e o terceiro são identificadores do tipo 'int', cada um referente a um usuário.
*	Assim, é utilizada a função busca_usuario para encontrar na árvore o nó em cada usuário está,
*	se eles forem amigos então a função remover_amizade é utilizada para desfazer a amizade entre eles.
*/
void excluir_amizade(PESSOA *raiz, int id_1, int id_2);

/**
* Função verificar_amizade
*
*	Esta função tem como objetivo verificar se dois usuários são amigos.
*	Há três parâmetros de entrada, o primeiro é a árvore de usuários que é do tipo 'PESSOA',
*	o segundo e o terceiro são identificadores do tipo 'int', cada um referente a um usuário.
*	Assim, é utilizada a função busca_usuário para encontrar na árvore o nó de um dos usuário,
*	deste modo, a função busca_amizade é usada para procurar na árvore de amizades de um dos usuários
*	o outro usuário.
*/
int verificar_amizade(PESSOA *raiz, int id_1, int id_2);

/**
* Função gerar_id
*
*	Esta função tem como objetivo gerar os números identificadores de cada usuário.
*	Não há parâmetros de entrada. Ela gera números sequenciais.
*/
int gerar_id(void);

/**
* Função esperar_enter
*
*	Esta função tem como objetivo pedir ao usuário que aperte a tecla 
*	enter para que o programa continue.
*/
void esperar_enter(void);

/**
* Função remover_perfil
*
*	Esta função tem como objetivo apagar um usuário do sistema, logo	
*	ele também deverá ser apagado da árvore de amizades de outros usuários.
*	Há dois parâmetros de entrada, o primeiro é a árvore de usuários do tipo 'PESSOA',
*	e o segundo é o identificador de um usuário. Assim, a função busca_usuario é utilizada
*	para encontrar o usuário dentro da árvore de usuários, após isso, é utilizada a função
*	amizade_free é usada para apagar a árvore de amizades do usuário, e em seguida
*	a função remover_usuario é utilizada para apagar o usuário do sistema.
*/
void remover_perfil(PESSOA *raiz, int id);

/**
* Função amizade_free
*
*	Esta função tem como objetivo apagar a árvore de amizades de um usuário do sistema.
*	Há três parâmetros de entrada, o primeiro é a árvores de usuários, o segundo é uma árvore de amizades,
*	e o terceiro é o identificador de um usuário.
*	Assim, a própria função é utilizada dentro dela mesma, tornando-a recursiva, tanto para os filhos 
*	da esquerda quanto da direita. E a função excluir_amizade é utilizada em seguida para exluir as amizades entre os usuários.
*/
void amizade_free(PESSOA *raiz, AMIZADE *root, int id);

/**
* Função free_tree
*
*	Esta função tem como objetivo apagar a árvore de usuários do sistema.
*	Há um parâmetro de entrada, sendo este a própria árvore de usuários.
*	A função é recursiva, e utiliza a função remover_perfil dentro dela.
*/
void free_tree(PESSOA *raiz);

#endif