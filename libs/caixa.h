#ifndef CAIXA_H
#define CAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"


/*função para salvar o caixa,*/
/*recebe o url do caixa*/
void salva_caixa(int tipo, char url[50], char modoabertura[5], struct caixa cx){
	/*ponteiro, para acessar o arquivo de caixa, cada hotel terá o seu separadamente, isso porque
	o caixa sempre guardará seu ultimo estado de abertura ou fechamento, servindo como relatório*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		/*mostra mensagem*/
		vermelho("\nERRO GRAVE, NÃO FOI POSSÍVEL ABRIR O ARQUIVO DE CAIXA!!!\n");
	}
	/*se estiver tudo ok*/
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				/*salva os dados*/
				fprintf(arquivo,"%u\n",cx.codigo);
				fprintf(arquivo,"%u\n",cx.codigo_hotel);
				fprintf(arquivo,"%i:%i\n",cx.t_ab.hora,cx.t_ab.minuto);
				fprintf(arquivo,"%i:%i\n",cx.t_fc.hora,cx.t_fc.minuto);
				fprintf(arquivo,"%.2f\n",cx.valor);
				fprintf(arquivo,"%s\n\n",cx.status);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados de caixa atualizados com sucesso!\n");
			break;
			case 2:/*arquivo binario*/
				/*salva os dados*/
				fwrite(&cx,sizeof(struct caixa),1,arquivo);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados de caixa atualizados com sucesso!\n");
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

