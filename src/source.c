#include "../lib/include.h"
#include "../lib/RedeSocial.h"
#include "../lib/AmizadeTree.h"
#include "../lib/funcoes.h"

/**
* Função main
*
*	Nesta função são lidos os comandos do indivíduo que usará o programa.
*	Há várias outras funções dentro desta, como por exemplo esperar_enter, inserir_usuario, entre outros.
*/
int main() {
	PESSOA *raiz = NULL;

	bool status = true;
	char comando[50];
	
	int num;
	int num_2;

	srand(time(NULL));

	while (status) {
		system("clear");
		printf("Digite um comando:\n");
		scanf(" %[^\n]%*c", comando);


		if (strcmp(comando, "inserir_usuario") == 0) {
			raiz = inserir_usuario(raiz, gerar_id());
			printf("Perfil criado com sucesso!\n");

			esperar_enter();
		}

		else if (strcmp(comando, "remover_perfil") == 0) {
			printf("Digite um Id:\n");
			scanf("%d%*c", &num);
			remover_perfil(raiz, num);
			printf("Perfil removido com sucesso\n");

			esperar_enter();
		}

		else if (strcmp(comando, "mostrar_perfil") == 0) {
			printf("Digite um Id:\n");
			scanf("%d%*c", &num);
			mostrar_perfil(raiz, num);

			esperar_enter();
		}

		else if (strcmp(comando, "adicionar_amizade") == 0) {
			printf("Digite o Id de cada pessoa:\n");
			scanf("%d%d", &num, &num_2);
			adicionar_amizade(raiz, num, num_2);


			esperar_enter();
		}

		else if (strcmp(comando, "excluir_amizade") == 0) {
			printf("Digite o Id de cada pessoa:\n");
			scanf("%d%d", &num, &num_2);
			excluir_amizade(raiz, num, num_2);

			esperar_enter();
		}

		else if (strcmp(comando, "verificar_amizade") == 0) {
			free_tree(raiz);
			printf("Digite o Id de cada pessoa:\n");
			scanf("%d%d", &num, &num_2);
			verificar_amizade(raiz, num, num_2);

			esperar_enter();
		}	

		else if (strcmp(comando, "quit") == 0) {
			free_tree(raiz);
			status = false;
		}

		else 
			printf("Esse comando não existe. Digite novamente !\n");
	}

	return 0;
}