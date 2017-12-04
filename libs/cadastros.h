#ifndef FUNCOES_H
#define FUNCOES_H
/*a biblioteca structs foi importada para ser usado as structs dentro das funções*/
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "structs.h"
#include "consulta.h"
#include "config.h"
#include "salvar.h"
#include "produto.h"
#include "reserva.h"
#include "contas.h"

/*funcao para cadastrar o hóspede, que sera executada no arquivo main*/
/*recebe os dados do hospede e salva na struct*/
struct hospede cadastrahospede(){
	/*chama a struct para poder passar os dados a ela*/
	struct hospede h;
	/*coloca local como portugues, para pegar os acentos no menu e funções*/
	setlocale(LC_ALL, "Portuguese");
	/*Resto da funcao que basicamente pega os dados e armazena na struct hotel*/
	/*%[^\n]s serve para pegar os espaços digitados pelo usuário*/ 
	ciano("\nCadastro de Hóspedes:\n\n");
	/*recebe o auto incremento do código, verifica o ultimo código adicionada no arquivo e soma mais um*/
	h.codigo = codigohospede(verificasave());
	
	/*recebe os dados do hospede*/
	setbuf(stdin,NULL);
	printf("Digite o Nome do Hóspede: ");
	scanf("%[^\n]s",h.nome);

