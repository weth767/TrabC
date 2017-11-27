#ifndef CONSULTA_H
#define CONSULTA_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "cores.h"

/*funcao para realizar a consulta do hospede*/
/*recebe o tipo de salvamento, url e modo de abertura por parametro*/
void consultahospede(int tipo,char url[50],char modoabertura[5]){
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
			arquivo = fopen(url,modoabertura);
			//verifico se ele foi aberto
			/*se houver erros na abertura mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não foram encontrados hospedes cadastrados\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*padronizo os dados que serao buscados*/
				azulclaro("\nDados dos Hospedes\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %i/%i/%i\n %s\n %s\n %s\n %s\n %s\n\n",&h.codigo,h.nome,&h.sexo,
					h.cpf,h.rg,h.rua,h.numero,h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,&h.data_nascimento.dia,
					&h.data_nascimento.mes,&h.data_nascimento.ano,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
						/*E vou listando os itens para o usuario em forma de lista*/
						printf("\n----------------------------------------------------------------------------\n");
						printf("Código: %u",h.codigo);
						printf("\nNome: %s",h.nome);
						if(h.sexo == 1){
							printf("\nSexo: Masculino");
						}
						else if(h.sexo == 2){
							printf("\nSexo: Feminino");
						}
						else if(h.sexo == 3){
							printf("\nSexo: Outros");
						}
						printf("\nCPF: %s",h.cpf);
						printf("\nRG: %s",h.rg);
						printf("\nRua: %s",h.rua);
						printf("\nNumero: %s",h.numero);
						printf("\nBairro: %s",h.bairro);
						printf("\nCidade: %s",h.cidadeestado.cidade);
						printf("\nEstado: %s",h.cidadeestado.estado);
						printf("\nCEP: %s",h.cep);
						printf("\nComplemento: %s",h.complemento);
						printf("\nData de Nascimento: %i/%i/%i",h.data_nascimento.dia,h.data_nascimento.mes,h.data_nascimento.ano);
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
			arquivo = fopen(url,modoabertura);
			/*verifica se ele foi aberto normalmente*/
			/*se houve algum erro mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não Foram encontrados hospedes cadastrados\n\n");
			}
			/*se foi aberto, verifica os dados no arquivo*/
			else{
				/*enquanto nao for o final do arquivo vai mostrando os dados*/
				azulclaro("\nDados dos Hospedes\n");
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
					if(h.sexo == 1){
						printf("\nSexo: Masculino");
					}
					else if(h.sexo == 2){
						printf("\nSexo: Feminino");
					}
					else if(h.sexo == 3){
						printf("\nSexo: Outros");
					}
					printf("\nCPF: %s",h.cpf);
					printf("\nRG: %s",h.rg);
					printf("\nRua: %s",h.rua);
					printf("\nNumero: %s",h.numero);
					printf("\nBairro: %s",h.bairro);
					printf("\nCidade: %s",h.cidadeestado.cidade);
					printf("\nEstado: %s",h.cidadeestado.estado);
					printf("\nCEP: %s",h.cep);
					printf("\nComplemento: %s",h.complemento);
					printf("\nData de Nascimento: %i/%i/%i",h.data_nascimento.dia,h.data_nascimento.mes,h.data_nascimento.ano);
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
void consultahotel(int tipo,char url[50],char modoabertura[5]){
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
			arquivo = fopen(url,modoabertura);
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
			arquivo = fopen(url,modoabertura);
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
void consultaproduto(int tipo,char url[50],char modoabertura[5]){
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
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erros na abertura do arquivo*/
			/*se houve algum erro mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta ou Não foram encontrados produtos cadastrados\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*verifica o arquivo e mostra os produtos cadastrados*/
				azulclaro("\nDados do(s) Produto(s)\n\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status)!= EOF){
					/*mostra os produtos em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nLucro: %.2f%%",p.lucro);
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
			arquivo = fopen(url,modoabertura);
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
					printf("\nLucro: %.2f%%",p.lucro);
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
void consultaacomodacao(int tipo,char url[50],char modoabertura[5]){
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
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erro na abertura do arquivo*/
			/*se houver erro mostra mensagem de erro na tela*/
			if(arquivo == NULL){
				vermelho("Erro em realizar a consulta ou não foram encontrados quartos cadastradas\n\n");
			}
			/*se estiver tudo ok..*/
			else{
				/*le o arquivo*/
				azulclaro("Acomodações cadastradas((valores númericos representam quantidade)não considerando a categoria): \n\n");
				while(!feof(arquivo)){
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,
					&ac.extra.banheira,&ac.categoriaselecionada,ac.status);
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
			arquivo = fopen(url,modoabertura);
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
void consultacategoria(int tipo,char url[50],char modoabertura[5]){
	/*struct de categorias, para ter acesso a suas variaveis*/
	struct categorias c;
	/*cria um ponterio de arquivo, para abrir os arquivos*/
	FILE *arquivo;
	ciano("\nConsulta de Categorias\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*se for o tipo de salvamento 1, arquivo texto*/
		case 1:
		/*abre o arquivo */
		arquivo = fopen(url,modoabertura);
		/*verifica se há erros na abertura do arquivo*/
		/*se houver erros, mostra mensagem na tela*/
		if(arquivo == NULL){
			vermelho("\nErro em realizar a consulta de categoria!!\n\n");
		}
		/*caso estiver tudo ok*/
		else{
			/*le o arquivo todo, salvando cada categoria por vez na struct*/
			azulclaro("\nCategorias Cadastradas\n\n");
			while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status) != EOF){
				/*E mostra a categoria selecionada em forma de lista*/
				printf("\n----------------------------------------------------------------------------\n");
				printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
				printf("\nPreço: R$%.2f",c.valor);
				printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
				printf("\nStatus: %s",c.status);
				printf("\n----------------------------------------------------------------------------\n");
				/*verifica se já esta no final do arquivo*/
				if(feof(arquivo)){
					/*caso esteja, sai do laço*/
					break;
				}
			}
			/*fecha o arquivo*/
			fclose(arquivo);
			break;
			/*tipo de salvamento 2, arquivo binário*/
			case 2:
			/*abre o arquivo*/
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erro na abertura do arquivo*/
			/*se houver erros, mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta de categoria!!\n\n");	
			}
			/*se estiver tudo ok..*/
			else{
				/*le o arquivo todo, pegando uma categoria por vez e armazenando na struct*/
				azulclaro("\nCategorias Cadastradas\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&c,sizeof(struct categorias),1,arquivo);
					/*verifica se já esta no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*se estiver, sai do laço*/
						break;
					}
					/*mostra a categoria seleciona em forma de lista*/
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
					printf("\nPreço: R$%.2f",c.valor);
					printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
					printf("\nStatus: %s",c.status);
					printf("\n----------------------------------------------------------------------------\n");
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			}
			break;
			/*mostra mensagem de erro para opções de salvamento não implementadas*/
			default:
				vermelho("\nOpcao ainda não implementada ou não existente\n\n");
			break;
		}
	}
}
/*função para consultar o fornecedor, recebe por parametro no o tipo de salvamento*/
void consultafornecedor(int tipo,char url[50],char modoabertura[5]){
	/*chama a struct para ter acesso a suas variaveis*/
	struct fornecedores f;
	/*cria um ponteiro do tipo arquivo para acessar o arquivo de fornecedores*/
	FILE *arquivo;
	ciano("\nConsulta de Fornecedores\n\n");
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo de fornecedores*/
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erros na abertura do arquivo*/
			/*se houver, mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta de fornecedor!!\n\n");
			}
			/*se estiver tudo ok...*/
			else{
				/*le o arquivo inteiro, armazenando um fornecedor por vez na struct*/
				azulclaro("\nFornecedores Cadastradoss\n\n");
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
					f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
					f.trepresentante,f.status) != EOF){
					/*mostra os fornecedores cadastrados em forma de lista*/
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
					/*verifica se já está no final do arquivo*/
					if(feof(arquivo)){
						/*sai do laço*/
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*tipo de salvamento 2, arquivo binário*/
		case 2:
			/*abre o arquivo dos fornecedores*/
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erros na abertura dos arquivos*/
			/*se houver erros, mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar a consulta de fornecedor!!\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*le o arquivo, a cada fornecedor lido é armazenado na struct, por vez*/
				azulclaro("\nFornecedores Cadastradoss\n\n");
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&f,sizeof(struct fornecedores),1,arquivo);
					/*verifica se ja esta no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					/*mostra os fornecedores cadastrados em forma de lista*/
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
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*mostra mensagem de erro para opções de salvamento ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}
/*função de consultar usuário*/
void consultausuario(char url[50],char modoabertura[5]){
	/*chama a struct dos usuários, para ter acesso a suas variaveis*/
	struct usuarios u;
	/*cria um ponteiro do tipo arquivo*/
	FILE *arquivo;
	ciano("\nConsulta de Usuários\n\n");
	int t;
	/*abre o arquivo de usuários*/
	arquivo = fopen(url,modoabertura);
	/*verifica se houve erro na abertura do arquivo*/
	/*se houver erro, mostra mensagem na tela*/
	if(arquivo == NULL){
		vermelho("Erro em realizar a consulta de usuário!!\n\n");
	}
	/*se estiver tudo ok..*/
	else{
		/*le o arquivo todo, pegando um usuario por vez e armazenando na struct*/
		azulclaro("Usuários cadastrados: \n\n");
		while(!feof(arquivo)){
			/*comando de leitura*/
			fread(&u,sizeof(struct usuarios),1,arquivo);
			/*verifica se ja esta no final do arquivo para evitar bugs*/
			if(feof(arquivo)){
				/*se estiver, sai do laço*/
				break;
			}
			/*lista os usuários cadastrados em forma de lista*/
			printf("\n----------------------------------------------------------------------------\n");
			printf("Código: %u",u.codigo);
			printf("\nNome do Usuário: %s",u.nome);
			printf("\nLogin: %s",u.login);
			/*pequeno macete para não mostra a senha do usuário*/
			t = strlen(u.senha);
			/*pega o tamanho da senha*/
			printf("\nSenha: ");
			/*e mostra * no lugar de cada caracter da senha*/
			for(int i = 0; i < t; i++){
				printf("*");
			}
			printf("\nPermissão: %i",u.permissao);
			printf("\nStatus: %s",u.status);
			printf("\n----------------------------------------------------------------------------\n");
		}
		/*fecha o arquivo*/
		fclose(arquivo);
	}
}
/*função de auto incremento de código do hospede*/
/*recebe por parametro o tipo de salvamento*/
int codigohospede(int tipo){
	int codigo = 0;
	/*cria um ponteiro do tipo arquivo para ter acesso ao arquivo do hospede*/
	FILE *arquivo;
	/*chama a struct do hospede para ter acesso a suas variaveis*/
	struct hospede h;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo dos hospedes em texto*/
			arquivo = fopen("saves/hospedes.txt","a+");
			/*verifica se ele já foi criado, senão foi*/
			if(arquivo == NULL){
				/*coloca código como 0, para ele receber 1 no final*/
				codigo = 0;
			}
			/*se já foi criado*/
			else{
				/*le o arquivo, pega o ultimo hospede cadastrado e verifica seu codigo*/
				while(fscanf(arquivo,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %i/%i/%i\n %s\n %s\n %s\n %s\n %s\n\n",&h.codigo,h.nome,&h.sexo,
					h.cpf,h.rg,h.rua,h.numero,h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,&h.data_nascimento.dia,
					&h.data_nascimento.mes,&h.data_nascimento.ano,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
					/*a variavel codigo, recebe o ultimo codigo salvo*/
					codigo = h.codigo;
					/*verifica o final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						break;
					}
				}
				/*soma mais um ao ultimo codigo salvo*/
				codigo++;
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*tipo de salvamento 2, arquivo binário*/
		case 2:
			/*abre o arquivo do hospede*/
			arquivo = fopen("saves/hospedes.bin","ab+");
			/*verifica se o arquivo ja existe*/
			if(arquivo == NULL){
				/*senao existe, da o valor zero para o código, que se tornará 1 no final */
				codigo = 0;
			}
			/*se existir*/
			else{
				/*le até o ultimo hospede cadastrado e pega o código dele*/
				while(!feof(arquivo)){
					fread(&h,sizeof(struct hospede),1,arquivo);
					/*verifica se já está no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					codigo = h.codigo;
				}
				/*incrementa o código*/
				codigo++;
			}
		break;
		/*mensagem de erro para opções de salvamento ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o código que ja incrementado no final*/
	return codigo;
}
/*função para auto incrementar o código do hotel*/
/*recebe por parametro o tipo de salvamento*/
int codigohotel(int tipo){
	int codigo = 0;
	/*cria um ponteiro do tipo arquivo para acessar o arquivo do hotel*/
	FILE *arquivo;
	/*chama a struct do hotel para ter acesso a suas variaveis*/
	struct hotel ht;
	/*verifica o tipo de salvamento que o hotel cadastrou*/
	switch(tipo){
		/*se for o 1, é arquivo texto(txt)*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/hoteis.txt","a+");
			/*verifica se ele foi criado recentemente ou já exista ainda*/
			/*se foi recentemente*/
			if(arquivo == NULL){
				/*atribui código 0, que será incrementado para 1 no final da função*/
				codigo = 0;
			}
			/*se já existia*/
			else{
				/*le o ultimo hotel cadastrado, pega seu código*/
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status)!= EOF){
					codigo = ht.codigo;
				}
				/*e incrementa esse código*/
				codigo++;
				
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*tipo de salvamento 2, arquivo binário*/
		case 2:
			/*abre o arquivo dos hoteis*/
			arquivo = fopen("saves/hoteis.bin","ab+");
			/*verifica se ele foi criado agora ou se ja existia*/
			if(arquivo == NULL){
				/*se foi criado agora, da o valor 0 ao codigo, que sera incrementado no final*/
				codigo = 0;
			}
			/*se já existia*/
			else{
				/*le o ultimo hotel cadastrado e pega seu codigo*/
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					/*verifica se ja esta no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*se estiver, sai do laçoi*/
						break;
					}
				}
				/*armazena o ultimo código cadastrado*/
				codigo = ht.codigo;
			}
			/*e incrementa 1 nele*/
			codigo++;
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mensagem de erro para opções de salvamento ainda não incrementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o código ja incrementado*/
	return codigo; 
}
/*funçao que faz o auto incremento do código relacionado ao produto*/
int codigoproduto(int tipo){
	/*chama a struct de produtos para ter acesso a suas variaveis*/
	struct produtos p;
	/*cria um ponteiro do tipo arquivo para abrir o arquivo de produto*/
	FILE *arquivo;
	int codigo;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*se for o tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/produtos.txt","a+");
			/*verifica se ele já existia ou foi criado recentemente pela função acima*/
			/*se é recente, o código será 0 para no final ser incrementado para 1*/
			if(arquivo == NULL){
				codigo = 0;
			}
			/*se já havia sido criado antes*/
			else{
				/*le o arquivo até o final, e pega o ultimo produto cadastrados*/
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status)!= EOF){
					/*armazena o ultimo código cadastrado*/
					codigo = p.codigo;
				}
				/*incrementa em 1 esse código*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);		
			}
		break;
		/*caso for o salvamento tipo 2, arquivo texto*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/produtos.bin","ab+");
			/*verifica se o arquivo já existia ou foi criado agora*/
			if(arquivo == NULL){
				/*se foi criado agora, código sera igual a zero para ser incrementado no final*/
				codigo = 0;
			}
			/*se já existia*/
			else{
				/*le o arquivo até o final e pega o código do ultimo produto salvo*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&p,sizeof(struct produtos),1,arquivo);
					/*verifica se já esta no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					codigo = p.codigo;
				}
				/*incrementa o código*/
				codigo++;
			}
		break;
		/*mostra mensagem para tipos de salvamento ainda não implementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o código já incrementado no final*/
	return codigo;
}
/*função de auto incremento do código da acomodação*/
/*recebe como parametro o tipo de salvamento ja cadastrado pelo usuario*/
int codigoacomodacao(int tipo){
	/*chama a structy de acomodações para ter acesso a suas variaveis*/
	struct acomodacoes ac;
	/*cria um ponteiro de arquivo para abrir o arquivo de acomodações*/
	FILE *arquivo;
	int codigo = 0;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/acomodacoes.txt","a+");
			/*verifica se o arquivo foi criado recentemente ou já existia*/
			/*se foi recentemente*/
			if(arquivo == NULL){
				/*coloca o valor de codigo como 0 que será incrementado no final*/
				codigo = 0;
			}
			/*se já existia*/
			else{
				/*verifica o arquivo todo, armazena a ultima acomodação cadastrada*/
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.categoriaselecionada,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,ac.status 	) != EOF){
					codigo = ac.codigo;
				}
				/*e por fim, incrementa o código armazenadi*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*caso for o tipo de salvamento 2, arquivo binario*/
		case 2:
			/*abre o arquivo'*/
			arquivo = fopen("saves/acomodacoes.bin","ab+");
			/*verifica se o arquivo foi criado recentemente*/
			/*se é recente, codigo recebe 0 para ser incrementado para 1 no final*/
			if(arquivo == NULL){
				codigo = 0;
			}
			/*se já existia*/
			else{
				/*le o arquivo todo, e armazena o ultimo codigo cadastrado*/
				while(!feof(arquivo)){
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					/*verifica se ja esta no final do arquivo para evitar bugs*/
					if(feof(arquivo)){
						/*sai do laço*/
						break;
					}
					codigo = ac.codigo;
				}
				/*incrementa o codigo*/
				codigo++;
			}
		break;
		/*mensagem de erro para opçoes de salvamento ainda nao implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o codigo ja incrementado no final*/
	return codigo;
}
/*função para auto incrementar o codigo da categoria*/
/*recebe por parametro o tipo de salvamento*/
int codigocategoria(int tipo){
	/*chama a struct de categoria para ter acesso a suas variaveis*/
	struct categorias c;
	/*cria um ponteiro de arquivo para abrir o arquivo de categorias*/
	FILE *arquivo;
	int codigo = 0;
	/*verifica o tipo de salvamento cadastrado pelo usuario*/
	switch(tipo){
		/*caso for o tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/categorias.txt","a+");
			/*verifica se o arquivo ja exista ou foi criado recentemente*/
			/*se foi criado recentemente, atribui o codigo como 0 para ser incrementado no final*/
			if(arquivo == NULL){
				codigo = 0;
			}
			/*se ja foi criado antes*/
			else{
				/*armazena o ultimo codigo cadastrado*/
				while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s\n",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status)!= EOF){
					codigo = c.codigo;
				}
				/*incrementa o codigo*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);		
			}
		break;
		/*for o tipo de salvamento 2, arquivo binario*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/categorias.bin","ab+");
			/*verifica se o arquivo foi criado agora ou ja existia*/
			/*se foi criado agora, atribui o codigo como 0 para ser incrementado depois*/
			if(arquivo == NULL){
				codigo = 0;
			}
			/*se ja existia antes*/
			else{
				/*le o ultimo codigo cadastrado*/
				while(!feof(arquivo)){
					fread(&c,sizeof(struct categorias),1,arquivo);
					/*verifica o final do arquivo, se estiver, sai do laço para evitar bugs*/
					if(feof(arquivo)){
						break;
					}
					/*armazena o ultimo codigo*/
					codigo = c.codigo;
				}
				/*incrementa o codigo*/
				codigo++;
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mostra mensagem de erro para tipos de salvamento ainda nao implementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o codigo ja incrementado*/
	return codigo;
}
/*função para auto incrementar o codigo do fornecedor*/
/*recebe por parametro o tipo de salvamento*/
int codigofornecedor(int tipo){
	/*chama a struct dos fornecedores para ter acesso a suas variaveis*/
	struct fornecedores f;
	/*cria o ponteiro par ater acesso ao arquivo do fornecedor*/
	FILE *arquivo;
	int codigo;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo de salvamento 1, arquivo texto*/
		case 1:
			arquivo = fopen("saves/fornecedores.txt","a+");
			/*verifica se o arquivo foi criado recentemente ou ja existia*/
			/*se foi criado recentemente, codigo recebe zero para receber 1 no final*/
			if(arquivo == NULL){
				codigo = 0;	
			}
			/*se ja existia*/
			else{
				/*le o arquivo, e armazena o ultimo codigo cadastrado*/
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
					f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
					f.trepresentante,f.status) != EOF){
					codigo = f.codigo;
				}
				/*incrementa o codigo*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*caso for o salvamento 2, arquivo binario*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/fornecedores.bin","ab+");
			/*verifica se o arquivo*/
			/*se foi criado recentemente, codigo recebe 0*/
			if(arquivo == NULL){
				codigo = 0;
			}
			/*senão le o arquivo até o final*/
			else{
				/*armazena o ultimo codigo cadastrado*/
				while(!feof(arquivo)){
					fread(&codigo,sizeof(int),1,arquivo);
					/*verifica se ja esta no final do arquivo, para evitar bugs*/
					if(feof(arquivo)){
						/*sai do laço*/
						break;
					}
				}
				/*incrementa o codigo*/
				codigo++;
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mostra mensagem de erro para salvamentos nao incrementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o codigo*/
	return codigo;
}
/*funcao de auto incremento de codigo para usuario*/
int codigousuario(){
	/*chama a struct usuarios, para ter acesso a suas variaveis*/
	struct usuarios u;
	/*cria um ponteiro de arquivo, para acessar o arquivo de usuarios*/
	FILE *arquivo;
	int codigo = 0;
	/*abre o arquivo*/
	arquivo = fopen("saves/usuarios.bin","ab+");
	/*se o arquivo foi criado recentemente, recebe codigo 0*/ 
	if(arquivo == NULL){
		codigo = 0;
	}
	/*se ja existia, le o ultimo codigo cadastrado*/
	else{
		/*armazena esse codigo*/
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			/*verifica o final do arquivo, para evitar bug*/
			if(feof(arquivo)){
				/*sai do laço*/
				break;
			}
			codigo = u.codigo;
		}
		/*incrementa o codigo*/
		codigo++;
		/*fecha o arquivo*/
		fclose(arquivo);
	}
	/*retorna o codigo ja incrementado*/
	return codigo;
}
/*função para verificar o usuario*/
int verificausuario(char login[20],char senha[20]){
	/*chama a struct para ter acesso as variveis*/
	struct usuarios u;
	/*cria os ponteiros para acessar o arquivo de usuarios e configs*/
	FILE *arquivo;
	FILE *arquivo2;
	struct config c;
	int verifica = 0;
	/*abre os dois arquivos*/
	arquivo = fopen("saves/usuarios.bin","ab+");
	arquivo2 = fopen("config/config.bin","ab+");
	/*verifica se os arquivos existem, */
	if(arquivo == NULL && arquivo2 == NULL){
		/*mostra mensagem na tela caso haja erra na abertura*/
		vermelho("\nErro na verificação de usuário!!\n");
	}
	else{
		/*caso esteja tudo ok, le o arquivo todo*/
		while(!feof(arquivo)){
			/*armazena os usuarios cadastrados*/
			fread(&u,sizeof(struct usuarios),1,arquivo);
			/*verifica se a senha e o login digitados são iguais a algum dos cadastrados*/
			if((strcmp(login,u.login) == 0) && (strcmp(senha,u.senha) == 0)){
				verifica = 1;
			}
		}
	}
	/*se ate o final encontrar um, return 1, senão for encontrado retorna 0*/
	if(verifica == 0){
	arquivo = fopen("config/config.bin","rb");
		while(!feof(arquivo)){
			fread(&c,sizeof(struct config),1,arquivo);
			if(strcmp(login,c.master_login) == 0 && strcmp(senha,c.master_senha) == 0){
				verifica = 1;
			}
			/*verifica o final do arquivo para evitar bugs*/
			if(feof(arquivo)){
				/*sai do laço*/
				break;
			}
		}	
	}
	/*fecha o arquivo*/
	fclose(arquivo);
	/*retorna se encontrou ou nao*/
	return verifica;
}
/*função para gerar o codigo automatico da entrada de produtos*/
int codigo_entradaprodutos(int tipo){
	/*chama a struct para ter acesso a suas variaveis*/
	struct entradaprodutos ep;
	int codigo;
	/*cria um ponteiro de arquivo para acessar o arquivo onde será salva os dados de entrada de produtos*/
	FILE *arquivo;
	/*um switch para verificar o tipo de salvamento*/
	switch(tipo){
		/*se for tipo 1, arquivo texto*/
		case 1:
			/*abre o arquivo*/
			arquivo = fopen("saves/entradaprodutos.txt","a+");
			/*verifica se ja existe*/
			if(arquivo == NULL){
				/*se nao codigo igual a 0*/
				codigo = 0;
			}
			/*se ja existir*/
			else{
				while(!feof(arquivo)){
					/*le o código e a quantidade de produtos distintos*/
					fscanf(arquivo,"%u\n %i\n",&ep.codigo,&ep.produtos_distintos);
					/*um for para ler a quantidade de produtos comprados*/
					for(int i = 0; i < ep.produtos_distintos; i++){
						/*pega esses valores*/
						fscanf(arquivo,"%u;%u;%i;%f;%s\n",&ep.codigoproduto[i],&ep.codigofornecedor[i],&ep.quantidade[i],&ep.precocusto[i],ep.status[i]);
					}
					/*pega o restante dos valores*/
					fscanf(arquivo,"%f\n %f\n %f\n\n",&ep.frete,&ep.imposto,&ep.totalnota);
					/*pega o ultimo codigo cadastrado*/
					codigo = ep.codigo;
				}
				/*incrementa ele*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*for o tipo de salvamento 2, arquivo binario*/
		case 2:
			/**abre o arquivo*/
			arquivo = fopen("saves/entradaprodutos.bin","ab+");
			/*verifica se o arquivo ja existe*/
			if(arquivo == NULL){
				/*se nao codigo igual a 0*/
				codigo = 0;
			}
			/*se existir*/
			else{
				/*le o arquivo*/
				while(!feof(arquivo)){
					
					/*le os dados*/
					fread(&ep,sizeof(struct entradaprodutos),1,arquivo);
					/*armazena o codigo*/
					codigo = ep.codigo;

					/*verifica se ja esta no final do arquivo*/
					if(feof(arquivo)){
						/*se estiver da um break e sai do laço*/
						break;
					}
				}
				/*incrementa o codigo*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*mostra mensagem de erro para salvamentos nao incrementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	/*retorna o codigo*/
	return codigo;
}

/*função para devolver o código incrementado para saida de produtos*/
int codigo_saidaprodutos(int tipo){
	/*chama a struct de saida de produtos, para ter acesso a suas variaveis*/
	struct saidaprodutos sp;
	/*cria um ponteiro para ter acesso ao arquivo de saida de produtos*/
	FILE *arquivo;
	int codigo;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		case 1:/*arquivo texto*/
			/*abre o arquivo*/
			arquivo = fopen("saves/saidaprodutos.txt","a+");
			/*verifica se o arquivo já existia antes*/
			if(arquivo == NULL){
				codigo = 0;
			}
			else{
				/*le o arquivo até o final, com um while*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %i\n",&sp.codigo,&sp.produtos_distintos);
					/*depois de lido a quantidade de produtos distintos*/
					/*le os outros dados que estão em forma de vetores*/
					for(int i = 0; i < sp.produtos_distintos; i++){
						/*le o resto dos dados*/
						fscanf(arquivo,"%u,%i,%f,%s\n",&sp.codigoproduto[i],&sp.quantidade[i],&sp.precovenda[i],sp.status[i]);
					}
					fscanf(arquivo,"%f\n\n",&sp.totalpagar);
					/*depois de lido todos os dados*/
					/*retornar o codigo incrementado */

					/*verifica antes, se já está no final do arquivo para evitar erros*/
					if(feof(arquivo)){
						break;
					}
				}
				codigo = sp.codigo;
				/*incrementa ele*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		case 2: /*caso 2, arquivo binário*/
			/*abre o arquivo*/
			arquivo = fopen("saves/saidaprodutos.bin","ab+");
			/*verifica o arquivo, se já existia antes ou foi criado agora*/
			if(arquivo == NULL){
				/*o codigo vai ser 0*/
				codigo = 0;
			}
			else{
				/*le o arquivo todo com o while*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&sp,sizeof(struct saidaprodutos),1,arquivo);
					/*verifica se já está no final do arquivo, da um break se tiver*/
					if(feof(arquivo)){
						break;
					}
				}
				codigo = sp.codigo;
				/*recebe e incrementa o código lido*/
				codigo++;
				/*fecha o arquivo*/
				fclose(arquivo);
			}
		break;
		/*tipo de salvamento inválido*/
		default:
			vermelho("\nOpção de salvamento inválida!\n");
		break;
	}
	/*retorna o codigo*/
	return codigo;
}
/*função para autoincrementar o código da reserva*/
int codigoreserva(int tipo){
	/*chama a struct para ter acesso a suas variaveis*/
	struct reserva r;
	int codigo;
	int contalinhas;
	/*cria um ponteiro do tipo arquivo para acessar o arquivo de reservas*/
	FILE *arquivo;
	/*switch para verificar o tipo de salvamento */
	switch(tipo){
		case 1:/*caso 1, arquivo texto*/
			/*abre o arquivo texto*/
			arquivo = fopen("saves/reservas.txt","a+");
			contalinhas = 0;
			/*conta a quantidade de linhas se for igual a 0, o codigo será igual a 1*/
			while(!feof){
				contalinhas++;
			}
			if(contalinhas == 0){
				codigo = 1;
			}
			else{
				/*verifica o arquivo todo*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
						&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,r.status);
					codigo = r.codigo;
					printf("\nFunção codigoreserva:%i\n",codigo);
					/*verifica se já esta no final do arquivo, para evitar repetições indesejadas*/
					if(feof(arquivo)){
						/*sai da laço*/
						break;
					}
				}
				codigo++;
				fclose(arquivo);
			}
		break;
		case 2:/*caso 2, arquivo binário*/
			/*abre o arquivo*/
			arquivo = fopen("saves/reservas.bin","ab+");
			/*verifica se foi criado nessa abertura ou não*/
			contalinhas = 0;
			/*conta a quantidade de linhas se for igual a 0, o codigo será igual a 1*/
			while(!feof){
				contalinhas++;
			}
			if(contalinhas == 0){
				codigo = 1;
			}
			/*senão le o arquivo inteiro e busca o ultimo codigo*/
			else{
				/*le o arquivo com um while*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&r,sizeof(struct reserva),1,arquivo);
					codigo = r.codigo;
					printf("\nFunção codigoreserva:%i\n",codigo);
					/*verifica se já está no final do arquivo*/
					if(feof(arquivo)){
						/*sai do while*/
						break;
					}
				}
				codigo++;
				fclose(arquivo);
			}
		break;
		default:
			/*mensagem de erro para opções de salvamento não implementadas*/
			vermelho("\nOpção de salvamento ainda não implementada!\n");
		break;
	}
	return codigo;
}

/*função para validar o codigo do hospede*/
/*recebe por parametro o codigo do hospede, o tipo de salvamento, o url e modo de abertura*/
int valida_codigohospede(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct hospede h;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de hospede*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				while(contador != 1){
					/*zera o contador para verificar o codigo*/
					contador = 0;
					/*inicia a leitura do arquivo*/
					while(!feof(arquivo)){
						/*le cada dado*/
						fscanf(arquivo,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %i/%i/%i\n %s\n %s\n %s\n %s\n %s\n\n",&h.codigo,h.nome,&h.sexo,
						h.cpf,h.rg,h.rua,h.numero,h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,&h.data_nascimento.dia,
						&h.data_nascimento.mes,&h.data_nascimento.ano,h.telefone,h.celular,h.estadocivil,h.email,h.status);
						/*verifica se há está no final do arquivo*/
						if(feof(arquivo)){
							break;
						}
						if(codigo == h.codigo){
							contador++;
						}
					}
					/*verifica se contador maior diferente de zero, ou seja há algum código como esse cadastrado*/
					if(contador == 1){
						/*se for igual a 1, o codigo digitado está ok*/
						return 1;
					}
					/*se for maior que 1, há valores repitidos no código*/
					else if(contador > 1){
						vermelho("\nErro, há códigos duplicados!\n");
					}
					/*se for diferente desses valores mostra codigo invalido ou nao cadastrado*/
					else{
						vermelho("\nCódigo inválido!\n");
					}
				}
				fclose(arquivo);
			break;
			case 2:
				while(contador != 1){
					/*zera o contador para verificar o codigo*/
					contador = 0;
					/*inicia a leitura do arquivo*/
					while(!feof(arquivo)){
						/*le cada dado*/
						fread(&h,sizeof(struct hospede),1,arquivo);
						/*verifica se há está no final do arquivo*/
						if(feof(arquivo)){
							break;
						}
						if(codigo == h.codigo){
							contador++;
						}
					}
					/*verifica se contador maior diferente de zero, ou seja há algum código como esse cadastrado*/
					if(contador == 1){
						/*se for igual a 1, o codigo digitado está ok*/
						return 1;
					}
					/*se for maior que 1, há valores repitidos no código*/
					else if(contador > 1){
						vermelho("\nErro, há códigos duplicados!\n");
					}
					/*se for diferente desses valores mostra codigo invalido ou nao cadastrado*/
					else{
						vermelho("\nCódigo inválido!\n");
					}
				}
				fclose(arquivo);
			break;
		}
	}	
}

/*função para validar o codigo do ĥotel*/
/*recebe por parametro o codigo do hotel, o tipo de salvamento, o url e modo de abertura*/
int valida_codigohotel(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct hotel ht;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de hotel*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				while(contador != 1){
					/*zera o contador para verificar o codigo*/
					contador = 0;
					/*inicia a leitura do arquivo*/
					while(!feof(arquivo)){
						/*le cada dado*/
						fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status);
						/*verifica se há está no final do arquivo*/
						if(feof(arquivo)){
							break;
						}
						if(codigo == ht.codigo){
							contador++;
						}
					}
					/*verifica se contador maior diferente de zero, ou seja há algum código como esse cadastrado*/
					if(contador == 1){
						/*se for igual a 1, o codigo digitado está ok*/
						return 1;
					}
					/*se for maior que 1, há valores repitidos no código*/
					else if(contador > 1){
						vermelho("\nErro, há códigos duplicados!\n");
					}
					/*se for diferente desses valores mostra codigo invalido ou nao cadastrado*/
					else{
						vermelho("\nCódigo inválido!\n");
					}
				}
				fclose(arquivo);
			break;
			case 2:
				while(contador != 1){
					/*zera o contador para verificar o codigo*/
					contador = 0;
					/*inicia a leitura do arquivo*/
					while(!feof(arquivo)){
						/*le cada dado*/
						fread(&ht,sizeof(struct hotel),1,arquivo);
						/*verifica se há está no final do arquivo*/
						if(feof(arquivo)){
							break;
						}
						if(codigo == ht.codigo){
							contador++;
						}
					}
					/*verifica se contador maior diferente de zero, ou seja há algum código como esse cadastrado*/
					if(contador == 1){
						/*se for igual a 1, o codigo digitado está ok*/
						return 1;
					}
					/*se for maior que 1, há valores repitidos no código*/
					else if(contador > 1){
						vermelho("\nErro, há códigos duplicados!\n");
					}
					/*se for diferente desses valores mostra codigo invalido ou nao cadastrado*/
					else{
						vermelho("\nCódigo inválido!\n");
					}
				}
				fclose(arquivo);
			break;
		}
	}	
}


