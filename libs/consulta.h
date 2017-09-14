#ifndef CONSULTA_H
#define CONSULTA_H

#include <string.h>
#include <stdio.h>
#include "structs.h"

/*caminho absoluto dos arquivos txt*/
char urlhospede[] = "saves/hospede.txt";
char urlhotel[] = "saves/hotel.txt";
char urlproduto[] = "saves/produto.txt";
char urlcategoria[] = "saves/categoria.txt";

/*funcao para realizar a consulta do hospede*/
void consultahospedetxt(){
	/*faço a chamada da struct, para ter acesso as variaveis do hospede*/
	struct hospede h;
	//crio um ponteiro do tipo arquivo para poder guardar a posicao dos dados do arquivo na memoria
	FILE *arquivo;
	/*abro o arquivo em modo de somente leitura*/
	arquivo = fopen(urlhospede,"r");
	//verifico se ele foi aberto
	if(arquivo == NULL){
		printf("\nErro em realizar a consulta ou Não foram encontrados hospedes cadastrados\n\n");
	}
	else{
		/*padronizo os dados que serao buscados*/
		printf("\nDados dos Usuários\n\n");
		while( fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
			h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
				/*E vou listando os itens para o usuario em forma de lista*/
				printf("Código: %u",h.codigo);
				printf("\nNome: %s",h.nome);
				printf("\nCPF: %s",h.cpf);
				printf("\nRG: %s",h.rg);
				printf("\nRua: %s",h.rua);
				printf("\nNumero: %s",h.numero);
				printf("\nBairro: %s",h.bairro);
				printf("\nCidade: %s",h.cidadeestado.cidade);
				printf("\nEstado: %s",h.cidadeestado.estado);
				printf("\nCEP: %s",h.cep);
				printf("\nComplemento: %s",h.complemento);
				printf("\nData de Nascimento: %s",h.datanascimento);
				printf("\nTelefone: %s",h.telefone);
				printf("\nCelular: %s",h.celular);
				printf("\nEstado Cívil: %s",h.estadocivil);
				printf("\nE-Mail: %s",h.email);
				printf("\nStatus: %s\n\n",h.status);
		}
		/*e no fim fecho o ponteiro do arquivo*/
		fclose(arquivo);
	}	
}

void consultahospedebin(){
	struct hospede h;
	FILE *arquivo;
	arquivo = fopen("saves/hospede.bin","rb");
	if(arquivo == NULL){
		printf("\nErro em realizar a consulta ou Não Foram encontrados hospedes cadastrados\n\n");
	}
	else{
		fread(&h,sizeof(struct hospede),1,arquivo);
		printf("Código: %u",h.codigo);
		printf("\nNome: %s",h.nome);
		printf("\nCPF: %s",h.cpf);
		printf("\nRG: %s",h.rg);
		printf("\nRua: %s",h.rua);
		printf("\nNumero: %s",h.numero);
		printf("\nBairro: %s",h.bairro);
		printf("\nCidade: %s",h.cidadeestado.cidade);
		printf("\nEstado: %s",h.cidadeestado.estado);
		printf("\nCEP: %s",h.cep);
		printf("\nComplemento: %s",h.complemento);
		printf("\nData de Nascimento: %s",h.datanascimento);
		printf("\nTelefone: %s",h.telefone);
		printf("\nCelular: %s",h.celular);
		printf("\nEstado Cívil: %s",h.estadocivil);
		printf("\nE-Mail: %s",h.email);
		printf("\nStatus: %s\n\n",h.status);
	}
	fclose(arquivo);
}

void consultahoteltxt(){
	struct hotel ht;
	FILE *arquivo;
	arquivo = fopen(urlhotel,"r");
	if(arquivo == NULL){
		printf("Erro em realizar a consulta ou Não foram encontrados hotéis cadastrados\n\n");	
	}
	else{
		printf("\nDados do(s) Hotel(éis)\n\n");
		while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
			ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){

			printf("Código: %u",ht.codigo);
			printf("\nRazão Social: %s",ht.razaosocial);
			printf("\nNome Fantasia: %s",ht.nomefantasia);
			printf("\nCNPJ: %s",ht.cnpj);
			printf("\nInscrição Estadual: %s",ht.insc);
			printf("\nRua: %s",ht.rua);
			printf("\nNumero: %s",ht.numero);
			printf("\nBairro: %s",ht.bairro);
			printf("\nCidade: %s",ht.cidadeestado.cidade);
			printf("\nEstado: %s",ht.cidadeestado.estado);
			printf("\nCEP: %s",ht.cep);
			printf("\nComplemento: %s",ht.complemento);
			printf("\nTelefone: %s",ht.telefone);
			printf("\nE-Mail: %s",ht.email);
			printf("\nNome do Responsável: %s",ht.nomeresponsavel);
			printf("\nTelefone do Responsável: %s",ht.telefoneresponsavel);
			printf("\nStatus: %s\n\n",ht.status);
		}
		fclose(arquivo);
	}	
}

