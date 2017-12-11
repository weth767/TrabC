

/* 
 * File:   main.c
 * Author: João Paulo e Marco Túlio
 *
 * Created on 10 de Agosto de 2017, 13:32
 */ 

/*bibliotecas*/
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
#include "libs/reserva.h"
#include "libs/produto.h"
#include "libs/checks.h"
#include "libs/caixa.h"
/***/
/*variaveis que serão utilizadas como constantes*/
char modoabertura[5];
char urlhospede[50];
char urlhotel[50];
char urlproduto[50];
char urlcategoria[50];
char urlacomodacao[50];
char urlfornecedor[50];
char urlusuario[50];
char url_entradaprodutos[50];
char url_saidaprodutos[50];
char url_reserva[50];
char urlcheck[50];
char urlconta[50];
char urlcaixa[50];
char urlcontapagar[50];
char urltemphospede[50];
char urltemphotel[50];
char urltempproduto[50];
char urltempcategoria[50];
char urltempacomodacao[50];
char urltempfornecedor[50];
char urltempusuario[50];
char urltemp_entradaprodutos[50];
char urltemp_saidaprodutos[50];
char urltemp_reserva[50];
char urltempcheck[50];
char urltempconta[50];
char urltempcaixa[50];
char urltempcontapagar[50];
/**/

/*função para definição dos urls e modo de abertura dos arquivos*/
void defineconstantes(){
	/*para a variavel da url do usuario, como é somente binario vai fora do if e seu temporario tambem*/
	strcpy(urlusuario,"saves/usuarios.bin");
	strcpy(urltempusuario,"saves/tempusuarios.bin");
	/*o resto vai ser comparado a configuração*/
	if(verificasave() == 1){
		/*caminhos originais*/
		strcpy(modoabertura,"a+");
		strcpy(urlhospede,"saves/hospedes.txt");
		strcpy(urlhotel,"saves/hoteis.txt");
		strcpy(urlproduto,"saves/produtos.txt");
		strcpy(urlcategoria,"saves/categorias.txt");
		strcpy(urlacomodacao,"saves/acomodacoes.txt");
		strcpy(urlfornecedor,"saves/fornecedores.txt");
		strcpy(url_entradaprodutos,"saves/entradaprodutos.txt");
		strcpy(url_saidaprodutos,"saves/saidaprodutos.txt");
		strcpy(url_reserva,"saves/reservas.txt");
		strcpy(urlcheck,"saves/checks.txt");
		strcpy(urlconta,"saves/contas.txt");
		strcpy(urlcaixa,"saves/caixa.txt");
		strcpy(urlcontapagar,"saves/contaspagar.txt");
		/*caminhos temporarios*/
		strcpy(urltemphospede,"saves/temphospedes.txt");
		strcpy(urltemphotel,"saves/temphoteis.txt");
		strcpy(urltempproduto,"saves/tempprodutos.txt");
		strcpy(urltempcategoria,"saves/tempcategorias.txt");
		strcpy(urltempacomodacao,"saves/tempacomodacoes.txt");
		strcpy(urltempfornecedor,"saves/tempfornecedores.txt");
		strcpy(urltemp_entradaprodutos,"saves/tempentradaprodutos.txt");
		strcpy(urltemp_saidaprodutos,"saves/tempsaidaprodutos.txt");
		strcpy(urltemp_reserva,"saves/tempreservas.txt");
		strcpy(urltempcheck,"saves/tempchecks.txt");
		strcpy(urltempconta,"saves/tempcontas.txt");
		strcpy(urltempcaixa,"saves/tempcaixa.txt");
		strcpy(urltempcontapagar,"saves/tempcontaspagar.txt");
		
	}
	else if(verificasave() == 2){
		/*caminhos originais do binario*/
		strcpy(modoabertura,"ab+");
		strcpy(urlhospede,"saves/hospedes.bin");
		strcpy(urlhotel,"saves/hoteis.bin");
		strcpy(urlproduto,"saves/produtos.bin");
		strcpy(urlcategoria,"saves/categorias.bin");
		strcpy(urlacomodacao,"saves/acomodacoes.bin");
		strcpy(urlfornecedor,"saves/fornecedores.bin");
		strcpy(url_entradaprodutos,"saves/entradaprodutos.bin");
		strcpy(url_saidaprodutos,"saves/saidaprodutos.bin");
		strcpy(url_reserva,"saves/reservas.bin");
		strcpy(urlcheck,"saves/checks.bin");
		strcpy(urlconta,"saves/contas.bin");
		strcpy(urlcaixa,"saves/caixa.bin");
		strcpy(urlcontapagar,"saves/contaspagar.bin");
		/*caminhos temporarios do binario*/
		strcpy(urltemphospede,"saves/temphospedes.bin");
		strcpy(urltemphotel,"saves/temphoteis.bin");
		strcpy(urltempproduto,"saves/tempprodutos.bin");
		strcpy(urltempcategoria,"saves/tempcategorias.bin");
		strcpy(urltempacomodacao,"saves/tempacomodacoes.bin");
		strcpy(urltempfornecedor,"saves/tempfornecedores.bin");
		strcpy(urltemp_entradaprodutos,"saves/tempentradaprodutos.bin");
		strcpy(urltemp_saidaprodutos,"saves/tempsaidaprodutos.bin");
		strcpy(urltemp_reserva,"saves/tempreservas.bin");
		strcpy(urltempcheck,"saves/tempchecks.bin");
		strcpy(urltempconta,"saves/tempcontas.bin");
		strcpy(urltempcaixa,"saves/tempcaixa.bin");
		strcpy(urltempcontapagar,"saves/tempcontaspagar.bin");
	}
	/*opção de salvamento ainda nao implementada*/
	else{
		vermelho("\nOpções ainda não implementadas\n");
	}
}



