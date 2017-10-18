#ifndef EDICAO_H
#define EDICAO_H

#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cores.h"


void editahospede(int tipo){
	struct hospede h;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	int verifica;
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
				vermelho("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			else{
				verifica = 0;
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
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
								verifica = 1;
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
								verifica = 1;
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
								verifica = 1;
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
								verifica = 1;
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
						
					}
				}
			if(verifica == 1){
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
				verde("\nDados alterados com sucesso!\n\n");
				remove("saves/hospedes.txt");
				rename("saves/temphospede.txt","saves/hospedes.txt");
				fclose(arquivo);
				fclose(arquivo2);
			}
			
		break;
		case 2:
			arquivo = fopen("saves/hospedes.bin","ab+");
			arquivo2 = fopen("saves/temphospede.bin","ab+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo de hospedes!!\n\n");
			}
			else{
				verifica = 0;
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
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
								verifica = 1;
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
								verifica = 1;
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
								verifica = 1;
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
								verifica = 1;
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
				}
				if(verifica == 1){
					fwrite(&h,sizeof(struct hospede),1,arquivo2);
					verde("\nDados alterados com sucesso!\n\n");
					remove("saves/hospedes.bin");
					rename("saves/temphospede.bin","saves/hospedes.bin");
					fclose(arquivo);
					fclose(arquivo2);
				}
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
	int verifica;
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
				vermelho("\nErro em localizar o arquivo de hotel!\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo do hotel\n");
			}
			else{
				verifica = 0;
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
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
								verifica = 1;
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
								verifica = 1;
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
								verifica = 1;
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
								verifica = 1;
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
						
					}
				}
			}
			if(verifica == 1){
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
				verde("\nDados alterados com sucesso!\n");
				remove("saves/hoteis.txt");
				rename("saves/temphotel.txt","saves/hoteis.txt");
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;

		case 2:
			arquivo = fopen("saves/hoteis.bin","ab+");
			arquivo2 = fopen("saves/temphotel.bin","ab+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de hotel!\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo de hotel!\n");
			}
			else{
				verifica = 0;
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
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
								verifica = 1;
							break;
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
								verifica = 1;
							break;
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
								verifica = 1;
							break;
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
								verifica = 1;
							break;
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
				}
				if(verifica == 1){
					fwrite(&ht,sizeof(struct hotel),1,arquivo2);
					verde("\nDados alterados com sucesso!\n\n");
					remove("saves/hoteis.bin");
					rename("saves/temphotel.bin","saves/hoteis.bin");
					fclose(arquivo);
					fclose(arquivo2);
				}
			}
		break;
	}
}

void editaproduto(int tipo){

}

