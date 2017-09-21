#ifndef FUNCOES_H
#define FUNCOES_H
/*a biblioteca structs foi importada para ser usado as structs dentro das funções*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"
#include "salvar.h"
#include "consulta.h"
#include "config.h"
#include "auxiliares.h"
/*funcao para cadastrar o hóspede, que sera executada no arquivo main*/
void cadastrahospede(){
	/*chama a struct para poder passar os dados a ela*/
	struct hospede h;
	/*coloca local como portugues, para pegar os acentos no menu e funções*/
	setlocale(LC_ALL, "Portuguese");
	/*Resto da funcao que basicamente pega os dados e armazena na struct hotel*/
	/*%[^\n]s serve para pegar os espaços digitados pelo usuário*/ 
	printf("\nCadastro de Hóspedes:\n\n");

	h.codigo = codigohospede(verificasave());
	setbuf(stdin,NULL);
	printf("Digite o Nome do Hóspede: ");
	scanf("%[^\n]s",h.nome);
	setbuf(stdin,NULL);
	printf("Digite o CPF do Hóspede: ");
	scanf("%[^\n]s",h.cpf);
	setbuf(stdin,NULL);
	printf("Digite o RG do Hóspede: ");
	scanf("%[^\n]s",h.rg);
	setbuf(stdin,NULL);
	printf("Digite a Rua da Residência do Hóspede: ");
	scanf("%[^\n]s",h.rua);
	setbuf(stdin,NULL);
	printf("Digite o Número da Residência do Hóspede: ");
	scanf("%[^\n]s",h.numero);
	setbuf(stdin,NULL);
	printf("Digite o Bairro da Residência do Hóspede: ");
	scanf("%[^\n]s",h.bairro);
	setbuf(stdin,NULL);
	printf("Digite a Cidade da Residência do Hóspede: ");
	scanf("%[^\n]s",h.cidadeestado.cidade);
	setbuf(stdin,NULL);
	printf("Digite o Estado da Residência do Hóspede: ");
	scanf("%[^\n]s",h.cidadeestado.estado);
	setbuf(stdin,NULL);
	printf("Digite o CEP da Residência do Hóspede: ");
	scanf("%[^\n]s",h.cep);
	setbuf(stdin,NULL);
	printf("Digite o Complemento da Residência do Hóspede: ");
	scanf("%[^\n]s",h.complemento);
	setbuf(stdin,NULL);
	printf("Digite a Data de Nascimento do Hóspede: ");
	scanf("%[^\n]s",h.datanascimento);
	setbuf(stdin,NULL);
	/*Preciso validar a data de nascimento*/
	printf("Digite o Telefone do Hóspede: ");
	scanf("%[^\n]s",h.telefone);
	setbuf(stdin,NULL);
	printf("Digite o Celular do Hóspede: ");
	scanf("%[^\n]s",h.celular);
	setbuf(stdin,NULL);
	printf("Digite o Estado Cívil do Hóspede: ");
	scanf("%[^\n]s",h.estadocivil);
	setbuf(stdin,NULL);
	printf("Digite o E-mail do Hóspede: ");
	scanf("%[^\n]s",h.email);
	setbuf(stdin,NULL);
	strcpy(h.status , "Ativo");
}

void cadastrahotel(){
	/*chama a struct para poder passar os dados a ela*/
	struct hotel ht;
	/*coloca local como portugues, para pegar os acentos no menu e funções*/
	setlocale(LC_ALL, "Portuguese");
	/*Resto da funcao que basicamente pega os dados e armazena na struct hotel*/
	/*%[^\n]s serve para pegar os espaços digitados pelo usuário*/

	printf("\nCadastro de Hotel:\n\n");

	ht.codigo = codigohotel(verificasave());
	
	setbuf(stdin,NULL);
	printf("Digite o Nome Fantasia do Hotel: ");
	scanf("%[^\n]s",ht.nomefantasia);
	setbuf(stdin,NULL);
	printf("Digite o Razão Social do Hotel: ");
	scanf("%[^\n]s",ht.razaosocial);
	setbuf(stdin,NULL);
	printf("Digite o CNPJ do Hotel: ");
	scanf("%[^\n]s",ht.cnpj);
	setbuf(stdin,NULL);
	printf("Digite o Inscrição Estadual do Hotel: ");
	scanf("%[^\n]s",ht.insc);
	setbuf(stdin,NULL);
	printf("Digite a Rua do Hotel: ");
	scanf("%[^\n]s",ht.rua);
	setbuf(stdin,NULL);
	printf("Digite o Número Hotel: ");
	scanf("%[^\n]s",ht.numero);
	setbuf(stdin,NULL);
	printf("Digite o Bairro do Hotel: ");
	scanf("%[^\n]s",ht.bairro);
	setbuf(stdin,NULL);
	printf("Digite a Cidade do Hotel: ");
	scanf("%[^\n]s",ht.cidadeestado.cidade);
	setbuf(stdin,NULL);
	printf("Digite o Estado do hotel: ");
	scanf("%[^\n]s",ht.cidadeestado.estado);
	setbuf(stdin,NULL);
	printf("Digite o Cep do hotel: ");
	scanf("%[^\n]s",ht.cep);
	setbuf(stdin,NULL);
	printf("Digite o Complemento do hotel: ");
	scanf("%[^\n]s",ht.complemento);
	setbuf(stdin,NULL);
	/*Preciso validar a data de nascimento*/
	printf("Digite o Telefone do Hotel: ");
	scanf("%[^\n]s",ht.telefone);
	setbuf(stdin,NULL);
	printf("Digite o E-mail do hotel: ");
	scanf("%[^\n]s",ht.email);
	setbuf(stdin,NULL);
	printf("Digite o Nome do Responsável: ");
	scanf("%[^\n]s",ht.nomeresponsavel);
	setbuf(stdin,NULL);
	printf("Digite o Telefone do Responsável: ");
	scanf("%[^\n]s",ht.telefoneresponsavel);
	setbuf(stdin,NULL);
	strcpy(ht.status , "Ativo");
}

