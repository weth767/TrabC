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

int menusalvar(){
	int op = 0;
	printf("\nO salvamento será realizado: \n\n1 - Memória;\n2 - Arquivo Texto;\n3 - Binário;\n4 - Banco de Dados;\n5 - Nuvem;\n\nDigite a sua opção: ");
	scanf("%i",&op);
	switch(op){
		case 1:
			return 1;
		break;
		case 2:
			return 2;
		break;
		case 3:
			return 3;
		break;
		case 4:
			printf("\nOpção ainda não foi implementada\n\n");
		break;
		case 5:
			printf("\nOpção ainda não foi implementada\n\n");
		break;
		default:
			printf("\nOpção Inválida!!\n\n");
		break;
	}
	
} 


int main(int argc, char** argv) {
	system("clear");
	char comando[50];
	while(1){
		printf(": ");
		scanf("%s",comando);
		/*
		depois de receber o comando digitado pelo usuário do sistema
		vai ser verificado qual o comando digitado o que sera feito em seguida
		*/

		/*comando para cadastro de hospedes cadhp*/
		if(strcmp(comando,"cadhp") == 0){
			int resposta = menusalvar();
			if(resposta == 1){
				cadastrahospede();
				printf("\nDados salvos com sucesso!");
			}
			else if(resposta == 2){
				cadastrahospede();
				salvarhospedetxt();
			}
		}
		/*comando secreto que fará alguma coisa futuramente*/
		else if(strcmp(comando,"32683") == 0){
			printf("\nComando sudo\n");
			char texto[] = "Além do horizonte exite um bug, que não deixa o programa compilar, mesmo com comentario, me perco no código, lálálálá";
			char nome[100];
			sprintf(nome,"spd-say -p +20 -r -90 -l 639-3:por '%s' ",texto);
			system(nome);
			
		}
		/*comando de teste nosso para realização de alguns teste*/
		else if(strcmp(comando,"test") == 0){
			codigocategoria();
		}
		/*comando para consultar os hospedes*/
		else if(strcmp(comando,"cshp") == 0){
			consultahospedetxt();
		}
		/*comando para limpar a tela do usuário lt*/
		else if(strcmp(comando,"lt") == 0){
			system("clear");
		}
		/*comando para sair do sistema exit*/
		else if(strcmp(comando,"sair") == 0){
			return(0);
		}
		/*comando para cadastrar hotel cadht*/
		else if(strcmp(comando,"cadht") == 0){
			cadastrahotel();
			salvarhotel();
		}
		else if(strcmp(comando,"csht") == 0){
			consultahotel();
		}
		/*comando para cadastrar acomodacoes cadac*/
		else if(strcmp(comando,"cadac") == 0){
			cadastraacomodacoes();
		}
		/*comando para cadastrar produtos cadp*/
		else if(strcmp(comando,"cadp") == 0){
			cadastraprodutos();
			salvarprodutos();
		}
		/*comando para consulta de produtos*/
		else if(strcmp(comando,"csp") == 0){
			consultaproduto();
		}
		/*comando para cadastrar categorias*/
		else if(strcmp(comando,"cadc") == 0){
			cadastracategoria();
			salvarcategorias();
		}
		/*comando para mostrar o menu ajuda sobre os outros comandos, help*/
		else if(strcmp(comando,"help") == 0){
			printf("\nLista de Funções do Sistema:\n");
			printf("\n-----------Cadastros-------------\n");
			printf("cadhp: Cadastro de Hóspedes\n");
			printf("cadht: Cadastro de Hotel\n");
			printf("cadac: Cadastro de Acomodações\n");
			printf("cadp: Cadastro de Produtos\n");
		}
		/*valida os comandos, caso não seja nenhum dos listados, indica o comando invalido*/
		else{
			printf("Comando invalido!\n");
		}

	}
}