/*função para verificar o login*/
int login(){
	/*dois vetores de char's para receber o login e a senha*/
	char login[20];
	char senha[20];
	/*Armazena o login e a senha*/
	printf("Login: ");
	scanf("%s",login);
	printf("Senha: ");
	scanf("%s",senha);
	/*chama a função para verificar se o usuario com esse login e essa senha existe*/
	if(verificausuario(login,senha) == 1){
		/*caso existe retorna 1*/
		return 1;
	}
	else{
		/*senão retorna 0*/
		return 0;
	}
}
/*funcao para realizar a configuração inicial*/
void config(){
	/*limpa a tela*/
	system("clear");
	int op;
	char mlogin[20];
	char msenha[20];
	/*Mostra mensagem ao usuário, indicando o que será feito*/
	branco("Início do Sistema!\n\n");
	branco("Agora será feita a configuração de salvamento do sistema.");
	branco("\nSua escolha será imutável durante todo o uso do programa, escolha sabiamente.");
	/*armazena a opção de salvamento*/
	branco("O tipo de salvamento será:\n1 - Arquivo Texto;\n2 - Arquivo Binário;\n3 - Banco de Dados;\n4 - Nuvem;\nDigite o número de sua opção: ");
	scanf("%i",&op);
	setbuf(stdin,NULL);
	/*e armazena o login e a senha master*/
	branco("Digite o login de primeiro acesso(master): ");
	scanf("%s",mlogin);
	setbuf(stdin,NULL);
	branco("Digite a senha de primeiro acesso(master): ");
	scanf("%s",msenha);
	/*valores armazenados que são passados como parametros para a função configsave*/
	configsave(op,mlogin,msenha);
	system("clear");
}

