#ifndef CHECKS_H
#define CHECKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "cores.h"

/*função de checkin do hospede*/
/*recebe por parametro, o tipo de salvamento, o url e o modo de abertura*/
void check(int tipo,char url[50],char urltemp[50],char modoabertura[5],struct checks ch){
	struct checks ch2;
	FILE *arquivo;
	FILE *arquivo2;
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	if(arquivo == NULL || arquivo2 == NULL){
		vermelho("\nErro na abertura do arquivo de checks!\n");
	}
	else{
		switch(tipo){
			case 1:
				/*verificar o tipo de check, se é check in, insere no arquivo de checks, essa checagem*/
				/*se for checkout, apaga o checkin, e o substitui pelo checkout*/
				if(ch.tipo == 0){
					/*salva os dados no arquivo*/
					fprintf(arquivo,"%u\n",ch.codigo);
					fprintf(arquivo,"%u\n",ch.codigo_hospede);
					fprintf(arquivo,"%u\n",ch.codigo_acomodacao);
					fprintf(arquivo,"%i\n",ch.tipo);
					fprintf(arquivo,"%i/%i/%i\n",ch.data_checkin.dia,ch.data_checkin.mes,ch.data_checkin.ano);
					fprintf(arquivo,"%i/%i/%i\n",ch.data_checkout.dia,ch.data_checkout.mes,ch.data_checkin.ano);
					fprintf(arquivo,"%f\n",ch.valor_total);
					fprintf(arquivo,"%i\n",ch.pago);
					fprintf(arquivo,"%s\n\n",ch.status);
					/*mostra mensagem de sucesso para o usuario*/
					printf("\nO número de check do hospede é: %i(Guarde-o Bem)\n",ch.codigo);
					verde("\nCheck in Realizado com Sucesso!\n");
				}
				/*nesse caso é necessário o hospede saber seu número de checkin, por isso vai ser informado a ele*/
				/*verifica o caso de checkout agora*/
				else if(ch.tipo == 1){
					/*ao inves de salvar simplesmente, agora vai buscar o checkin referente a esse codigo e substituir agora pelo checkout*/
					/*então primeiro vem a leitura*/
					while(!feof(arquivo)){
						/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						fscanf(arquivo,"%u\n %u\n %u\n %i\n %i/%i/%i\n %i/%i/%i\n %f\n %i\n %s\n\n",&ch2.codigo,&ch2.codigo_hospede,&ch.codigo_acomodacao,&ch.tipo,
						&ch2.data_checkin.dia,&ch2.data_checkin.mes,&ch2.data_checkin.ano,&ch2.data_checkout.dia,&ch2.data_checkout.mes,&ch2.data_checkin.ano,
						&ch2.valor_total,&ch2.pago,ch2.status);
						/*depois de lido,vai verificar o arquivo até encontrar o valor que corresponde ao código que foi passado no checkout*/
						if(ch2.codigo != ch.codigo){
							/*se o código for diferente, que dizer que são outros checks e devem ser preservados em um arquivo temporario*/
							fprintf(arquivo2,"%u\n",ch2.codigo);
							fprintf(arquivo2,"%u\n",ch2.codigo_hospede);
							fprintf(arquivo2,"%u\n",ch2.codigo_acomodacao);
							fprintf(arquivo2,"%i\n",ch2.tipo);
							fprintf(arquivo2,"%i/%i/%i\n",ch2.data_checkin.dia,ch2.data_checkin.mes,ch2.data_checkin.ano);
							fprintf(arquivo2,"%i/%i/%i\n",ch2.data_checkout.dia,ch2.data_checkout.mes,ch2.data_checkin.ano);
							fprintf(arquivo2,"%f\n",ch2.valor_total);
							fprintf(arquivo2,"%i\n",ch2.pago);
							fprintf(arquivo2,"%s\n\n",ch2.status);
						}
						/*se o código for igual, altera os valores e salva no arquivo temporario*/
						else{
							/*verifica se o hospede já pagou*/
							if(ch2.pago == 1){
								/*salva somente como dado novo a data de checkout e o tipo que agora é checkout*/
								fprintf(arquivo2,"%u\n",ch2.codigo);
								fprintf(arquivo2,"%u\n",ch2.codigo_hospede);
								fprintf(arquivo2,"%u\n",ch2.codigo_acomodacao);
								fprintf(arquivo2,"%i\n",ch.tipo);
								fprintf(arquivo2,"%i/%i/%i\n",ch2.data_checkin.dia,ch2.data_checkin.mes,ch2.data_checkin.ano);
								fprintf(arquivo2,"%i/%i/%i\n",ch.data_checkout.dia,ch.data_checkout.mes,ch.data_checkin.ano);
								fprintf(arquivo2,"%f\n",ch2.valor_total);
								fprintf(arquivo2,"%i\n",ch2.pago);
								fprintf(arquivo2,"%s\n\n",ch2.status);
							}
							/*se o hospede ainda não pagou*/
							else if(ch2.pago == 0){
								/*salva o tipo que é checkout, o valor, confirma o pagamento e o status informando a forma de pagamento*/
								/*o restante dos dados continua o mesmo*/
								fprintf(arquivo2,"%u\n",ch2.codigo);
								fprintf(arquivo2,"%u\n",ch2.codigo_hospede);
								fprintf(arquivo2,"%u\n",ch2.codigo_acomodacao);
								fprintf(arquivo2,"%i\n",ch.tipo);
								fprintf(arquivo2,"%i/%i/%i\n",ch2.data_checkin.dia,ch2.data_checkin.mes,ch2.data_checkin.ano);
								fprintf(arquivo2,"%i/%i/%i\n",ch.data_checkout.dia,ch.data_checkout.mes,ch.data_checkin.ano);
								fprintf(arquivo2,"%f\n",ch.valor_total);
								fprintf(arquivo2,"%i\n",ch.pago);
								fprintf(arquivo2,"%s\n\n",ch.status);
							}
							
						}
					}
					/*mostra o sucesso na tela*/
					verde("\nCheck Out Realizado com Sucesso!\n");	
				}
				remove(url);
				rename(urltemp,url);
				fclose(arquivo);
				fclose(arquivo2);
			break;
			/*caso 2, arquivo binário*/
			case 2:
				/*verificar o tipo de check, se é check in, insere no arquivo de checks, essa checagem*/
				/*se for checkout, apaga o checkin, e o substitui pelo checkout*/
				if(ch.tipo == 0){
					/*salva os dados no arquivo*/
					fwrite(&ch,sizeof(struct checks),1,arquivo);
					/*mostra mensagem de sucesso para o usuario*/
					printf("\nO número de check do hospede é: %i(Guarde-o Bem)\n",ch.codigo);
					verde("\nCheck in Realizado com Sucesso!\n");
				}
				/*nesse caso é necessário o hospede saber seu número de checkin, por isso vai ser informado a ele*/
				/*verifica o caso de checkout agora*/
				else if(ch.tipo == 1){
					/*ao inves de salvar simplesmente, agora vai buscar o checkin referente a esse codigo e substituir agora pelo checkout*/
					/*então primeiro vem a leitura*/
					while(!feof(arquivo)){
						/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						fread(&ch2,sizeof(struct checks),1,arquivo);
						/*depois de lido,vai verificar o arquivo até encontrar o valor que corresponde ao código que foi passado no checkout*/
						if(ch2.codigo != ch.codigo){
							/*se o código for diferente, que dizer que são outros checks e devem ser preservados em um arquivo temporario*/
							fwrite(&ch2,sizeof(struct checks),1,arquivo2);
						}
						/*se o código for igual, altera os valores e salva no arquivo temporario*/
						else{
							/*verifica se o hospede já pagou*/
							if(ch2.pago == 1){
								/*salva somente como dado novo a data de checkout e o tipo que agora é checkout*/
								/*coloca os valores em uma struct so para salvar no arquivo*/
								ch2.data_checkout.dia = ch.data_checkout.dia;
								ch2.data_checkout.mes = ch.data_checkout.mes;
								ch2.data_checkout.ano = ch.data_checkout.ano;
								ch2.tipo = ch.tipo;
								fwrite(&ch2,sizeof(struct checks),1,arquivo2);
							}
							/*se o hospede ainda não pagou*/
							else if(ch2.pago == 0){
								/*salva o tipo que é checkout, o valor, confirma o pagamento e o status informando a forma de pagamento*/
								/*o restante dos dados continua o mesmo*/
								ch2.data_checkout.dia = ch.data_checkout.dia;
								ch2.data_checkout.mes = ch.data_checkout.mes;
								ch2.data_checkout.ano = ch.data_checkout.ano;
								ch2.tipo = ch.tipo;
								ch2.valor_total = ch.valor_total;
								ch2.pago = ch.pago;
								strcpy(ch2.status,ch.status);

								fwrite(&ch2,sizeof(struct checks),1,arquivo2);
							}
							
						}
					}
					/*mostra o sucesso na tela*/
					verde("\nCheck Out Realizado com Sucesso!\n");	
				}
				remove(url);
				rename(urltemp,url);
				fclose(arquivo);
				fclose(arquivo2);
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
/*função para consultar e mostra na tela os checks até o momento*/
/*recebe por parametro o tipo de salvamento, o url e o modo de abertura*/
void consulta_checks(int tipo,char url[50],char modoabertura[5]){
	/*chama a struct para ter acesso a suas variaveis*/
	struct checks ck;
	ciano("\nConsulta de Checagens\n\n");
	/*cria um ponteiro de arquivo para acessar o arquivo de checks*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica erros na abertura do arquivo*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de checks!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			case 1:
				/*arquivo texto*/
				/*le o arquivo, com um while até seu final*/
				printf("\n-------------------------------------------------------------------------\n");
				while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}

					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i\n %i/%i/%i\n %i/%i/%i\n %f\n %i\n %s\n\n",&ck.codigo,&ck.codigo_hospede,&ck.codigo_acomodacao,&ck.tipo,
						&ck.data_checkin.dia,&ck.data_checkin.mes,&ck.data_checkin.ano,&ck.data_checkout.dia,&ck.data_checkout.mes,&ck.data_checkout.ano,
						&ck.valor_total,&ck.pago,ck.status);
					/*mostra na tela aquilo que foi lido*/
					printf("Código: %u\n",ck.codigo);
					printf("Código do Hospede: %u\n",ck.codigo_hospede);
					printf("Código da Acomodação: %u\n",ck.codigo_acomodacao);
					if(ck.tipo == 0){
						printf("Tipo de Checagem: Check In\n");
					}
					else if(ck.tipo == 1){
						printf("Tipo de Checagem: Check Out\n");
					}
					printf("Data de Check In: %i/%i/%i\n",ck.data_checkin.dia,ck.data_checkin.mes,ck.data_checkin.ano);
					if(ck.data_checkout.dia == 0 && ck.data_checkout.mes == 0 && ck.data_checkout.ano == 0){
						printf("Data de Check Out: Check Out ainda não realizado");
					}
					else{
						printf("Data de Check In: %i/%i/%i\n",ck.data_checkout.dia,ck.data_checkout.mes,ck.data_checkout.ano);
					}
					printf("Valor Total das Diárias: %f\n",ck.valor_total);
					if(ck.pago == 0){
						printf("Status da Fatura: ");
						amarelo("Ainda não Paga\n");
					}
					else{
						printf("Status da Fatura: ");
						verde("Paga\n");
					}
					printf("Status: %s\n",ck.status);
					printf("\n-------------------------------------------------------------------------\n");
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;

			case 2:
				/*arquivo binário*/
				/*le o arquivo, com um while até seu final*/
				printf("\n-------------------------------------------------------------------------\n");
				while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}

					/*comando de leitura*/
					fread(&ck,sizeof(struct checks),1,arquivo);
					/*mostra na tela aquilo que foi lido*/
					printf("Código: %u\n",ck.codigo);
					printf("Código do Hospede: %u\n",ck.codigo_hospede);
					printf("Código da Acomodação: %u\n",ck.codigo_acomodacao);
					if(ck.tipo == 0){
						printf("Tipo de Checagem: Check In\n");
					}
					else if(ck.tipo == 1){
						printf("Tipo de Checagem: Check Out\n");
					}
					printf("Data de Check In: %i/%i/%i\n",ck.data_checkin.dia,ck.data_checkin.mes,ck.data_checkin.ano);
					if(ck.data_checkout.dia == 0 && ck.data_checkout.mes == 0 && ck.data_checkout.ano == 0){
						printf("Data de Check Out: Check Out ainda não realizado");
					}
					else{
						printf("Data de Check In: %i/%i/%i\n",ck.data_checkout.dia,ck.data_checkout.mes,ck.data_checkout.ano);
					}
					printf("Valor Total das Diárias: %f\n",ck.valor_total);
					if(ck.pago == 0){
						printf("Status da Fatura: ");
						amarelo("Ainda não Paga\n");
					}
					else{
						printf("Status da Fatura: ");
						verde("Paga\n");
					}
					printf("Status: %s\n",ck.status);
					printf("\n-------------------------------------------------------------------------\n");
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}


