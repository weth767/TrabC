#ifndef EDICAO_H
#define EDICAO_H

#include "structs.h"
#include <string.h>
#include <stdio.h>
#include "listavariaveis.h"

void editahospede(int tipo,char filtro[50]){
	struct hospede h;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	char edicao[25];
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hospedes.txt","a+");
			arquivo2 = fopen("saves/temphospede.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			else{
				printf("Digite o código do hospede a ser editado: ");
				scanf("%i",&codigo);
				printf("Digite o que será editado: ");
				scanf("%[^\n]s",edicao);
				while( fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
					h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
					if(h.codigo != codigo){
						fprintf(arquivo2,"%u",h.codigo);
						fprintf(arquivo2,"\n%s",h.nome);
						fprintf(arquivo2,"\n%s",h.cpf);
						fprintf(arquivo2,"\n%s",h.rg);
						fprintf(arquivo2,"\n%s",h.rua);
						fprintf(arquivo2,"\n%s",h.numero);
						fprintf(arquivo2,"\n%s",h.bairro);
						fprintf(arquivo2,"\n%s",h.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",h.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",h.cep);
						fprintf(arquivo2,"\n%s",h.complemento);
						fprintf(arquivo2,"\n%s",h.datanascimento);
						fprintf(arquivo2,"\n%s",h.telefone);
						fprintf(arquivo2,"\n%s",h.celular);
						fprintf(arquivo2,"\n%s",h.estadocivil);
						fprintf(arquivo2,"\n%s",h.email);
						fprintf(arquivo2,"\n%s\n\n",h.status);
					}
					else if(){
						
					}
				}
			}
		break;

		case 2:

		break;
	}
}



#endif EDICAO_H