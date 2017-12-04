#ifndef CONTAS_H
#define CONTAS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "cores.h"



/*função para adicionar valor nas conta  do hospede, criar conta e consultar existencia de conta */
/*recebe como paremetro o tipo de salvamento, os urls, modo de abertura, struct de contas e a função*/
void conta_hospede(int tipo,char url[50],char urltemp[50],char modoabertura[5],struct contas ct,int funcao){
	/*cria dois ponteiros de arquivo que vai possibiltar salvar no arquivo de contas*/
	FILE *arquivo;
	FILE *arquivo2;
	struct contas cts;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica se os arquivos foram abertos corretamente*/
	if(arquivo == NULL || arquivo2 == NULL){
		vermelho("\nErro em realizar o arquivo de contas!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				/*verifica se é criação de contas, consulta de conta, ou utilização de conta*/
				if(funcao == -1){
					/*pesquisa de contas*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
						/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}
						/*comando de leitura*/
						fscanf(arquivo,"%u\n %u\n %u\n %f\n %f\n %i\n %s\n\n",&cts.codigo,&cts.codigo_hospede,&cts.codigo_acomodacao,
						&cts.valor,&cts.valor_total,&cts.pago,cts.status);
						/*verifica o código do hospede*/
						if(cts.codigo_hospede == ct.codigo_hospede){
							/*mostra na tela os dados relacionados ao hospede*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							else if(cts.pago == -1){
								printf("Status da Fatura da Conta: ");
								azul("Fechada\n");
							}
							printf("Status: %s\n\n",cts.status);
						}
					}
					/*fecha o arquivo*/
					fclose(arquivo);
				}
				else if(funcao == 0){
					/*função 0, cria conta*/
					/*salva os dados no arquivo*/
					fprintf(arquivo,"%u\n",ct.codigo);
					fprintf(arquivo,"%u\n",ct.codigo_hospede);
					fprintf(arquivo,"%u\n",ct.codigo_acomodacao);
					fprintf(arquivo,"%f\n",ct.valor);
					fprintf(arquivo,"%f\n",ct.valor_total);
					fprintf(arquivo,"%i\n",ct.pago);
					fprintf(arquivo,"%s\n\n",ct.status);
					/*conta criada*/
					verde("\nConta criada com sucesso!\n");
					/*fecha o arquivo*/
					fclose(arquivo);
				}
				else if(funcao == 1){
					/*função igual a 1, o hospede compra itens e os valores são adicionados na conta*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						/*comando de leitura*/
						fscanf(arquivo,"%u\n %u\n %u\n %f\n %f\n %i\n %s\n\n",&cts.codigo,&cts.codigo_hospede,&cts.codigo_acomodacao,
						&cts.valor,&cts.valor_total,&cts.pago,cts.status);
						/*verifica a conta que o códigos são diferentes do código digitado e salvo no arquivo temporario*/
						if(cts.codigo != ct.codigo){
							fprintf(arquivo2,"%u\n",cts.codigo);
							fprintf(arquivo2,"%u\n",cts.codigo_hospede);
							fprintf(arquivo2,"%u\n",cts.codigo_acomodacao);
							fprintf(arquivo2,"%f\n",cts.valor);
							fprintf(arquivo2,"%f\n",cts.valor_total);
							fprintf(arquivo2,"%i\n",cts.pago);
							fprintf(arquivo2,"%s\n\n",cts.status);
						}
						else{
							/*soma os valores que já tem com o novo valor*/
							cts.codigo_acomodacao = ct.codigo_acomodacao;
							cts.pago = 0;
							cts.valor = cts.valor + ct.valor;
							cts.valor_total = cts.valor_total + cts.valor;
							strcpy(cts.status,"Aberta");
							/*depois de atualizado o valor, salva no arquivo temporario*/
							fprintf(arquivo2,"%u\n",cts.codigo);
							fprintf(arquivo2,"%u\n",cts.codigo_hospede);
							fprintf(arquivo2,"%u\n",cts.codigo_acomodacao);
							fprintf(arquivo2,"%f\n",cts.valor);
							fprintf(arquivo2,"%f\n",cts.valor_total);
							fprintf(arquivo2,"%i\n",cts.pago);
							fprintf(arquivo2,"%s\n\n",cts.status);
						}
					}
					verde("\nConta atualizada com sucesso!\n");
					remove(url);
					rename(urltemp,url);
					fclose(arquivo);
					fclose(arquivo2);
				}
				else if(funcao == 10){
					/*função 10, fecha a conta e devolve o valor a pagar*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						/*comando de leitura*/
						fscanf(arquivo,"%u\n %u\n %u\n %f\n %f\n %i\n %s\n\n",&cts.codigo,&cts.codigo_hospede,&cts.codigo_acomodacao,
						&cts.valor,&cts.valor_total,&cts.pago,cts.status);
						/*verifica a conta que o códigos são diferentes do código digitado e salvo no arquivo temporario*/
						if(cts.codigo != ct.codigo){
							fprintf(arquivo2,"%u\n",cts.codigo);
							fprintf(arquivo2,"%u\n",cts.codigo_hospede);
							fprintf(arquivo2,"%u\n",cts.codigo_acomodacao);
							fprintf(arquivo2,"%f\n",cts.valor);
							fprintf(arquivo2,"%f\n",cts.valor_total);
							fprintf(arquivo2,"%i\n",cts.pago);
							fprintf(arquivo2,"%s\n\n",cts.status);
						}
						else{
							/*mostra os valores na tela para o usuário*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							printf("Status: %s\n\n",cts.status);
							/*zera o valor e o hospede paga sua conta*/
							cts.valor = 0;
							/*mostra o status da conta fechada*/
							cts.pago = 1;
							strcpy(cts.status,"Fechada");
							/*salva os novos dados no arquivo*/
							fprintf(arquivo2,"%u\n",cts.codigo);
							fprintf(arquivo2,"%u\n",cts.codigo_hospede);
							fprintf(arquivo2,"%u\n",cts.codigo_acomodacao);
							fprintf(arquivo2,"%f\n",cts.valor);
							fprintf(arquivo2,"%f\n",cts.valor_total);
							fprintf(arquivo2,"%i\n",cts.pago);
							fprintf(arquivo2,"%s\n\n",cts.status);

							/*mostra agora os valores atualizados*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							printf("Status: %s\n\n",cts.status);
						}
					}
					verde("\nConta acertada com sucesso!\n");
					/*fecha os arquivos e remove o arquivo original e renomeia o temporario*/
					remove(url);
					rename(urltemp,url);
					fclose(arquivo);
					fclose(arquivo2);
				}
			break;
			case 2:/*arquivo binário*/
				/*verifica se é criação de contas, consulta de conta, ou utilização de conta*/
				if(funcao == -1){
					/*pesquisa de contas*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}
						/*comando de leitura*/
						fread(&cts,sizeof(struct contas),1,arquivo);
						/*verifica o código do hospede*/
						if(cts.codigo_hospede == ct.codigo_hospede){
							/*mostra na tela os dados relacionados ao hospede*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							else if(cts.pago == -1){
								printf("Status da Fatura da Conta: ");
								azul("Fechada\n");
							}
							printf("Status: %s\n\n",cts.status);
						}
					}
					/*fecha o arquivo*/
					fclose(arquivo);
				}
				else if(funcao == 0){
					/*função 0, cria conta*/
					/*salva os dados no arquivo*/
					fwrite(&ct,sizeof(struct contas),1,arquivo);
					/*conta criada*/
					verde("\nConta criada com sucesso!\n");
					/*fecha o arquivo*/
					fclose(arquivo);
				}
				else if(funcao == 1){
					/*função igual a 1, o hospede compra itens e os valores são adicionados na conta*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						/*comando de leitura*/
						fread(&cts,sizeof(struct contas),1,arquivo);
						/*verifica a conta que o códigos são diferentes do código digitado e salvo no arquivo temporario*/
						if(cts.codigo != ct.codigo){
							fwrite(&cts,sizeof(struct contas),1,arquivo2);
						}
						else{
							/*soma os valores que já tem com o novo valor*/
							cts.codigo_acomodacao = ct.codigo_acomodacao;
							cts.pago = 0;
							cts.valor = cts.valor + ct.valor;
							cts.valor_total = cts.valor_total + cts.valor;
							strcpy(cts.status,"Aberta");
							/*depois de atualizado o valor, salva no arquivo temporario*/
							fwrite(&cts,sizeof(struct contas),1,arquivo2);
						}
					}
					verde("\nConta atualizada com sucesso!\n");
					remove(url);
					rename(urltemp,url);
					fclose(arquivo);
					fclose(arquivo2);
				}
				else if(funcao == 10){
					/*função 10, fecha a conta e devolve o valor a pagar*/
					/*primeiro le o arquivo de contas*/
					while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
						if(feof(arquivo)){
							break;
						}

						/*comando de leitura*/
						fread(&cts,sizeof(struct contas),1,arquivo);
						/*verifica a conta que o códigos são diferentes do código digitado e salvo no arquivo temporario*/
						if(cts.codigo != ct.codigo){
							fwrite(&cts,sizeof(struct contas),1,arquivo2);
						}
						else{
							/*mostra os valores na tela para o usuário*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							printf("Status: %s\n\n",cts.status);
							/*zera o valor e o hospede paga sua conta*/
							cts.valor = 0;
							/*mostra o status da conta fechada*/
							cts.pago = 1;
							strcpy(cts.status,"Fechada");
							/*salva os novos dados no arquivo*/
							fwrite(&cts,sizeof(struct contas),1,arquivo2);

							/*mostra agora os valores atualizados*/
							printf("Código da Conta: %u\n",cts.codigo);
							printf("Código do Hospede: %u\n",cts.codigo_hospede);
							printf("Código da Acomodação: %u\n",cts.codigo_acomodacao);
							printf("Valor da Dívida Atual: R$%.2f\n",cts.valor);
							printf("Valor Total Gasto: R$%.2f\n",cts.valor_total);
							if(cts.pago == 0){
								printf("Status da Fatura da Conta: ");
								amarelo("Ainda não Paga\n");
							}
							else if(cts.pago == 1){
								printf("Status da Fatura da Conta: ");
								verde("Paga\n");
							}
							printf("Status: %s\n\n",cts.status);
						}
					}
					verde("\nConta acertada com sucesso!\n");
					/*fecha os arquivos e remove o arquivo original e renomeia o temporario*/
					remove(url);
					rename(urltemp,url);
					fclose(arquivo);
					fclose(arquivo2);
				}
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

#endif