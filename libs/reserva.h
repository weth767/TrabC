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
void consulta_reserva(int tipo,char url[50],char modoabertura[5],int codigo){
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
					printf("\n---------------------------------------------------------------------\n");
				}
				
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

void consulta_reservas(int tipo,char url[50],char modoabertura[5]){
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
				printf("\n---------------------------------------------------------------------\n");
				ciano("Reservas\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
						&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,r.status);
					if(feof(arquivo)){
						break;
					}
					/*mostra a reserva lida*/
					printf("Código da Reserva: %u\n",r.codigo);
					printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
					printf("Código do Hóspede: %u\n",r.codigo_hospede);
					printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
					printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
					printf("Status da Reserva: %s\n",r.status);
					printf("\n---------------------------------------------------------------------\n");
					
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			break;
			case 2:/*arquivo binário*/
				/*while para ler o arquivo todo*/
				printf("\n---------------------------------------------------------------------\n");
				ciano("Reservas\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&r,sizeof(struct reserva),1,arquivo);
					/*printa a reserva lida, assim irá mostrar todas as reservas que forem do hospede, selecionado pelo código*/
					if(feof(arquivo)){
						break;
					}
					/*mostra a reserva lida*/
					printf("Código da Reserva: %u\n",r.codigo);
					printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
					printf("Código do Hóspede: %u\n",r.codigo_hospede);
					printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
					printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
					printf("Status da Reserva: %s\n",r.status);
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

/*função para realizar o cancelamento da reserva*/
/*recebe por parametro o tipo de salvamento, as urls, modo de abertura e o codigo*/
void cancela_reserva(int tipo,char url[50],char urltemp[50],char modoabertura[5],int codigo){
	/*struct de reserva para ter acesso as varaiveis*/
	struct reserva r;
	/*ponteiro para abrir o arquivo*/
	FILE *arquivo;
	FILE *arquivo2;
	int op = 0;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica erros na abertura do arquivo*/
	if(arquivo == NULL || arquivo2 == NULL){
		vermelho("\nErro na abertura do arquivo de Reservas!\n");
	}
	/*se estiver tudo ok, continua a execução*/
	else{
		/*switch para verificar os tipo de salvamento*/
		switch(tipo){
			/*caso 1, arquivo texto*/
			case 1:
				/*while para ler o arquivo todo*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
						&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,r.status);

					if(feof(arquivo)){
						break;
					}
					/*se o codigo lido no momento, for diferente do código digitado pelo usuário*/
					/*salva no arquivo temporario*/
					if(r.codigo != codigo){
						fprintf(arquivo2,"%u\n",r.codigo);
						fprintf(arquivo2,"%u\n",r.codigo_acomodacao);
						fprintf(arquivo2,"%u\n",r.codigo_hospede);
						fprintf(arquivo2,"%i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
						fprintf(arquivo2,"%i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
						fprintf(arquivo2,"%s\n\n",r.status);
					}
					/*se o código for igual*/
					/*mostra o código selecionado e verifica se o usuário realmente deseja cancelar*/
					else{
						azulclaro("\nReserva Selecionada: \n\n");
						printf("Código da Reserva: %u\n",r.codigo);
						printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
						printf("Código do Hóspede: %u\n",r.codigo_hospede);
						printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
						printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
						printf("Status da Reserva: %s\n",r.status);
					}
				}
				/*pergunta ao usuário se a reserva realmente vai ser cancelada*/
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a cancelamento(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*caso a resposta seja sim*/
				if(op == 1){
					/*exclui o hospode*/
					/*remove o arquivo*/
					remove(url);
					/*renomeia o temporario com os outros dados que não foram excluidos*/
					rename(urltemp,url);
					/*mostra mensagem de sucesso*/
					verde("\nReserva Cancelada com Sucesso\n\n");
				}
				else{
					remove(urltemp);
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
			break;
			case 2:/*arquivo binário*/
				/*while para ler o arquivo todo*/
				printf("\n---------------------------------------------------------------------\n");
				azulclaro("Reservas de Acordo com o Código Digitado\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&r,sizeof(struct reserva),1,arquivo);
					/*printa a reserva lida, assim irá mostrar todas as reservas que forem do hospede, selecionado pelo código*/
					if(feof(arquivo)){
						break;
					}
					if(r.codigo != codigo){
						fwrite(&r,sizeof(struct reserva),1,arquivo2);
					}
					azulclaro("\nReserva Selecionada: \n\n");
					printf("Código da Reserva: %u\n",r.codigo);
					printf("Código da Acomodação: %u\n",r.codigo_acomodacao);
					printf("Código do Hóspede: %u\n",r.codigo_hospede);
					printf("Data de Entrada: %i/%i/%i\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
					printf("Data de Saída: %i/%i/%i\n",r.data_saida.dia,r.data_saida.mes,r.data_saida.ano);
					printf("Status da Reserva: %s\n",r.status);
				}
				/*pergunta ao usuário se a reserva realmente vai ser cancelada*/
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a cancelamento(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*caso a resposta seja sim*/
				if(op == 1){
					/*exclui o hospode*/
					/*remove o arquivo*/
					remove(url);
					/*renomeia o temporario com os outros dados que não foram excluidos*/
					rename(urltemp,url);
					/*mostra mensagem de sucesso*/
					verde("\nReserva Cancelada com Sucesso\n\n");
				}
				else{
					remove(urltemp);
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
			break;
			default:
				/*mensagem de erro para opções de salvamento não implementadas*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
/*função para fazer a pesquisa das acomodações segundo as preferencias do hospede*/
/*recebe por parametro o tipo de salvamento, o url das acomodações*/
int* pesquisa_acomodacoes(int tipo,char urlacomodacoes[50],char urlcategoria[50],char urlreserva[50],char modoabertura[5],
	struct data d,int quantidade_adultos,int quantidade_criancas,int tv,int tvcabo,int arcondicionado,
	int frigobar,int banheiro,int camacasal,int camasolteiro,int banheira,int hidromassagem){
	/*verifica todos os tipos de requesitos possíveis*/
	/*cria um ponteiro de arquivo para acessar o arquivo de categorias, acomodacoes e reservas*/
	FILE *arquivo_acomodacoes;
	FILE *arquivo_categorias;
	FILE *arquivo_reservas;
	int codigos_acomodacoes[1000];
	int contador = 0;
	int cont = 0;
	/*abre os arquivos*/
	arquivo_acomodacoes = fopen(urlacomodacoes,modoabertura);
	arquivo_categorias = fopen(urlcategoria,modoabertura);
	arquivo_reservas = fopen(urlreserva,modoabertura);
	struct reserva r;
	struct acomodacoes ac;
	/*verifica erros no arquivos*/
	if(arquivo_acomodacoes == NULL || arquivo_categorias == NULL || arquivo_reservas == NULL){
		vermelho("\nErro na abertura dos arquivos necessários a realizar a pesquisa de acomodações!\n");
	}
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*salvamento no arquivo texto*/
				/*verifica quais foram as preferencias que o hospede quer*/
				while(!feof(arquivo_reservas)){
					fscanf(arquivo_reservas,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
					&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,r.status);
					/*verifica se o a data que ele o hospede pediu está disponivel*/
					if(d.dia > r.data_saida.dia){/*acrescenta as acomodações disponíveis no vetor*/
						/*faz a leitura das acomodações*/
						/*para buscar suas categorias e ter o valor e a quantidade de pessoas da acomodação no final*/

						/*ESTRUTURAR MELHOR A PESQUISA DE CATEGORIA, QUE DEPENDE DA ACOMODAÇÃO, FAZER DE FORMA QUE ISSO ACONTEÇA*/
						fscanf(arquivo_acomodacoes,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
						&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,
						&ac.extra.banheira,&ac.categoriaselecionada,ac.status);
						/*faz  leitura da categoria*/
						while(!feof(arquivo_categorias)){
							fscanf(arquivo_categorias,"%u\n %s\n %f\n %i\n %i\n %s",&ac.categoria.codigo,ac.categoria.descricao,&ac.categoria.valor,&ac.categoria.quantidadeadultos
							,&ac.categoria.quantidadecriancas,ac.categoria.status);
							if(ac.categoriaselecionada == ac.categoria.codigo){
								/*verifica a possibilidade com todas as facilidades facilidades*/
								/*verifica primeiro a quantidade de adultos que é aceita na acomodação*/
								if(ac.categoria.quantidadeadultos != quantidade_adultos){
									/*se for diferente da qual o hospede deseja*/
									/*adiciona o codigo dessa acomodação no vetor*/
									codigos_acomodacoes[contador] = ac.codigo;
									contador++;
								}
								/*verifica a segunda condição possivel, se ela é igual a qual o hospede deseja*/
								if(ac.categoria.quantidadecriancas != quantidade_criancas){
									/*se for diferente*/
									/*salva também do vetor*/
									codigos_acomodacoes[contador] = ac.codigo;
									contador++;
								}
							}
						}
						
						/*verifica a terceira condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.tv != tv){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a quarta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.tvcabo != tvcabo){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a quinta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.arcondicionado != arcondicionado){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a sexta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.frigobar != frigobar){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a setima condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.banheiro != banheiro){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica oitava condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.camacasal != camacasal){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a nona condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.camasolteiro != camasolteiro){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a decima condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.banheira != banheira){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a decima primeira condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.hidromassagem != hidromassagem){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
					}
				}
				/*mostra ao usuário as acomodações que atendem as prefencias do hospede e estão disponiveis na data requisitada*/
				azulclaro("\nAcomodações que atendem as preferencias do hospede: \n\n");
				while(!feof(arquivo_acomodacoes)){
					/*le as acomodações cadastradas*/
					cont = 0;
					fscanf(arquivo_acomodacoes,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
						&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,
						&ac.extra.banheira,&ac.categoriaselecionada,ac.status);
					/*e como um for, verifica cada codigo das não validas*/
					for(int i = 0; i < contador; i++){
						if(ac.codigo != codigos_acomodacoes[i]){
							/*conta as iterações e para evitar repetições mostra depois a acomodação que atende os requisitos*/
							cont++;
						}
					}
					/*e mostra na tela as que são diferentes da não validas*/
					if(cont >= 1){
						printf("Acomodação: %i\n",ac.codigo);	
					}
				}
				/*fecha os arquivos*/
				fclose(arquivo_reservas);
				fclose(arquivo_acomodacoes);
				fclose(arquivo_categorias);
				/*e finalmente retorna o vetor de codigos de acomodacoes invalidas*/
			break;


			case 2:/*salvamento no arquivo binario*/
				/*verifica quais foram as preferencias que o hospede quer*/
				while(!feof(arquivo_reservas)){
					fread(&r,sizeof(struct reserva),1,arquivo_reservas);
					/*verifica se o a data que ele o hospede pediu está disponivel*/
					if(d.dia > r.data_saida.dia){/*acrescenta as acomodações disponíveis no vetor*/
						/*faz a leitura das acomodações*/
						/*para buscar suas categorias e ter o valor e a quantidade de pessoas da acomodação no final*/

						/*ESTRUTURAR MELHOR A PESQUISA DE CATEGORIA, QUE DEPENDE DA ACOMODAÇÃO, FAZER DE FORMA QUE ISSO ACONTEÇA*/
						fread(&ac,sizeof(struct acomodacoes),1,arquivo_acomodacoes);
						/*faz  leitura da categoria*/
						while(!feof(arquivo_categorias)){
							fread(&ac.categoria,sizeof(struct categorias),1,arquivo_categorias);
							if(ac.categoriaselecionada == ac.categoria.codigo){
								/*verifica a possibilidade com todas as facilidades facilidades*/
								/*verifica primeiro a quantidade de adultos que é aceita na acomodação*/
								if(ac.categoria.quantidadeadultos != quantidade_adultos){
									/*se for diferente da qual o hospede deseja*/
									/*adiciona o codigo dessa acomodação no vetor*/
									codigos_acomodacoes[contador] = ac.codigo;
									contador++;
								}
								/*verifica a segunda condição possivel, se ela é igual a qual o hospede deseja*/
								if(ac.categoria.quantidadecriancas != quantidade_criancas){
									/*se for diferente*/
									/*salva também do vetor*/
									codigos_acomodacoes[contador] = ac.codigo;
									contador++;
								}
							}
						}
						
						/*verifica a terceira condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.tv != tv){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a quarta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.tvcabo != tvcabo){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a quinta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.arcondicionado != arcondicionado){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a sexta condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.frigobar != frigobar){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a setima condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.banheiro != banheiro){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica oitava condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.camacasal != camacasal){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a nona condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.camasolteiro != camasolteiro){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a decima condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.banheira != banheira){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
						/*verifica a decima primeira condição possivel, se ela é igual a qual o hospede deseja*/
						if(ac.extra.hidromassagem != hidromassagem){
							codigos_acomodacoes[contador] = ac.codigo;
							contador++;
							/*se for diferente da qual o hospede deseja*/
							/*adiciona o codigo dessa acomodação no vetor*/
						}
					}
				}
				/*mostra ao usuário as acomodações que atendem as prefencias do hospede e estão disponiveis na data requisitada*/
				azulclaro("\nAcomodações que atendem as preferencias do hospede: \n\n");
				while(!feof(arquivo_acomodacoes)){
					/*le as acomodações cadastradas*/
					cont = 0;
					fread(&ac,sizeof(struct acomodacoes),1,arquivo_acomodacoes);
					/*e como um for, verifica cada codigo das não validas*/
					for(int i = 0; i < contador; i++){
						if(ac.codigo != codigos_acomodacoes[i]){
							/*conta as iterações e para evitar repetições mostra depois a acomodação que atende os requisitos*/
							cont++;
						}
					}
					/*e mostra na tela as que são diferentes da não validas*/
					if(cont >= 1){
						printf("Acomodação: %i\n",ac.codigo);	
					}
				}
				/*fecha os arquivos*/
				fclose(arquivo_reservas);
				fclose(arquivo_acomodacoes);
				fclose(arquivo_categorias);
				/*e finalmente retorna o vetor de codigos de acomodacoes invalidas*/
		}
	}
}
#endif	