void editacategoria(int tipo){
	struct categorias c;
	FILE *arquivo;
	FILE *arquivo2;
	int verifica;
	int codigo;
	int op;
	printf("Digite o código da categoria que será editada: ");
	scanf("%i",&codigo);
	printf("Digite o que será editado: \n1 - Descrição\n2 - Valor\n3 - Quantidade de Adultos\n4 - Quantidade de Crianças\n5 - Status\n: ");
	scanf("%i",&op);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/categorias.txt","a+");
			arquivo2 = fopen("saves/tempcategoria.txt","a+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de categorias!\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo de categorias!\n");
			}
			else{
				verifica = 0;
				while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status) != EOF){
					if(c.codigo != codigo){
						fprintf(arquivo2,"%u",c.codigo);
						fprintf(arquivo2,"\n%s",c.descricao);
						fprintf(arquivo2,"\n%.2f",c.valor);
						fprintf(arquivo2,"\n%i",c.quantidadeadultos);
						fprintf(arquivo2,"\n%i",c.quantidadecriancas);
						fprintf(arquivo2,"\n%s\n\n",c.status);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",c.descricao);
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Valor: ");
								scanf("%f",&c.valor);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Adultos: ");
								scanf("%i",&c.quantidadeadultos);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Crianças: ");
								scanf("%i",&c.quantidadecriancas);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",c.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
				}
			}
			if(verifica == 1){
				fprintf(arquivo2,"%u",c.codigo);
				fprintf(arquivo2,"\n%s",c.descricao);
				fprintf(arquivo2,"\n%.2f",c.valor);
				fprintf(arquivo2,"\n%i",c.quantidadeadultos);
				fprintf(arquivo2,"\n%i",c.quantidadecriancas);
				fprintf(arquivo2,"\n%s\n\n",c.status);
				verde("\nDados alterados com sucesso!\n");
				remove("saves/categorias.txt");
				rename("saves/tempcategoria.txt","saves/categorias.txt");
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/categorias.bin","ab+");
			arquivo2 = fopen("saves/tempcategoria.bin","ab+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de categorias!\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo de categorias!\n");
			}
			else{
				verifica = 0;
				while(!feof(arquivo)){
					fread(&c,sizeof(struct categorias),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					if(c.codigo != codigo){
						fwrite(&c,sizeof(struct categorias),1,arquivo2);
					}
					else{
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",c.descricao);
								verifica = 1;
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Valor: ");
								scanf("%f",&c.valor);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Adultos: ");
								scanf("%i",&c.quantidadeadultos);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Crianças: ");
								scanf("%i",&c.quantidadecriancas);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",c.status);
								verifica = 1;
							break;
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}
					}
				}
				if(verifica == 1){
					fwrite(&c,sizeof(struct categorias),1,arquivo2);
					verde("\nDados alterados com sucesso!\n\n");
					remove("saves/categorias.bin");
					rename("saves/tempcategoria.bin","saves/categorias.bin");
					fclose(arquivo);				fwrite(&c,sizeof(struct categorias),1,arquivo2);
					verde("\nDados alterados com sucesso!\n\n");
					remove("saves/categorias.bin");
					rename("saves/tempcategoria.bin","saves/categorias.bin");
					fclose(arquivo);
					fclose(arquivo2);
					fclose(arquivo2);
				}	
			}
		break;
	}
}