void consulta_checks_codigo(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct para ter acesso a suas variaveis*/
	struct checks ck;
	ciano("\nConsulta de Checagens por código\n\n");
	/*cria um ponteiro de arquivo para acessar o arquivo de checks*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica erros na abertura do arquivo*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de checks!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			case 1:
				/*arquivo texto*/
				/*le o arquivo, com um while até seu final*/
				while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}

					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i\n %i/%i/%i\n %i/%i/%i\n %f\n %i\n %s\n\n",&ck.codigo,&ck.codigo_hospede,&ck.codigo_acomodacao,&ck.tipo,
						&ck.data_checkin.dia,&ck.data_checkin.mes,&ck.data_checkin.ano,&ck.data_checkout.dia,&ck.data_checkout.mes,&ck.data_checkout.ano,
						&ck.valor_total,&ck.pago,ck.status);
					/*mostra na tela aquilo que foi lido*/
					if(ck.codigo == codigo){
						printf("Código: %u\n",ck.codigo);
						printf("Código do Hospede: %u\n",ck.codigo_hospede);
						printf("Código da Acomodação: %u\n",ck.codigo_acomodacao);
						if(ck.tipo == 0){
							printf("Tipo de Checagem: Check In\n");
						}
						else if(ck.tipo == 1){
							printf("Tipo de Checagem: Check Out\n");
						}
						printf("Data de Check In: %i/%i/%i\n",ck.data_checkin.dia,ck.data_checkin.mes,ck.data_checkin.ano);
						if(ck.data_checkout.dia == 0 && ck.data_checkout.mes == 0 && ck.data_checkout.ano == 0){
							printf("Data de Check Out: Check Out ainda não realizado");
						}
						else{
							printf("Data de Check In: %i/%i/%i\n",ck.data_checkout.dia,ck.data_checkout.mes,ck.data_checkout.ano);
						}
						printf("Valor Total das Diárias: %f\n",ck.valor_total);
						if(ck.pago == 0){
							printf("Status da Fatura: ");
							amarelo("Ainda não Paga\n");
						}
						else{
							printf("Status da Fatura: ");
							verde("Paga\n");
						}
						printf("Status: %s\n",ck.status);
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;

			case 2:
				/*arquivo binário*/
				/*le o arquivo, com um while até seu final*/
				while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}

					/*comando de leitura*/
					fread(&ck,sizeof(struct checks),1,arquivo);
					/*mostra na tela aquilo que foi lido*/
					if(ck.codigo == codigo){
						printf("Código: %u\n",ck.codigo);
						printf("Código do Hospede: %u\n",ck.codigo_hospede);
						printf("Código da Acomodação: %u\n",ck.codigo_acomodacao);
						if(ck.tipo == 0){
							printf("Tipo de Checagem: Check In\n");
						}
						else if(ck.tipo == 1){
							printf("Tipo de Checagem: Check Out\n");
						}
						printf("Data de Check In: %i/%i/%i\n",ck.data_checkin.dia,ck.data_checkin.mes,ck.data_checkin.ano);
						if(ck.data_checkout.dia == 0 && ck.data_checkout.mes == 0 && ck.data_checkout.ano == 0){
							printf("Data de Check Out: Check Out ainda não realizado");
						}
						else{
							printf("Data de Check In: %i/%i/%i\n",ck.data_checkout.dia,ck.data_checkout.mes,ck.data_checkout.ano);
						}
						printf("Valor Total das Diárias: %f\n",ck.valor_total);
						if(ck.pago == 0){
							printf("Status da Fatura: ");
							amarelo("Ainda não Paga\n");
						}
						else{
							printf("Status da Fatura: ");
							verde("Paga\n");
						}
						printf("Status: %s\n",ck.status);
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}


#endif