#include "usuario.h"
#include "plantas.h"

void menuElemento();
void menuControle();
void montarMenu();

int main() {

	int n;

	if (jota==0) {
		Logar();
	}

	printf("\n");
	printf("\t1 - Planta\n");
	printf("\t2 - Analise de dados\n");
	printf("\t3 - Controle de Acesso\n");
	printf("\t0 - Sair\n");
	printf("________________________________________\n");
	scanf("%d", &n);
	printf("\n");
                
	montarMenu(n);
	
return 0;	
}

void montarMenu(int n) {

	switch (n){

		case 1:
			menuElemento();
			break;

		case 2:

			break;

		case 3:
			menuControle();

		case 0:
			exit(0);
			break;			

	}

}
void menuElemento() {

	int n;

	printf("\t1 - Incluir planta\n");
	printf("\t2 - Consultar planta\n");
	printf("\t3 - Listar planta\n");
	printf("\t4 - Excluir planta\n");
	printf("\t0 - Voltar ao menu principal\n");
	printf("________________________________________\n");

	scanf("%d", &n);

	switch(n){

		case 1:
			IncluirPlanta();
			break;

		case 2:
			ConsultarPlanta();
			break;

		case 3:
			ListarPlantas();
			break;

		case 4:
			ExcluirPlanta();
			break;

		case 0:
			main();
			break;		


	}

	menuElemento();


}
void menuControle() {

	int n;

	printf("\t1 - Incluir\n");
	printf("\t2 - Excluir\n");
	printf("\t3 - Listar usuarios\n");
	printf("\t4 - Alterar senha\n");
	printf("\t0 - Voltar ao menu principal\n");
	printf("________________________________________\n");

	scanf("%d", &n);

	switch(n){

		case 1:
			IncluirUsuario();
			break;

		case 2:
			ExcluirUsuario();
			break;

		case 3:
			ListarUsuarios();
			break;

		case 4:
			AlterarSenha();
			break;

		case 0:
			main();
			break;

	}

	menuControle();

}


