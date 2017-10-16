#ifndef CONSULTA_H
#define CONSULTA_H

#include <string.h>
#include <stdio.h>
#include "structs.h"

/*funcao para realizar a consulta do hospede*/
void consultahospede(int tipo){
	/*faço a chamada da struct, para ter acesso as variaveis do hospede*/
	struct hospede h;
	//crio um ponteiro do tipo arquivo para poder guardar a posicao dos dados do arquivo na memoria
	FILE *arquivo;
	switch(tipo){
		case 1:
			/*abro o arquivo*/
			arquivo = fopen("saves/hospedes.txt","a+");
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
				/*e no fim fecho o ponteiro do arquivo*/
				fclose(arquivo);
			}	
		break;
		/*caso 2, verifica em binario*/
		case 2:
			/*abre o arquivo*/
			arquivo = fopen("saves/hospedes.bin","ab+");
			/*verifica se ele pode ser aberto ou existe*/
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta ou Não Foram encontrados hospedes cadastrados\n\n");
			}
			/*se foi aberto, verifica os dados no arquivo*/
			else{
				/*enquanto nao for o final do arquivo vai mostrando os dados*/
				printf("\nDados dos Usuários\n\n");
				while(!feof(arquivo)){
					/*verifica se ja alcancou o final do arquivo*/
					fread(&h,sizeof(struct hospede),1,arquivo);
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}		
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
					printf("\nStatus: %s\n\n",h.status);
					printf("\n----------------------------------------------------------------------------\n");
					
				}
			}
			/*e no final fecha o ponteiro*/
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}

void consultahotel(int tipo){
	struct hotel ht;
	FILE *arquivo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hoteis.txt","a+");
			if(arquivo == NULL){
				printf("Erro em realizar a consulta ou Não foram encontrados hotéis cadastrados\n\n");	
			}
			else{
				printf("\nDados do(s) Hotel(éis)\n\n");
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
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
					printf("\nStatus: %s\n\n",ht.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				fclose(arquivo);
			}	
		break;
		case 2:
			arquivo = fopen("saves/hoteis.bin","ab+");
			if(arquivo == NULL){
				printf("Erro em realizar a consulta ou Não foram encontrados hotéis cadastrados\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&ht,sizeof(struct hotel),1,arquivo);
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
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
					printf("\nStatus: %s\n\n",ht.status);
					printf("\n----------------------------------------------------------------------------\n");
				}	
				
			}
			fclose(arquivo);
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
void consultaproduto(int tipo){
	struct produtos p;
	FILE *arquivo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/produtos.txt","a+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta ou Não foram encontrados produtos cadastrados\n\n");
			}
			else{
				printf("\nDados do(s) Produto(s)\n\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.precocusto,&p.precovenda,p.status)!= EOF){
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nPreço de Custo: R$%.2f",p.precocusto);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s\n\n",p.status);
					printf("\n----------------------------------------------------------------------------\n");
					/*verifica se ja alcancou o final do arquivo*/
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				fclose(arquivo);		
			}
		break;
		case 2:
			arquivo = fopen("saves/produtos.bin","ab+");
			if(arquivo == NULL){
				printf("\nErro em realizar a consulta ou Não foram encontrados produtos cadastrados\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
					printf("\n----------------------------------------------------------------------------\n");
					printf("Código: %u",p.codigo);
					printf("\nDescrição: %s",p.descricao);
					printf("\nEstoque: %i",p.estoque);
					printf("\nEstoque Minimo: %i",p.estoqueminimo);
					printf("\nPreço de Custo: R$%.2f",p.precocusto);
					printf("\nPreço de Venda: R$%.2f",p.precovenda);
					printf("\nStatus: %s\n\n",p.status);
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

void consultaacomodacao(int tipo){
	struct acomodacoes ac;
	FILE *arquivo;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/acomodacoes.txt","a+");
			if(arquivo == NULL){
				printf("Erro em realizar a consulta ou não foram encontrados quartos cadastradas\n\n");
			}
			else{
				printf("Acomodações cadastradas((valores númericos representam quantidade)não considerando a categoria): \n\n");
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,&ac.categoriaselecionada,ac.status) != EOF){
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
					printf("\nStatus: %s\n\n",ac.status);
					printf("\n----------------------------------------------------------------------------\n");
					if(feof(arquivo)){
						/*se ja sai do laco*/
						break;
					}
				}
				fclose(arquivo);
			}
		break;
		case 2:
			/*consulta em binário*/
			arquivo = fopen("saves/acomodacoes.bin","ab+");
			if(arquivo == NULL){
				printf("Erro em realizar a consulta ou não foram encontrados quartos cadastradas\n\n");	
			}
			else{
				printf("Acomodações cadastradas((valores númericos representam quantidade)não considerando a categoria): \n\n");
				while(!feof(arquivo)){
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					if(feof(arquivo)){
						break;
					}
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
					printf("\nStatus: %s\n\n",ac.status);
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

void consultacategoria(int tipo){
	struct categorias c;
	FILE *arquivo;
	switch(tipo){
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
				printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
				printf("\nStatus: %s\n",c.status);
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
					printf("\nNúmero de Adultos: %i, Número de Crianças: %i\n",c.quantidadeadultos,c.quantidadecriancas);
					printf("\nStatus: %s\n",c.status);
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
					printf("\nStatus: %s\n\n",f.status);
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
					printf("\nStatus: %s\n\n",f.status);
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
			printf("Código: %u",u.codigo);
			printf("\nNome do Usuário: %s",u.nome);
			printf("\nLogin: %s",u.login);
			t = strlen(u.senha);
			printf("\nSenha: ");
			for(int i = 0; i < t; i++){
				printf("*");
			}
			printf("\nPermissão: %i",u.permissao);
			printf("\nStatus: %s\n\n",u.status);
			
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
		codigo = 0;
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if(feof(arquivo)){
				break;
			}
			codigo = u.codigo;
		}
		printf("\n%i\n", u.codigo);
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