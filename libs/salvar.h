#ifndef SALVAR_H
#define SALVAR_H

#include "structs.h"
#include <string.h>
#include <locale.h>
#include "config.h"
/*********Comentar*******************/
/*funcao para salvar para o hospede no arquivo texto*/
void salvarhospede(int tipo){
	/*chama a struct hospede para usar as variaveis do hospede*/
	struct hospede h;
	setlocale(LC_ALL, "Portuguese");
	/*coloca um ponteiro para armazenar a localizacao do arquivo*/
	FILE *arquivo;
	switch(tipo){
		/*no primeiro caso, salva em arquivo texto*/
		case 1:
			/*abre o arquivo texto*/
			arquivo = fopen("saves/hospede.txt","a+");
			/*verifica o arquivo texto*/
			if(arquivo == NULL){
				/*se for nulo, ou seja nao foi encontrado, mostra uma mensagem de erro*/
				printf("\nErro em realizar o cadastro do hóspede no arquivo texto!!\n\n");
			}
			/*senao faz a insersao do arquivo*/
			else{
				fprintf(arquivo,"%u",h.codigo);
				fprintf(arquivo,"\n%s",h.nome);
				fprintf(arquivo,"\n%s",h.cpf);
				fprintf(arquivo,"\n%s",h.rg);
				fprintf(arquivo,"\n%s",h.rua);
				fprintf(arquivo,"\n%s",h.numero);
				fprintf(arquivo,"\n%s",h.bairro);
				fprintf(arquivo,"\n%s",h.cidadeestado.cidade);
				fprintf(arquivo,"\n%s",h.cidadeestado.estado);
				fprintf(arquivo,"\n%s",h.cep);
				fprintf(arquivo,"\n%s",h.complemento);
				fprintf(arquivo,"\n%s",h.datanascimento);
				fprintf(arquivo,"\n%s",h.telefone);
				fprintf(arquivo,"\n%s",h.celular);
				fprintf(arquivo,"\n%s",h.estadocivil);
				fprintf(arquivo,"\n%s",h.email);
				fprintf(arquivo,"\n%s\n\n",h.status);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			/*e por fim fecha o arquivo*/
			fclose(arquivo);
		break;
		/*no segundo caso, salva em binario*/
		case 2:
			//*abre o arquivo binario*//
			arquivo = fopen("saves/hospede.bin","ab");
			/*caso o arquivo nao exista o ponteiro retornara nulo*/
			if(arquivo == NULL){
				printf("Erro em realizar o cadastro do hóspede no arquivo binário!!\n\n");
			}
			/*caso exista sera inserido os dados em binario*/
			else{
				fwrite(&h,sizeof(struct hospede),1,arquivo);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			/*e por fim fecha o ponteiro*/
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}
/*void salvarhospedecsv(){
	struct hospede h;
	setlocale(LC_ALL, "Portuguese");
	FILE *arquivo;
	arquivo = fopen("saves/hospede.csv","a+");

	if(arquivo == NULL){
		printf("\nErro em realizar o cadastro do hóspede no arquivo texto!!\n\n");
	}
	else{
		fprintf(arquivo,"%u",h.codigo);
		fprintf(arquivo,";%s",h.nome);
		fprintf(arquivo,";%s",h.cpf);
		fprintf(arquivo,";%s",h.rg);
		fprintf(arquivo,";%s",h.rua);
		fprintf(arquivo,";%s",h.numero);
		fprintf(arquivo,";%s",h.bairro);
		fprintf(arquivo,";%s",h.cidadeestado.cidade);
		fprintf(arquivo,";%s",h.cidadeestado.estado);
		fprintf(arquivo,";%s",h.cep);
		fprintf(arquivo,";%s",h.complemento);
		fprintf(arquivo,";%s",h.datanascimento);
		fprintf(arquivo,";%s",h.telefone);
		fprintf(arquivo,";%s",h.celular);
		fprintf(arquivo,";%s",h.estadocivil);
		fprintf(arquivo,";%s",h.email);
		fprintf(arquivo,";%s\n",h.status);
		printf("\nDados foram salvos com sucesso!\n\n");
	}
	fclose(arquivo);
}*/
void salvarhotel(int tipo){
	//realizo a chamada da struct hotel, para ter acesso as variaveis relacionadas a essa struct
	struct hotel ht;
	//coloca o local padrão como portugues, assim pegará todos os acentos.
	setlocale(LC_ALL,"Portuguese");
	//crio uma variavel do tipo arquivo com um ponteiro para que possa criar e salvar dados em um arquivo, nesse caso txt
	FILE *arquivo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hotel.txt","a+");
			//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
			if(arquivo == NULL){
				printf("\nErro em realizar o cadastro de hotel!!\n\n");
			}
			//senão houver nenhum problema, salva os arquivos no txt que foi criado
			else{
				fprintf(arquivo,"%u",ht.codigo);
				fprintf(arquivo,"\n%s",ht.nomefantasia);
				fprintf(arquivo,"\n%s",ht.razaosocial);
				fprintf(arquivo,"\n%s",ht.cnpj);
				fprintf(arquivo,"\n%s",ht.insc);
				fprintf(arquivo,"\n%s",ht.rua);
				fprintf(arquivo,"\n%s",ht.numero);
				fprintf(arquivo,"\n%s",ht.bairro);
				fprintf(arquivo,"\n%s",ht.cidadeestado.cidade);
				fprintf(arquivo,"\n%s",ht.cidadeestado.estado);
				fprintf(arquivo,"\n%s",ht.cep);
				fprintf(arquivo,"\n%s",ht.complemento);
				fprintf(arquivo,"\n%s",ht.telefone);
				fprintf(arquivo,"\n%s",ht.email);
				fprintf(arquivo,"\n%s",ht.nomeresponsavel);
				fprintf(arquivo,"\n%s",ht.telefoneresponsavel);
				fprintf(arquivo,"\n%s\n\n",ht.status);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			//ao final do salvamento, finalizo o ponteiro e encerro o salvamento de arquivos
			fclose(arquivo);
		break;
		case 2:
			arquivo = fopen("saves/hotel.bin","ab");

			if(arquivo == NULL){
				printf("Erro em realizar o cadastro do hotel no arquivo binário!!\n\n");
			}
			else{
				fwrite(&ht,sizeof(struct hotel),1,arquivo);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}

void salvarcategorias(int tipo){
	struct categorias c;
	//chama a struct categorias para ter acesso a suas variaveis
	setlocale(LC_ALL,"Portuguese");
	//coloca como linguagem padrao a portuguesa
	FILE *arquivo;
	switch(tipo){
		case 1:
			//crio um ponteiro que apontara para a localizacao do arquivo
			arquivo = fopen("saves/categoria.txt","a+");
			//abro o arquivo
			//agora verifico se o arquivo existe, senao sera criado na hora
			//senao for criado da mensagem de erro
			if(arquivo == NULL){
				printf("\nErro em realizar o cadastro de categoria!!\n\n");
			}
			//se for criado salva os dados no arquivo txt
			else{
				fprintf(arquivo,"%u",c.codigo);
				fprintf(arquivo,"\n%s",c.descricao);
				fprintf(arquivo,"\n%.2f",c.valor);
				fprintf(arquivo,"\n%i",c.quantidadeadultos);
				fprintf(arquivo,"\n%i",c.quantidadecriancas);
				fprintf(arquivo,"\n%s\n\n",c.status);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			fclose(arquivo);
		break;
		case 2:
			arquivo = fopen("saves/categoria.bin","ab");
			if(arquivo == NULL){
				printf("\nErro em realizar o cadastro de categoria!!\n\n");
			}
			else{
				fwrite(&c,sizeof(struct categorias),1,arquivo);
				printf("\nDados foram salvos com sucesso!\n\n");
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
	
void salvaracomodacao(){
	//realizo a chamada da struct acomodacoes, para ter acesso as variaveis relacionadas a essa struct
	struct acomodacoes acomod;
	//coloca o local padrão como portugues, assim pegará todos os acentos.
	setlocale(LC_ALL,"Portuguese");
	//crio uma variavel do tipo arquivo com um ponteiro para que possa criar e salvar dados em um arquivo, nesse caso txt
	FILE *arquivo; 
	arquivo = fopen("saves/hotel.txt","a+");
	//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
	if(arquivo == NULL){
		printf("\nErro em realizar o cadastro de acomodações!!\n\n");
	}
	//senão houver nenhum problema, salva os arquivos no txt que foi criado
	else{
		
	}
}

void salvarproduto(int tipo){
	//chama a struct produtos para ter acesso as variaveis dela
	struct produtos p;
	//seta o local padrão, ou seja o idioma que deve ser interpretado como portugues
	setlocale(LC_ALL,"Portuguese");
	FILE *arquivo;
	switch(tipo){
		/*caso 1 salvar em txt*/
		case 1:
			arquivo = fopen("saves/produto.txt","a+");
			//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
			if(arquivo == NULL){
				printf("\nErro em realizar o cadastro de produtos!!\n");
			}
			//senão houver nenhum problema, salva os arquivos no txt que foi criado
			else{
				fprintf(arquivo,"%u",p.codigo);
				fprintf(arquivo,"\n%s",p.descricao);
				fprintf(arquivo,"\n%i",p.estoque);
				fprintf(arquivo,"\n%i",p.estoqueminimo);
				fprintf(arquivo,"\n%.2f",p.precocusto);
				fprintf(arquivo,"\n%.2f",p.precovenda);
				fprintf(arquivo,"\n%s\n\n",p.status);
				printf("\nDados foram salvos com sucesso!\n");
			}
			fclose(arquivo);
		break;
		/*caso 2 salvar em binario*/
		case 2:
			/*tenta abrir o arquivo*/
			arquivo = fopen("saves/produto.bin","ab");
			if(arquivo == NULL){
				printf("\nErro em realizar o cadastro de produtos!!\n");
			}
			/*se der tudo certo*/
			else{
				/*salva os dados no arquivo binario*/
				fwrite(&p,sizeof(struct produtos),1,arquivo);
				printf("\nDados foram salvos com sucesso!\n");
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	} 
	
}

void salvarusuariosbin(){
	struct usuarios u;
	//faço a chamada da struct, para ter acesso as varíaveis desta;*/
	/*coloco como linguagem obrigatória, o português, para evitar certos problemas de acentuação*/
	setlocale(LC_ALL,"Portuguese");
	FILE *arquivo;
	arquivo = fopen("saves/usuarios.bin","ab");
	//verifico a nulidade do arquivo que sera criado
	if(arquivo == NULL){
		printf("\nErro em realizar o cadastro de usuário!\n");
	}
	/*se estiver tudo ok, salva o arquivo*/
	else{
		fwrite(&u,sizeof(struct usuarios),1,arquivo);
		printf("\nDados salvos com sucesso!\n");
	}
	//fecha o ponteiro
	fclose(arquivo);
}
#endif