	setbuf(stdin,NULL);
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
	printf("Digite a Data de Nascimento do Hóspede(Ex: 06 03 1997): ");
	scanf("%i %i %i",&h.data_nascimento.dia,&h.data_nascimento.mes,&h.data_nascimento.ano);
	

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
	/*retorna a struct com seus dados preenchidos*/
	return h;
}
/*função de cadastro de hotel, recebe os dados do hotel é passa para a struct*/
struct hotel cadastrahotel(){
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
	/*retorna a struct*/
	return ht;
}
/*função para cadastrar categoria*/
struct categorias cadastracategoria(){
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
	/*retorna a struct de categorias*/
	return c;

}
/*função para cadastrar os dados da acomodação*/
/*recebe os dados para salvar na struct*/
struct acomodacoes cadastraacomodacao(char urlcategoria[50],char modoabertura[5]){
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
	strcpy(ac.status , "Desocupada");
	/*retorna a struct da acomodação*/
	return ac;
}
/*função de cadastra de produto*/
/*recebe os dados do produto é salva na struct*/
struct produtos cadastraproduto(){
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
	printf("Digite a Porcentagem de Lucro do Produto: ");
	scanf("%f",&p.lucro);
	setbuf(stdin,NULL);
	printf("Digite o Valor de Venda do Produto: ");
	scanf("%f",&p.precovenda);
	setbuf(stdin,NULL);
	/*salva o produto como padrão ativo*/
	strcpy(p.status , "Ativo");
	/*retorna a struct de produtos*/
	return p;

}
/*função de cadastro de usuário*/
/*recebe os dados do usuário para armazenar na struct*/
struct usuarios cadastrausuario(){
	struct usuarios u;
	//faço a chamada da struct, para ter acesso as varíaveis desta;*/
	/*coloco como linguagem obrigatória, o português, para evitar certos problemas de acentuação*/
	setlocale(LC_ALL,"Portuguese");
	/*verifico o codigo e faço o alto incremento automático*/
	u.codigo = codigousuario();
	/*faço o cadastro dos dados do usuário e */
	/*limpo o buffer para evitar erros nas strings*/
	ciano("\nCadastro de Usuários\n\n");
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
	/*retorna a struct de usuários*/
	return u;
}
/*função para cadastrar fornecedor*/
/*recebe os dados do fornecedor*/
struct fornecedores cadastrafornecedor(){
	/*chama a struct do fornecedor para ter acesso a suas variaveis*/
	struct fornecedores f;
	/*da um setlocale para evitar bugs na linguagem portuguesa*/
	setlocale(LC_ALL,"Portuguese");
	/*código autoincrementado, recebe o código da função que pesquisa o ultimo código adicionado
	e soma mais um*/
	f.codigo = codigofornecedor(verificasave());
	/*recebe o restante dos dados do fornecedor*/
	setbuf(stdin,NULL);
	ciano("\nCadastro de Fornecedores\n\n");
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
	/*retorna a struct de fornecedores*/
	return f;
}
/*função para armazenar os dados na entrada de produtos*/
/*recebe por parametro o url do produto e o modo de abertura*/
struct entradaprodutos cadastra_entradaprodutos(char urlproduto[50],char urlfornecedor[50],char modoabertura[5]){
	/*chama a struct de entrada de produtos para acessar suas variaveis*/
	struct entradaprodutos ep;
	int verifica = 0;
	float soma = 0.0;
	ciano("\nCadastro de Nota Fiscal\n\n");
	/*seta linguagem padrão o portugues*/
	setlocale(LC_ALL,"Portuguese");
	/*auto incrementa o código*/
	ep.codigo = codigo_entradaprodutos(verificasave());
	setbuf(stdin,NULL);
	/*recebe a quantidade de produtos diferentes presentes na nota*/
	printf("Digite a quantidade de produtos distintos na nota: ");
	scanf("%i",&ep.produtos_distintos);
	/*recebe o código do produto*/
	for(int i = 0; i < ep.produtos_distintos; i++){
		verifica = 0;
		/*verifica até que esteja certo*/
		while(verifica == 0){
			/*seta o buffer com vazio para evitar erros*/
			/*recebe os valores para entrada dos produtos*/
			setbuf(stdin,NULL);
			printf("Digite o código do %iº Produto: ",i + 1);
			scanf("%u",&ep.codigoproduto[i]);
			/*verifica se o código é igual a 0, se for, cadastra um novo produto*/
			if(ep.codigoproduto[i] == 0){
				salvarproduto(verificasave(),urlproduto,modoabertura,cadastraproduto());
			}
			/*se o codigo for igual a -1*/
			else if(ep.codigoproduto[i] == -1){
				/*mostra os produtos cadastrados*/
				consultaproduto(verificasave(),urlproduto,modoabertura);
			}
			/*se a verificação do código for diferente de 1, quer dizer que o código não está cadastrado, ou seja o usuário digitou
			um código inválido*/
			else if(valida_codigoproduto(verificasave(),urlproduto,modoabertura,ep.codigoproduto[i]) == 0){
				vermelho("\nCódigo inválido!\n");
			}
			/*se não acontecer nada disto, está tudo ok*/
			else{
				verifica = 1;
			}
			
		}
		verifica = 0;
		while(verifica == 0){
			/*seta o buffer com vazio para evitar erros*/
			setbuf(stdin,NULL);
			/*recebe o código do fornecedor*/
			printf("Digite o código do %iº Fornecedor: ",i + 1);
			scanf("%u",&ep.codigofornecedor[i]);
			/*verifica se o codigo é igual a zero*/
			if(ep.codigofornecedor[i] == 0){
				/*se for cadastra um novo fornecedor*/
				salvarfornecedor(verificasave(),urlfornecedor,modoabertura,cadastrafornecedor());
			}
			/*se o codigo for igual a -1*/
			else if(ep.codigofornecedor[i] == -1){
				/*mostra os fornecedores cadastrados*/
				consultafornecedor(verificasave(),urlfornecedor,modoabertura);
			}
			/*se a verificação for diferente de 1, mostra codigo invalido na tela*/
			else if(valida_codigofornecedor(verificasave(),urlfornecedor,modoabertura,ep.codigofornecedor[i]) == 0){
				vermelho("\nCódigo Inválido!\n");
			}
			/*se estiver tudo ok, continua normalmente*/
			else{
				verifica = 1;
			}
		}
		/*recebe mais alguns dados ainda dentro do for*/
		setbuf(stdin,NULL);
		printf("Digite a quantidade do %iº Produto: ",i + 1);
		scanf("%i",&ep.quantidade[i]);
		setbuf(stdin,NULL);
		printf("Digite o valor do %iº Produto: ",i + 1);
		scanf("%f",&ep.precocusto[i]);
		/*realiza a soma total dos valores, para atribuir ao total da nota no final*/
		soma = soma + ep.precocusto[i];
		/*define por default o status como ativo*/
		strcpy(ep.status[i],"Ativo");
	}
	/*recebe o restante dos dados fora do for*/
	/*seta o buffer com vazio para evitar erros*/
	setbuf(stdin,NULL);
	/*recebe o valor do frete e do imposto*/
	printf("Digite o valor do Frete: ");
	scanf("%f",&ep.frete);
	setbuf(stdin,NULL);
	printf("Digite o valor do Imposto: ");
	scanf("%f",&ep.imposto);
	/*soma os valores com o frete e o imposto e atribui ao total da nota*/
	soma = soma + ep.frete + ep.imposto;
	ep.totalnota = soma;
	/*retorna a struct de entrada de produtos*/
	return ep;
}

