#include "usuario.h"

int IncluirUsuario(){

	int n, cont, quantos_caracteres=0, i;
	char aux;

	f=fopen("usuarios.txt", "a");

	if(f==NULL){        //Verificar se o arquivo existe
		printf("Erro na abertura do arquivo!\n");
	}

	printf("Digite o novo login: ");
	scanf(" %s", acesso.login);
	printf("\n");

	printf("Digite o novo usuario: ");
	scanf(" %[^\n]", acesso.usuario);
	printf("\n");

	do{ 
		printf("Digite a nova senha: ");
		scanf(" %s", acesso.senha);
		printf("\n");

	if(strlen(acesso.senha)<3){
		printf("Senha inválida!\n");
	}
	}while(strlen(acesso.senha) < 3);

		quantos_caracteres=strlen(acesso.senha);
		
			for(i=0; i<quantos_caracteres; i++){
				if((acesso.senha[i]>=48 && acesso.senha[i]<=57) || (acesso.senha[i]>=65 && acesso.senha[i]<=90) || (acesso.senha[i]>=97 && acesso.senha[i]<=122)){
					acesso.senha[i]=acesso.senha[i]+3;
				}
			}
		
			if(quantos_caracteres%2==1){
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=acesso.senha[i];
					acesso.senha[i]=acesso.senha[i+1];
					acesso.senha[i+1]=aux;
				}
			}else{
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=acesso.senha[i];
					acesso.senha[i]=acesso.senha[i+1];
					acesso.senha[i+1]=aux;
				}
			}
		
			for(i=0; i<quantos_caracteres; i++){
				if(acesso.senha[i]==' '){
					acesso.senha[i]='+';
				}else if(acesso.senha[i]=='+'){
					acesso.senha[i]=' ';
				}
			}
		
		acesso.senha[quantos_caracteres]='\0';

	fclose(f);

	f=fopen("usuarios.txt", "r");

		if(f==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura do arquivo!\n");
		}

		while(fscanf(f, " %s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario) != EOF){

			if(strcmp(acesso2.login, acesso.login)==0){
				printf("Nao e possivel criar mais de um usuario com o mesmo login, por favor digite outro:");
				scanf(" %s", acesso.login);
				rewind(f);
			}

		}

	fclose(f);

	f=fopen("usuarios.txt", "a");

		if(f==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura do arquivo!\n");
		}

		fprintf(f, "%s\t%s\t%s\n", acesso.login, acesso.senha, acesso.usuario);

	fclose(f);

	}


