#ifndef PRODUTO_H
#define PRODUTO_H
#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cores.h"
/*função para realizar a entrada dos produtos e ainda calcular o preço de venda do produto*/
/*recebe por parametro o tipo de salvamento, o url e o modo de abertura*/
float* entradaprodutos(int tipo,char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct para ter acesso as variaveis e vetores*/
	struct entradaprodutos ep;
	int quantidades = 0;
	float *valores;
	/*cria um ponteiro do tipo arquivo para acessar o arquivo de entrada produto*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	if(arquivo == NULL){
		vermelho("\nErro em realizar a abertura do arquivo!\n");
	}
	else{
		for(int i = 0; i < ep.produtos_distintos; i++){
			quantidades = quantidades + ep.quantidade[i];
		}
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*tipo 1quantidades = quantidades + ep.quantidade[i];
			/*começa a realizar o salvamento*/
				fprintf(arquivo,"%u\n",ep.codigo);
				fprintf(arquivo,"%i\n",ep.produtos_distintos);
				/*um for para todos os produtos que foram comprados na nota*/
				for(int i = 0; i < ep.produtos_distintos; i++){
					fprintf(arquivo,"%u %u %i %f %s\n",ep.codigoproduto,ep.codigofornecedor,ep.quantidade,ep.precocusto,ep.status);
				}
				/*agora cadastra o restante dos produtos*/
				fprintf(arquivo,"%f\n",&ep.frete);
				fprintf(arquivo,"%f\n",&ep.imposto);
				fprintf(arquivo,"%f\n\n",&ep.totalnota);
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
	atualiza_valorprodutos(tipo,url,modoabertura,valores,urltemp);
	return valores;
}
/*função para atualizar o valor dos produtos
recebe como parametro o ponteiro do vetor retornado pela função acima*/
void atualiza_valorprodutos(int tipo,char url[50],char modoabertura[5],char urltemp[50],float *valores){
	/*chama as structs de entrada de produtos e de produtos*/
	struct produtos p;
	struct entradaprodutos ep;
	FILE *arquivo;
	FILE *arquivo2;
	/*será lido o arquivo de produtos inteiro para, que com os dados sejam comparadas os codigos dos produtos com os codigos que estão
	na entrada de produtos e assim poder atualizar o valor do devido produto*/
	arquivo = fopen(url,modoabertura);
	arquivo = fopen(url,modoabertura);
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
					/*para evitar bugs, verifica antes de qualquer coisa se já está no final do arquivo*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,
						p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status);
					/*depois de lido um produto*/
					/*terá um for para verificar todos os códigos que estiveram na nota fiscal*/
					/*e verifica no for até achar o codigo igual ao primeiro produto lido, senão tiver, continuará lendo até o final do arquivo*/
					/*se achar, atualiza o valor de venda dele*/
					/*sai do laço for */
					for(int i = 0; i < ep.produtos_distintos; i++){
						if(p.codigo == ep.codigoproduto[i]){
							p.precovenda = ep.precocusto + valores[0] + valores[1];
							break;
						}
					}
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
					/*verifica se já está no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						break;
					}
					/*comando de leitura*/
					/*depois de lido um produto*/
					/*terá um for para verificar todos os códigos que estiveram na nota fiscal*/
					/*e verifica no for até achar o codigo igual ao primeiro produto lido, senão tiver, continuará lendo até o final do arquivo*/
					/*se achar, atualiza o valor de venda dele*/
					/*sai do laço for */
					fread(&p,sizeof(struct produtos),1,arquivo);
					for(int i = 0; i < ep.produtos_distintos; i++){
						if(p.codigo == ep.codigoproduto[i]){
							p.precovenda = ep.precocusto + valores[0] + valores[1];
							break;
						}
					}
					/*salva esses dados no arquivo temporario*/
					/*para todos os produtos, mesmo que não esteja na nota*/
					fwrite(&p,sizeof(struct produtos),1,arquivo2);
				}
				/*assim que acabar de ler o arquivo*/
				/*deve-se renomear o arquivo temporario e excluir o antigo*/
				remove(url);
				rename(urltemp,url);
				/*mostra ao usuário, mensagem de sucesso na operação*/
				verde("\nNota cadastrada com sucesso!\n");
			break;
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}

#endif