/*função para cadastrar a saida de produtos*/
/*recebe por parametro, o url do produto...*/
struct saidaprodutos cadastra_saidaprodutos(char urlproduto[50],char modoabertura[5]){
	/*chama a struct de saida de produtos para ter acesso a suas variaveis*/
	struct saidaprodutos sp;
	int verifica = 0;
	int tamanho;
	int resposta;
	/*seta a linguagem local, como português, para evitar alguns erros que possam aparecer*/
	setlocale(LC_ALL,"Portuguese");
	ciano("\nVenda de Produtos\n");
	/*receber o código da saida de produtos auto incrementada*/
	sp.codigo = codigo_saidaprodutos(verificasave());
	/*recebe o ponteiro da função que retorna os valores dos produtos*/
	float *valores = retorna_valoresprodutos(verificasave(),urlproduto,modoabertura);
	/*pega o tamanho do vetor, que está na posição 1*/
	tamanho = (int)valores[0];
	/*inicia a quantidade de produtos distintos com 0*/
	/*e inicia a nota com 0 também*/
	sp.totalpagar = 0;
	sp.produtos_distintos = 0;
	while(verifica == 0){
		/*recebe os outros dados dos produtos que podem ser mais de um cada*/
		/*recebe o código do produto*/
		setbuf(stdin,NULL);
		printf("Digite o código do %iº produto: ", sp.produtos_distintos + 1);
		scanf("%u",&sp.codigoproduto[sp.produtos_distintos]);
		/*recebe o quantidade do produto comprada*/
		setbuf(stdin,NULL);
		printf("Digite a quantidade do %iº produto: ",sp.produtos_distintos + 1);
		scanf("%i",&sp.quantidade[sp.produtos_distintos]);
		/*recebe o valor de cada produto para somar ao total da nota*/
		for (int i = 1; i < tamanho; i++){
			for(int j = 0; j < sp.produtos_distintos; j++){
				if(sp.codigoproduto[j] == i){
					sp.precovenda[sp.produtos_distintos] = valores[i];
					break;
				}
			}
		}
		sp.totalpagar += sp.precovenda[sp.produtos_distintos];
		/*atualiza a quantidade de produtos distintos a cada produto novo acrescentado*/
		sp.produtos_distintos++;
		/*verifica se o cliente deseja mais alguma coisa*/
		setbuf(stdin,NULL);
		printf("\nDeseja mais inserir mais algum produto na conta\n1 - Sim\n0 - Não\n: ");
		scanf("%i",&resposta);
		if(resposta == 0){
			verifica = 1;
		}
	}
	/*mostra o total a pagar*/
	printf("\nTotal a pagar: R$%.2f\n",sp.totalpagar);
	/*retorna a struct de saida de produtos*/
	return sp;
}

