#ifndef PRODUTO_H
#define PRODUTO_H
#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cores.h"
/*função para realizar a entrada dos produtos e ainda calcular o preço de venda do produto*/
/*recebe por parametro o tipo de salvamento, o url e o modo de abertura*/
float* entradaprodutos(int tipo,char url[50],char modoabertura[5]){
	/*chama a struct para ter acesso as variaveis e vetores*/
	struct entradaprodutos ep;
	float valores[3];
	int quantidades = 0;
	/*cria um ponteiro do tipo arquivo para acessar o arquivo de entrada produto*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	if(arquivo == NULL){
		vermelho("\nErro em realizar a abertura do arquivo!\n");
	}
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*tipo 1, arquivo texto*/
			case 1:
			/*começa a realizar o salvamento*/
				fprintf(arquivo,"%u\n",ep.codigo);
				fprintf(arquivo,"%i\n",ep.produtos_distintos);
				/*um for para todos os produtos que foram comprados na nota*/
				for(int i = 0; i < ep.produtos_distintos; i++){
					fprintf(arquivo,"%u %u %i %f %s\n",ep.codigoproduto,ep.codigofornecedor,ep.quantidade,ep.precocusto,ep.status);
					quantidades = quantidades + ep.quantidade[i];
				}
				/*agora cadastra o restante dos produtos*/
				fprintf(arquivo,"%f\n",&ep.frete);
				fprintf(arquivo,"%f\n",&ep.imposto);
				fprintf(arquivo,"%f\n\n",&ep.totalnota);
				/*fecha o arquivo*/
				fclose(arquivo);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados salvos com sucesso!\n");
				/*pega o valor do frete a ser retornado*/
				valores[0] = ep.frete / quantidades;
				valores[1] = ep.imposto / quantidades;
			break;
		}
	}
	
	
}


#endif