/*função para validar o codigo do produto*/
/*recebe por parametro o codigo do produto, o tipo de salvamento, o url e modo de abertura*/
int valida_codigoproduto(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct produtos p;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de produto*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.lucro,&p.precovenda,p.status);
					/*verifica se há está no final do arquivo*/
					if(codigo == p.codigo){
						return 1;
					}

					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
			case 2:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(codigo == p.codigo){
						return 1;
					}

					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
		}
	}	
}
/*função para validar o codigo da categoria*/
/*recebe por parametro o codigo da categoria, o tipo de salvamento, o url e modo de abertura*/
int valida_codigocategoria(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct categorias c;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de categoria*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status);
					/*verifica se há está no final do arquivo*/
					
					if(codigo == c.codigo){
						return 1;
					}

					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
			case 2:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fread(&c,sizeof(struct categorias),1,arquivo);
					/*verifica se há está no final do arquivo*/
					
					if(codigo == c.codigo){
						return 1;
					}

					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
		}
	}	
}

/*função para validar o codigo da acomodação*/
/*recebe por parametro o codigo da acomodação, o tipo de salvamento, o url e modo de abertura*/
int valida_codigoacomodacao(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct acomodacoes ac;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de acomodação*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
				&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,&ac.categoriaselecionada,ac.status);
					if(codigo == ac.codigo){
						return 1;
					}
					/**verifica se há está no final do arquivo*/
					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
			case 2:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					
					if(codigo == ac.codigo){
						return 1;
					}

					/*verifica se há está no final do arquivo*/
					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
		}
	}	
}

