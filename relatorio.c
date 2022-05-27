#include "plantas.h"

int main(){
	Relatorio();
}

int Relatorio () {
	int cont=0;
	z = fopen("relatorio.html", "w");
	
	if(z==NULL)		
		printf("Erro na abertura do arquivo!\n");
		
	fprintf(z,"<html>\n");
	fprintf(z,"<head>\n");
	fprintf(z,"\t<meta charset=\"UTF-8>\"\n");
	fprintf(z,"</head>\n");
	fprintf(z,"<body>\n");	
	fprintf(z,"\t<h1>Análise de Dados</h1>\n\n");
	fprintf(z,"\t<h2>F L O R I C U L T U R A</h2>\n\n");
	fprintf(z,"\t<table border=”1”>\n");
	fprintf(z,"\t\t<tr>\n");
	
	fprintf(z,"\t\t\t<td>Numero de identificacao</td>\n");
	fprintf(z,"\t\t\t<td>Nome cientifico</td>\n");
	fprintf(z,"\t\t\t<td>Ano do plantio</td>\n");
	fprintf(z,"\t\t\t<td>Frutifera</td>\n");
	fprintf(z,"\t\t\t<td>Preco de venda</td>\n");
	fprintf(z,"\t\t\t<td>Familia</td>\n");
	
	fprintf(z,"\t\t</tr>\n");
	
	x = fopen("plantas.txt","r");
	
	while(fscanf(x, "%d %s %d %c %f %[^\n]", &dados.identificacao, dados.nome_cientifico, &dados.ano, &dados.frutifera, &dados.preco, dados.familia) != EOF){
		fprintf(z,"\t\t<tr>\n");
		fprintf(z,"\t\t\t<td>%d</td>\n\t\t\t<td>%s</td>\n\t\t\t<td>%d</td>\n\t\t\t<td>%c</td>\n\t\t\t<td>%.2f</td>\n\t\t\t<td>%s</td>\n",
		         dados.identificacao, dados.nome_cientifico, dados.ano, dados.frutifera, dados.preco, dados.familia);
		fprintf(z,"\t\t</tr>\n");
		cont++;		 	
	}
	
	fprintf(z,"\t</table>\n");
	fprintf(z,"\t<p>Total de itens: %d</p>\n", cont);
	fprintf(z,"</body>\n");
	fprintf(z,"</html>\n");
	
	fclose(z);
	fclose(x);
}
