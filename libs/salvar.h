#ifndef SALVAR_H
#define SALVAR_H

#include "structs.h"
#include <string.h>
#include <locale.h>
#include "config.h"
#include "cores.h"
/*********Comentar*******************/
/*funcao para salvar para o hospede no arquivo texto*/
void salvarhospede(int tipo,char url[50],char modoabertura[5]){
	/*chama a struct hospede para usar as variaveis do hospede*/
	struct hospede h;
	setlocale(LC_ALL, "Portuguese");
	/*coloca um ponteiro para armazenar a localizacao do arquivo*/
	FILE *arquivo;
	switch(tipo){
		/*no primeiro caso, salva em arquivo texto*/
		case 1:
			/*abre o arquivo texto*/
			arquivo = fopen(url,modoabertura);
			/*verifica o arquivo texto*/
			if(arquivo == NULL){
				/*se for nulo, ou seja nao foi encontrado, mostra uma mensagem de erro*/
				vermelho("\nErro em realizar o cadastro do hóspede no arquivo texto!!\n\n");
			}
			/*senao faz a insersao do arquivo*/
			else{
				fprintf(arquivo,"%u",h.codigo);
				fprintf(arquivo,"\n%s",h.nome);
				fprintf(arquivo,"\n%i",h.sexo);
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
				/*mostra aviso sobre o sucesso de envio de dados*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*e por fim fecha o arquivo*/
			fclose(arquivo);
		break;
		/*no segundo caso, salva em binario*/
		case 2:
			//*abre o arquivo binario*//
			arquivo = fopen(url,modoabertura);
			/*caso o arquivo nao exista o ponteiro retornara nulo*/
			if(arquivo == NULL){
				vermelho("Erro em realizar o cadastro do hóspede no arquivo binário!!\n\n");
			}
			/*caso exista sera inserido os dados em binario*/
			else{
				fwrite(&h,sizeof(struct hospede),1,arquivo);
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*e por fim fecha o ponteiro*/
			fclose(arquivo);
		break;
		default:
		/*mostra aviso, caso o usuário tenha escolhido uma opção inválida*/
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void salvarhotel(int tipo,char url[50],char modoabertura[5]){
	//realizo a chamada da struct hotel, para ter acesso as variaveis relacionadas a essa struct
	struct hotel ht;
	//coloca o local padrão como portugues, assim pegará todos os acentos.
	setlocale(LC_ALL,"Portuguese");
	//crio uma variavel do tipo arquivo com um ponteiro para que possa criar e salvar dados em um arquivo, nesse caso txt
	FILE *arquivo;
	switch(tipo){
		case 1:
		/*abre o arquivo texto*/
			arquivo = fopen(url,modoabertura);
			//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de hotel!!\n\n");
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
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			//ao final do salvamento, finalizo o ponteiro e encerro o salvamento de arquivos
			fclose(arquivo);
		break;
		case 2:
		/*abre o arquivo binário*/
			arquivo = fopen(url,modoabertura);
			/*verifica se o arquivo foi aberto*/
			/*caso houver erro, mostra mensagem de erro na tela*/
			if(arquivo == NULL){
				vermelho("Erro em realizar o cadastro do hotel no arquivo binário!!\n\n");
			}
			/*se estiver tudo ok, salva os dados no arquivo*/
			else{
				/*fwrite, nomestruct,tamanhostruct,quantidade,ponteiroarquivo*/
				fwrite(&ht,sizeof(struct hotel),1,arquivo);
				/*mostra mensagem de sucesso ao usuário*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mostra aviso, para opções que não foram implementadas, caso sejam escolhidas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}

void salvarcategorias(int tipo,char url[50],char modoabertura[5]){
	struct categorias c;
	//chama a struct categorias para ter acesso a suas variaveis
	setlocale(LC_ALL,"Portuguese");
	//coloca como linguagem padrao a portuguesa
	FILE *arquivo;
	switch(tipo){
		case 1:
			//crio um ponteiro que apontara para a localizacao do arquivo
			arquivo = fopen(url,modoabertura);
			//abro o arquivo
			//agora verifico se o arquivo existe, senao sera criado na hora
			//senao for criado da mensagem de erro
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de categoria!!\n\n");
			}
			//se for criado salva os dados no arquivo txt
			else{
				fprintf(arquivo,"%u",c.codigo);
				fprintf(arquivo,"\n%s",c.descricao);
				fprintf(arquivo,"\n%.2f",c.valor);
				fprintf(arquivo,"\n%i",c.quantidadeadultos);
				fprintf(arquivo,"\n%i",c.quantidadecriancas);
				fprintf(arquivo,"\n%s\n\n",c.status);
				/*mostra mensagem de sucesso ao usuário*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		case 2:
		/*abre o arquivo binario*/
			arquivo = fopen(url,modoabertura);
			/*verifica se o arquivo foi aberto*/
			/*caso haja erro, mostra mensagem de erro na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de categoria!!\n\n");
			}
			/*se estiver tudo ok, salva os dados no arquivo*/
			else{
				fwrite(&c,sizeof(struct categorias),1,arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mensagem de erro para tipos de salvamento ainda não implementados*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
	
}
	
void salvaracomodacao(int tipo,char url[50],char modoabertura[5]){
	//realizo a chamada da struct acomodacoes, para ter acesso as variaveis relacionadas a essa struct
	struct acomodacoes ac;
	//coloca o local padrão como portugues, assim pegará todos os acentos.
	setlocale(LC_ALL,"Portuguese");
	//crio uma variavel do tipo arquivo com um ponteiro para que possa criar e salvar dados em um arquivo, nesse caso txt
	FILE *arquivo;
	switch(tipo){
		case 1:
			arquivo = fopen(url,modoabertura);
			//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de acomodações!!\n\n");
			}
			//senão houver nenhum problema, salva os arquivos no txt que foi criado
			else{
				fprintf(arquivo,"%u",ac.codigo);
				fprintf(arquivo,"\n%s",ac.descricao);
				fprintf(arquivo,"\n%i",ac.extra.tv);
				fprintf(arquivo,"\n%i",ac.extra.tvcabo);
				fprintf(arquivo,"\n%i",ac.extra.arcondicionado);
				fprintf(arquivo,"\n%i",ac.extra.frigobar);
				fprintf(arquivo,"\n%i",ac.extra.banheiro);
				fprintf(arquivo,"\n%i",ac.extra.camacasal);
				fprintf(arquivo,"\n%i",ac.extra.camasolteiro);
				fprintf(arquivo,"\n%i",ac.extra.hidromassagem);
				fprintf(arquivo,"\n%i",ac.extra.banheira);
				fprintf(arquivo,"\n%i",ac.categoriaselecionada);
				fprintf(arquivo,"\n%s\n\n",ac.status);
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		case 2:
		/*abre o arquivo binario*/
			arquivo = fopen(url,modoabertura);
			/*verifica se houve erro na abertura do arquivo*/
			/*se houver erro, mostra mensagem de erro*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de acomodações!!\n\n");
			}
			/*se estiver tudo ok, salva os dados no arquivo e mostra mensagem de sucesso*/
			else{
				fwrite(&ac,sizeof(struct acomodacoes),1,arquivo);
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			fclose(arquivo);
		break;
		default:
		/*mensagem de erro para tipos de save ainda não implementados*/
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void salvarproduto(int tipo,char url[50],char modoabertura[5]){
	//chama a struct produtos para ter acesso as variaveis dela
	struct produtos p;
	//seta o local padrão, ou seja o idioma que deve ser interpretado como portugues
	setlocale(LC_ALL,"Portuguese");
	FILE *arquivo;
	switch(tipo){
		/*caso 1 salvar em txt*/
		case 1:
			arquivo = fopen(url,modoabertura);
			//verifico se esta nulo o arquivo, ou seja ocorrerá algum erro no salvamento
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de produtos!!\n");
			}
			//senão houver nenhum problema, salva os arquivos no txt que foi criado
			else{
				fprintf(arquivo,"%u",p.codigo);
				fprintf(arquivo,"\n%s",p.descricao);
				fprintf(arquivo,"\n%i",p.estoque);
				fprintf(arquivo,"\n%i",p.estoqueminimo);
				fprintf(arquivo,"\n%.2f",p.lucro);
				fprintf(arquivo,"\n%.2f",p.precovenda);
				fprintf(arquivo,"\n%s\n\n",p.status);
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*caso 2 salvar em binario*/
		case 2:
			/*tenta abrir o arquivo*/
			arquivo = fopen(url,modoabertura);
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de produtos!!\n");
			}
			/*se der tudo certo*/
			else{
				/*salva os dados no arquivo binario*/
				fwrite(&p,sizeof(struct produtos),1,arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*mostra mensagem de erro para opções de save ainda não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	} 
	
}

void salvarfornecedor(int tipo,char url[50],char modoabertura[5]){
	/*chama a struct do forncedor para ter acesso as suas variaveis*/
	struct fornecedores f;
	/*seta o linguagem local como portugues para evitar erros de leitura*/
	setlocale(LC_ALL,"Portuguese");
	/*cria um ponteiro de arquivo*/
	FILE *arquivo;
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*se for tipo 1 ou txt*/
		case 1:
		/*abre o arquivo*/
			arquivo = fopen(url,modoabertura);
			/*verifica se sua abertura aconteceu*/
			/*se houver algum erro, mostra mensagem de erro*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de fornecedores!!\n");
			}
			/*senão salva os dados daquele forneceodr*/
			else{
				/*fprintf, comando para salvar no arquivo, no caso de arquivo do tipo texto*/
				/*como parametro é passado o ponteiro do arquivo, a codificação do item ex: %i, e a variavel da struct*/
				fprintf(arquivo,"%u",f.codigo);
				fprintf(arquivo,"\n%s",f.nomefantasia);
				fprintf(arquivo,"\n%s",f.razaosocial);
				fprintf(arquivo,"\n%s",f.cnpj);
				fprintf(arquivo,"\n%s",f.insc);
				fprintf(arquivo,"\n%s",f.rua);
				fprintf(arquivo,"\n%s",f.numero);
				fprintf(arquivo,"\n%s",f.bairro);
				fprintf(arquivo,"\n%s",f.cep);
				fprintf(arquivo,"\n%s",f.complemento);
				fprintf(arquivo,"\n%s",f.cidadeestado.cidade);
				fprintf(arquivo,"\n%s",f.cidadeestado.estado);
				fprintf(arquivo,"\n%s",f.telefone);
				fprintf(arquivo,"\n%s",f.celular);
				fprintf(arquivo,"\n%s",f.email);
				fprintf(arquivo,"\n%s",f.nrepresentante);
				fprintf(arquivo,"\n%s",f.trepresentante);
				fprintf(arquivo,"\n%s\n\n",f.status);
				/*mostra a mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);
		break;
		/*se for o tipo 2, ou binario*/
		case 2:
		/*abre o arquivo binario*/
			arquivo = fopen(url,modoabertura);
			/*verifica se o arquivo foi aberto*/
			/*caso tenha acontecido algum erro mostra mensagem na tela*/
			if(arquivo == NULL){
				vermelho("\nErro em realizar o cadastro de fornecedores!!\n");	
			}
			/*se deu tudo certo salva os dados no arquivo*/
			else{
				/*fwrite, comando para salvar dados no arquivo, &nomestruct,tamanhostruct, quantidadededadossalva,arquivo*/
				fwrite(&f,sizeof(struct fornecedores),1,arquivo);
				/*mostra mensagem de sucesso*/
				verde("\nDados foram salvos com sucesso!\n\n");
			}
			/*fecha o arquivo*/
			fclose(arquivo);	
		break;
		/*mostra mensagem caso seja alguma opção diferente das já implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void salvarusuarios(char url[50],char modoabertura[5]){
	struct usuarios u;
	//faço a chamada da struct, para ter acesso as varíaveis desta;*/
	/*coloco como linguagem obrigatória, o português, para evitar certos problemas de acentuação*/
	setlocale(LC_ALL,"Portuguese");
	FILE *arquivo;
	arquivo = fopen(url,modoabertura);
	//verifico a nulidade do arquivo que sera criado
	if(arquivo == NULL){
		vermelho("\nErro em realizar o cadastro de usuário!\n");
	}
	/*se estiver tudo ok, salva o arquivo*/
	else{
		fwrite(&u,sizeof(struct usuarios),1,arquivo);
		verde("\nDados salvos com sucesso!\n");
	}
	//fecha o arquivo
	fclose(arquivo);
}
#endif