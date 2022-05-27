#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f;
FILE *p;
FILE *g;


typedef struct p{
	
	char login[50];
	char usuario[50];
	char senha[50];

} Estrutura;

char SENHA[50];
char LOGIN[50];
int jota;

Estrutura acesso;
Estrutura acesso2;
Estrutura LOGAR;

int IncluirUsuario();
int ExcluirUsuario();
int ListarUsuarios();
int AlterarSenha();
int Logar();
int Digitar();
int main();