/*função para cadastro de reserva*/
/*recebe por parametro a url da acomodacao e da categoria*/
struct reserva cadastra_reserva(char urlacomodacao[50],char urlcategoria[50],char urlhospede[50],char modoabertura[5]){
	/*struct de reserva, para ter acesso as variaveis*/
	struct reserva r;
	char cpf[14];
	/*variaveis necessárias a função*/
	int verifica = 0;
	float valor_quarto;
	/*coloca como linguagem padrão a portuguesa*/
	ciano("\nReserva\n");
	setlocale(LC_ALL,"Portuguese");
	/*recebe o codigo autoincrementado pela função de retorno*/
	r.codigo = codigoreserva(verificasave());
	/*solicita o restante dos dados*/
	while(verifica == 0){
		setbuf(stdin,NULL);
		printf("Digite o código da Acomodação: ");
		scanf("%i",&r.codigo_acomodacao);
		/*verifica se o usuário sabia qual o código ou se ele precisou cadastrar a acomodação agora*/
		/*se o codigo digitado for igual a 0, cadastra uma nova acomodação*/
		if(r.codigo_acomodacao == 0){
			salvaracomodacao(verificasave(),urlacomodacao,modoabertura,cadastraacomodacao(urlcategoria,modoabertura));
		}
		/*se o codigo digitado for -1, mostra a acomodações cadastradas*/
		else if(r.codigo_acomodacao == -1){
			consultaacomodacao(verificasave(),urlacomodacao,modoabertura);
		}
		/*se não for nenhuma das opções acima, verifica se o codigo está cadastrada, se estiver, sai do loop*/
		else if(valida_codigoacomodacao(verificasave(),urlacomodacao,modoabertura,r.codigo_acomodacao) == 1){
			verifica = 1;
		}
	}
	/*recebe o restante dos dados*/
	setbuf(stdin,NULL);
	printf("Digite o CPF do hospede: ");
	scanf("%[^\n]s",cpf);
	r.codigo_hospede = codigo_hospede_cpf(verificasave(),urlhospede,modoabertura,cpf);
	setbuf(stdin,NULL);
	printf("Digite a data de entrada(ex: 06 02 2016): ");
	scanf("%i %i %i",&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano);
	setbuf(stdin,NULL);
	printf("Digite a data de saída(ex: 10 02 2016): ");
	scanf("%i %i %i",&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano);
	/*seta o status da reserva como confirmada*/
	strcpy(r.status,"Confirmada");
	/*retorna a struct de reservas*/
	return r;
}
/*função para receber os dados que o hospede deseja em sua acomodação*/
/*recebe por parametro os urls de acomodacao, categoria, e reserva, além do tipo de salvamento, do modo de abertura e as facilidades possiveis*/
void pesquisa_acomodacao(char urlacomodacoes[50],char urlcategoria[50],char urlreserva[50],char modoabertura[5]){
	/*chama as structs de data e de acomodações para acessar suas variaveis*/
	struct data d;
	struct acomodacoes ac;
	ciano("\nPesquisa de Acomodações\n");
	/*recebe os dados do usuário*/
	setbuf(stdin,NULL);
	printf("Digite a data de preferência(ex: 06 03 2018): ");
	scanf("%i %i %i",&d.dia,&d.mes,&d.ano);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de adultos(0 para não importa): ");
	scanf("%i",&ac.categoria.quantidadeadultos);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de crianças(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.categoria.quantidadecriancas);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de tvs(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.tv);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de tvs a cabo(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.tvcabo);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de ares condicionados(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.arcondicionado);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de frigobares(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.frigobar);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de banheiros(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.banheiro);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de camas de casal(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.camacasal);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de camas de solteiro(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.camasolteiro);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de banheira(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.banheira);
	setbuf(stdin,NULL);
	printf("Digite a quantidade de hidromassagens(0 para não importa ou nenhuma): ");
	scanf("%i",&ac.extra.hidromassagem);
	/*chama a função de pesquisa de acomodações*/
	pesquisa_acomodacoes(verificasave(),urlacomodacoes,urlcategoria,urlreserva,modoabertura,
		d,ac.categoria.quantidadeadultos,ac.categoria.quantidadecriancas,ac.extra.tv,ac.extra.tvcabo,ac.extra.arcondicionado,
		ac.extra.frigobar,ac.extra.banheiro,ac.extra.camacasal,ac.extra.camasolteiro,ac.extra.banheira,ac.extra.hidromassagem);

}

