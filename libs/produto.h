#ifndef PRODUTO_H
#define PRODUTO_H
#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cores.h"
#include <locale.h>
/*função para realizar a entrada dos produtos e ainda calcular o preço de venda do produto*/
/*recebe por parametro o tipo de salvamento, o url e o modo de abertura*/
float* entrada_produtos(int tipo,char url[50],char modoabertura[5],struct entradaprodutos ep){
	/*chama a struct para ter acesso as variaveis e vetores*/
	int quantidades = 0;
	float *valores;
	setlocale(LC_ALL, "Portuguese");
	/*cria um ponteiro do tipo arquivo para acessar o arquivo de entrada produto*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	if(arquivo == NULL){
		vermelho("\nErro em realizar a abertura do arquivo!\n");
	}
	/*se estiver ok, continua a execução*/
	else{
		/*um for para atualizar a quantidades de produtos*/
		for(int i = 0; i < ep.produtos_distintos; i++){
			quantidades = quantidades + ep.quantidade[i];
		}
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:
			/*tipo 1 arquivo texto
			/*começa a realizar o salvamento*/
				fprintf(arquivo,"%u\n",ep.codigo);
				fprintf(arquivo,"%i\n",ep.produtos_distintos);
				/*um for para todos os produtos que foram comprados na nota*/
				for(int i = 0; i < ep.produtos_distintos; i++){
					fprintf(arquivo,"%u,",ep.codigoproduto[i]);
					fprintf(arquivo,"%u,",ep.codigofornecedor[i]);
					fprintf(arquivo,"%i,",ep.quantidade[i]);
					fprintf(arquivo,"%f,",ep.precocusto[i]);
					fprintf(arquivo,"%s\n",ep.status[i]);
				}
				fprintf(arquivo,"%i/%i/%i\n",ep.data_entrada.dia,ep.data_entrada.mes,ep.data_entrada.ano);
				/*agora cadastra o restante dos produtos*/
				fprintf(arquivo,"%f\n",ep.frete);
				fprintf(arquivo,"%f\n",ep.imposto);
				fprintf(arquivo,"%f\n\n",ep.totalnota);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados salvos com sucesso!\n");
			break;
			/*caso for o tipo 2, arquivo binario*/
			case 2:
			/*começa a realizar o salvamento*/
				fwrite(&ep,sizeof(struct entradaprodutos),1,arquivo);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados salvos com sucesso!\n");
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
	/*aloca espaços para o ponteiro do vetor que foi passado com parametro*/
	valores = (float *)malloc(2 * sizeof(float));
	/*e atribui valores nele*/
	valores[0] = ep.frete / quantidades;
	valores[1] = ep.imposto / quantidades;
	/*retorna esses valores*/
	return &valores[0];
}
/*função para atualizar o valor dos produtos
recebe como parametro o ponteiro do vetor retornado pela função acima*/
void atualiza_valorprodutos(int tipo,char url[50],char modoabertura[5],char urltemp[50],float *valores,struct entradaprodutos ep){
	/*chama as structs de produtos*/
	struct produtos p;
	FILE *arquivo;
	FILE *arquivo2;
	/*será lido o arquivo de produtos inteiro para, que com os dados sejam comparadas os codigos dos produtos com os codigos que estão
	na entrada de produtos e assim poder atualizar o valor do devido produto*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verificar a integridade da abertura do arquivo*/
	if(arquivo == NULL || arquivo2 == NULL){
		vermelho("\nErro em realizar a abertura do arquivo!\n");
	}
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*no caso 1, o salvamento é arquivo texto*/
			case 1:
				/*faz a leitura do arquivo para pegar todos os dados de todos os produtos já cadastrados*/
				/*enquanto não for o final do arquivo continua a leitura*/
				while(!feof(arquivo)){			
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,
						p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status);
					/*para evitar bugs, verifica antes de qualquer coisa se já está no final do arquivo*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					/*mostra as informações antigas*/
					printf("\n----------------------------------------------------------------------------\n");
					ciano("Informações Antigas do Produto: \n\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nLucro: %.2f%%",p.lucro);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*depois de lido um produto*/
					/*terá um for para verificar todos os códigos que estiveram na nota fiscal*/
					/*e verifica no for até achar o codigo igual ao primeiro produto lido, senão tiver, continuará lendo até o final do arquivo*/
					/*se achar, atualiza o valor de venda dele*/
					/*sai do laço for */
					for(int i = 0; i < ep.produtos_distintos; i++){
						/*atualiza o preço e o estoque apos a compra*/
						if(p.codigo == ep.codigoproduto[i]){
							p.precovenda = p.precovenda + valores[0] + valores[1];
							p.precovenda = p.precovenda + (p.precovenda * p.lucro);
							p.estoque += ep.quantidade[i];
						}
					}
					/*mostra a informação atualizada*/
					printf("\n----------------------------------------------------------------------------\n");
					ciano("Informações Novas do Produto: \n\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nLucro: %.2f%%",p.lucro);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*salva esses dados no arquivo temporario*/
					/*para todos os produtos, mesmo que não esteja na nota*/
					fprintf(arquivo2,"%u",p.codigo);
					fprintf(arquivo2,"\n%s",p.descricao);
					fprintf(arquivo2,"\n%i",p.estoque);
					fprintf(arquivo2,"\n%i",p.estoqueminimo);
					fprintf(arquivo2,"\n%.2f",p.lucro);
					fprintf(arquivo2,"\n%.2f",p.precovenda);
					fprintf(arquivo2,"\n%s\n\n",p.status);
				}
				fclose(arquivo);
				fclose(arquivo2);
				/*assim que acabar de ler o arquivo*/
				/*deve-se renomear o arquivo temporario e excluir o antigo*/
				remove(url);
				rename(urltemp,url);
				/*mostra ao usuário, mensagem de sucesso na operação*/
				verde("\nNota cadastrada com sucesso!\n");
			break;
			/*caso 2, arquivo binário*/
			case 2:
				/*um while para ler o arquivo até seu final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					/*depois de lido um produto*/
					/*terá um for para verificar todos os códigos que estiveram na nota fiscal*/
					/*e verifica no for até achar o codigo igual ao primeiro produto lido, senão tiver, continuará lendo até o final do arquivo*/
					/*se achar, atualiza o valor de venda dele*/
					/*sai do laço for */
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					/*mostra a informação antiga*/
					printf("\n----------------------------------------------------------------------------\n");
					ciano("Informações Antigas do Produto: \n\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nLucro: %.2f%%",p.lucro);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					for(int i = 0; i < ep.produtos_distintos; i++){
						/*atualiza o preço e o estoque após a compra*/
						if(p.codigo == ep.codigoproduto[i]){
							p.precovenda = ep.precocusto[i] + valores[0] + valores[1];
							p.estoque += ep.quantidade[i];
						}
					}
					/*mostra a informação atualizada*/
					printf("\n----------------------------------------------------------------------------\n");
					ciano("Informações Novas do Produto: \n\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição:%s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nLucro: %.2f%%",p.lucro);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*salva esses dados no arquivo temporario*/
					/*para todos os produtos, mesmo que não esteja na nota*/
					fwrite(&p,sizeof(struct produtos),1,arquivo2);
				}
				fclose(arquivo);
				fclose(arquivo2);
				/*assim que acabar de ler o arquivo*/
				/*deve-se renomear o arquivo temporario e excluir o antigo*/
				remove(url);
				rename(urltemp,url);
				/*mostra ao usuário, mensagem de sucesso na operação*/
				verde("\nNota cadastrada com sucesso!\n");
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
/*função que atualiza a quantidade de produtos a cada compra*/
/*recebe como parametro o tipo de salvamento, a url do produto, o modo de abertura e a struct de saida de produtos*/
void atualiza_quantidadeprodutos(int tipo,char url[50],char urltemp[50],char modoabertura[5],struct saidaprodutos sp){
	/*struct de produtos para fazer uso de suas variaveis*/
	struct produtos p;
	/*cria o ponteiro, para acessar o arquivo*/
	FILE *arquivo;
	FILE *arquivo2;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		/*mostra mensagem de erro*/
		vermelho("\nErro em realizar a abertura do arquivo de produtos!\n");
	}
	else{
		/*se estiver tudo ok, verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*ARQUIVO TEXTO*/
				/*um while para ler o arquivo todo até seu final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,
						p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status);
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}
					/*um for que vai de 0 até a quantidade de produtos distintos - 1*/
					for(int i = 0; i < sp.produtos_distintos; i++){
						/*verifica o codigo do produto lido, se está em um dos produtos comprados*/
						if(p.codigo == sp.codigoproduto[i]){
							/*se estiver, atualiza sua quantidade*/
							p.estoque = p.estoque - sp.quantidade[i];
						}
					}
					/*salva os dados no arquivo temporario*/
					fprintf(arquivo2,"%u",p.codigo);
					fprintf(arquivo2,"\n%s",p.descricao);
					fprintf(arquivo2,"\n%i",p.estoque);
					fprintf(arquivo2,"\n%i",p.estoqueminimo);
					fprintf(arquivo2,"\n%.2f",p.lucro);
					fprintf(arquivo2,"\n%.2f",p.precovenda);
					fprintf(arquivo2,"\n%s\n\n",p.status);
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
				/*assim que acabar de ler o arquivo*/
				/*deve-se renomear o arquivo temporario e excluir o antigo*/
				remove(url);
				rename(urltemp,url);
				/*mostra ao usuário, mensagem de sucesso na operação*/
				verde("\nQuantidade de produtos atulizada com sucesso!\n");
			break;
			case 2:/*ARQUIVO BINÀRIO*/
				/*um while para ler o arquivo todo até seu final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&p,sizeof(struct produtos),1,arquivo);
					/*verifica o final do arquivo para evitar repetições*/
					if(feof(arquivo)){
						break;
					}
					/*um for que vai de 0 até a quantidade de produtos distintos - 1*/
					for(int i = 0; i < sp.produtos_distintos; i++){
						/*verifica o codigo do produto lido, se está em um dos produtos comprados*/
						if(p.codigo == sp.codigoproduto[i]){
							/*se estiver, atualiza sua quantidade*/
							p.estoque = p.estoque - sp.quantidade[i];
						}
					}
					/*salva os dados no arquivo temporario*/
					fwrite(&p,sizeof(struct produtos),1,arquivo2);
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
				/*assim que acabar de ler o arquivo*/
				/*deve-se renomear o arquivo temporario e excluir o antigo*/
				remove(url);
				rename(urltemp,url);
				/*mostra ao usuário, mensagem de sucesso na operação*/
				verde("\nQuantidade de produtos atulizada com sucesso!\n");
			break;
			/*erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

/*função para a saída de produtos, ou seja, para a venda dos produtos no hotel*/
void saida_produtos(int tipo,char url[50],char modoabertura[5],struct saidaprodutos sp){
	/*chama a struct de saida de produtos, para ter acesso a suas variáveis*/
	/*cria um ponteiro do tipo arquivo, para acessar o arquivo de produtos futuramente*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifico se o arquivo abriu corretamente, se não abriu, mostro mensagem de erro na tela*/
	if(arquivo == NULL){
		vermelho("\nErro em realizar a abertura do arquivo!\n");
	}
	/*se o arquivo abriu ok, continua a execução*/
	else{
		/*verifico o tipo de salvamento*/
		switch(tipo){
			/*caso for o tipo 1, o salvamento é em arquivo texto*/
			case 1:
				/*salva os dados da venda do produto*/
				fprintf(arquivo,"%u\n",sp.codigo);
				fprintf(arquivo,"%i\n",sp.produtos_distintos);
				for(int i = 0; i < sp.produtos_distintos; i++){
					fprintf(arquivo,"%u %i %f %s\n",sp.codigoproduto[i],sp.quantidade[i],sp.precovenda[i],sp.status[i]);
				}
				fprintf(arquivo,"%i/%i/%i\n",sp.data_saida.dia,sp.data_saida.mes,sp.data_saida.ano);
				fprintf(arquivo,"%f\n\n",sp.totalpagar);
				/*fecha o arquivo e mostra mensagem de sucesso*/
				fclose(arquivo);
				verde("\nDados salvos com sucesso!\n");
			break;
			/*caso 2, arquivo binário*/
			case 2:
				/*salva os dados no arquivo*/
				fwrite(&sp,sizeof(struct saidaprodutos),1,arquivo);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados salvos com sucesso!\n");
			break;
			/*opção de salvamento invalida*/
			default:
				vermelho("\nOpção de salvamento não implementada!\n");
			break;

		}
	}
}

/*função para retornar os valores de todos os produtos cadastrados no arquivo*/
/*recebe por parametro o url do produto, o modo de abertura, e o tipo de salvamento*/
float retorna_valoresprodutos(int tipo, char url[50], char modoabertura[5],int codigo){
	/*chama a struct de saida de produtos e de produtos para acessar suas variaveis*/
	struct produtos p;
	float valor = 0;
	/*cria um ponteiro, de arquivo para acessar o arquivo de produto*/
	FILE *arquivo;
	/*abre o arquivo de produto, para acessar os valores de venda dos produtos*/
	arquivo = fopen(url,modoabertura);
	/*verifica se o arquivo foi aberto com sucesso*/
	if(arquivo == NULL){
		/*se der problema, mostra mensagem de erro */
		vermelho("\nErro em realizar abertura do arquivo!\n");
	}
	/*se estiver tudo ok, continua a execução da função*/
	else{
		/*verifica o tipo de salvamento que está configurado*/
		switch(tipo){
			case 1:/*caso 1, salvamento em arquivo texto*/
				/*um while para ler o arquivo até seu final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,
						&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status);
					/*verifica se o codigo que o usuário ou descrição digitados foram encontrados*/
					if(p.codigo == codigo){ 
						valor = p.precovenda;
					}
					/*verifica se já está no final do arquivo para evitar repetições indesejadas*/
					if(feof(arquivo)){
						/*sai do laço*/
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				return valor;
			break;
			case 2:
				/*um while para ler o arquivo até seu final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(p.codigo == codigo){ 
						valor = p.precovenda;
					}
					/*verifica se já está no final do arquivo, para evitar repetições*/
					if(feof(arquivo)){
						/*sai do laço*/
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				return valor;
			break;
			default:
				/*opção de salvamento não valida*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
/*função para mostrar quanto foi ganho ao todo no hotel*/
/*recebe por parametro o tipo de salvamento, o url de saida de produtos e o modo de abertura*/
void relatorio_vendas(int tipo,char url[50],char modoabertura[5]){
	/*cria um ponteiro de arquivo, para poder abrir o arquivo de saida de produtos*/
	FILE *arquivo;
	/*chama a struct de saida de produtos para armazenar os dados lidos*/
	struct saidaprodutos sp;
	float soma_ganhos = 0;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica a nulidade do arquivo*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de saida de produtos!\n");
	}
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*caso 1, arquivo texto*/
			case 1:
				/*um while para ler o arquivo todo até seu final*/
				while(!feof(arquivo)){
					printf("\n----------------------------------------------------------------------------\n");
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %i\n",&sp.codigo,&sp.produtos_distintos);
					printf("Código: %u\n",sp.codigo);
					printf("Produtos Distintos: %i\n",sp.produtos_distintos);
					/*depois de lido a quantidade de produtos distintos*/
					/*le os outros dados que estão em forma de vetores*/
					for(int i = 0; i < sp.produtos_distintos; i++){
						/*le o resto dos dados*/
						fscanf(arquivo,"%u,%i,%f,%s\n",&sp.codigoproduto[i],&sp.quantidade[i],&sp.precovenda[i],sp.status[i]);
						printf("\tCódigo do Produto: %u\n",sp.codigoproduto[i]);
						printf("\tQuantidade do Produto: %i\n",sp.quantidade[i]);
						printf("\tPreço de Venda: R$%.2f\n",sp.precovenda[i]);
						printf("\tStatus do Produto: %s\n",sp.status[i]);
						/*verifica antes, se já está no final do arquivo para evitar erros*/
						
					}
					fscanf(arquivo,"%f\n\n",&sp.totalpagar);
					printf("Total Pago: R$%.2f\n",sp.totalpagar);
					soma_ganhos += sp.totalpagar;
					printf("\n----------------------------------------------------------------------------\n");
					/*verifica antes, se já está no final do arquivo para evitar erros*/
					if(feof(arquivo)){
							break;
					}
				}
				fclose(arquivo);
				printf("\n----------------------------------------------------------------------------\n");
				printf("TOTAL DE GANHOS: R$%.2f\n",soma_ganhos);
				printf("\n----------------------------------------------------------------------------\n");
			break;
			/*caso 2, arquivo binário*/
			case 2:
				/*um while para ler o arquivo todo até seu final*/
				while(!feof(arquivo)){
					printf("\n----------------------------------------------------------------------------\n");
					/*comando de leitura*/
					fread(&sp,sizeof(struct saidaprodutos),1,arquivo);
					/*verifica antes, se já está no final do arquivo para evitar erros*/
					if(feof(arquivo)){
							break;
					}
					printf("Código: %u\n",sp.codigo);
					printf("Produtos Distintos: %i\n",sp.produtos_distintos);
					/*depois de lido a quantidade de produtos distintos*/
					/*le os outros dados que estão em forma de vetores*/
					for(int i = 0; i < sp.produtos_distintos; i++){
						printf("\tCódigo do Produto: %u\n",sp.codigoproduto[i]);
						printf("\tQuantidade do Produto: %i\n",sp.quantidade[i]);
						printf("\tPreço de Venda: R$%.2f\n",sp.precovenda[i]);
						printf("\tStatus do Produto: %s\n",sp.status[i]);
						/*verifica antes, se já está no final do arquivo para evitar erros*/
						
					}
					printf("Total Pago: R$%.2f\n",sp.totalpagar);
					soma_ganhos += sp.totalpagar;
					printf("\n----------------------------------------------------------------------------\n");
					
				}
				fclose(arquivo);
				printf("\n----------------------------------------------------------------------------\n");
				printf("TOTAL DE GANHOS: R$%.2f\n",soma_ganhos);
				printf("\n----------------------------------------------------------------------------\n");
			break;
			default:
				/*opção de salvamento não valida*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

#endif