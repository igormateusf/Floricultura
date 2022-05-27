#include "plantas.h"

int IncluirPlanta() {
	
	z = fopen("plantas.txt","a");
	
	fclose(z);
		
		printf("\nDigite o numero de identificacao: ");
		scanf("%d", &dados.identificacao);

		printf("\nDigite o respectivo nome cientifico: ");
		scanf(" %s", dados.nome_cientifico);
	
		printf("\nDigite o ano do plantio: ");
		scanf("%d", &dados.ano);
	
		for (;;) {
			if (dados.ano>0) {
				break;
			}
			else {
				printf("\nO ano de plantio nao pode ser negativo.\n");
				printf("Digite o ano de plantio: ");
				scanf("%d", &dados.ano);	
			}
		}

		printf("\nDigite 'S' para frutifera ou 'N' para nao frutifera: ");
		scanf(" %c", &dados.frutifera);
		for (;;) {
			if (dados.frutifera=='S' || dados.frutifera=='N') {
				break;
			}
			else {
				printf("\nResposta invalida, digite somente 'S' para sim ou 'N' para nao: ");
				scanf(" %c", &dados.frutifera);
			}
		}

		printf("\nDigite o preco de venda: R$ ");
		scanf("%f", &dados.preco);
		
		printf("\nDigite a familia da planta: ");
		scanf(" %s", dados.familia);
	
	z= fopen("plantas.txt", "r");
	
		while(fscanf(z, "%d %s %d %c %f %s", &dados2.identificacao, dados2.nome_cientifico, &dados2.ano, &dados2.frutifera, &dados2.preco, dados2.familia) != EOF){
			if(dados2.identificacao==dados.identificacao){
    			printf("Nao e possivel criar numeros de identificacoes iguais, por favor digite outro: ");
    			scanf(" %d", &dados.identificacao);
	    		rewind(z);
	    	}
    	}
    fclose(z);
		
	z= fopen("plantas.txt", "a");
	
		if(z==NULL){
			printf("Erro na abertura do arquivo!\n");
		}	
	
		fprintf(z, "%d\t%s\t%d\t%c\t%.2f\t%s\n",dados.identificacao, dados.nome_cientifico, dados.ano, dados.frutifera, dados.preco, dados.familia);

	fclose(z);
}

int ConsultarPlanta(){

	int id, verify=0;

	z=fopen("plantas.txt", "r");
		if(z==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura do arquivo!\n");
		}

		printf("Digite a identificação da planta:");
		
		scanf("%d", &id);

		while(fscanf(z, "%d %s %d %c %f %s", &dados.identificacao, dados.nome_cientifico, &dados.ano, &dados.frutifera, &dados.preco, dados.familia) != EOF){
			if(id==dados.identificacao){
				printf("\n%d\n%s\n%d\n%c\n%.2f\n%s\n", dados.identificacao, dados.nome_cientifico, dados.ano, dados.frutifera, dados.preco, dados.familia);
				verify++;
			}
		}	
		
		if(verify==0){
			printf("\nNúmero de indentificação não econtrado!\n");
		}

}

int ListarPlantas(){

	z=fopen("plantas.txt", "r");

		if(z==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura do arquivo!\n");
		}

		while(fscanf(z, "%d %s %d %c %f %s", &dados.identificacao, dados.nome_cientifico, &dados.ano, &dados.frutifera, &dados.preco, dados.familia) != EOF){
			printf("\nID:%d\tNome científico:%s\tFrutífera:%c\tPreço:%.2f\n", dados.identificacao, dados.nome_cientifico, dados.frutifera, dados.preco);
		}

	fclose(z);

}

int ExcluirPlanta(){

	int i=0;
	int excluir=0;

	z=fopen("plantas.txt", "r");
	x=fopen("plantasReserva.txt", "w");

		if(z==NULL || x==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura de um dos arquivos!\n");
		}

		printf("Digite o ID da planta que deseja excluir:");
		scanf(" %d", &excluir);
		printf("\n");

		while(fscanf(z, "%d %s %d %c %f %[^\n]", &dados.identificacao, dados.nome_cientifico, &dados.ano, &dados.frutifera, &dados.preco, dados.familia) != EOF){
			if(excluir!=dados.identificacao){
				fprintf(x, "%d\t%s\t%d\t%c\t%.2f\t%s\n", dados.identificacao, dados.nome_cientifico, dados.ano, dados.frutifera, dados.preco, dados.familia);
			}
		}

	fclose(z);
	fclose(x);

	z=fopen("plantas.txt", "w");
	x=fopen("plantasReserva.txt", "r");

		if(z==NULL || x==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura de um dos arquivos!\n");
		}

		while(fscanf(x, "%d %s %d %c %f %[^\n]", &dados.identificacao, dados.nome_cientifico, &dados.ano, &dados.frutifera, &dados.preco, dados.familia) != EOF){
				fprintf(z, "%d\t%s\t%d\t%c\t%.2f\t%s\n", dados.identificacao, dados.nome_cientifico, dados.ano, dados.frutifera, dados.preco, dados.familia);		
		}

	fclose(z);
	fclose(x);

}