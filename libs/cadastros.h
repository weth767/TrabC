#ifndef FUNCOES_H
#define FUNCOES_H
/*a biblioteca structs foi importada para ser usado as structs dentro das funções*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "structs.h"
#include "consulta.h"
#include "config.h"

/*funcao para cadastrar o hóspede, que sera executada no arquivo main*/
/*recebe os dados do hospede e salva na struct*/
void cadastrahospede(){
	/*chama a struct para poder passar os dados a ela*/
	struct hospede h;
	/*coloca local como portugues, para pegar os acentos no menu e funções*/
	setlocale(LC_ALL, "Portuguese");
	/*Resto da funcao que basicamente pega os dados e armazena na struct hotel*/
	/*%[^\n]s serve para pegar os espaços digitados pelo usuário*/ 
	ciano("\nCadastro de Hóspedes:\n\n");
	/*recebe o auto incremento do código, verifica o ultimo código adicionada no arquivo e soma mais um*/
	h.codigo = codigohospede(verificasave());
	setbuf(stdin,NULL);
	/*recebe os dados do hospede*/
	printf("Digite o Nome do Hóspede: ");
	scanf("%[^\n]s",h.nome);
	printf("Digite o Sexo do Hóspede:\n1 - Masculino\n2 - Feminino\n3 - Outros\n: ");
	scanf("%i",&h.sexo);
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
	/*coloca como padrão o hospede como ativo*/
	strcpy(h.status , "Ativo");
}
/*função de cadastro de hotel, recebe os dados do hotel é passa para a struct*/
void cadastrahotel(){
	/*chama a struct para poder passar os dados a ela*/
	struct hotel ht;
	/*coloca local como portugues, para pegar os acentos no menu e funções*/
	setlocale(LC_ALL, "Portuguese");
	/*Resto da funcao que basicamente pega os dados e armazena na struct hotel*/
	/*%[^\n]s serve para pegar os espaços digitados pelo usuário*/
	ciano("\nCadastro de Hotel:\n\n");
	setbuf(stdin,NULL);
	/*o código é auto incrementado pela função, verifica o ultimo código adicionado no arquivo e
	adiciona um */
	ht.codigo = codigohotel(verificasave());
	/*recebe os outros dados do hotel*/
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
	/*atribui como padrão o hotel como ativo*/
	strcpy(ht.status , "Ativo");
}
/*função para cadastrar categoria*/
void cadastracategoria(){
	//coloca o linguagem local para portugues, assim pegará os acentos
	setlocale(LC_ALL,"Portuguese");
	/*struct categoria para fazer o acesso a struct no outro arquivo*/	
	struct categorias c;
	ciano("\nCadastro de Categorias\n");
	/*código autoincrementado, verifica o ultimo código adicionado no arquivo e soma mais um, */
	c.codigo = codigocategoria(verificasave());
	/*recebe o restante dos dados da categoria*/
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
	/*coloca a categoria como padrão ativa*/
	strcpy(c.status,"Ativa");

}
/*função para cadastrar os dados da acomodação*/
/*recebe os dados para salvar na struct*/
void cadastraacomodacao(char urlcategoria[50],char modoabertura[5]){
	//chama a struct das acomodacoes
	struct acomodacoes ac;
	//coloca o linguagem local para portugues, assim pegará os acentos
	setlocale(LC_ALL,"Portuguese");
	setbuf(stdin,NULL);
	ciano("\nCadastro de Acomodações:\n");
	/*código autoincrementado, função lẽ o ultimo código salvo e adiciona mais um*/
	ac.codigo = codigoacomodacao(verificasave());
	/*recebe os outros dados da acomodação*/
	setbuf(stdin,NULL);
	printf("Digite a Descrição da Acomodações: ");
	scanf("%[^\n]s",ac.descricao);
	setbuf(stdin,NULL);
	/*para adicionar as categorias, mostra para o usuário as categorias que ele já tem cadastrada*/
	consultacategoria(verificasave(),urlcategoria,modoabertura);
	/*continua recebendo normalmente os outros dados da acomodação*/
	printf("Digite o código da categoria desejada: ");
	scanf("%i",&ac.categoriaselecionada);
	printf("\nAcomodação possui Televisão Comum?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.tv);
	setbuf(stdin,NULL);
	printf("Acomodação possui Televisão a Cabo?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.tvcabo);
	setbuf(stdin,NULL);
	printf("Acomodação possui Ar Condicionado?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.arcondicionado);
	setbuf(stdin,NULL);
	printf("Acomodação possui Frigobar?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.frigobar);
	setbuf(stdin,NULL);
	printf("Acomodação possui Banheiro?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.banheiro);
	setbuf(stdin,NULL);
	printf("Acomodação possui Cama de Casal?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.camacasal);
	setbuf(stdin,NULL);
	printf("Acomodação possui Cama de Solteiro?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.camasolteiro);
	setbuf(stdin,NULL);
	printf("Acomodação possui Hidromassagem?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.hidromassagem);
	setbuf(stdin,NULL);
	printf("Acomodação possui Banheira?(1 - Sim, 0 - Não): ");
	scanf("%i",&ac.extra.banheira);
	setbuf(stdin,NULL);
	/*salva como padrão ativa*/
	strcpy(ac.status , "Ativo");
}
/*função de cadastra de produto*/
/*recebe os dados do produto é salva na struct*/
void cadastraproduto(){
	/*chama a struct para ter acesso as suas variaveis*/
	struct produtos p;
	setlocale(LC_ALL,"Portuguese");
	/*da um setlocale, para evitar alguns erros de linguagem*/
	ciano("\nCadastro de Produtos\n\n");
	/*auto incremento no código, a função verifica o ultimo código salvo e soma mais um*/
	p.codigo = codigoproduto(verificasave());
	/*armazena o restante dos dados do produto*/
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
	/*salva o produto como padrão ativo*/
	strcpy(p.status , "Ativo");

}
/*função de cadastro de usuário*/
/*recebe os dados do usuário para armazenar na struct*/
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
	setbuf(stdin,NULL);
	printf("Digite a senha do usuário: ");
	scanf("%s",u.senha);
	setbuf(stdin,NULL);
	printf("Digite o nível de acesso do usuário\n1 - Acesso Mínimo;\n2 - Acesso Básico;\n3 - Acesso Comum;\n4 - Acesso Alto;\n5 - Acesso Máximo;\nDigite sua opção: ");
	scanf("%i",&u.permissao);
	setbuf(stdin,NULL);
	/*salva como padrão ativo*/
	strcpy(u.status , "Ativo");
}
/*função para cadastrar fornecedor*/
/*recebe os dados do fornecedor*/
void cadastrafornecedor(){
	/*chama a struct do fornecedor para ter acesso a suas variaveis*/
	struct fornecedores f;
	/*da um setlocale para evitar bugs na linguagem portuguesa*/
	setlocale(LC_ALL,"Portuguese");
	/*código autoincrementado, recebe o código da função que pesquisa o ultimo código adicionado
	e soma mais um*/
	f.codigo = codigofornecedor(verificasave());
	/*recebe o restante dos dados do fornecedor*/
	setbuf(stdin,NULL);
	printf("Digite o Nome Fantasia do Fornecedor: ");
	scanf("%[^\n]s",f.nomefantasia);
	setbuf(stdin,NULL);
	printf("Digite o Razão Social do Fornecedor: ");
	scanf("%[^\n]s",f.razaosocial);
	setbuf(stdin,NULL);
	printf("Digite o CNPJ do Fornecedor: ");
	scanf("%[^\n]s",f.cnpj);
	setbuf(stdin,NULL);
	printf("Digite a Inscrição Estadual do Fornecedor: ");
	scanf("%[^\n]s",f.insc);
	setbuf(stdin,NULL);
	printf("Digite a Rua onde se localiza o Fornecedor: ");
	scanf("%[^\n]s",f.rua);
	setbuf(stdin,NULL);
	printf("Digite o Número do local onde está localizado o Fornecedor: ");
	scanf("%[^\n]s",f.numero);
	setbuf(stdin,NULL);
	printf("Digite o Bairro do local onde está localizado o Fornecedor: ");
	scanf("%[^\n]s",f.bairro);
	setbuf(stdin,NULL);
	printf("Digite o CEP do local onde está localizado o Fornecedor: ");
	scanf("%[^\n]s",f.cep);
	setbuf(stdin,NULL);
	printf("Digite o Complemento do local onde está localizado o Fornecedor: ");
	scanf("%[^\n]s",f.complemento);
	setbuf(stdin,NULL);
	printf("Digite a Cidade onde se localiza a matriz do Fornecedor: ");
	scanf("%[^\n]s",f.cidadeestado.cidade);
	setbuf(stdin,NULL);
	printf("Digite o Estado onde se localiza a matriz do Forneceodr: ");
	scanf("%[^\n]s",f.cidadeestado.estado);
	setbuf(stdin,NULL);
	printf("Digite o Telefone do Fornecedor: ");
	scanf("%[^\n]s",f.telefone);
	setbuf(stdin,NULL);
	printf("Digite o Celular do Fornecedor: ");
	scanf("%[^\n]s",f.celular);
	setbuf(stdin,NULL);
	printf("Digite o E-mail do Fornecedor: ");
	scanf("%[^\n]s",f.email);
	setbuf(stdin,NULL);
	printf("Digite o Nome do Representante do Fornecedor: ");
	scanf("%[^\n]s",f.nrepresentante);
	setbuf(stdin,NULL);
	printf("Digite o Telefone do Representante do Fornecedor: ");
	scanf("%[^\n]s",f.trepresentante);
	/*salva o fornecedor com padrão ativo*/
	strcpy(f.status,"Ativo");
}

void cadastra_entradaprodutos(){
	
}
#endif 