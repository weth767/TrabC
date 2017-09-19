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
	printf("Início do Sistema!\n\n");
	printf("Agora será feita a configuração de salvamento do sistema.");
	printf("\nSua escolha será imutável durante todo o uso do programa, escolha sabiamente.");
	printf("O tipo de salvamento será:\n1 - Arquivo Texto;\n2 - Arquivo Binário;\n3 - Banco de Dados;\n4 - Nuvem;\nDigite o número de sua opção: ");
	scanf("%i",&op);
	configsave(op);
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
	/*cadastro de hospede, tanto pra texto quanto pra binario*/
	if((strcmp(com,"cadhp") == 0) && tiposave == 1){
		cadastrahospede();
		salvarhospedetxt();
	}
	else if(((strcmp(com,"cadhp") == 0) && tiposave == 2)){
		cadastrahospede();
		salvarhospedebin();
	}
	/*Consulta de Hospede*/
	else if((strcmp(com,"cshp") == 0) && tiposave == 1){
		consultahospedetxt();
	}
	else if(((strcmp(com,"cshp") == 0) && tiposave == 2)){
		consultahospedebin();
	}
	/*comandos para cadastro de hotel*/
	else if((strcmp(com,"cadht") == 0) && tiposave == 1){
		cadastrahotel();
		salvarhoteltxt();
	}
	else if(((strcmp(com,"cadhp") == 0) && tiposave == 2)){
		cadastrahotel();
		salvarhotelbin();
	}
	/*consulta dos dados do hotel*/
	else if((strcmp(com,"csht") == 0) && tiposave == 1){
		consultahoteltxt();
	}
	else if((strcmp(com,"csht") == 0) && tiposave == 2){
		consultahotelbin();
	}
	/*comando para cadastro de hospede*/
	else if((strcmp(com,"cadus") == 0)){
		cadastrausuario();
		salvarusuariosbin();
	}
	/*comandos da categoria*/
	else if((strcmp(com,"cadc") == 0)){
		cadastracategoria();
		salvarcategorias	(tiposave);
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
	while(verifica == 0){
		if(login() == 1){
			verifica = 1;
			printf("\nUsuário conectado com sucesso!!\n\n");
		}
		else{
			printf("\nLogin e/ou senha incorreto(s)!!\n\n");
		}
	}
	sleep(1);
	system("clear");	
	while(1){
		//verifica a configuração inicial, caso não tenha sido feita, obrigatoriamente o usuário terá que faze-la.
		if(verificaconfig() == 0){
			config();
		}
		else{
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
	