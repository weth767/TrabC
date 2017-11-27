#ifndef RESERVA_H
#define RESERVA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
#include "structs.h"

/*função para cadastrar a reserva*/
/*recebe por parametro, o tipo de salvamento, o url da reserva, o modo abertura e a struct de reserva*/
void reserva(int tipo,char url[50],char modoabertura[5],struct reserva r){
	/*ponteiro de arquivo para abrir o arquivo de reservas*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura do arquivo*/
	if(arquivo == NULL){
		/*mostra mensagem de erro*/
		vermelho("\nErro na abertura do arquivo de Reservas!\n");
	}
	/*se estiver tudo ok, continua a execução*/
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*caso 1, arquivo texto*/
			case 1:
				/*salva os dados da struct no arquivo texto*/
				fprintf(arquivo,"%u\n",r.codigo);
				fprintf(arquivo,"%u\n",r.codigo_acomodacao);
				fprintf(arquivo,"%u\n",r.codigo_hospede);
				fprintf(arquivo,"%i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
				fprintf(arquivo,"%i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
				fprintf(arquivo,"%s\n\n",r.status);
				/*mostra mensagem de sucesso ao usuário*/
				printf("\nCódigo da Reserva: %i\n",r.codigo);
				verde("\nDados salvos com sucesso!\n");
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			case 2:/*arquivo binário*/
				/*salva os dados da struct no arquivo binário*/
				fwrite(&r,sizeof(struct reserva),1,arquivo);
				/*dados salvos*/
				/*mostra mensagem de sucesso ao usuário*/
				printf("\nCódigo da Reserva: %i\n",r.codigo);
				verde("\nDados salvos com sucesso!\n");
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			default:
				/*mensagem de erro para opções de salvamento não implementadas*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

/*função para consultar todas as reservas*/
void consulta_reservas(int tipo,char url[50],char modoabertura[5],int codigo){
	/*struct de reserva para ter acesso as varaiveis*/
	struct reserva r;
	/*ponteiro para abrir o arquivo*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica erros na abertura do arquivo*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de Reservas!\n");
	}
	/*se estiver tudo ok, continua a execução*/
	else{
		/*switch para verificar os tipo de salvamento*/
		switch(tipo){
			/*caso 1, arquivo texto*/
			case 1:
				/*while para ler o arquivo todo*/
				ciano("Reservas de Acordo com o Código Digitado\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
						&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,r.status);
					if(feof(arquivo)){
						break;
					}
					/*printa a reserva lida, assim irá mostrar todas as reservas que forem do hospede, selecionado pelo código*/
					if(r.codigo == codigo){
						printf("Código da Reserva: %u\n",r.codigo);
						printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
						printf("Código do Hóspede: %u\n",r.codigo_hospede);
						printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
						printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
						printf("Status da Reserva: %s\n",r.status);
					}
				}
				printf("\n---------------------------------------------------------------------\n");
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			case 2:/*arquivo binário*/
				/*while para ler o arquivo todo*/
				printf("\n---------------------------------------------------------------------\n");
				ciano("Reservas de Acordo com o Código Digitado\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&r,sizeof(struct reserva),1,arquivo);
					/*printa a reserva lida, assim irá mostrar todas as reservas que forem do hospede, selecionado pelo código*/
					if(feof(arquivo)){
						break;
					}
					if(r.codigo == codigo){
						printf("Código da Reserva: %u\n",r.codigo);
						printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
						printf("Código do Hóspede: %u\n",r.codigo_hospede);
						printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
						printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
						printf("Status da Reserva: %s\n",r.status);
					}
					printf("\n---------------------------------------------------------------------\n");
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			default:
				/*mensagem de erro para opções de salvamento não implementadas*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
#endif