void editaacomodacao(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int op,codigo,verifica;
	struct acomodacoes ac;
	ciano("\nEdição de Acomodações!\n");
	printf("Digite o código da Acomodação que será editada: ");
	scanf("%i",&codigo);
	printf("Digite o que será editado: \n1 - Descrição\n2 - Categoria Selecionada\n3 - TV\n4 - TV a Cabo\n5 - Ar Condicionado\n6 - Frigobar\n7 - Banheiro\n8 - Cama de Casal"
		"\n9 - Cama de Solteiro\n10 - Hidromassagem\n11 - Banheira\n12 - Status\n: ");
	scanf("%i",&op);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/acomodacoes.txt","a+");
			arquivo2 = fopen("saves/tempacomodacao.txt","a+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de acomodações\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo de acomodações\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,
				&ac.extra.banheira,&ac.categoriaselecionada,ac.status) != EOF){
					if(ac.codigo != codigo){
						fprintf(arquivo2,"%u",ac.codigo);
						fprintf(arquivo2,"\n%s",ac.descricao);
						fprintf(arquivo2,"\n%i",ac.extra.tv);
						fprintf(arquivo2,"\n%i",ac.extra.tvcabo);
						fprintf(arquivo2,"\n%i",ac.extra.arcondicionado);
						fprintf(arquivo2,"\n%i",ac.extra.frigobar);
						fprintf(arquivo2,"\n%i",ac.extra.banheiro);
						fprintf(arquivo2,"\n%i",ac.extra.camacasal);
						fprintf(arquivo2,"\n%i",ac.extra.camasolteiro);
						fprintf(arquivo2,"\n%i",ac.extra.hidromassagem);
						fprintf(arquivo2,"\n%i",ac.extra.banheira);
						fprintf(arquivo2,"\n%i",ac.categoriaselecionada);
						fprintf(arquivo2,"\n%s\n\n",ac.status);
					}
					else{
						verifica = 0;
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",ac.descricao);
								verifica = 1;	
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite a nova Categoria Selecionada: ");
								scanf("%i",&ac.categoriaselecionada);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's: ");
								scanf("%i",&ac.extra.tv);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's a Cabo: ");
								scanf("%i",&ac.extra.tvcabo);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Ares Condicionados: ");
								scanf("%i",&ac.extra.arcondicionado);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Frigobares: ");
								scanf("%i",&ac.extra.frigobar);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiros: ");
								scanf("%i",&ac.extra.banheiro);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Casal: ");
								scanf("%i",&ac.extra.camacasal);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Solteiro: ");
								scanf("%i",&ac.extra.camasolteiro);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Hidromassagens: ");
								scanf("%i",&ac.extra.hidromassagem);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiras: ");
								scanf("%i",&ac.extra.banheira);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ac.status);
								verifica = 1;	
							break;
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}
					}
				}
			}
			if(verifica == 1){
				fprintf(arquivo2,"%u",ac.codigo);
				fprintf(arquivo2,"\n%s",ac.descricao);
				fprintf(arquivo2,"\n%i",ac.extra.tv);
				fprintf(arquivo2,"\n%i",ac.extra.tvcabo);
				fprintf(arquivo2,"\n%i",ac.extra.arcondicionado);
				fprintf(arquivo2,"\n%i",ac.extra.frigobar);
				fprintf(arquivo2,"\n%i",ac.extra.banheiro);
				fprintf(arquivo2,"\n%i",ac.extra.camacasal);
				fprintf(arquivo2,"\n%i",ac.extra.camasolteiro);
				fprintf(arquivo2,"\n%i",ac.extra.hidromassagem);
				fprintf(arquivo2,"\n%i",ac.extra.banheira);
				fprintf(arquivo2,"\n%i",ac.categoriaselecionada);
				fprintf(arquivo2,"\n%s\n\n",ac.status);
				verde("\nDados alterados com sucesso!\n");
				remove("saves/acomodacoes.txt");
				rename("saves/tempacomodacao.txt","saves/acomodacoes.txt");
			}
		break;
		case 2:
			arquivo = fopen("saves/acomodacoes.bin","ab+");
			arquivo2 = fopen("saves/tempacomodacao.bin","ab+");
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo de acomodações\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo de acomodações\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					if(ac.codigo != codigo){
						fwrite(&ac,sizeof(struct acomodacoes),1,arquivo2);
					}
					else{
						verifica = 0;
						switch(op){
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",ac.descricao);
								verifica = 1;	
							break;
							case 2:
								setbuf(stdin,NULL);
								printf("Digite a nova Categoria Selecionada: ");
								scanf("%i",&ac.categoriaselecionada);
								verifica = 1;
							break;
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's: ");
								scanf("%i",&ac.extra.tv);
								verifica = 1;
							break;
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's a Cabo: ");
								scanf("%i",&ac.extra.tvcabo);
								verifica = 1;
							break;
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Ares Condicionados: ");
								scanf("%i",&ac.extra.arcondicionado);
								verifica = 1;
							break;
							case 6:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Frigobares: ");
								scanf("%i",&ac.extra.frigobar);
								verifica = 1;
							break;
							case 7:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiros: ");
								scanf("%i",&ac.extra.banheiro);
								verifica = 1;
							break;
							case 8:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Casal: ");
								scanf("%i",&ac.extra.camacasal);
								verifica = 1;
							break;
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Solteiro: ");
								scanf("%i",&ac.extra.camasolteiro);
								verifica = 1;
							break;
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Hidromassagens: ");
								scanf("%i",&ac.extra.hidromassagem);
								verifica = 1;
							break;
							case 11:
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiras: ");
								scanf("%i",&ac.extra.banheira);
								verifica = 1;
							break;
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ac.status);
								verifica = 1;	
							break;
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}	
					}
				}
			}
			if(verifica == 1){
				fwrite(&ac,sizeof(struct categorias),1,arquivo2);
				verde("\nDados alterados com sucesso!\n\n");
				remove("saves/acomodacoes.bin");
				rename("saves/tempacomodacao.bin","saves/acomodacoes.bin");
				fclose(arquivo);
				fclose(arquivo2);				
			}
		break;
	}
}
#endif