void consulta_caixa(int tipo, char url[50], char modoabertura[5]){
	/*ponteiro, para acessar o arquivo de caixa, cada hotel terá o seu separadamente, isso porque
	o caixa sempre guardará seu ultimo estado de abertura ou fechamento, servindo como relatório*/
	FILE *arquivo;
	struct caixa cx;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		/*mostra mensagem*/
		vermelho("\nERRO GRAVE, NÃO FOI POSSÍVEL ABRIR O ARQUIVO DE CAIXA!!!\n");
	}
	/*se estiver tudo ok*/
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				printf("\n-------------------------------------------------------------------------------------\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %i:%i\n %i:%i\n %f\n %s\n\n",&cx.codigo,&cx.codigo_hotel,&cx.t_ab.hora,&cx.t_ab.minuto,
						&cx.t_fc.hora,&cx.t_fc.minuto,&cx.valor,cx.status);
					if(feof(arquivo)){
						break;
					}
					printf("Código do Caixa: %u\n",cx.codigo);
					printf("Código do Hotel: %u\n",cx.codigo_hotel);
					printf("Hora de Abertura: %i:%i\n",cx.t_ab.hora,cx.t_ab.minuto);
					printf("Hora de Fechamento: %i:%i\n",cx.t_fc.hora,cx.t_fc.minuto);
					printf("Valor: R$%.2f\n",cx.valor);
					printf("Status: %s\n",cx.status);
					printf("\n-------------------------------------------------------------------------------------\n");
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			case 2:/*arquivo binario*/
				printf("\n-------------------------------------------------------------------------------------\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&cx,sizeof(struct caixa),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					printf("Código do Caixa: %u\n",cx.codigo);
					printf("Código do Hotel: %u\n",cx.codigo_hotel);
					printf("Hora de Abertura: %i:%i\n",cx.t_ab.hora,cx.t_ab.minuto);
					printf("Hora de Fechamento: %i:%i\n",cx.t_fc.hora,cx.t_fc.minuto);
					printf("Valor: R$%.2f\n",cx.valor);
					printf("Status: %s\n",cx.status);
					printf("\n-------------------------------------------------------------------------------------\n");
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

/*função de salvar contas a pagar*/
/*recebe por parametro o tipo de salvamento, o url de contas a pagar e o modo de abertura*/
void salva_contas_pagar(int tipo, char url[50], char modoabertura[5],float valor){
	/*ponteiro do arquivo*/
	FILE *arquivo;
	int codigo;
	struct contaspagar cp;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de contas a pagar!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				/*ajeita os dados*/
				cp.codigo = codigo_contapagar(tipo);
				cp.valor = valor;
				strcpy(cp.status,"EM_DÉBITO");
				/*salva os dados no arquivo*/
				fprintf(arquivo,"%u\n",cp.codigo);
				fprintf(arquivo,"%.2f\n",cp.valor);
				fprintf(arquivo,"%s\n\n",cp.status);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nConta a pagar salva com sucesso!\n");
			break;
			case 2:/*arquivo binario*/
				/*ajeita os dados*/
				cp.codigo = codigo_contapagar(tipo);
				cp.valor = valor;
				strcpy(cp.status,"EM_DÉBITO");
				/*salva os dados no arquivo*/
				fwrite(&cp,sizeof(struct contaspagar),1,arquivo);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nConta a pagar salva com sucesso!\n");
			break;
			/*erro em opções de salvamento nao validas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}


/*função para atualizar o valor do caixa*/
/*recebe por parametro o tipo de salvamento, o url, o urltemporario, o modo de abertura o valor e a opção*/
void atualiza_valor_caixa(int tipo,char url[50],char urltemp[50],char urlctp[50],char modoabertura[5],float valor,int opcao){
	/*struct de caixa, para armazena os dados*/
	struct caixa cx;
	struct contaspagar cpp;
	/*cria o ponteiro de arquivo para acessar o arquivo de caixa*/
	FILE *arquivo;
	FILE *arquivo2;
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		/*mensagem de erro*/
		vermelho("\nERRO GRAVE, NÃO FOI POSSÍVEL ABRIR O ARQUIVO DE CAIXA!!!\n");
	}
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				/*le o arquivo até seu fim*/
				while(!feof(arquivo)){
					fscanf(arquivo,"%u\n %u\n %i:%i\n %i:%i\n %f\n %s\n\n",&cx.codigo,&cx.codigo_hotel,&cx.t_ab.hora,&cx.t_ab.minuto,
						&cx.t_fc.hora,&cx.t_fc.minuto,&cx.valor,cx.status);
					/*verifica se não está no final do arquivo*/
					if(!feof(arquivo)){
						/*salva os dados no arquivo temporario*/
						fprintf(arquivo2,"%u\n",cx.codigo);
						fprintf(arquivo2,"%u\n",cx.codigo_hotel);
						fprintf(arquivo2,"%i:%i\n",cx.t_ab.hora,cx.t_ab.minuto);
						fprintf(arquivo2,"%i:%i\n",cx.t_fc.hora,cx.t_fc.minuto);
						fprintf(arquivo2,"%.2f\n",cx.valor);
						fprintf(arquivo2,"%s\n\n",cx.status);
					}
					/*se estiver, verifica a opção*/
					else{
						/*se for 0, entrada, então soma valor*/
						if(opcao == 0){
							cx.valor = cx.valor + valor;
						}
						/*se for 1, saida, ai verifica denovo*/
						else if(opcao == 1){
							/*se o valor for maior do que ha em caixa*/
							if(valor > cx.valor){
								salva_contas_pagar(tipo, urlctp, modoabertura , valor);
							}/*senão, diminui o valor do caixa*/
							else{
								cx.valor = cx.valor - valor;
							}
						}
						/*depois salva no arquivo temporario denovo*/
						fprintf(arquivo2,"%u\n",cx.codigo);
						fprintf(arquivo2,"%u\n",cx.codigo_hotel);
						fprintf(arquivo2,"%i:%i\n",cx.t_ab.hora,cx.t_ab.minuto);
						fprintf(arquivo2,"%i:%i\n",cx.t_fc.hora,cx.t_fc.minuto);
						fprintf(arquivo2,"%.2f\n",cx.valor);
						fprintf(arquivo2,"%s\n\n",cx.status);
					}
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
				/*remove o original e renomeia o temporario*/
				remove(url);
				rename(urltemp,url);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados de caixa atualizados com sucesso!\n");
			break;
			case 2:/*arquivo binario*/
				/*le o arquivo até seu fim*/
				while(!feof(arquivo)){
					fread(&cx,sizeof(struct caixa),1,arquivo);
					/*verifica se não está no final do arquivo*/
					if(!feof(arquivo)){
						/*salva os dados no arquivo temporario*/
						fwrite(&cx,sizeof(struct caixa),1,arquivo2);
					}
					/*se estiver, verifica a opção*/
					else{
						/*se for 0, entrada, então soma valor*/
						if(opcao == 0){
							cx.valor = cx.valor + valor;
						}
						/*se for 1, saida, ai verifica denovo*/
						else if(opcao == 1){
							/*se o valor for maior do que ha em caixa*/
							if(valor > cx.valor){
								salva_contas_pagar(tipo, urlctp, modoabertura , valor);
							}/*senão, diminui o valor do caixa*/
							else{
								cx.valor = cx.valor - valor;
							}
						}
						/*depois salva no arquivo temporario denovo*/
						fwrite(&cx,sizeof(struct caixa),1,arquivo2);
					}
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
				/*remove o original e renomeia o temporario*/
				remove(url);
				rename(urltemp,url);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados de caixa atualizados com sucesso!\n");
			break;
			/*erro em opções de salvamento nao validas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}


/*função para realizar o pagamento da conta a pagar*/
/*recebe por parametro o tipo de salvamento, o url, e o modo de abertura*/
void paga_contaspagar(int tipo, char url[50], char urltemp[50], char urlcaixa[50], char urltempcaixa[50], char modoabertura[5]){
	/*ponteiros do arquivo*/
	FILE *arquivo;
	FILE *arquivo2;
	/*struct de contaspagar*/
	struct contaspagar cp;
	int codigo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica se houve erros na abertura*/
	if(arquivo == NULL || arquivo2 == NULL){
		vermelho("\nErro na abertura do arquivo de contas a pagar!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			/*arquivo texto*/
			case 1:
				/*le o arquivo para verifica as contas que ainda não foram pagar*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %f\n %s\n\n",&cp.codigo,&cp.valor,cp.status);
					/*verifica quais ainda não foram pagas*/
					if(strcmp(cp.status,"EM_DÉBITO")){
						printf("Código: %u\n",cp.codigo);
						printf("Valor: %.2f\n",cp.valor);
						printf("Status: %s\n\n",cp.status);
					}
				}
				printf("Digite o código da conta a ser paga: ");
				scanf("%i",&codigo);
				/*le o arquivo para verifica pelo codigo digitado*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %f\n %s\n\n",&cp.codigo,&cp.valor,cp.status);
					if(cp.codigo != codigo){
						/*se o codigo for diferente*/
						fprintf(arquivo2,"%u\n",cp.codigo);
						fprintf(arquivo2,"%.2f\n",cp.valor);
						fprintf(arquivo2,"%s\n\n",cp.status);
					}
					/*se o codigo for igual*/
					else{
						/*muda o status para paga*/
						strcpy(cp.status,"PAGA");
						/*salva no arquivo temporario*/
						fprintf(arquivo2,"%u\n",cp.codigo);
						fprintf(arquivo2,"%.2f\n",cp.valor);
						fprintf(arquivo2,"%s\n\n",cp.status);
						/*atualiza o caixa*/
						atualiza_valor_caixa(tipo,urlcaixa,urltempcaixa,url,modoabertura,cp.valor,1);
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				fclose(arquivo2);
				/*remove o arquivo original*/
				remove(url);
				rename(urltemp,url);
				/*mensagem de sucesso*/
				verde("\nConta paga com sucesso!\n");
			break;
			/*arquivo texto*/
			case 2:
				/*le o arquivo para verifica as contas que ainda não foram pagar*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&cp,sizeof(struct contaspagar),1,arquivo);
					/*verifica quais ainda não foram pagas*/
					if(strcmp(cp.status,"EM_DÉBITO")){
						printf("Código: %u\n",cp.codigo);
						printf("Valor: %.2f\n",cp.valor);
						printf("Status: %s\n\n",cp.status);
					}
				}
				printf("Digite o código da conta a ser paga: ");
				scanf("%i",&codigo);
				/*le o arquivo para verifica pelo codigo digitado*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&cp,sizeof(struct contaspagar),1,arquivo);
					if(cp.codigo != codigo){
						/*se o codigo for diferente*/
						fwrite(&cp,sizeof(struct contaspagar),1,arquivo2);
					}
					/*se o codigo for igual*/
					else{
						/*muda o status para paga*/
						strcpy(cp.status,"PAGA");
						/*salva no arquivo temporario*/
						fwrite(&cp,sizeof(struct contaspagar),1,arquivo2);
						/*atualiza o caixa*/
						atualiza_valor_caixa(tipo,urlcaixa,urltempcaixa,url,modoabertura,cp.valor,1);
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				fclose(arquivo2);
				/*remove o arquivo original*/
				remove(url);
				rename(urltemp,url);
				/*mensagem de sucesso*/
				verde("\nConta paga com sucesso!\n");
			break;
			/*erro em opções de salvamento nao validas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}



#endif