/*função para validar o codigo da fornecedor*/
/*recebe por parametro o codigo da fornecedor, o tipo de salvamento, o url e modo de abertura*/
int valida_codigofornecedor(int tipo,char url[50],char modoabertura[5],int codigo){
	/*chama a struct do hospede para ter acesso as variaveis*/
	struct fornecedores f;
	int contador;
	/*cria um ponteiro de arquivo para poder abrir o arquivo de fornecedor*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(url,modoabertura);
	/*verifica se há erros na abertura*/
	if(arquivo == NULL){
		/*se houver, mostra erro na tela*/
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:

				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
				f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
				f.trepresentante,f.status);
					
					if(codigo == f.codigo){
						return 1;
					}

					/*verifica se há está no final do arquivo*/
					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
			case 2:
				/*inicia a leitura do arquivo*/
				while(!feof(arquivo)){
					/*le cada dado*/
					fread(&f,sizeof(struct fornecedores),1,arquivo);
					
					if(codigo == f.codigo){
						return 1;
					}

					/*verifica se há está no final do arquivo*/
					if(feof(arquivo)){
						break;
					}
				}
				fclose(arquivo);
				return 0;
			break;
		}
	}	
}

/*função que retorna o valor do quarto, de acordo com o seu código*/
/*recebe por parametro, o tipo de salvamento, o url da acomodação e das categorias, o modo de abertura e o codigo*/
float retorna_valoracomodacao(int tipo,char urlacomodacao[50],char urlcategoria[50],char modoabertura[5],int codigo){
	/*chama as structs de acomodacões e de categorias para ter acesso as suas variaveis*/
	struct acomodacoes ac;
	struct categorias c;
	/*variavel que receberá o valor da acomodação e será retornada */
	float valor = 0;;
	int codigo_categoria;
	/*dois ponteiros de arquivos, um para abrir o arquivo de acomodação e outro para o arquivo de categoria*/
	FILE *arquivo_acomodacao;
	FILE *arquivo_categoria;
	/*abre os arquivos*/
	arquivo_acomodacao = fopen(urlacomodacao,modoabertura);
	arquivo_categoria = fopen(urlcategoria,modoabertura);
	/*verifica se houve erros na abertura do arquivo*/
	if(arquivo_acomodacao == NULL || arquivo_categoria == NULL){
		vermelho("\nErro em retornar o código da Acomodação desejada!\n");
	}
	/*se estiver tudo ok, continua a execução*/
	else{
		/*um switch para verificar o tipo de salvamento*/
		switch(tipo){
			case 1:/*caso 1, arquivo texto*/
				/*um while para ler o arquivo inteiro*/
				while(!feof(arquivo_acomodacao)){
					/*comando de leitura*/
					fscanf(arquivo_acomodacao,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.categoriaselecionada,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,ac.status);
					
					if(codigo == ac.codigo){
						/*pega a categoria selecionada na acomodaçao*/
						codigo_categoria = ac.categoriaselecionada;
					}
					/*depois de lido verifica se está no final do arquivo, para evitar repetições*/
					if(feof(arquivo_acomodacao)){
						break;
					}
				}
				/*agora le o arquivo de categorias*/
				/*um while também para ler o arquivo de cateogorias inteiro*/
				while(!feof(arquivo_categoria)){
					/*comando para leitura*/
					fscanf(arquivo_categoria,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status);
					/*depois de lido verifica o código igual a categoria armazenada*/
					if(c.codigo == codigo_categoria){
						valor = c.valor;
					}
					/*depois de lido verifica se está no final do arquivo, para evitar repetições*/
					if(feof(arquivo_acomodacao)){
						break;
					}
				}
			break;

			case 2:/*caso 2, arquivo binário*/
				/*um while para ler o arquivo inteiro*/
				while(!feof(arquivo_acomodacao)){
					/*comando de leitura*/
					fread(&ac,sizeof(struct acomodacoes),1,arquivo_acomodacao);
					if(codigo == ac.codigo){
						/*pega a categoria selecionada na acomodaçao*/
						codigo_categoria = ac.categoriaselecionada;
					}
					/*depois de lido verifica se está no final do arquivo, para evitar repetições*/
					if(feof(arquivo_acomodacao)){
						break;
					}
				}
				/*agora le o arquivo de categorias*/
				/*um while também para ler o arquivo de cateogorias inteiro*/
				while(!feof(arquivo_categoria)){
					/*comando para leitura*/
					fread(&c,sizeof(struct categorias),1,arquivo_categoria);
					/*depois de lido verifica o código igual a categoria armazenada*/
					if(c.codigo == codigo_categoria){
						valor = c.valor;
					}
					/*depois de lido verifica se está no final do arquivo, para evitar repetições*/
					if(feof(arquivo_acomodacao)){
						break;
					}
				}
			break;
			/*mensagem de erro para opções de salvamento ainda não implementadas*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
	return valor;
}

/*função para retornar o código de um usuário de acordo com o cpf digitado*/
/*recebe por parametro o tipo de salvamento, url do hospede, o modo de abertura e o cpf*/
int codigo_hospede_cpf(int tipo,char urlhospede[50],char modoabertura[5],char cpf[14]){
	/*chama a struct de hospede para acessar as variaveis*/
	struct hospede h;
	/*ponteiro de arquivo para abrir o arquivo de hospedes*/
	FILE *arquivo;
	/*abre o arquivo*/
	arquivo = fopen(urlhospede,modoabertura);
	/*verifica se o arquivo foi aberto corretamente*/
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo de Hospedes!\n");
	}
	/*se estiver tudo ok, continua a execução*/
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			case 1:/*arquivo texto*/
				/*le o arquivo todo com um while*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fscanf(arquivo,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %i/%i/%i\n %s\n %s\n %s\n %s\n %s\n\n",&h.codigo,h.nome,&h.sexo,
						h.cpf,h.rg,h.rua,h.numero,h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,&h.data_nascimento.dia,
						&h.data_nascimento.mes,&h.data_nascimento.ano,h.telefone,h.celular,h.estadocivil,h.email,h.status);
					/*se o cpf, foi igual a algum cpf, retorna o código do hospede, senão retorna 0*/
					if(strcmp(cpf,h.cpf) == 0){
						return h.codigo;
					}
					/*verifica se está no final do arquivo para evitar repetições indesejadas*/
					if(feof(arquivo)){
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				return 0;
			break;
			case 2:/*arquivo binário*/
				/*um while para ler o arquivo até o final*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&h,sizeof(struct hospede),1,arquivo);
					/*se o cpf, foi igual a algum cpf, retorna o código do hospede, senão retorna 0*/
					if(strcmp(cpf,h.cpf) == 0){
						return h.codigo;
					}
					/*verifica se está no final do arquivo para evitar repetições indesejadas*/
					if(feof(arquivo)){
						break;
					}
				}
				/*fecha o arquivo*/
				fclose(arquivo);
				return 0;
			break;
			default:/*erro para opções de salvamento invalidas*/
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
#endif 