/*função para verificar o tipo de save*/
int verificaconfig(){
	/*caso o tipo de save for igual a um valor diferente de 0, retorna o número de acordo com esse tipo de save,
	1 para texto*/
	if(verificasave() == 1){
		return 1;	
	}
	/*2 para binario*/
	else if(verificasave() == 2){
		return 2;
	}/*3 e 4 não implementados ainda*/
	else if(verificasave() == 3){
		printf("Opcao Ainda nao implementada!!!\n\n");
	}
	else if(verificasave() == 4){
		printf("Opcao Ainda nao implementada!!!\n\n");
	}
	/*0 retorna invalido*/
	else{
		return 0;
	}
}
float *valores;
char resposta[3];
/*função menu, aqui são verificados os comandos referentes ao sistema*/
void menu(char com[50],int tiposave){
	/*comandos de hospede*/
	/*cadastro de hospede*/
	if((strcmp(com,"cadhp") == 0)){
		salvarhospede(tiposave,urlhospede,modoabertura,cadastrahospede());
	}
	/*Consulta de Hospede*/
	else if(strcmp(com,"cshp") == 0){
		consultahospede(tiposave,urlhospede,modoabertura);
	}
	/*excluir hospede*/
	else if(strcmp(com,"exhp") == 0){
		excluihospede(tiposave,urlhospede,modoabertura,urltemphospede);
	}
	/*editar hospede*/
	else if(strcmp(com,"edhp") == 0){
		editahospede(tiposave,urlhospede,modoabertura,urltemphospede);
	}





	/*comandos para cadastro de hotel*/
	else if(strcmp(com,"cadht") == 0){
		salvarhotel(tiposave,urlhotel,modoabertura,cadastrahotel());
	}
	/*consulta dos dados do hotel*/
	else if(strcmp(com,"csht") == 0){
		consultahotel(tiposave,urlhotel,modoabertura);
	}
	/*excluir hotel*/
	else if(strcmp(com,"exht") == 0){
		excluihotel(tiposave,urlhotel,modoabertura,urltemphotel);
	}
	/*editar hotel*/
	else if(strcmp(com,"edht") == 0){
		editahotel(tiposave,urlhotel,modoabertura,urltemphotel);
	}







	/*comando para o fornecedor*/
	else if(strcmp(com,"cadf") == 0){
		salvarfornecedor(tiposave,urlfornecedor,modoabertura,cadastrafornecedor());
	}
	/*consulta os dados do fornecedor*/
	else if(strcmp(com,"csf") == 0){
		consultafornecedor(tiposave,urlfornecedor,modoabertura);
	}
	/*excluir forncedores*/
	else if(strcmp(com,"exf") == 0){
		excluifornecedor(tiposave,urlfornecedor,modoabertura,urltempfornecedor);
	}
	/*editar fornecedores*/
	else if(strcmp(com,"edf") == 0){
		editafornecedor(tiposave,urlfornecedor,modoabertura,urltempfornecedor);
	}




	/*comando para cadastro de usuario*/
	else if(strcmp(com,"cadus") == 0){
		salvarusuarios(urlusuario,modoabertura,cadastrausuario());
	}
	/*consulta dados do usuario*/
	else if(strcmp(com,"csus") == 0){
		consultausuario(urlusuario,modoabertura);
	}
	/*excluir usuário*/
	else if(strcmp(com,"exus") == 0){
		excluiusuario(urlusuario,modoabertura,urltempusuario);
	}
	/*editar usuário*/
	else if(strcmp(com,"edus") == 0){
		editausuario(urlusuario,modoabertura,urltempusuario);
	}





	/*comando para cadastro de categoria*/
	else if(strcmp(com,"cadc") == 0){	
		salvarcategorias(tiposave,urlcategoria,modoabertura,cadastracategoria());
	}
	/*comando para consultar categoria*/
	else if(strcmp(com,"csc") == 0){
		consultacategoria(tiposave,urlcategoria,modoabertura);	
	}
	/*excluir categoria*/
	else if(strcmp(com,"exc") == 0){
		excluicategoria(tiposave,urlcategoria,modoabertura,urltempcategoria);
	}
	/*editar categoria*/
	else if(strcmp(com,"edc") == 0){
		editacategoria(tiposave,urlcategoria,modoabertura,urltempcategoria);
	}





	/*comandos de cadastrar produto*/
	else if(strcmp(com,"cadp") == 0){
		salvarproduto(tiposave,urlproduto,modoabertura,cadastraproduto());
	}
	/*consultar os produtos*/
	else if(strcmp(com,"csp") == 0){
		consultaproduto(tiposave,urlproduto,modoabertura);
	}
	/*excluir produto*/
	else if(strcmp(com,"exp") == 0){
		excluiproduto(tiposave,urlproduto,modoabertura,urltempproduto);
	}
	/*editar produto*/
	else if(strcmp(com,"edp") == 0){

	}




	/*comando para cadastrar acomodação*/
	else if(strcmp(com,"cadac") == 0){
		salvaracomodacao(tiposave,urlacomodacao,modoabertura,cadastraacomodacao(urlcategoria,modoabertura));
	}
	/*consultar acomodação*/
	else if(strcmp(com,"csac") == 0){
		consultaacomodacao(tiposave,urlacomodacao,modoabertura);
	}
	/*excluir acomodação*/
	else if(strcmp(com,"exac") == 0){
		excluiacomodacao(tiposave,urlacomodacao,modoabertura,urltempacomodacao);
	}
	/*editar acomodação*/
	else if(strcmp(com,"edac") == 0){
		editaacomodacao(tiposave,urlacomodacao,modoabertura,urltempacomodacao,urlcategoria);
	}






	/*comando para compra e venda de produtos no hotel*/
	/*compra de produtos*/
	else if(strcmp(com,"cpp") == 0){
		struct entradaprodutos ep = cadastra_entradaprodutos(urlproduto,urlfornecedor,urlcaixa,urltempcaixa,urlcontapagar,modoabertura);
		valores = entrada_produtos(tiposave,url_entradaprodutos,modoabertura,ep);
		atualiza_valorprodutos(tiposave,urlproduto,modoabertura,urltempproduto,valores,ep);
	}
	/*Venda de produtos*/
	else if(strcmp(com,"vdp") == 0){
		struct saidaprodutos sp = cadastra_saidaprodutos(urlproduto,urlconta,urltempconta,urlcaixa,urltempcaixa,urlhospede,urlcontapagar,modoabertura);
		saida_produtos(tiposave,url_saidaprodutos,modoabertura,sp);
		atualiza_quantidadeprodutos(tiposave,urlproduto,urltempproduto,modoabertura,sp);
	}
	/*Comandos de reserva*/







	/*comando para realizar a reserva*/
	else if(strcmp(com,"rsv") == 0){

		reserva(tiposave,url_reserva,modoabertura,cadastra_reserva(urlacomodacao,urlcategoria,urlhospede,modoabertura));
	}
	/*comando para consultar reserva de acordo com o código*/
	else if(strcmp(com,"csrsvc") == 0){
		int c;
		ciano("\nConsulta de Reserva\n\n");
		branco("Digite o código da Reserva: ");
		scanf("%i",&c);
		consulta_reserva(tiposave,url_reserva,modoabertura,c);
	}
	/*comando para consultar todas as reservas*/
	else if(strcmp(com,"csrsv") == 0){
		int c;
		ciano("\nConsulta de Reservas\n\n");
		consulta_reservas(tiposave,url_reserva,modoabertura);
	}
	/*comando para cancelar a reserva feita*/
	else if(strcmp(com,"canrsv") == 0){
		int c;
		branco("\nCancelamento de Reserva\n\n");
		ciano("Digite o código da Reserva: ");
		scanf("%i",&c);
		cancela_reserva(tiposave,url_reserva,urltemp_reserva,modoabertura,c);
	}
	/*comando para realizar a pesquisa de acomodações*/
	else if(strcmp(com,"psrsv") == 0){
		pesquisa_acomodacao(urlacomodacao,urlcategoria,url_reserva,modoabertura);
	}





	/*Comandos para checks*/
	/*comando para realizar checagem, tanto check in quanto check out*/
	else if(strcmp(com,"chk") == 0){
		check(tiposave,urlcheck,urltempcheck,modoabertura,checagens(urlacomodacao,urlcategoria,urlhospede,url_reserva,urlcheck,urlconta,
		urltempconta,urlcaixa,urltempcaixa,urlcontapagar,modoabertura));
	}
	/*comando para consulta de todos os checks*/
	else if(strcmp(com,"cschk") == 0){
		consulta_checks(verificasave(),urlcheck,modoabertura);
	}
	/*comando para consulta de checks segundo um código*/
	else if(strcmp(com,"cschkc") == 0){
		int c;
		branco("Digite o código da Checagem: ");
		scanf("%i",&c);
		consulta_checks_codigo(verificasave(),urlcheck,modoabertura,c);
	}




	/*comandos para criação de contas*/
	/*comando para cria conta*/
	else if(strcmp(com,"cadct") == 0){
		cadastra_conta(urlconta,urltempconta,urlhospede,url_reserva,modoabertura);
	}
	/*comando de consulta de contas, pelo cpf*/
	else if(strcmp(com,"csct") == 0){
		char cpf[14];
		struct contas ct;
		ciano("\nConsulta de contas!\n");
		printf("Digite o CPF do hospede: ");
		scanf("%[^\n]s",cpf);
		ct.codigo_hospede = codigo_hospede_cpf(tiposave,urlhospede,modoabertura,cpf);
		conta_hospede(tiposave,urlconta,urltempconta,modoabertura,ct,-1);
	}




	/*comando de exportação*/
	else if(strcmp(com,"exparq") == 0){
		exporta_tabelas(tiposave,modoabertura);
	}
	


	/*comandos de caixa*/
	/*comando para cadastrar caixa*/
	else if(strcmp(com,"cadcx") == 0){
		salva_caixa(tiposave, urlcaixa, modoabertura, cadastra_caixa(urlhotel, modoabertura));
	}
	/*comando para abertura ou fechamento de caixa*/
	else if(strcmp(com,"caixa") == 0){
		int op;
		printf("Digite 1 para abertura, 0 para fechamento: ");
		scanf("%i",&op);
		salva_caixa(tiposave, urlcaixa, modoabertura, abertura_fechamento_caixa(urlhotel,urlcaixa, modoabertura, op));
	}
	/*comando para pagar contas*/
	else if(strcmp(com,"ctp") == 0){
		paga_contaspagar(tiposave,urlcontapagar,urltempcontapagar,urlcaixa,urltempcaixa,modoabertura);
	}



	/*Outros comandos*/
	/*comando para limpar a tela*/
	else if(strcmp(com,"lt") == 0){
		system("clear");
	}
	/*comando para dar reset na configuração*/
	else if(strcmp(com,"rconfig") == 0){
		/*avisa ao usuário a operação critica que ele está realizando*/
		amarelo("Tem certeza que deseja RESETAR a configuração do Sistema?\n: ");
		scanf("%s",resposta);
		/*verifica a resposta e caso for sim reseta a configuração*/
		if(strcmp(resposta,"Sim") || strcmp(resposta,"SIM") || strcmp(resposta,"sim")){
			resetaconfig();
		}
		else{
			/*senão aborta o processo*/
			amarelo("\nProcesso abortado!\n");
		}
	}
	/*comando help do sistema*/
	else if(strcmp(com,"help") == 0){
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("TODOS OS COMANDOS A SEGUIR SÃO EM LETRA MINUSCULA\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("USUARIO\n");
		printf("Digite cadus para cadastrar novos usuarios.\n");
		printf("Digite csus para fazer consulta de usuario.\n");
		printf("Digite edus para editar o usuario.\n");
		printf("Digite exus para excluir usuario.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("HÓSPEDE\n");
		printf("Digite cadhp para cadastrar novos hóspedes.\n");
		printf("Digite cshp para fazer consulta de hóspede.\n");
		printf("Digite edhp para editar um hóspede.\n");
		printf("Digite exhp para excluir um hóspede.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("HOTEL\n");
		printf("Digite cadht para cadastrar novos hoteis.\n");
		printf("Digite csht para fazer consulta de um hotel.\n");
		printf("Digite edht para editar um hotel.\n");
		printf("Digite exht para excluir hotel.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("PRODUTO\n");
		printf("Digite cadp para cadastrar novos produtos.\n");
		printf("Digite csp para fazer consulta de um produto.\n");
		printf("Digite edht para editar um produto.\n");
		printf("Digite exht para excluir um produto.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("FORNECEDOR\n");
		printf("Digite cadf para cadastrar novos fornecedores.\n");
		printf("Digite csf para fazer consulta de um fornecedor.\n");
		printf("Digite edf para editar um fornecedor.\n");
		printf("Digite exf para excluir um fornecedor.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("CATEGORIA\n");
		printf("Digite cadc para cadastrar uma nova categoria.\n");
		printf("Digite csc para fazer consulta de um categoria.\n");
		printf("Digite edc para editar uma categoria.\n");
		printf("Digite exc para excluir uma categoria.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("ACOMODAÇÃO\n");
		printf("Digite cadac para cadastrar uma nova acomodação.\n");
		printf("Digite csac para fazer consulta de uma acomodação.\n");
		printf("Digite edac para editar uma acomodação.\n");
		printf("Digite exac para excluir uma acomodação.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("VENDA/COMPRA DE PRODUTOS\n");
		printf("Digite cpp para comprar produtos.\n");
		printf("Digite vdp para vender produtos.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("RESERVA\n");
		printf("Digite rsv para cadastrar uma reserva.\n");
		printf("Digite csrsv consultar todas as reservas.\n");
		printf("Digite csrsvc consultar uma reserva pelo código.\n");
		printf("Digite canrsv para cancelar uma reserva.\n");
		printf("Digite psrsv para pesquisar uma acomodação pelo código.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("CHECKS\n");
		printf("Digite chk para realizar um check in ou check out.\n");
		printf("Digite cschk consultar todos os checks.\n");
		printf("Digite cschkc consultar um check pelo código.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("CONTA\n");
		printf("Digite cadct cadastrar uma conta.\n");
		printf("Digite csct uma conta pelo cpf.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("CAIXA\n");
		printf("Digite cadcx cadastrar um caixa.\n");
		printf("Digite caixa para abrir ou fechar o caixa.\n");
		printf("Digite ctp para inserir ou pagar uma conta a pagar.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("IMPORTAÇÃO/EXPORTAÇÃO\n");
		printf("Digite exparq para exportar arquivos.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
		printf("OUTROS COMANDOS\n");
		printf("Digite lt para limpar a tela.\n");
		printf("Digite rconfig para refazer as configurações iniciais do Sistema.\n");
		printf("Digite sair para sair do sistema do Sistema.\n");
		printf("\n------------------------------------------------------------------------------------------\n");
	}
	/*comando inválido*/
	else{
		vermelho("\nComando Inválido!\n\n");
	}
}

char comando[50];

/*função principal*/
int main(int argc, char** argv) {
	int verifica = 0;
	/*caso não exista, cria as pastas necessárias ao sistema*/
	system("mkdir config");
	system("mkdir saves");
	system("mkdir libs");
	/*limpa tela*/
	system("clear");
	/*um while que sempre ira rodar, ou seja o sistema executa até que o usuário mande sair*/
	while(1){
		//verifica a configuração inicial, caso não tenha sido feita, obrigatoriamente o usuário terá que faze-la.
		if(verificaconfig() == 0){
			config();
		}
		else{
			/*verifica o login e a senha*/
			while(verifica == 0){
				/*o login estiver correto com algum existente*/
				if(login() == 1){
					/*usuário conecta*/
					verifica = 1;
					verde("\nUsuário conectado com sucesso!!\n\n");
					sleep(1);
					system("clear");
				}
				else{
					/*Senão mostra a mensagem*/
					vermelho("\nLogin e/ou senha incorreto(s)!!\n\n");
					sleep(1);
					system("clear");
				}
			}
			defineconstantes();
			/*Funcoes*/
			/*Após a config feita, o usuário será direcionado para a tela de opções*/
			/*Abaixo sera a parte dos comandos relacionados ao sistema*/
			setbuf(stdin,NULL);
			/*recebe o comando*/	
			printf("Digite um comando: ");
			scanf("%[^\n]s",comando);
			setbuf(stdin,NULL);
			/*caso o comando seja sair*/
			if(strcmp(comando,"sair") == 0){
				/*conta 5 segundos e sai do sistema*/
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
	
