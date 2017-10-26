

/* 
 * File:   main.c
 * Author: João Paulo e Marco Túlio
 *
 * Created on 10 de Agosto de 2017, 13:32
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/cadastros.h"
#include "libs/salvar.h"
#include "libs/consulta.h"
#include "libs/config.h"
#include <unistd.h>
#include "libs/exclusao.h"
#include "libs/edicao.h"
#include "libs/cores.h"


int login(){
	char login[20];
	char senha[20];
	printf("Login: ");
	scanf("%s",login);
	printf("Senha: ");
	scanf("%s",senha);
	if(verificausuario(login,senha) == 1){
		return 1;
	}
	else{
		return 0;
	}
}

void config(){
	system("clear");
	int op;
	char mlogin[20];
	char msenha[20];
	branco("Início do Sistema!\n\n");
	branco("Agora será feita a configuração de salvamento do sistema.");
	branco("\nSua escolha será imutável durante todo o uso do programa, escolha sabiamente.");
	branco("O tipo de salvamento será:\n1 - Arquivo Texto;\n2 - Arquivo Binário;\n3 - Banco de Dados;\n4 - Nuvem;\nDigite o número de sua opção: ");
	scanf("%i",&op);
	setbuf(stdin,NULL);
	branco("Digite o login de primeiro acesso(master): ");
	scanf("%s",mlogin);
	setbuf(stdin,NULL);
	branco("Digite a senha de primeiro acesso(master): ");
	scanf("%s",msenha);
	configsave(op,mlogin,msenha);
	system("clear");
}

int verificaconfig(){
	if(verificasave() == 1){
		return 1;	
	}
	else if(verificasave() == 2){
		return 2;
	}
	else if(verificasave() == 3){
		printf("Opcao Ainda nao implementada!!!\n\n");
	}
	else if(verificasave() == 4){
		printf("Opcao Ainda nao implementada!!!\n\n");
	}
	else{
		return 0;
	}
}

char resposta[3];

void menu(char com[50],int tiposave){
	/*comandos de hospede*/
	/*cadastro de hospede*/
	if((strcmp(com,"cadhp") == 0)){
		cadastrahospede();
		salvarhospede(tiposave);
	}
	/*Consulta de Hospede*/
	else if(strcmp(com,"cshp") == 0){
		consultahospede(tiposave);
	}
	else if(strcmp(com,"exhp") == 0){
		excluihospede(tiposave);
	}

	else if(strcmp(com,"edhp") == 0){
		editahospede(tiposave);
	}

	/*comandos para cadastro de hotel*/
	else if(strcmp(com,"cadht") == 0){
		cadastrahotel();
		salvarhotel(tiposave);
	}
	/*consulta dos dados do hotel*/
	else if(strcmp(com,"csht") == 0){
		consultahotel(tiposave);
	}
	else if(strcmp(com,"exht") == 0){
		excluihotel(tiposave);
	}
	else if(strcmp(com,"edht") == 0){
		editahotel(tiposave);
	}

	/*comando para o fornecedor*/
	else if(strcmp(com,"cadf") == 0){
		cadastrafornecedor();
		salvarfornecedor(tiposave);
	}
	else if(strcmp(com,"csf") == 0){
		consultafornecedor(tiposave);
	}
	else if(strcmp(com,"exf") == 0){
		excluifornecedor(tiposave);
	}
	else if(strcmp(com,"edf") == 0){
		editafornecedor(tiposave);
	}


	/*comando para cadastro de hospede*/
	else if(strcmp(com,"cadus") == 0){
		cadastrausuario();
		salvarusuarios();
	}
	else if(strcmp(com,"csus") == 0){
		consultausuario();
	}
	else if(strcmp(com,"exus") == 0){
		excluiusuario();
	}
	/*comandos da categoria*/


	else if(strcmp(com,"cadc") == 0){
		cadastracategoria();
		salvarcategorias(tiposave);
	}
	else if(strcmp(com,"csc") == 0){
		consultacategoria(tiposave);	
	}
	else if(strcmp(com,"exc") == 0){
		excluicategoria(tiposave);
	}
	else if(strcmp(com,"edc") == 0){
		editacategoria(tiposave);
	}


	/*comandos do produto*/
	else if(strcmp(com,"cadp") == 0){
		cadastraproduto();
		salvarproduto(tiposave);
	}
	else if(strcmp(com,"csp") == 0){
		consultaproduto(tiposave);
	}
	else if(strcmp(com,"exp") == 0){
		excluiproduto(tiposave);
	}


	/*comandos de acomodação*/
	else if(strcmp(com,"cadac") == 0){
		cadastraacomodacao();
		salvaracomodacao(tiposave);
	}
	else if(strcmp(com,"csac") == 0){
		consultaacomodacao(tiposave);
	}
	else if(strcmp(com,"exac") == 0){
		excluiacomodacao(tiposave);
	}
	else if(strcmp(com,"edac") == 0){
		editaacomodacao(tiposave);
	}

	/*Outros comandos*/
	else if(strcmp(com,"lt") == 0){
		system("clear");
	}
	else if(strcmp(com,"rconfig") == 0){
		amarelo("Tem certeza que deseja RESETAR a configuração do Sistema?\n: ");
		scanf("%s",resposta);
		if(strcmp(resposta,"Sim") || strcmp(resposta,"SIM") || strcmp(resposta,"sim")){
			resetaconfig();
		}
		else{
			branco("\nProcesso abortado!\n");
		}
	}
	else if(strcmp(com,"32683") == 0){
	}
	else{
		vermelho("\nComando Inválido!\n\n");
	}
}

char comando[50];
 
int main(int argc, char** argv) {
	int verifica = 0;
	system("mkdir config");
	system("mkdir saves");
	system("mkdir libs");
	system("clear");
	while(1){
		//verifica a configuração inicial, caso não tenha sido feita, obrigatoriamente o usuário terá que faze-la.
		if(verificaconfig() == 0){
			config();
		}
		else{
			while(verifica == 0){
				if(login() == 1){
					verifica = 1;
					verde("\nUsuário conectado com sucesso!!\n\n");
					sleep(1);
					system("clear");
				}
				else{
					vermelho("\nLogin e/ou senha incorreto(s)!!\n\n");
					sleep(1);
					system("clear");
				}
			}
			/*Funcoes*/
			/*Após a config feita, o usuário será direcionado para a tela de opções*/
			/*Abaixo sera a parte dos comandos relacionados ao sistema*/
			setbuf(stdin,NULL);	
			printf("Digite um comando: ");
			scanf("%[^\n]s",comando);
			setbuf(stdin,NULL);
			if(strcmp(comando,"sair") == 0){
				printf("Adeus!\n\n");
				for(int i = 5; i >= 1; i--){
					printf("Saindo em: %i\n", i);
					sleep(1);
				}
				return(0);
			}
			else{
				/*serão verificados os comandos para saber o que o usuário deseja fazer*/
				menu(comando,verificasave());
			}
		}
	}
}	
	
