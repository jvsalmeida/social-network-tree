#include "../lib/include.h"
#include "../lib/RedeSocial.h"
#include "../lib/AmizadeTree.h"
#include "../lib/funcoes.h"

void mostrar_perfil(PESSOA *raiz, int id) {
	
	PESSOA *endereco = busca_usuario(raiz, id);

	if (endereco == NULL)
		return;


	printf("Nome: %s\n", endereco -> nome);
	printf("ID : %d\n", endereco -> id);


	if (endereco -> aponta == NULL)
		printf("Nao tem amigos");
	else {
		printf("Amigos:\n");
		em_ordem(endereco -> aponta);
	}
	puts("\n");
}

void adicionar_amizade(PESSOA *raiz, int id_1, int id_2) {
	PESSOA *endereco_1 = busca_usuario(raiz, id_1);
	PESSOA *endereco_2 = busca_usuario(raiz, id_2);

	if (endereco_1 == NULL) {
		return;
	}

	if (endereco_2 == NULL) {
		return;
	}

	if (!(verificar_amizade(raiz, id_1, id_2))) {
		endereco_1 -> aponta = inserir_amizade(endereco_1 -> aponta, id_2);
		endereco_2 -> aponta = inserir_amizade(endereco_2 -> aponta, id_1);
	}
}


void excluir_amizade(PESSOA *raiz, int id_1, int id_2) {
	PESSOA *endereco_1 = busca_usuario(raiz, id_1);
	PESSOA *endereco_2 = busca_usuario(raiz, id_2);

	if (endereco_1 == NULL) {
		return;
	}

	if (endereco_2 == NULL) {
		return;
	}

	if (verificar_amizade(raiz, id_1, id_2)) {
		endereco_1 -> aponta = remover_amizade(endereco_1 -> aponta, id_2);
		endereco_2 -> aponta = remover_amizade(endereco_2 -> aponta, id_1);
	}

}

int verificar_amizade(PESSOA *raiz, int id_1, int id_2) {

	PESSOA *endereco = busca_usuario(raiz, id_1);
	PESSOA *endereco_2 = busca_usuario(raiz, id_2);

	if(endereco == NULL) {
		printf("Id: %d não existe\n", id_1);
		return 0;
	}

	else if(endereco_2 == NULL) {
		printf("Id: %d não existe\n", id_2);
		return 0;
	}
	
	else if (busca_amizade(endereco -> aponta, id_2) != NULL) {
		return 1;
	}
	
	else {
		return 0;
	}

}

void remover_perfil(PESSOA *raiz, int id) {
	PESSOA *endereco = busca_usuario(raiz, id);

	if (endereco == NULL)
		return;

	amizade_free(raiz, endereco -> aponta, id);
	raiz = remover_usuario(raiz, id);
}


void amizade_free(PESSOA *raiz, AMIZADE *root, int id) {
	if (root == NULL)
		return;

	amizade_free(raiz, root -> esq, id);
	amizade_free(raiz, root -> dir, id);

	excluir_amizade(raiz, id, root -> id);
}


int gerar_id(void) {
	static int w = 0;

	++w;

	return w;

	//int number = rand() % 10 + 1;
	//return number;
}


void esperar_enter(void) {
	printf("Pressione enter para continuar\n");
	while (true) {
		char enter;
		scanf("%c", &enter);

		if (enter == '\n')
			break;
	}
}


void free_tree(PESSOA *raiz) {
	if (raiz != NULL) {
		free_tree(raiz -> esq);
		free_tree(raiz -> dir);

		remover_perfil(raiz, raiz -> id);
	}
}
