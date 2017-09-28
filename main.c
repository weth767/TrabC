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
	printf("Início do Sistema!\n\n");
	printf("Agora será feita a configuração de salvamento do sistema.");
	printf("\nSua escolha será imutável durante todo o uso do programa, escolha sabiamente.");
	printf("O tipo de salvamento será:\n1 - Arquivo Texto;\n2 - Arquivo Binário;\n3 - Banco de Dados;\n4 - Nuvem;\nDigite o número de sua opção: ");
	scanf("%i",&op);
	setbuf(stdin,NULL);
	printf("Digite o login de primeiro acesso(master): ");
	scanf("%s",mlogin);
	setbuf(stdin,NULL);
	printf("Digite a senha de primeiro acesso(master): ");
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
	/*comando para cadastro de hospede*/
	else if(strcmp(com,"cadus") == 0){
		cadastrausuario();
		salvarusuariosbin();
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
	/*comandos do produto*/
	else if(strcmp(com,"cadp") == 0){
		cadastraproduto();
		salvarproduto(tiposave);
	}
	else if(strcmp(com,"csp") == 0){
		consultaproduto(tiposave);
	}
	/*comandos de acomodação*/
	else if(strcmp(com,"cadac") == 0){
		cadastraacomodacao();
		salvaracomodacao(tiposave);
	}
	else if(strcmp(com,"csac") == 0){
		consultaacomodacao(tiposave);
	}
	/*Outros comandos*/
	else if(strcmp(com,"lt") == 0){
		system("clear");
	}
	else if(strcmp(com,"32683") == 0){
	}
	else{
		printf("\nComando Inválido!\n\n");
	}
}

char comando[50];
 
int main(int argc, char** argv) {
	int verifica = 0;
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
					printf("\nUsuário conectado com sucesso!!\n\n");
					sleep(1);
					system("clear");
				}
				else{
					printf("\nLogin e/ou senha incorreto(s)!!\n\n");
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
	