/* 
 * File:   main.c
 * Author: alunos
 *
 * Created on 10 de Agosto de 2017, 13:32
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/cadastros.h"
#include "libs/salvar.h"
#include "libs/consulta.h"
#include <sys/dir.h>

int main(int argc, char** argv) {
	system("clear");
	char comando[50];
	while(1){
		printf(": ");
		scanf("%[^\n]s",comando);
		setbuf(stdin,NULL);
		/*
		depois de receber o comando digitado pelo usuário do sistema
		vai ser verificado qual o comando digitado o que sera feito em seguida
		*/
		/*os comandos terão parametros para dar as opcoes de escolha para o usuario
		os parametros serao iniciados por comando -parametro
		*/
		/*************************************************************************************************************************************/

		/***
		Comandos do hospede
		**/

		/*comando para cadastro de hospedes cadhp na memoria*/
		if(strcmp(comando,"cadhp -m") == 0){
			printf("\nSalvamento na Memória acarreta em perca dos dados anteriormente salvos na mesma!!\n\n");
			cadastrahospede();
			printf("\nDados salvos na memória com sucesso!");
		}
		/*comando para cadastro de hospedes cadhp em arquivo texto*/		
		else if(strcmp(comando,"cadhp -t") == 0){
			cadastrahospede();
			salvarhospedetxt();
		}
		/*comando para cadastro de hospedes cadhp no arquivo binario*/
		else if(strcmp(comando,"cadhp -b") == 0){
			cadastrahospede();
			salvarhospedebin();	
		}
		/**comando para cadastro de hospedes cadhp no arquivo csv**/
		else if(strcmp(comando,"cadhp -c") == 0){
			cadastrahospede();
			salvarhospedecsv();
		}
		/*comando para consultar os hospedes txt*/
		else if(strcmp(comando,"cshp -t") == 0){
			consultahospedetxt();
		}
		/*comando para consultar os hospedes em binario*/
		else if(strcmp(comando,"cshp -b") == 0){
			consultahospedebin();
		}
		/***
		Fim dos comandos do hospede
		***/
		
		/***Comandos do hotel***/

		/*comando para cadastrar hotel cadht*/
		else if(strcmp(comando,"cadht -m") == 0){
			cadastrahotel();
			printf("\nDados salvos com sucesso!");
		}
		else if(strcmp(comando,"cadht -t") == 0){
				cadastrahotel();
				salvarhoteltxt();
		}
		else if(strcmp(comando,"cadht -b") == 0){
			cadastrahotel();
			salvarhotelbin();
		}
		else if(strcmp(comando,"csht -t") == 0){
			consultahoteltxt();
		}
		else if(strcmp(comando,"csht -b") == 0){
			consultahotelbin();
		}
		/***Fim dos comandos do hotel***/

		/***Comandos da acomadação***/

		/*comando para cadastrar acomodacoes cadac*/
		else if(strcmp(comando,"cadac") == 0){
			cadastraacomodacoes();
		}

		/***Fim dos comandos da acomodação***/

		/***Comandos do Produto***/

		/*comando para cadastrar produtos cadp*/
		else if(strcmp(comando,"cadp") == 0){
			cadastraprodutos();
			salvarprodutos();
		}
		/*comando para consulta de produtos*/
		else if(strcmp(comando,"csp") == 0){
			consultaproduto();
		}

		/***Fim dos comandos do produto***/


		/*comando para cadastrar categorias*/
		else if(strcmp(comando,"cadc") == 0){
			cadastracategoria();
			salvarcategorias();
		}
		

		/**
		Outros comandos do sistema
		**/
		/*Comando secreto*/
		else if(strcmp(comando,"32683") == 0){
			printf("\nComando sudo\n");
			char texto[] = "Além do horizonte exite um bug, que não deixa o programa compilar, mesmo com comentario, me perco no código, lálálálá";
			char nome[100];
			sprintf(nome,"spd-say -p +20 -r -90 -l 639-3:por '%s' ",texto);
			system(nome);
			
		}
		/*comando de teste nosso para realização de alguns teste*/
		else if(strcmp(comando,"test") == 0){
			/*****/
		}
		/*comando para limpar a tela do usuário lt*/
		else if(strcmp(comando,"lt") == 0){
			system("clear");
		}
		/*comando para sair do sistema exit*/
		else if(strcmp(comando,"sair") == 0){
			return(0);
		}
		/*comando para mostrar o menu ajuda sobre os outros comandos, help*/
		else if(strcmp(comando,"help") == 0){
			printf("\nLista de Funções do Sistema:\n");
			/*help para as funcoes do hospede**/
			printf("\n------------------Hospedes------------------\n\n");
			/*comandos*/
			printf("Cadastros\n");
			printf("cadhp -m: Cadastro de Hóspedes na Memória (Salvamento na Memória acarreta em perca dos dados anteriormente salvos na mesma)\n");
			printf("cadhp -t: Cadastro de Hóspedes no Arquivo Texto\n");
			printf("cadhp -b: Cadastro de Hóspedes no Arquivo Binário\n");
			printf("cadhp -c: Cadastro de Hóspedes no CSV\n\n");
			printf("Consultas\n");
			printf("cshp -t: Consulta de Hóspedes no Arquivo Texto\n");
			printf("cshp -b: Consulta de Hóspedes no Arquivo Binário\n\n");
			printf("\n------------------Hotéis------------------\n");
			printf("cadht: Cadastro de Hotel\n\n");
			printf("\n------------------Acomodações------------------\n");
			printf("cadac: Cadastro de Acomodações\n\n");
			printf("\n------------------Produtos------------------\n");
			printf("cadp: Cadastro de Produtos\n\n");
		}
		/*valida os comandos, caso não seja nenhum dos listados, indica o comando invalido*/
		else{
			printf("Comando invalido!\n");
		}

	}
}

