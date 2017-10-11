#ifndef EDICAO_H
#define EDICAO_H

#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void editahospede(int tipo){
	struct hospede h;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
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
				printf("\nDigite o que será editado: \n");
				printf("1 - Nome\n2 - CPF\n3 - RG\n4 - Rua\n5 - Número6 - Bairro\n7 - CEP\n8 - Complemento\n9 - Cidade\n10 - Estado\n11 - Data de Nascimento\n12 - Telefone\n"
					"13 - Celular\n14 - Estado Cívil\n15 - E-mail\n16 - Status\n: ");
				scanf("%i",&op);
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
					else {
						switch(op){
							case 1:
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
							break;
							case 2:
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
							break;
							case 3:
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
							break;
							case 4:
								printf("Digite o nova Rua: ");
								scanf("%[^\n]s",h.rua);
							break;
							case 5:
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
							break;
							case 6:
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
							break;
							case 7:
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
							break;
							case 8:
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
							break;
							case 9:
								printf("Digite o nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
							break;
							case 10:
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
							break;
							case 11:
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
							break;
							case 12:
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
							break;
							case 13:
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
							break;
							case 14:
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
							break;
							case 15:
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
							break;
							case 16:
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
							break;
						}
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
						printf("\nDados alterados com sucesso!\n\n");
					}
				}
			remove("saves/hospedes.txt");
			rename("saves/temphospede.txt","saves/hospedes.txt");
			fclose(arquivo);
			fclose(arquivo2);
		break;
		case 2:
			arquivo = fopen("saves/hospedes.bin","ab+");
			arquivo2 = fopen("saves/temphospede.bin","ab+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			else{
				printf("Digite o código do hospede a ser editado: ");
				scanf("%i",&codigo);
				printf("\nDigite o que será editado: \n");
				printf("1 - Nome\n2 - CPF\n3 - RG\n4 - Rua\n5 - Número6 - Bairro\n7 - CEP\n8 - Complemento\n9 - Cidade\n10 - Estado\n11 - Data de Nascimento\n12 - Telefone\n"
					"13 - Celular\n14 - Estado Cívil\n15 - E-mail\n16 - Status\n: ");
				scanf("%i",&op); 	
				while(!feof(arquivo)){
					fread(&h,sizeof(struct hospede),1,arquivo);
					if(h.codigo != codigo){
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
					}
					else{
						switch(op){
							case 1:
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
							break;
							case 2:
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
							break;
							case 3:
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
							break;
							case 4:
								printf("Digite o nova Rua: ");
								scanf("%[^\n]s",h.rua);
							break;
							case 5:
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
							break;
							case 6:
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
							break;
							case 7:
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
							break;
							case 8:
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
							break;
							case 9:
								printf("Digite o nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
							break;
							case 10:
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
							break;
							case 11:
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
							break;
							case 12:
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
							break;
							case 13:
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
							break;
							case 14:
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
							break;
							case 15:
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
							break;
							case 16:
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
							break;
						}
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
						printf("\nDados alterados com sucesso!\n\n");
					}
				}
			}
			remove("saves/hospedes.bin");
			rename("saves/temphospede.bin","saves/hospedes.bin");
			fclose(arquivo);
			fclose(arquivo2);
		break;
	  }
	}
}
#endif