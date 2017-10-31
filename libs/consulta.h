#ifndef CONSULTA_H
#define CONSULTA_H

#include <string.h>
#include <stdio.h>
#include "structs.h"
#include "cores.h"

/*funcao para realizar a consulta do hospede*/
/*recebe o tipo de salvamento por parametro*/
void consultahospede(int tipo){
	/*faço a chamada da struct, para ter acesso as variaveis do hospede*/
	struct hospede h;
	//crio um ponteiro do tipo arquivo
	FILE *arquivo;
	ciano("\nConsulta de Hospedes\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for 1, salvamento arquivo texto*/
		case 1:
			/*abro o arquivo*/
			arquivo = fopen("saves/hospedes.txt","a+");
			//verifico se ele foi aberto
			/*se houver erros na abertura mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não foram encontrados hospedes cadastrados\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*padronizo os dados que serao buscados*/
				azulclaro("\nDados dos Hospedes\n\n");
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
					h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
						/*E vou listando os itens para o usuario em forma de lista*/
						printf("\n----------------------------------------------------------------------------\n");
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
						printf("\nStatus: %s",h.status);
						printf("\n----------------------------------------------------------------------------\n");
						/*verifica se ja alcancou o final do arquivo*/
						if(feof(arquivo)){
							//*se ja sai do laco*/
							break;
						}
				}
				/*e no fim fecho o arquivo*/
				fclose(arquivo);
			}	
		break;
		/*caso 2, verifica em binario*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/hospedes.bin","ab+");
			/*verifica se ele foi aberto normalmente*/
			/*se houve algum erro mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não Foram encontrados hospedes cadastrados\n\n");
			}
			/*se foi aberto, verifica os dados no arquivo*/
			else{
				/*enquanto nao for o final do arquivo vai mostrando os dados*/
				azulclaro("\nDados dos Hospedes\n\n");
				while(!feof(arquivo)){
					/*verifica se ja alcancou o final do arquivo*/
					fread(&h,sizeof(struct hospede),1,arquivo);
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
					/*mostra os hospedes em forma de lista*/		
					printf("\n----------------------------------------------------------------------------\n");
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
					printf("\nStatus: %s",h.status);
					printf("\n----------------------------------------------------------------------------\n");
					
				}
			}
			/*e no final fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mensagem de erro para opções de salvamento ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
/*função de consulta de dados dos hoteis*/
/*recebe por parametro o tipo de salvamento*/
void consultahotel(int tipo){
	/*chama a struct do hotel para ter acesso a suas variaveis*/
	struct hotel ht;
	/*cria um ponterio do tipo arquivo para abrir o arquivo do hotel*/
	FILE *arquivo;
	ciano("\nConsulta de Hotéis\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/hoteis.txt","a+");
			/*verifca se houve erros na abertura*/
			/*se houve, mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("Erro em realizar a consulta ou Não foram encontrados hotéis cadastrados\n\n");	
			}
			/*se estiver tudo ok*/
			else{
				/*verifica até o final do arquivo */
				azulclaro("\nDados do(s) Hotel(éis)\n\n");
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
					/*mostrando os hoteis cadastrados em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
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
					printf("\nStatus: %s",ht.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				/*fecha o arquivo no final*/
				fclose(arquivo);
			}	
		break;
		case 2:
			/*caso o tipo de salvamento for 2, arquivo binário*/
			arquivo = fopen("saves/hoteis.bin","ab+");
			/*verifica se há erros na abertura do arquivo*/
			if(arquivo == NULL){
				/*se houver, mostra mensagem de erro na tela*/
				vermelho("Erro em realizar a consulta ou Não foram encontrados hotéis cadastrados\n\n");
			}
			else{
				azulclaro("\nDados do(s) Hotel(éis)\n\n");
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
					/*mostra os hoteis cadastrados em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
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
					printf("\nStatus: %s",ht.status);
					printf("\n----------------------------------------------------------------------------\n");
				}	
				
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mensagem de erro para opções de salvemento ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
/*função de consulta de produtos*/
/*recebe o tipo de salvamento por parametro*/
void consultaproduto(int tipo){
	/*chama a struct para acessar as variaveis do produto*/
	struct produtos p;
	ciano("\nConsulta de Produtos\n\n");
	/*cria um ponteiro do tipo arquivo para abrir o arquivo de produtos*/
	FILE *arquivo;
	/*verifica o tipo de salvamento */
	switch(tipo){
		/*se o tipo de salvamento for 1, arquivo texto*/
		case 1:
			/*abre o arquivo de produtos*/
			arquivo = fopen("saves/produtos.txt","a+");
			/*verifica se houve erros na abertura do arquivo*/
			/*se houve algum erro mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não foram encontrados produtos cadastrados\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*verifica o arquivo e mostra os produtos cadastrados*/
				azulclaro("\nDados do(s) Produto(s)\n\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.precocusto,&p.precovenda,p.status)!= EOF){
					/*mostra os produtos em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nPreço de Custo: R$%.2f",p.precocusto);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);		
			}
		break;
		/*caso for o tipo de salvamento 2, arquivo binário*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/produtos.bin","ab+");
			/*verifica se houve algum erro na abertura do arquivo*/
			/*se houve algum erro mostra na tela um aviso*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não foram encontrados produtos cadastrados\n\n");
			}
			/*se estiver tudo ok..*/
			else{
				azulclaro("\nDados do(s) Produto(s)\n\n");
				/*verifica todo o arquivo*/
				while(!feof(arquivo)){
					/*armazena cada produto por vez na struct*/
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
					/*mostra em forma de lista na tela*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nPreço de Custo: R$%.2f",p.precocusto);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*mensagem de erro para opções de salvamento ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
/*função de consulta de acomodação*/
/*recebe como parametro, o tipo de salvamento*/
void consultaacomodacao(int tipo){
	/*chama a struct de acomodações para ter acesso a suas variaveis*/
	struct acomodacoes ac;
	/*cria um ponteiro do tipo arquivo para abrir o arquivo de acomods*/
	FILE *arquivo;
	ciano("\nConsulta de Acomodações\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo de salvamento 1, arquivo texto*/
		case 1:
			/*abre o arquivo de acomodacoes*/
			arquivo = fopen("saves/acomodacoes.txt","a+");
			/*verifica se houve erro na abertura do arquivo*/
			/*se houver erro mostra mensagem de erro na tela*/
			if(arquivo == NULL){
				vermelho("Erro em realizar a consulta ou não foram encontrados quartos cadastradas\n\n");
			}
			/*se estiver tudo ok..*/
			else{
				/*le o arquivo*/
				azulclaro("Acomodações cadastradas((valores númericos representam quantidade)não considerando a categoria): \n\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,&ac.categoriaselecionada,ac.status) != EOF){
					/*mostra as acomodações cadastradas em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %i",ac.codigo);
					printf("\nDescrição: %s",ac.descricao);
					printf("\nCom TV comum: %i",ac.extra.tv);
					printf("\nCom TV a Cabo: %i",ac.extra.tvcabo);
					printf("\nCom Ar condicionado: %i",ac.extra.arcondicionado);
					printf("\nCom Frigobar: %i",ac.extra.frigobar);
					printf("\nCom Banheiro Próprio: %i",ac.extra.banheiro);
					printf("\nCom Cama de Casal: %i",ac.extra.camacasal);
					printf("\nCom Cama de Solteiro: %i",ac.extra.camasolteiro);
					printf("\nCom Hidromassagem: %i",ac.extra.hidromassagem);
					printf("\nCom Banheira: %i",ac.extra.banheira);
					printf("\nCategoria da Acomodação: %i",ac.categoriaselecionada);
					printf("\nStatus: %s",ac.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*caso já tenho chegado no final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		case 2:
			/*tipo de salvamento 2, arquivo binário*/
			/*consulta em binário*/
			/*abre o arquivo das acomodações*/
			arquivo = fopen("saves/acomodacoes.bin","ab+");
			/*verifica se houve erros na abertura*/
			/*se houve algum erro, mostra mensagem de erro na tela*/
			if(arquivo == NULL){
				vermelho("Erro em realizar a consulta ou não foram encontrados quartos cadastradas\n\n");	
			}
			/*se estiver tudo ok..*/
			else{
				/*le o arquivo*/
				azulclaro("Acomodações cadastradas((valores númericos representam quantidade)não considerando a categoria): \n\n");
				while(!feof(arquivo)){
					/*e enquanto não chega no final do arquivo vai mostrando as acomodações cadastradas*/
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					/*verifica se já está no final do arquivo*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					/*mostra em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %i",ac.codigo);
					printf("\nDescrição: %s",ac.descricao);
					printf("\nCom TV comum: %i",ac.extra.tv);
					printf("\nCom TV a Cabo: %i",ac.extra.tvcabo);
					printf("\nCom Ar condicionado: %i",ac.extra.arcondicionado);
					printf("\nCom Frigobar: %i",ac.extra.frigobar);
					printf("\nCom Banheiro Próprio: %i",ac.extra.banheiro);
					printf("\nCom Cama de Casal: %i",ac.extra.camacasal);
					printf("\nCom Cama de Solteiro: %i",ac.extra.camasolteiro);
					printf("\nCom Hidromassagem: %i",ac.extra.hidromassagem);
					printf("\nCom Banheira: %i",ac.extra.banheira);
					printf("\nCategoria da Acomodação: %i",ac.categoriaselecionada);
					printf("\nStatus: %s",ac.status);
					printf("\n----------------------------------------------------------------------------\n");
					
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*mensagem de erro para tipos de salvamento diferentes do já implementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}
/*função para consulta de categorias, recebe como parametro o tipo de salvamento*/
void consultacategoria(int tipo){
	/*struct de categorias, para ter acesso a suas variaveis*/
	struct categorias c;
	/*cria um ponterio de arquivo, para abrir os arquivos*/
	FILE *arquivo;
	ciano("\nConsulta de Categorias\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*se for o tipo de salvamento 1, arquivo texto*/
		case 1:
		arquivo = fopen("saves/categorias.txt","a+");
		if(arquivo == NULL){
			printf("\nErro em realizar a consulta de categoria!!\n\n");
		}
		else{
			printf("\nCategorias Cadastradas\n\n");
			while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status) != EOF){
				printf("\n----------------------------------------------------------------------------\n");
				printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
				printf("\nPreço: R$%.2f",c.valor);
				printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
				printf("\nStatus: %s",c.status);
				printf("\n----------------------------------------------------------------------------\n");
				if(feof(arquivo)){
					break;
				}
			}
			fclose(arquivo);
			break;
			case 2:
			arquivo = fopen("saves/categorias.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta de categoria!!\n\n");	
			}
			else{
				printf("\nCategorias Cadastradas\n\n");
				while(!feof(arquivo)){
					fread(&c,sizeof(struct categorias),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
					printf("\nPreço: R$%.2f",c.valor);
					printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
					printf("\nStatus: %s",c.status);
					printf("\n----------------------------------------------------------------------------\n");
				}
				fclose(arquivo);
			}
			break;
			default:
				printf("\nOpcao ainda não implementada ou não existente\n\n");
			break;
		}
	}
}

void consultafornecedor(int tipo){
	struct fornecedores f;
	FILE *arquivo;
	ciano("\nConsulta de Fornecedores\n\n");
	switch(tipo){
		case 1:
			arquivo = fopen("saves/fornecedores.txt","a+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta de fornecedor!!\n\n");
			}
			else{
				printf("\nFornecedores Cadastradoss\n\n");
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
					f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
					f.trepresentante,f.status) != EOF){
					printf("\n----------------------------------------------------------------------------\n");
					printf("Codigo: %u",f.codigo);
					printf("\nNome Fantasia: %s",f.nomefantasia);
					printf("\nRazão Social %s",f.razaosocial);
					printf("\nCNPJ: %s",f.cnpj);
					printf("\nInscrição Estadual: %s",f.insc);
					printf("\nRua: %s",f.rua);
					printf("\nNúmero: %s",f.numero);
					printf("\nBairro: %s",f.bairro);
					printf("\nCEP: %s",f.cep);
					printf("\nComplemento: %s",f.complemento);
					printf("\nCidade: %s",f.cidadeestado.cidade);
					printf("\nEstado: %s",f.cidadeestado.estado);
					printf("\nTelefone: %s",f.telefone);
					printf("\nCelular: %s",f.celular);
					printf("\nE-mail: %s",f.email);
					printf("\nRepresentante: %s",f.nrepresentante);
					printf("\nTelefone do Representante: %s",f.trepresentante);
					printf("\nStatus: %s",f.status);
					printf("\n----------------------------------------------------------------------------\n");
					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
			}
		break;
		case 2:
			arquivo = fopen("saves/fornecedores.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta de fornecedor!!\n\n");
			}
			else{
				printf("\nFornecedores Cadastradoss\n\n");
				while(!feof(arquivo)){
					fread(&f,sizeof(struct fornecedores),1,arquivo);
					if(feof(arquivo)){
						break;
					}
					printf("\n----------------------------------------------------------------------------\n");
					printf("Codigo: %u",f.codigo);
					printf("\nNome Fantasia: %s",f.nomefantasia);
					printf("\nRazão Social %s",f.razaosocial);
					printf("\nCNPJ: %s",f.cnpj);
					printf("\nInscrição Estadual: %s",f.insc);
					printf("\nRua: %s",f.rua);
					printf("\nNúmero: %s",f.numero);
					printf("\nBairro: %s",f.bairro);
					printf("\nCEP: %s",f.cep);
					printf("\nComplemento: %s",f.complemento);
					printf("\nCidade: %s",f.cidadeestado.cidade);
					printf("\nEstado: %s",f.cidadeestado.estado);
					printf("\nTelefone: %s",f.telefone);
					printf("\nCelular: %s",f.celular);
					printf("\nE-mail: %s",f.email);
					printf("\nRepresentante: %s",f.nrepresentante);
					printf("\nTelefone do Representante: %s",f.trepresentante);
					printf("\nStatus: %s",f.status);
					printf("\n----------------------------------------------------------------------------\n");
				}
				fclose(arquivo);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void consultausuario(){
	struct usuarios u;
	FILE *arquivo;
	ciano("\nConsulta de Usuários\n\n");
	int t;
	arquivo = fopen("saves/usuarios.bin","ab+");
	if(arquivo == NULL){
		printf("Erro em realizar a consulta de usuário!!\n\n");
	}
	else{
		printf("Usuários cadastrados: \n\n");
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if(feof(arquivo)){
					break;
			}
			printf("\n----------------------------------------------------------------------------\n");
			printf("Código: %u",u.codigo);
			printf("\nNome do Usuário: %s",u.nome);
			printf("\nLogin: %s",u.login);
			t = strlen(u.senha);
			printf("\nSenha: ");
			for(int i = 0; i < t; i++){
				printf("*");
			}
			printf("\nPermissão: %i",u.permissao);
			printf("\nStatus: %s",u.status);
			printf("\n----------------------------------------------------------------------------\n");
		}
		fclose(arquivo);
	}
}

int codigohospede(int tipo){
	int codigo = 0;
	FILE *arquivo;
	struct hospede h;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hospedes.txt","a+");
			if(arquivo == NULL){
				codigo = 0;
			}
			else{
				while( fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
					h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
					codigo = h.codigo;
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
			fclose(arquivo);
		break;
		case 2:
			arquivo = fopen("saves/hospedes.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
	
	return codigo;
}

int codigohotel(int tipo){
	int codigo = 0;
	FILE *arquivo;
	struct hotel ht;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hoteis.txt","a+");
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
		break;
		case 2:
			arquivo = fopen("saves/hoteis.bin","ab+");
			if(arquivo == NULL){
				codigo = 0;
			}
			else{
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo = ht.codigo;
			}
			codigo++;
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
	return codigo; 
}

int codigoproduto(int tipo){
	struct produtos p;
	FILE *arquivo;
	int codigo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/produtos.txt","a+");
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
		break;
		case 2:
			arquivo = fopen("saves/produtos.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
	return codigo;
}

int codigoacomodacao(int tipo){
	struct acomodacoes ac;
	FILE *arquivo;
	int codigo = 0;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/acomodacoes.txt","a+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta!!\n\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.categoriaselecionada,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,ac.status 	) != EOF){
					codigo = ac.codigo;
				}
				codigo++;
				fclose(arquivo);
			}
		break;
		case 2:
			arquivo = fopen("saves/acomodacoes.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	return codigo;
}

int codigocategoria(int tipo){
	struct categorias c;
	FILE *arquivo;
	int codigo = 0;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/categorias.txt","a+");
			if(arquivo == NULL){
				printf("\nErro na localização do arquivo para criar o código\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s\n",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status)!= EOF){
					codigo = c.codigo;
				}
				codigo++;
				fclose(arquivo);		
			}
		break;
		case 2:
			arquivo = fopen("saves/categorias.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	return codigo;
}

int codigofornecedor(int tipo){
	struct fornecedores f;
	FILE *arquivo;
	int codigo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/fornecedores.txt","a+");
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo!!\n\n");	
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
					f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
					f.trepresentante,f.status) != EOF){
					codigo = f.codigo;
				}
				codigo++;
				fclose(arquivo);
			}
		break;
		case 2:
			arquivo = fopen("saves/fornecedores.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo!!\n\n");	
			}
			else{
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					if(feof(arquivo)){
						break;
					}
				}
				codigo++;
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	return codigo;
}

int codigousuario(){
	struct usuarios u;
	FILE *arquivo;
	int codigo = 0;
	arquivo = fopen("saves/usuarios.bin","rb");
	if(arquivo == NULL){
		codigo = 1;
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if(feof(arquivo)){
				break;
			}
			codigo = u.codigo;
		}
		codigo++;
		fclose(arquivo);
	}
	return codigo;
}

int verificausuario(char login[20],char senha[20]){
	struct usuarios u;
	FILE *arquivo;
	FILE *arquivo2;
	struct config c;
	int verifica = 0;
	arquivo = fopen("saves/usuarios.bin","ab+");
	arquivo2 = fopen("config/config.bin","ab+");
	if(arquivo == NULL && arquivo2 == NULL){
		printf("\nErro na verificação de usuário!!\n");
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if((strcmp(login,u.login) == 0) && (strcmp(senha,u.senha) == 0)){
				verifica = 1;
			}
		}
	}
	if(verifica == 0){
	arquivo = fopen("config/config.bin","rb");
		while(!feof(arquivo)){
			fread(&c,sizeof(struct config),1,arquivo);
			if(strcmp(login,c.master_login) == 0 && strcmp(senha,c.master_senha) == 0){
				verifica = 1;
			}
			if(feof(arquivo)){
				break;
			}
		}	
	}
	fclose(arquivo);
	return verifica;
}

#endif 