void consultahotelbin(){
	struct hotel ht;
	FILE *arquivo;
	arquivo = fopen("saves/hotel.bin","rb");
	if(arquivo == NULL){
		printf("\nErro em realizar a consulta ou Não Foram encontrados hoteis cadastrados\n\n");
	}
	else{
		fread(&ht,sizeof(struct hotel),1,arquivo);
		printf("Código: %u",ht.codigo);
		printf("\nRazão Social: %s",ht.razaosocial);
		printf("\nNome Fantasia: %s",ht.nomefantasia);
		printf("\nCNPJ: %s",ht.cnpj);
		printf("\nInscrição Estadual: %s",ht.insc);
		printf("\nRua: %s",ht.rua);
		printf("\nNumero: %s",ht.numero);
		printf("\nBairro: %s",ht.bairro);
		printf("\nCidade: %s",ht.cidadeestado.cidade);
		printf("\nEstado: %s",ht.cidadeestado.estado);
		printf("\nCEP: %s",ht.cep);
		printf("\nComplemento: %s",ht.complemento);
		printf("\nTelefone: %s",ht.telefone);
		printf("\nE-Mail: %s",ht.email);
		printf("\nNome do Responsável: %s",ht.nomeresponsavel);
		printf("\nTelefone do Responsável: %s",ht.telefoneresponsavel);
		printf("\nStatus: %s\n\n",ht.status);
	}
	fclose(arquivo);
}

void consultaproduto(){
	struct produtos p;
	FILE *arquivo;
	arquivo = fopen(urlproduto,"r");
	if(arquivo == NULL){
		printf("Erro em realizar a consulta ou Não foram encontrados produtos cadastrados");
	}
	else{
		printf("\nDados do(s) Produto(s)\n\n");
		while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.precocusto,&p.precovenda,p.status)!= EOF){
			printf("Código: %u",p.codigo);
			printf("\nDescrição: %s",p.descricao);
			printf("\nEstoque: %i",p.estoque);
			printf("\nEstoque Minimo: %i",p.estoqueminimo);
			printf("\nPreço de Custo: R$%.2f",p.precocusto);
			printf("\nPreço de Venda: R$%.2f",p.precocusto);
			printf("\nStatus: %s\n\n",p.status);
		}
		fclose(arquivo);		
	}
}


int codigohospede(){
	int codigo = 0;
	FILE *arquivo;
	arquivo = fopen(urlhospede,"a+");
	if(arquivo == NULL){
		codigo = 0;
	}
	else{
		while(fscanf(arquivo,"%u\n",&codigo)!= EOF){
			fgetc(arquivo);
		}
		codigo++;
		
	}
	fclose(arquivo);
	
	return codigo;
}

int codigohotel(){
	int codigo = 0;
	FILE *arquivo;
	arquivo = fopen(urlhotel,"a+");
	if(arquivo == NULL){
		codigo = 0;
	}
	else{
		while(fscanf(arquivo,"%u\n",&codigo)!= EOF){
			fgetc(arquivo);
		}
		codigo++;
		
	}
	fclose(arquivo);
	return codigo; 
}

int codigoproduto(){
	struct produtos p;
	FILE *arquivo;
	int codigo;
	arquivo = fopen(urlproduto,"a+");
	if(arquivo == NULL){
		codigo = 0;
	}
	else{
		while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.precocusto,&p.precovenda,p.status)!= EOF){
			codigo = p.codigo;
		}
		codigo++;
		fclose(arquivo);		
	}
	return codigo;
}

int codigocategoria(){
	struct categorias c;
	FILE *arquivo;
	int codigo;
	arquivo = fopen(urlcategoria,"a+");
	if(arquivo == NULL){
		codigo = 0;
	}
	else{
		while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s\n",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status)!= EOF){
			codigo = c.codigo;
		}
		codigo++;
		fclose(arquivo);		
	}
	return codigo;
}

int codigousuario(){
	struct usuarios u;
	FILE *arquivo;
	int codigo;
	arquivo = fopen("saves/usuarios.bin","rb");
	if(arquivo == NULL){
		codigo = 0;
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
		}
		fclose(arquivo);
	}
	codigo = u.codigo;
	codigo++;
	return codigo;

}

int verificausuario(char login[20],char senha[20]){
	struct usuarios u;
	FILE *arquivo;
	int verifica = 0;
	arquivo = fopen("saves/usuarios.bin","rb");
	if(arquivo == NULL){
		printf("\nErro na verificação de usuário!!\n");
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if((strcmp(login,u.login) == 0) && (strcmp(senha,u.senha) == 0)){
				verifica = 1;
			}
		}
		return verifica;
		fclose(arquivo);
	}
}
#endif 