/*função para checkin e checkout*/
/*recebe por parametro o url da acomdação, das categorias e da reserva*/
struct checks checagens(char urlacomodacao[50],char urlcategoria[50],char urlhospede[50],char urlreserva[50],char urlchecks[50],char urlcontas[50],
	char urltempcontas[50],char modoabertura[5]){
	/*chama a struct de checks para acessar suas variaveis*/
	struct checks ch;
	struct contas ct;
	char cpf[14];
	int codigo_reserva;
	int verifica;
	int dias;
	float valor;
	int f_pagamento;
	int *dados;
	ciano("\nChecks\n");
	/*recebe os dados do usuário*/
	setbuf(stdin,NULL);
	printf("Digite 0 para checkin e 1 para checkout: ");
	scanf("%i",&ch.tipo);
	/*verifica se o hospede vai fazer checkin ou checkout*/
	if(ch.tipo == 0){
		ciano("\nCheck In\n");
		ch.codigo = codigo_checks(verificasave());
		/*se for checkin pego todos os dados*/
		setbuf(stdin,NULL);
		printf("Digite o CPF do hospede: ");
		scanf("%[^\n]s",cpf);
		ch.codigo_hospede = codigo_hospede_cpf(verificasave(),urlhospede,modoabertura,cpf);
		setbuf(stdin,NULL);
		/*o hospede fornece ao usuário o seu número da reserva*/
		printf("Digite o código da reserva: ");
		scanf("%i",&codigo_reserva);
		/*mostra a reserva para o usuário do sistema para ele digitar o código da acomodação*/
		consulta_reserva(verificasave(),urlreserva,modoabertura,codigo_reserva);
		setbuf(stdin,NULL);
		printf("Digite o código da Acomodação: ");
		scanf("%i",&ch.codigo_acomodacao);
		setbuf(stdin,NULL);
		/*recebe a data de checkin*/
		printf("Digite a data de check in(ex 03 04 2012): ");
		scanf("%i %i %i",&ch.data_checkin.dia,&ch.data_checkin.mes,&ch.data_checkin.ano);
		/*e atribui um valor 0 na data de checkout, afirmando que o hospede ainda nao fez o checkout*/
		ch.data_checkout.dia = 0;
		ch.data_checkout.mes = 0;
		ch.data_checkout.ano = 0;
		/*verifica se o hospede vai pagar no momento do checkin*/
		printf("O hospede realizará o pagamento agora(1 para sim, 0 para não): ");
		scanf("%i",&verifica);
		/*se for, verifica a forma de pagamento*/
		if(verifica == 1){
			printf("Digite a quantidade de dias da permenência do hospede: ");
			scanf("%i",&dias);
			/*pega o valor da acomodação*/
			valor = retorna_valoracomodacao(verificasave(),urlacomodacao,urlcategoria,modoabertura,ch.codigo_acomodacao);
			/*e multiplica pela quantidade de dias da permanencia*/
			ch.valor_total = dias * valor;
			/*assim encontra o valor que o hospede deve pagar*/
			printf("\nValor a pagar pelo quarto: R$%.2f\n",ch.valor_total);
			/*pago recebe 1, afirmando que o usuário vai pagar*/
			ch.pago = 1;
			/*verifica a forma de pagamento*/
			printf("Digite a forma de pagamento(1 - Cartão,2 - Dinheiro,3 - Depósito,4 - Cheque): ");
			scanf("%i",&f_pagamento);
			if(f_pagamento == 1){
				strcpy(ch.status,"PAGO COM CARTÃO");	
			}
			else if(f_pagamento == 2){
				strcpy(ch.status,"PAGO COM DINHEIRO");
			}
			else if(f_pagamento == 3){
				strcpy(ch.status,"PAGO COM DEPÓSITO");
			}
			else if(f_pagamento == 4){
				strcpy(ch.status,"PAGO COM CHEQUE");
			}	
		}
		/*se não for, salva no sistema o debito*/
		else{
			/*atribui 0 a valor para dizer que ele ainda não deve nada, pois ainda não foi calculado seus debitos e 0 para pago, afirmando que 
			o hospede nao pagou ainda*/
			ch.valor_total = 0;
			ch.pago = 0;
			strcpy(ch.status,"EM DÉBITO");
		}
	}
	else if(ch.tipo == 1){
		ciano("\nCheck Out\n");
		/*recebe o código do checkin*/
		printf("Digite o código de check in: ");
		scanf("%i",&ch.codigo);
		/*pega o dia de check in e se pagou ou não*/
		dados = retorna_dia_checkin_pago(verificasave(),urlchecks,modoabertura,ch.codigo);
		/*recebe o cpf para assim retornar o codigo dele*/
		setbuf(stdin,NULL);
		printf("Digite o CPF do hospede: ");
		scanf("%[^\n]s",cpf);
		ch.codigo_hospede = codigo_hospede_cpf(verificasave(),urlhospede,modoabertura,cpf);
		/*recebe o codigo da reserva*/
		setbuf(stdin,NULL);
		printf("Digite o código da reserva: ");
		scanf("%i",&codigo_reserva);
		/*e assim lista as informações da reserva do hospede*/
		consulta_reserva(verificasave(),urlreserva,modoabertura,codigo_reserva);
		setbuf(stdin,NULL);
		/*e assim ele digita o codigo da acomodação com a informação cedida anteriormente*/
		printf("Digite o código da Acomodação: ");
		scanf("%i",&ch.codigo_acomodacao);
		setbuf(stdin,NULL);

		/*vai ser pego a data de checkin na lida do arquivo*/
		printf("Digite a data de check out(ex 03 04 2012): ");
		scanf("%i %i %i",&ch.data_checkout.dia,&ch.data_checkout.mes,&ch.data_checkout.ano);
		ch.pago = dados[1];
		if(ch.pago == 0){
			/*recebe o valor da acomodação do hospede*/
			valor = retorna_valoracomodacao(verificasave(),urlacomodacao,urlcategoria,modoabertura,ch.codigo_acomodacao);
			/*calcula quanto ele deve pagar pelo quarto*/
			dias = ch.data_checkout.dia - dados[0];
			ch.valor_total = dias * valor;
			/*recebe o valor a pagar pelo quarto*/
			printf("\nValor a pagar pelo quarto: R$%.2f\n",ch.valor_total);
			/*recebe a forma de pagamento*/
			printf("Digite a forma de pagamento(1 - Cartão,2 - Dinheiro,3 - Depósito,4 - Cheque): ");
			scanf("%i",&f_pagamento);
			if(f_pagamento == 1){
				strcpy(ch.status,"PAGO COM CARTÃO");	
			}
			else if(f_pagamento == 2){
				strcpy(ch.status,"PAGO COM DINHEIRO");
			}
			else if(f_pagamento == 3){
				strcpy(ch.status,"PAGO COM DEPÓSITO");
			}
			else if(f_pagamento == 4){
				strcpy(ch.status,"PAGO COM CHEQUE");
			}
		}
		/*recebe o codigo do hospede*/
		ct.codigo_hospede = ch.codigo_hospede;
		/*verifica o codigo da conta dele*/
		conta_hospede(verificasave(),urlcontas,urltempcontas,modoabertura,ct,-1);
		printf("Hospede possui conta(1 - para Sim, 2 - para Não): ");
		scanf("%i",&verifica);
		if(verifica == 1){
			/*o usuário digita o código da conta dele*/
			printf("Digite o código da conta: ");
			scanf("%i",&ct.codigo);
			conta_hospede(verificasave(),urlcontas,urltempcontas,modoabertura,ct,10);
		}
	}	
	return ch;
}

struct contas ct cadastra_conta(){
	/*CONTINUAR A PARTIR DAQUI, DO CADASTRO DE CONTAS*/
}
#endif 