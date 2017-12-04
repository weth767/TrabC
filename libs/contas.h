#ifndef CONTAS_H
#define CONTAS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "cores.h"

/*unsigned codigo;
	unsigned codigo_hospede;
	unsigned codigo_acomodacao;
	/*-1 pesquisar a existencia de conta*/
	/*0 para abertura de conta*/
	/*1 para conta existente*
	float valor;
	float valor_total;
	int pago;
	char status[20];*/

/*função para adicionar valor na */
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
					if(cts.codigo == ct.codigo){
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
				/*primeiro le o arquivo de contas*/
				while(!feof(arquivo)){
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}


					/*comando de leitura*/
					fscanf(arquivo,)
				}
			break;
		}
	}
}

#endif