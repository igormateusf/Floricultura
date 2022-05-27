#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *z;
FILE *x;

typedef struct L{
	
	int identificacao;
	char nome_cientifico[20];
	int ano;
	char frutifera;
	float preco;
	char familia[40];
	
} Dados;

Dados dados;
Dados dados2;

int IncluirPlanta();
int ConsultarPlanta();
int ListarPlantas();
int ExcluirPlanta();
int Relatorio();