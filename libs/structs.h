#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*structs diretamente importantes ao sistema, possuem status*/
/*struct de cidade e estado*/
struct cidadeestado{
	unsigned int codigo;
	char cidade[40];
	char estado[30];
	char status[20];
};
/*struct de hospedes*/
struct hospede{
	unsigned int codigo;
	char nome[50];
	int sexo;
	char cpf[14];
	char rg[20];
	char rua[40];
	char numero[6];
	char bairro[50];
	struct cidadeestado cidadeestado;
	char cep[13];
	char complemento[50];
	char datanascimento[10];
	char telefone[14];
	char celular[15];
	char estadocivil[15];
	char email[50];
	char status[20];
};
/*struct para os hoteis*/
struct hotel{
	unsigned int codigo;
	char razaosocial[50];
	char nomefantasia[50];
	char cnpj[20];
	char insc[20];
	char rua[40];
	char numero[6];
	char bairro[50];
	struct cidadeestado cidadeestado;
	char cep[13];
	char complemento[50];
	char telefone[14];
	char email[50];
	char nomeresponsavel[50];
	char telefoneresponsavel[14];
	char status[20];
};
/*struct para as categorias*/
struct categorias{
	unsigned int codigo;
	char descricao[50];
	float valor;
	int quantidadeadultos;
	int quantidadecriancas;
	char status[20];
};

struct extras{
	int tv;
	int tvcabo;
	int arcondicionado;
	int frigobar;
	int banheiro;
	int camacasal;
	int camasolteiro;
	int hidromassagem;
	int banheira;
};
/*struct para as acomodações*/
struct acomodacoes{
	unsigned int codigo;
	char descricao[50];
	int categoriaselecionada;
	struct extras extra;
	struct categorias categoria;
	char status[20];
};
/*struct para os produtos*/
struct produtos{
	unsigned int codigo;
	char descricao[50];
	int estoque;
	int estoqueminimo;
	float precocusto;
	float precovenda;
	char status[20];
};
/*struct para os forncedores*/
struct fornecedores{
	unsigned int codigo;
	char nomefantasia[50];
	char razaosocial[50];
	char cnpj[20];
	char insc[20];
	char rua[40];
	char numero[6];
	char bairro[50];
	struct cidadeestado cidadeestado;
	char cep[13];
	char complemento[50];
	char telefone[14];
	char celular[15];
	char email[50];
	char nrepresentante[50];
	char trepresentante[14];
	char status[20];
};
/*struct para os usuários*/
struct usuarios{
	unsigned int codigo;
	char nome[50];
	char login[25];
	char senha[25];
	int permissao;
	char status[20];
};
/*struct para as configurações iniciais*/
struct config{
	int opcao;
	char master_login[20];
	char master_senha[20];
};

#endif