void cadastracategoria(){
	//coloca o linguagem local para portugues, assim pegará os acentos
	setlocale(LC_ALL,"Portuguese");
	/*struct categoria para fazer o acesso a struct no outro arquivo*/	
	struct categorias c;
	printf("\nCadastro de Categorias\n");
	
	c.codigo = codigocategoria(verificasave());

	setbuf(stdin,NULL);
	printf("Digite a Descrição da Categoria: ");
	scanf("%[^\n]s",c.descricao);
	//coloca o buffer do teclado como vazio, evitando perda de dados
	setbuf(stdin,NULL);
	printf("Digite o Valor da Categoria: ");
	scanf("%f",&c.valor);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de adultos(Permitidos na Acomodação): ");
	scanf("%i",&c.quantidadeadultos);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de crianças(Permitidos na Acomodação): ");
	scanf("%i",&c.quantidadecriancas);
	setbuf(stdin,NULL);
	strcpy(c.status,"Ativa");

}

void cadastraacomodacao(){
	//chama a struct das acomodacoes
	struct acomodacoes acomod;
	//coloca o linguagem local para portugues, assim pegará os acentos
	setlocale(LC_ALL,"Portuguese");
	printf("\nCadastro de Acomodações:\n");
	acomod.codigo = codigoacomodacao(verificasave());
	setbuf(stdin,NULL);
	printf("Digite a Descrição da Acomodações: ");
	scanf("%[^\n]s",acomod.descricao);
	setbuf(stdin,NULL);
	consultacategoria(verificasave());
	printf("Digite o código da categoria desejada: ");
	scanf("%i",&acomod.categoriaselecionada);
	printf("\nAcomodação possui Televisão Comum?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.tv);
	setbuf(stdin,NULL);
	printf("Acomodação possui Televisão a Cabo?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.tvcabo);
	setbuf(stdin,NULL);
	printf("Acomodação possui Ar Condicionado?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.arcondicionado);
	setbuf(stdin,NULL);
	printf("Acomodação possui Frigobar?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.frigobar);
	setbuf(stdin,NULL);
	printf("Acomodação possui Banheiro?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.banheiro);
	setbuf(stdin,NULL);
	printf("Acomodação possui Cama de Casal?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.camacasal);
	setbuf(stdin,NULL);
	printf("Acomodação possui Cama de Solteiro?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.camasolteiro);
	setbuf(stdin,NULL);
	printf("Acomodação possui Hidromassagem?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.hidromassagem);
	setbuf(stdin,NULL);
	printf("Acomodação possui Banheira?(1 - Sim, 0 - Não): ");
	scanf("%i",&acomod.extra.banheira);
	setbuf(stdin,NULL);
	strcpy(acomod.status , "Ativo");
}

void cadastraproduto(){
	struct produtos p;
	setlocale(LC_ALL,"Portuguese");

	printf("\nCadastro de Produtos\n\n");
	
	p.codigo = codigoproduto(verificasave());

	setbuf(stdin,NULL);
	printf("Digite a Descrição do Produto: ");
	scanf("%[^\n]s",p.descricao);
	setbuf(stdin,NULL);
	printf("Digite o Estoque do Produto: ");
	scanf("%i",&p.estoque);
	setbuf(stdin,NULL);
	printf("Digite o Estoque mínimo do Produto: ");
	scanf("%i",&p.estoqueminimo);
	setbuf(stdin,NULL);
	printf("Digite o Valor de Compra do Produto: ");
	scanf("%f",&p.precocusto);
	setbuf(stdin,NULL);
	printf("Digite o Valor de Venda do Produto: ");
	scanf("%f",&p.precovenda);
	setbuf(stdin,NULL);
	strcpy(p.status , "Ativo");

}

void cadastrausuario(){
	struct usuarios u;
	//faço a chamada da struct, para ter acesso as varíaveis desta;*/
	/*coloco como linguagem obrigatória, o português, para evitar certos problemas de acentuação*/
	setlocale(LC_ALL,"Portuguese");
	/*verifico o codigo e faço o alto incremento automático*/
	u.codigo = codigousuario();
	/*faço o cadastro dos dados do usuário e */
	/*limpo o buffer para evitar erros nas strings*/
	setbuf(stdin,NULL);
	printf("Digite o nome do usuário: ");
	scanf("%[^\n]s",u.nome);
	setbuf(stdin,NULL);
	printf("Digite o login do usuário: ");
	scanf("%s",u.login);
	printf("Digite a senha do usuário: ");
	scanf("%s",u.senha);
	printf("Digite o nível de acesso do usuário\n1 - Acesso Mínimo;\n2 - Acesso Básico;\n3 - Acesso Comum;\n4 - Acesso Alto;\n5 - Acesso Máximo;\nDigite sua opção: ");
	scanf("%i",&u.permissao);
	strcpy(u.status , "Ativo");
}
#endif 