int ExcluirUsuario(){

	int i=0;
	char excluir[50];

	f=fopen("usuarios.txt", "r");
	p=fopen("usuariosReserva.txt", "w");

		if(f==NULL || p==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura de um dos arquivos!\n");
		}

		printf("Qual usuario deseja excluir?:");
		scanf(" %[^\n]", excluir);
		printf("\n");

		while(fscanf(f, " %s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario) != EOF){
			if(strcmp(acesso2.usuario, excluir)!=0){
				fprintf(p, "%s\t%s\t%s\n", acesso2.login, acesso2.senha, acesso2.usuario);
			}

		}

	fclose(f);
	fclose(p);

	f=fopen("usuarios.txt", "w");
	p=fopen("usuariosReserva.txt", "r");

		if(f==NULL || p==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura de um dos arquivos!\n");
		}

		char letra[50];

		while(fscanf(p, " %s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario) != EOF){
				
				fprintf(f, "%s\t%s\t%s\n", acesso2.login, acesso2.senha, acesso2.usuario);
		}

	fclose(f);
	fclose(p);

}

int ListarUsuarios() {
	Estrutura string[50];
	int i=0, j, k, r;
	char aux[50];
	
	f=fopen("usuarios.txt", "r");

		if(f==NULL){        //Verificar se o arquivo existe
				printf("Erro na abertura do arquivo!\n");
			}
	
		while (fscanf(f, " %s %s %[^\n]", string[i].login, string[i].senha, string[i].usuario)!=EOF){		
			i++;
		}

		for (k=0; k<i-1; k++){
			for (j=k+1; j<i; j++) {
				r= strcmp(string[j].usuario, string[k].usuario);
				if(r<0) {
				
					strcpy(aux, string[j].usuario);
					strcpy(string[j].usuario, string[k].usuario);
					strcpy(string[k].usuario, aux);
				}
			}
		}
	
		printf("\n");
		for (k=0; k<i; k++) {
			printf("%d-%s\n", k+1, string[k].usuario);
		}
		printf("\n");
	
	fclose(f);
}	

int AlterarSenha() {
	char auxiliar[50];
	char novaSenha[50];
	int n, cont, quantos_caracteres=0, i;
	char aux;
	
	f = fopen("usuarios.txt", "r");
	g = fopen("alterarSenha.txt", "w");
	
		if(f==NULL || g==NULL){
			printf("Erro na abertura de um dos arquivos!\n");
		}
	
		printf("Confirme sua senha atual: ");
		scanf("%s", auxiliar);
		getchar();
	
		for (;;) {
			if(strcmp(auxiliar,SENHA)==0) {
			printf("\nSenha correta!\n");
			printf("Digite a nova senha: ");
			scanf(" %s", novaSenha);
			printf("\n");
			strcpy(SENHA, novaSenha);
			break;
		
			}
			else {
				printf("\nSenha incorreta!\n");
				printf("Digite sua senha: ");
				scanf(" %s", auxiliar);
			}
		}

	//________________________________________
	// CRIPTOGRAFAR NOVASENHA
	//________________________________________


		quantos_caracteres=strlen(novaSenha);
		
			for(i=0; i<quantos_caracteres; i++){
				if((novaSenha[i]>=48 && novaSenha[i]<=57) || (novaSenha[i]>=65 && novaSenha[i]<=90) || (novaSenha[i]>=97 && novaSenha[i]<=122)){
					novaSenha[i]=novaSenha[i]+3;
				}
			}
		
			if(quantos_caracteres%2==1){
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=novaSenha[i];
					novaSenha[i]=novaSenha[i+1];
					novaSenha[i+1]=aux;
				}
			}else{
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=novaSenha[i];
					novaSenha[i]=novaSenha[i+1];
					novaSenha[i+1]=aux;
				}
			}
		
			for(i=0; i<quantos_caracteres; i++){
				if(novaSenha[i]==' '){
					novaSenha[i]='+';
				}else if(novaSenha[i]=='+'){
					novaSenha[i]=' ';
				}
			}
		
		novaSenha[quantos_caracteres]='\0';

	//________________________________________
	//TERMINADO
	//________________________________________



	//________________________________________
	// CRIPTOGRAFAR AUXILIAR
	//________________________________________


		quantos_caracteres=strlen(auxiliar);
		
			for(i=0; i<quantos_caracteres; i++){
				if((auxiliar[i]>=48 && auxiliar[i]<=57) || (auxiliar[i]>=65 && auxiliar[i]<=90) || (auxiliar[i]>=97 && auxiliar[i]<=122)){
					auxiliar[i]=auxiliar[i]+3;
				}
			}
		
			if(quantos_caracteres%2==1){
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=auxiliar[i];
					auxiliar[i]=auxiliar[i+1];
					auxiliar[i+1]=aux;
				}
			}else{
				for(i=0; i<quantos_caracteres-1; i+=2){
					aux=auxiliar[i];
					auxiliar[i]=auxiliar[i+1];
					auxiliar[i+1]=aux;
				}
			}
		
			for(i=0; i<quantos_caracteres; i++){
				if(auxiliar[i]==' '){
					auxiliar[i]='+';
				}else if(auxiliar[i]=='+'){
					auxiliar[i]=' ';
				}
			}
		
		auxiliar[quantos_caracteres]='\0';



	//________________________________________
	//TERMINADO
	//________________________________________

	
		while(fscanf(f, " %s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario) != EOF){
			if(strcmp(acesso2.senha, auxiliar)!=0 && strcmp(acesso2.login, LOGIN)!=0){
				fprintf(g, "%s\t%s\t%s\n", acesso2.login, acesso2.senha, acesso2.usuario);
			}
			if(strcmp(acesso2.senha, auxiliar)==0) {
				fprintf(g, "%s\t%s\t%s\n", acesso2.login, novaSenha, acesso2.usuario);
			}
		}
		
	fclose(f);
	fclose(g);

	f= fopen("usuarios.txt", "w");
	g= fopen("alterarSenha.txt", "r");

		if(f==NULL || g==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura de um dos arquivos!\n");
		}
	
		while(fscanf(g, " %s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario) != EOF){
			fprintf(f, "%s\t%s\t%s\n", acesso2.login, acesso2.senha, acesso2.usuario);
		}
		
	fclose(f);
	fclose(g);	
}	


	//FUNÇÕES PARA O USUARIO DO SOFTWARE LOGAR
int Logar() {
	char n;
	
	do{
		printf("Voce ja possui um login? Digite 'S' para sim, 'N' para nao: ");
		scanf("%c", &n);
		getchar();
	}while(n!='S' && n!='N');
	
	if (n=='S') {
		Digitar();
	}
	else if(n=='N'){
		IncluirUsuario();
		Digitar();
	}
	
}

int Digitar() {

	int n, cont, quantos_caracteres=0, i;
	char aux;

	printf("\n\tDigite seu login: ");
	scanf(" %s", LOGAR.login);
	printf("\tDigite sua senha: ");
	scanf(" %s", LOGAR.senha);
	printf("\n");
	strcpy(SENHA, LOGAR.senha);
	strcpy(LOGIN, LOGAR.login);

	//________________________________________
	// CRIPTOGRAFAR LOGAR.SENHA
	//________________________________________


	quantos_caracteres=strlen(LOGAR.senha);
	
	for(i=0; i<quantos_caracteres; i++){
		if((LOGAR.senha[i]>=48 && LOGAR.senha[i]<=57) || (LOGAR.senha[i]>=65 && LOGAR.senha[i]<=90) || (LOGAR.senha[i]>=97 && LOGAR.senha[i]<=122)){
			LOGAR.senha[i]=LOGAR.senha[i]+3;
		}
	}
		
	if(quantos_caracteres%2==1){
		for(i=0; i<quantos_caracteres-1; i+=2){
			aux=LOGAR.senha[i];
			LOGAR.senha[i]=LOGAR.senha[i+1];
			LOGAR.senha[i+1]=aux;
		}
	}else{
		for(i=0; i<quantos_caracteres-1; i+=2){
			aux=LOGAR.senha[i];
			LOGAR.senha[i]=LOGAR.senha[i+1];
			LOGAR.senha[i+1]=aux;
		}
	}
	
	for(i=0; i<quantos_caracteres; i++){
		if(LOGAR.senha[i]==' '){
			LOGAR.senha[i]='+';
		}else if(LOGAR.senha[i]=='+'){
			LOGAR.senha[i]=' ';
		}
	}
		
	LOGAR.senha[quantos_caracteres]='\0';


	//________________________________________
	//TERMINADO
	//________________________________________

		
	f = fopen("usuarios.txt", "r");

		if(f==NULL){        //Verificar se o arquivo existe
			printf("Erro na abertura do arquivo!\n");
		}

		while(fscanf(f, "%s %s %[^\n]", acesso2.login, acesso2.senha, acesso2.usuario)!= EOF) {
			if(strcmp(LOGAR.login, acesso2.login)==0 && strcmp(LOGAR.senha, acesso2.senha)==0) {
				printf("Voce esta logado no usuario: %s.\n\n", acesso2.usuario);
				jota++;
				main();
			}
		}
		if (jota==0) {
			printf("Login ou senha incorretos.\n");
			Digitar();
		}

	fclose(f);
}