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
	setbuf(stdin,NULL);
	printf("Digite o código do hospede a ser editado: ");
	scanf("%i",&codigo);
	setbuf(stdin,NULL);
	printf("Digite o que será editado:\n1 - Nome\n2 - CPF\n3 - RG\n4 - Rua\n5 - Número\n6 - Bairro\n7 - CEP\n8 - Complemento\n9 - Cidade\n10 - Estado\n11 - Data de Nascimento\n12 - Telefone\n"
		"13 - Celular\n14 - Estado Cívil\n15 - E-mail\n16 - Status\n: ");
	scanf("%i",&op);
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
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
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
					else{
						switch(op){
							printf("\nEntrou no switch\n");
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
							break;
							case 16:
								setbuf(stdin,NULL);
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
				while(!feof(arquivo)){
					fread(&h,sizeof(struct hospede),1,arquivo);
					if(h.codigo != codigo){
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
							break;
						}
					}
				}
				fwrite(&h,sizeof(struct hospede),1,arquivo2);
				printf("\nDados alterados com sucesso!\n\n");
				remove("saves/hospedes.bin");
				rename("saves/temphospede.bin","saves/hospedes.bin");
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
	  }
	}
}


void editahotel(int tipo){
	struct hotel ht;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	printf("Digite o codigo a ser editado: ");
	scanf("%i",&codigo);
	printf("Digite o que será editado:\n1 - Nome Fantasia\n2 - Razão Social\n3 - CNPJ\n4 - Inscrição Estadual\n5 - Rua\n6 - Número\n7 - Bairro\n8 - CEP\n9 - Complemento\n10 - Cidade\n11 - Estado\n12 - Telefone\n13 - E-Mail\n"
		"14 - Nome do Responsável\n15 - Telefone do Responsável\n16 - Status\n: ");
	scanf("%i",&op);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hoteis.txt","a+");
			arquivo2 = fopen("saves/temphotel.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo de hotel!\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hotel\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
					if(ht.codigo != codigo){
						fprintf(arquivo2,"%u",ht.codigo);
						fprintf(arquivo2,"\n%s",ht.nomefantasia);
						fprintf(arquivo2,"\n%s",ht.razaosocial);
						fprintf(arquivo2,"\n%s",ht.cnpj);
						fprintf(arquivo2,"\n%s",ht.insc);
						fprintf(arquivo2,"\n%s",ht.rua);
						fprintf(arquivo2,"\n%s",ht.numero);
						fprintf(arquivo2,"\n%s",ht.bairro);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",ht.cep);
						fprintf(arquivo2,"\n%s",ht.complemento);
						fprintf(arquivo2,"\n%s",ht.telefone);
						fprintf(arquivo2,"\n%s",ht.email);
						fprintf(arquivo2,"\n%s",ht.nomeresponsavel);
						fprintf(arquivo2,"\n%s",ht.telefoneresponsavel);
						fprintf(arquivo2,"\n%s\n\n",ht.status);	
					}
					else{
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",ht.nomefantasia);
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
							break;
						}
						fprintf(arquivo2,"\n%s",ht.nomefantasia);
						fprintf(arquivo2,"\n%s",ht.razaosocial);
						fprintf(arquivo2,"\n%s",ht.cnpj);
						fprintf(arquivo2,"\n%s",ht.insc);
						fprintf(arquivo2,"\n%s",ht.rua);
						fprintf(arquivo2,"\n%s",ht.numero);
						fprintf(arquivo2,"\n%s",ht.bairro);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",ht.cep);
						fprintf(arquivo2,"\n%s",ht.complemento);
						fprintf(arquivo2,"\n%s",ht.telefone);
						fprintf(arquivo2,"\n%s",ht.email);
						fprintf(arquivo2,"\n%s",ht.nomeresponsavel);
						fprintf(arquivo2,"\n%s",ht.telefoneresponsavel);
						fprintf(arquivo2,"\n%s\n\n",ht.status);
						printf("\nDados alterados com sucesso!\n");
					}
				}
			}
			remove("saves/hoteis.txt");
			rename("saves/temphotel.txt","saves/hoteis.txt");
			fclose(arquivo);
			fclose(arquivo2);
		break;

		case 2:
			arquivo = fopen("saves/hoteis.bin","ab+");
			arquivo2 = fopen("saves/temphotel.bin","ab+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo de hotel!\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo de hotel!\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					if(ht.codigo != codigo){
						fwrite(&ht,sizeof(struct hotel),1,arquivo2);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",ht.nomefantasia);
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
							break;
						}
					}
				}
				fwrite(&ht,sizeof(struct hotel),1,arquivo2);
				printf("\nDados alterados com sucesso!\n\n");
				remove("saves/hoteis.bin");
				rename("saves/temphotel.bin","saves/hoteis.bin");
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
	}
}

void editaproduto(int tipo){

}

void editacategoria(int tipo){
	
}
#endif