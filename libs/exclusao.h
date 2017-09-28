#ifndef EXCLUSAO_H
#define EXCLUSAO_H

#include <stdio.h>
#include <string.h>
#include "structs.h"

void excluihospede(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct hospede h;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hospedes.txt","a+");
			arquivo2 = fopen("saves/temphospede.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			else{
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
					else{
						printf("\nHospede selecionado: \n\n");
						printf("Código: %u",h.codigo);
						printf("\nNome: %s",h.nome);
						printf("\nCPF: %s",h.cpf);
						printf("\nRG: %s",h.rg);
						printf("\nRua: %s",h.rua);
						printf("\nNumero: %s",h.numero);
						printf("\nBairro: %s",h.bairro);
						printf("\nCidade: %s",h.cidadeestado.cidade);
						printf("\nEstado: %s",h.cidadeestado.estado);
						printf("\nCEP: %s",h.cep);
						printf("\nComplemento: %s",h.complemento);
						printf("\nData de Nascimento: %s",h.datanascimento);
						printf("\nTelefone: %s",h.telefone);
						printf("\nCelular: %s",h.celular);
						printf("\nEstado Cívil: %s",h.estadocivil);
						printf("\nE-Mail: %s",h.email);
						printf("\nStatus: %s\n",h.status);
					}
					
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/hospedes.txt");
					rename("saves/temphospede.txt","saves/hospedes.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
		}
		break;
		case 2:
			arquivo = fopen("saves/hospedes.bin","ab");
			arquivo2 = fopen("saves/temphospede.bin","ab");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&h,sizeof(struct hospede),1,arquivo);
					if(h.codigo != codigo){
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
					}
					else{
						printf("\nHospede selecionado: \n\n");
						printf("Código: %u",h.codigo);
						printf("\nNome: %s",h.nome);
						printf("\nCPF: %s",h.cpf);
						printf("\nRG: %s",h.rg);
						printf("\nRua: %s",h.rua);
						printf("\nNumero: %s",h.numero);
						printf("\nBairro: %s",h.bairro);
						printf("\nCidade: %s",h.cidadeestado.cidade);
						printf("\nEstado: %s",h.cidadeestado.estado);
						printf("\nCEP: %s",h.cep);
						printf("\nComplemento: %s",h.complemento);
						printf("\nData de Nascimento: %s",h.datanascimento);
						printf("\nTelefone: %s",h.telefone);
						printf("\nCelular: %s",h.celular);
						printf("\nEstado Cívil: %s",h.estadocivil);
						printf("\nE-Mail: %s",h.email);
						printf("\nStatus: %s\n",h.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/hospedes.bin");
					rename("saves/temphospede.bin","saves/hospedes.bin");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);		
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluihotel(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct hotel ht;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hoteis.txt","a+");
			arquivo2 = fopen("saves/temphotel.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do hotel!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hotel!!\n\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,
					ht.insc,ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,
					ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
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
						printf("\nHotel selecionado:\n\n");
						printf("Código: %u",ht.codigo);
						printf("\nRazão Social: %s",ht.razaosocial);
						printf("\nNome Fantasia: %s",ht.nomefantasia);
						printf("\nCNPJ: %s",ht.cnpj);
						printf("\nInscrição Estadual: %s",ht.insc);
						printf("\nRua: %s",ht.rua);
						printf("\nNumero: %s",ht.numero);
						printf("\nBairro: %s",ht.bairro);
						printf("\nCidade: %s",ht.cidadeestado.cidade);
						printf("\nEstado: %s",ht.cidadeestado.estado);
						printf("\nCEP: %s",ht.cep);
						printf("\nComplemento: %s",ht.complemento);
						printf("\nTelefone: %s",ht.telefone);
						printf("\nE-Mail: %s",ht.email);
						printf("\nNome do Responsável: %s",ht.nomeresponsavel);
						printf("\nTelefone do Responsável: %s",ht.telefoneresponsavel);
						printf("\nStatus: %s\n\n",ht.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/hoteis.txt");
					rename("saves/temphotel.txt","saves/hoteis.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/hoteis.bin","ab");
			arquivo2 = fopen("saves/temphotel.bin","ab");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					if(ht.codigo != codigo){
						fwrite(&ht,sizeof(struct hotel),1,arquivo2);
					}
					else{
						printf("\nHotel selecionado:\n\n");
						printf("Código: %u",ht.codigo);
						printf("\nRazão Social: %s",ht.razaosocial);
						printf("\nNome Fantasia: %s",ht.nomefantasia);
						printf("\nCNPJ: %s",ht.cnpj);
						printf("\nInscrição Estadual: %s",ht.insc);
						printf("\nRua: %s",ht.rua);
						printf("\nNumero: %s",ht.numero);
						printf("\nBairro: %s",ht.bairro);
						printf("\nCidade: %s",ht.cidadeestado.cidade);
						printf("\nEstado: %s",ht.cidadeestado.estado);
						printf("\nCEP: %s",ht.cep);
						printf("\nComplemento: %s",ht.complemento);
						printf("\nTelefone: %s",ht.telefone);
						printf("\nE-Mail: %s",ht.email);
						printf("\nNome do Responsável: %s",ht.nomeresponsavel);
						printf("\nTelefone do Responsável: %s",ht.telefoneresponsavel);
						printf("\nStatus: %s\n\n",ht.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/hoteis.bin");
					rename("saves/temphotel.bin","saves/hoteis.bin");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluicategoria(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct categorias c;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/categorias.txt","a+");
			arquivo2 = fopen("saves/tempcategoria.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			else{
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
						printf("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n",c.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/categorias.txt");
					rename("saves/tempcategoria.txt","saves/categorias.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/categorias.bin","ab");
			arquivo2 = fopen("saves/tempcategoria.bin","ab");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&c,sizeof(struct categorias),1,arquivo);
					if(c.codigo != codigo){
						fwrite(&c,sizeof(struct categorias),1,arquivo2);
					}
					else{
						printf("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n",c.status);	
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/categorias.txt");
					rename("saves/tempcategoria.txt","saves/categorias.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluiacomodacao(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct acomodacoes ac;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/acomodacoes.txt","a+");
			arquivo2 = fopen("saves/tempacomodacao.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da acomodação!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,
					&ac.categoriaselecionada,ac.status) != EOF){
					if(ac.codigo != codigo){
						fprintf(arquivo,"%u",ac.codigo);
						fprintf(arquivo,"\n%s",ac.descricao);
						fprintf(arquivo,"\n%i",ac.extra.tv);
						fprintf(arquivo,"\n%i",ac.extra.tvcabo);
						fprintf(arquivo,"\n%i",ac.extra.arcondicionado);
						fprintf(arquivo,"\n%i",ac.extra.frigobar);
						fprintf(arquivo,"\n%i",ac.extra.banheiro);
						fprintf(arquivo,"\n%i",ac.extra.camacasal);
						fprintf(arquivo,"\n%i",ac.extra.camasolteiro);
						fprintf(arquivo,"\n%i",ac.extra.hidromassagem);
						fprintf(arquivo,"\n%i",ac.extra.banheira);
						fprintf(arquivo,"\n%i",ac.categoriaselecionada);
						fprintf(arquivo,"\n%s\n\n",ac.status);	
					}
					else{
						printf("Código: %i",ac.codigo);
						printf("\nDescrição: %s",ac.descricao);
						printf("\nCom TV comum: %i",ac.extra.tv);
						printf("\nCom TV a Cabo: %i",ac.extra.tvcabo);
						printf("\nCom Ar condicionado: %i",ac.extra.arcondicionado);
						printf("\nCom Frigobar: %i",ac.extra.frigobar);
						printf("\nCom Banheiro Próprio: %i",ac.extra.banheiro);
						printf("\nCom Cama de Casal: %i",ac.extra.camacasal);
						printf("\nCom Cama de Solteiro: %i",ac.extra.camasolteiro);
						printf("\nCom Hidromassagem: %i",ac.extra.hidromassagem);
						printf("\nCom Banheira: %i",ac.extra.banheira);
						printf("\nCategoria da Acomodação: %i",ac.categoriaselecionada);
					}
					
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/acomodacoes.txt");
					rename("saves/tempacomodacao.txt","saves/acomodacoes.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:

		break;
	}
} 
#endif