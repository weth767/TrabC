#ifndef EDICAO_H
#define EDICAO_H

#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cores.h"
#include "consulta.h"
/*função para editar os dados dos hospedes*/
/*recebe por parametro o tipo de salvamento,url original e temporario e o modo de abertura*/
void editahospede(int tipo,char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct de hospode para acessar suas variaveis*/
	struct hospede h;
	/*cria dois ponteiros de arquivo, um para o arquivo original e um para o temporario*/
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	int verifica;
	ciano("\nEdição de Hospedes!\n");
	setbuf(stdin,NULL);
	/*recebe o codigo que sera editado*/
	printf("Digite o código do hospede a ser editado: ");
	scanf("%i",&codigo);
	setbuf(stdin,NULL);
	/*verifica o tipo de salvamento*/
	/*abre os arquivos, original e temporario*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica o se houve erro na abertura dos dois arquivos*/
	/*se houver, mostra mensagem de erro */
	if(arquivo2 == NULL || arquivo == NULL){
		vermelho("\nErro em localizar o arquivo de hospedes!!\n\n");
	}
	else{
		/*se estiver tudo ok...*/
		switch(tipo){
			/*for o tipo de salvamento 1, arquivo texto*/
			case 1:
				/*a variavel verifica recebe 0, para controlar quando será escolhido uma opção para edição*/
				verifica = 0;
				/*verifica o arquivo todo, armazenando um hospede por vez */
				while(fscanf(arquivo,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,&h.sexo,h.cpf,h.rg,h.rua,h.numero,
					h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
					/*verifica se o codigo lido é diferente do codigo digitado*/
					/*se for, salva os dados no arquivo temporario*/
					if(h.codigo != codigo){
						fprintf(arquivo2,"%u",h.codigo);
						fprintf(arquivo2,"\n%s",h.nome);
						fprintf(arquivo2,"\n%i",h.sexo);
						fprintf(arquivo2,"\n%s",h.cpf);
						fprintf(arquivo2,"\n%s",h.rg);
						fprintf(arquivo2,"\n%s",h.rua);
						fprintf(arquivo2,"\n%s",h.numero);
						fprintf(arquivo2,"\n%s",h.bairro);
						fprintf(arquivo2,"\n%s",h.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",h.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",h.cep);
						fprintf(arquivo2,"\n%s",h.complemento);
						fprintf(arquivo2,"\n%s",h.datanascimento);
						fprintf(arquivo2,"\n%s",h.telefone);
						fprintf(arquivo2,"\n%s",h.celular);
						fprintf(arquivo2,"\n%s",h.estadocivil);
						fprintf(arquivo2,"\n%s",h.email);
						fprintf(arquivo2,"\n%s\n\n",h.status);
					}
					/*se for igual o codigo*/
					else{
						/*mostra o hospede selecionado*/
						azulclaro("\nHospede selecionado: \n\n");
						printf("Código: %u",h.codigo);
						printf("\nNome: %s",h.nome);
						printf("\nSexo: %i",h.sexo);
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
						printf("\nStatus: %s\n",h.status);
						/*recebe a opção que será de qual dado será editado*/
						branco("\nDigite o que será editado:\n1 - Nome\n2 - CPF\n3 - RG\n4 - Rua\n5 - Número\n6 - Bairro\n7 - CEP\n8 - Complemento\n9 - Cidade\n10 - Estado\n11 - Data de Nascimento\n12 - Telefone\n"
							"13 - Celular\n14 - Estado Cívil\n15 - E-mail\n16 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica a opção de edição*/
						/*para opções de edições validas, verifica recebe o valor 1*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*para o tipo 1, edita o nome do hospede*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
								verifica = 1;
							break;
							/*para o tipo 2, edita o cpf do hospede*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
								verifica = 1;
							break;
							case 3:
							/*para o tipo 3, edita o rg do hospede*/
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
								verifica = 1;
							break;
							/*para o tipo 4, edita a rua da casa do hospede*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
								verifica = 1;
							break;
							/*para o tipo 5, edita o numero da casa do hospede */
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
								verifica = 1;
							break;
							/*para o tipo 6, edita o bairro da casa do hospede*/
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
								verifica = 1;
							break;
							/*para o tipo 7, edita o cep da casa do hospede*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
								verifica = 1;
							break;
							/*para o tipo 8, edita o complemento da casa do hospede*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
								verifica = 1;
							break;
							/*para o tipo 9, edita a cidade de residencia do hospede*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
								verifica = 1;
							break;
							/*para o tipo 10, edita o estado de residencia do hospede*/
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
								verifica = 1;
							break;
							/*para o tipo 11, edita a data de nascimento do hospede*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
								verifica = 1;
							break;
							/*para o tipo 12, edita o telefone do hospede*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
								verifica = 1;
							break;
							/*para o tipo 13, edita o celular do hospede*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
								verifica = 1;
							break;
							/*para o tipo 14, edita o estado civil do hospede*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
								verifica = 1;
							break;
							/*para o tipo 15, edita o email do hospede*/
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
								verifica = 1;
							break;
							/*para o tipo 16, edita o sexo do hospede*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o Sexo do Hóspede:\n1 - Masculino\n 2 - Feminino\n3 - Outros\n: ");
								scanf("%i",&h.sexo);
								verifica = 1;
							break;
							/*para o tipo 17, edita o status do hospede*/
							case 17:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
								verifica = 1;
							break;
							/*e outra opção que não seja as listadas acima, mostra mensagem de erro*/
							default:
								vermelho("\nOpção invalida!!\n");
								remove(urltemp);
							break;
						}
					}
				}
				/*verifica igual 1, quer dizer que algo será editado*/	
				if(verifica == 1){
					/*então salva o dado novo junto com os antigos nao alterados*/
					/*salva no arquivo temporario*/
					fprintf(arquivo2,"%u",h.codigo);
					fprintf(arquivo2,"\n%s",h.nome);
					fprintf(arquivo2,"\n%i",h.sexo);
					fprintf(arquivo2,"\n%s",h.cpf);
					fprintf(arquivo2,"\n%s",h.rg);
					fprintf(arquivo2,"\n%s",h.rua);
					fprintf(arquivo2,"\n%s",h.numero);
					fprintf(arquivo2,"\n%s",h.bairro);
					fprintf(arquivo2,"\n%s",h.cidadeestado.cidade);
					fprintf(arquivo2,"\n%s",h.cidadeestado.estado);
					fprintf(arquivo2,"\n%s",h.cep);
					fprintf(arquivo2,"\n%s",h.complemento);
					fprintf(arquivo2,"\n%s",h.datanascimento);
					fprintf(arquivo2,"\n%s",h.telefone);
					fprintf(arquivo2,"\n%s",h.celular);
					fprintf(arquivo2,"\n%s",h.estadocivil);
					fprintf(arquivo2,"\n%s",h.email);
					fprintf(arquivo2,"\n%s\n\n",h.status);
					/*mostra mensagem de sucesso*/
					verde("\nDados alterados com sucesso!\n\n");
					/*remove o arquivo antigo, original*/
					remove(url);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
					/*fecha os dois arquivos*/
					fclose(arquivo);
					fclose(arquivo2);
				}
			break;
			/*tipo de salvamento 2, arquivo binario*/
			case 2:
				/*verifica receberá 0 para depois ser verificado as opções de edição*/
				verifica = 0;
				/*le o arquivo todo, armazenando cada hospede por vez*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&h,sizeof(struct hospede),1,arquivo);
					/*verifica se o codigo lido é diferente do codigo digitado*/
					if(h.codigo != codigo){
						/*se for salva os dados para todos diferentes no arquivo temporario*/
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
					}
					/*se for igual ao codigo digitado*/
					else{
						/*verifica se ja esta no final do arquivo para nao ter bug de repetião*/
						if(feof(arquivo)){
							/*se tiver, sai do laço*/
							break;
						}
						/*mostra o hospede selecionado*/
						azulclaro("\nHospede selecionado: \n\n");
						printf("Código: %u",h.codigo);
						printf("\nNome: %s",h.nome);
						printf("\nSexo: %i",h.sexo);
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
						printf("\nStatus: %s\n",h.status);
						/*recebe a opção que será de qual dado será editado*/
						branco("\nDigite o que será editado:\n1 - Nome\n2 - CPF\n3 - RG\n4 - Rua\n5 - Número\n6 - Bairro\n7 - CEP\n8 - Complemento\n9 - Cidade\n10 - Estado\n11 - Data de Nascimento\n12 - Telefone\n"
							"13 - Celular\n14 - Estado Cívil\n15 - E-mail\n16 - Sexo\n17 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica a opção de edição digitado*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*para o tipo 1, edita o nome do hospede*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo nome: ");
								scanf("%[^\n]s",h.nome);
								verifica = 1;
							break;
							/*para o tipo 2, edita o cpf do hospede*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo CPF: ");
								scanf("%[^\n]s",h.cpf);
								verifica = 1;
							break;
							case 3:
							/*para o tipo 3, edita o rg do hospede*/
								setbuf(stdin,NULL);
								printf("Digite o novo RG: ");
								scanf("%[^\n]s",h.rg);
								verifica = 1;
							break;
							/*para o tipo 4, edita a rua da casa do hospede*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua: ");
								scanf("%[^\n]s",h.rua);
								verifica = 1;
							break;
							/*para o tipo 5, edita o numero da casa do hospede */
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",h.numero);
								verifica = 1;
							break;
							/*para o tipo 6, edita o bairro da casa do hospede*/
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",h.bairro);
								verifica = 1;
							break;
							/*para o tipo 7, edita o cep da casa do hospede*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",h.cep);
								verifica = 1;
							break;
							/*para o tipo 8, edita o complemento da casa do hospede*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",h.complemento);
								verifica = 1;
							break;
							/*para o tipo 9, edita a cidade de residencia do hospede*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",h.cidadeestado.cidade);
								verifica = 1;
							break;
							/*para o tipo 10, edita o estado de residencia do hospede*/
							case 10:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",h.cidadeestado.estado);
								verifica = 1;
							break;
							/*para o tipo 11, edita a data de nascimento do hospede*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o nova Data de Nascimento: ");
								scanf("%[^\n]s",h.datanascimento);
								verifica = 1;
							break;
							/*para o tipo 12, edita o telefone do hospede*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",h.telefone);
								verifica = 1;
							break;
							/*para o tipo 13, edita o celular do hospede*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",h.celular);
								verifica = 1;
							break;
							/*para o tipo 14, edita o estado civil do hospede*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado Cívil: ");
								scanf("%[^\n]s",h.estadocivil);
								verifica = 1;
							break;
							/*para o tipo 15, edita o email do hospede*/
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",h.email);
								verifica = 1;
							break;
							/*para o tipo 16, edita o sexo do hospede*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o Sexo do Hóspede:\n1 - Masculino\n 2 - Feminino\n3 - Outros\n: ");
								scanf("%i",&h.sexo);
								verifica = 1;
							break;
							/*para o tipo 17, edita o status do hospede*/
							case 17:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",h.status);
								verifica = 1;
							break;
							/*e outra opção que não seja as listadas acima, mostra mensagem de erro*/
							default:
								vermelho("\nOpção invalida!!\n");
								remove(urltemp);
							break;
						}
					}
				}
				/*se o verifica for igual a 1, foi escolhida alguma opção de edição*/
				if(verifica == 1){
					/*salva o dado novo, junto com os velhos no arquivo temporario*/
					fwrite(&h,sizeof(struct hospede),1,arquivo2);
					/*mostra mensagem de suceso*/
					verde("\nDados alterados com sucesso!\n\n");
					/*remove o arquivo original*/
					remove(url);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
					/*fecha os dois arquivos*/
					fclose(arquivo);
					fclose(arquivo2);
				}
			break;
			/*mostra mensagem de erro para opções de salvamento ainda não implementadas*/
			default:
				vermelho("\nOpcao ainda não implementada ou não existente\n\n");		
			break;
		}
	}	
}
/*função para editar os dados do hotel*/
/*recebe por parametro o tipo de salvamento*/
void editahotel(int tipo,char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct, para ter acesso a suas variaveis*/
	struct hotel ht;
	/*cria os dois ponteiros para ter acesso aos arquivos*/
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	int verifica;
	ciano("\nEdição de Hotel(is)!\n");
	/*recebe o codigo que sera editado*/
	printf("Digite o codigo a ser editado: ");
	scanf("%i",&codigo);
	/*abre os dois arquivos, o original e o temporario*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica se houve erro na abertura dos arquivos*/
	/*se houve mostra mensagem de erro na tela*/
	if(arquivo2 == NULL || arquivo == NULL){
		vermelho("\nErro em localizar o arquivo de hotel!\n");
	}
	else{
		/*se esta tudo ok, */
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*se for o tipo 1, arquivo txt*/
			case 1:
				/*verifica recebe o valor 0, que será usado para verifica se alguma opção de edição foi escolhida*/
				verifica = 0;
				/*le o arquivo, armazenando por vez, um hotel*/
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,
					ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
					/*verifica se o codigo lido é diferente do digitado*/
					if(ht.codigo != codigo){
						/*se for salva os dados no arquivo temporario*/
						fprintf(arquivo2,"%u",ht.codigo);
						fprintf(arquivo2,"\n%s",ht.nomefantasia);
						fprintf(arquivo2,"\n%s",ht.razaosocial);
						fprintf(arquivo2,"\n%s",ht.cnpj);
						fprintf(arquivo2,"\n%s",ht.insc);
						fprintf(arquivo2,"\n%s",ht.rua);
						fprintf(arquivo2,"\n%s",ht.numero);
						fprintf(arquivo2,"\n%s",ht.bairro);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",ht.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",ht.cep);
						fprintf(arquivo2,"\n%s",ht.complemento);
						fprintf(arquivo2,"\n%s",ht.telefone);
						fprintf(arquivo2,"\n%s",ht.email);
						fprintf(arquivo2,"\n%s",ht.nomeresponsavel);
						fprintf(arquivo2,"\n%s ",ht.telefoneresponsavel);
						fprintf(arquivo2,"\n%s\n\n",ht.status);	
					}
					/*se for igual*/
					else{
						/*mostra o hotel selecionado*/
						azulclaro("\nHotel selecionado:\n\n");
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
						/*recebe a opção de edição selecionada*/
						branco("Digite o que será editado:\n1 - Nome Fantasia\n2 - Razão Social\n3 - CNPJ\n4 - Inscrição Estadual\n5 - Rua\n6 - Número\n7 - Bairro\n8 - CEP\n9 - Complemento\n10 - Cidade\n11 - Estado\n12 - Telefone\n13 - E-Mail\n"
						"14 - Nome do Responsável\n15 - Telefone do Responsável\n16 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica essa opção*/
						/*variavel verifica recebe 1 nos valores de edição validos*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso seja igual a 1, edita o nome fantasia*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",ht.nomefantasia);
								verifica = 1;
							break;
							case 2:
							/*caso for igual a 2, edita a razao social*/
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
								verifica = 1;
							break;
							/*caso for igual a 3, edita o cnpj*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
								verifica = 1;
							break;
							/*caso for iugal a 4, edita a inscrição estadual*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
								verifica = 1;
							break;
							/*caso for igual a 5, edita a rua onde se encontra o hotel*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
								verifica = 1;
							break;
							case 6:
							/*caso for igual a 6, edita o numero onde se encontra o hotel*/
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
								verifica = 1;
							break;
							/*caso for igual a 7, edita o bairro onde se encontra o hotel*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
								verifica = 1;
							break;
							/*caso for igual a 8, edita o cep de onde se encontra o hotel*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
								verifica = 1;
							break;
							/*caso for igual a 9 edita o complemento do hotel*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
								verifica = 1;
							break;
							case 10:
							/*caso for igual a 10, edita a cidade onde se encontra o hotel*/
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
								verifica = 1;
							break;
							/*caso for igual a 11, edita o estado onde se encontra o hotel*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
								verifica = 1;
							break;
							/*caso for igual a 12, edita o telefone do hotel*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
								verifica = 1;
							break;
							/*caso for igual a 13, edita o email do hotel*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
								verifica = 1;
							break;
							/*caso for igual a 14, edita o nome do responsavel do hotel*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
								verifica = 1;
							break;
							case 15:
							/*caso for igual a 15, edita o telefone do responsavel do hotel*/
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
								verifica = 1;
							break;
							/*caso for igual a 16, edita o status do hotel*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
								verifica = 1;
							break;
							/*caso for uma opção diferente das listadas acima mostra mensagem de erro*/
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
							
					}
				}
				/*se verifica igual a 1 salva o novo dado e os outros dados antigos que nao foram alterados no arquivo temporario*/
				if(verifica == 1){
					fprintf(arquivo2,"\n%s",ht.nomefantasia);
					fprintf(arquivo2,"\n%s",ht.razaosocial);
					fprintf(arquivo2,"\n%s",ht.cnpj);
					fprintf(arquivo2,"\n%s",ht.insc);
					fprintf(arquivo2,"\n%s",ht.rua);
					fprintf(arquivo2,"\n%s",ht.numero);
					fprintf(arquivo2,"\n%s",ht.bairro);
					fprintf(arquivo2,"\n%s",ht.cidadeestado.cidade);
					fprintf(arquivo2,"\n%s",ht.cidadeestado.estado);
					fprintf(arquivo2,"\n%s",ht.cep);
					fprintf(arquivo2,"\n%s",ht.complemento);
					fprintf(arquivo2,"\n%s",ht.telefone);
					fprintf(arquivo2,"\n%s",ht.email);
					fprintf(arquivo2,"\n%s",ht.nomeresponsavel);
					fprintf(arquivo2,"\n%s",ht.telefoneresponsavel);
					fprintf(arquivo2,"\n%s\n\n",ht.status);
					/*mostra mensagem de sucesso na tela*/
					verde("\nDados alterados com sucesso!\n");
					/*remove o arquivo original*/
					remove(url);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
					/*fecha os arquivos*/
					fclose(arquivo);
					fclose(arquivo2);
				}
			break;
			/*tipo de salvamento 2, arquivo binario*/
			case 2:
				/*a variavel verifica recebe 0, para ver os dados que podem ser editados*/
				verifica = 0;
				/*le o arquivo inteiro, armazena um hotel por vez*/
				while(!feof(arquivo)){
					/*comando de leitura*/
					fread(&ht,sizeof(struct hotel),1,arquivo);
					/*verifica se o codigo lido é diferente do codigo digitado*/
					if(ht.codigo != codigo){
						/*se for, salva os dados no arquivo temporario*/
						fwrite(&ht,sizeof(struct hotel),1,arquivo2);
					}
					/*se for igual*/
					else{
						/*verifica o final do arquivo para evitar bugs*/
						if(feof(arquivo)){
							/*sai do laço*/
							break;
						}
						/*mostra o hotel selecionado*/
						azulclaro("\nHotel selecionado:\n\n");
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
						/*recebe a opção que será editado*/
						branco("Digite o que será editado:\n1 - Nome Fantasia\n2 - Razão Social\n3 - CNPJ\n4 - Inscrição Estadual\n5 - Rua\n6 - Número\n7 - Bairro\n8 - CEP\n9 - Complemento\n10 - Cidade\n11 - Estado\n12 - Telefone\n13 - E-Mail\n"
						"14 - Nome do Responsável\n15 - Telefone do Responsável\n16 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica a opção que será editado*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso seja igual a 1, edita o nome fantasia*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",ht.nomefantasia);
								verifica = 1;
							break;
							case 2:
							/*caso for igual a 2, edita a razao social*/
								setbuf(stdin,NULL);
								printf("Digite o novo Razão Social: ");
								scanf("%[^\n]s",ht.razaosocial);
								verifica = 1;
							break;
							/*caso for igual a 3, edita o cnpj*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ:");
								scanf("%[^\n]s",ht.cnpj);
								verifica = 1;
							break;
							/*caso for iugal a 4, edita a inscrição estadual*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",ht.insc);
								verifica = 1;
							break;
							/*caso for igual a 5, edita a rua onde se encontra o hotel*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a nova Rua : ");
								scanf("%[^\n]s",ht.rua);
								verifica = 1;
							break;
							case 6:
							/*caso for igual a 6, edita o numero onde se encontra o hotel*/
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",ht.numero);
								verifica = 1;
							break;
							/*caso for igual a 7, edita o bairro onde se encontra o hotel*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",ht.bairro);
								verifica = 1;
							break;
							/*caso for igual a 8, edita o cep de onde se encontra o hotel*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",ht.cep);
								verifica = 1;
							break;
							/*caso for igual a 9 edita o complemento do hotel*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",ht.complemento);
								verifica = 1;
							break;
							case 10:
							/*caso for igual a 10, edita a cidade onde se encontra o hotel*/
								setbuf(stdin,NULL);
								printf("Digite a nova Cidade: ");
								scanf("%[^\n]s",ht.cidadeestado.cidade);
								verifica = 1;
							break;
							/*caso for igual a 11, edita o estado onde se encontra o hotel*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",ht.cidadeestado.estado);
								verifica = 1;
							break;
							/*caso for igual a 12, edita o telefone do hotel*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",ht.telefone);
								verifica = 1;
							break;
							/*caso for igual a 13, edita o email do hotel*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo E-mail: ");
								scanf("%[^\n]s",ht.email);
								verifica = 1;
							break;
							/*caso for igual a 14, edita o nome do responsavel do hotel*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome do Responsável: ");
								scanf("%[^\n]s",ht.nomeresponsavel);
								verifica = 1;
							break;
							case 15:
							/*caso for igual a 15, edita o telefone do responsavel do hotel*/
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Responsável: ");
								scanf("%[^\n]s",ht.telefoneresponsavel);
								verifica = 1;
							break;
							/*caso for igual a 16, edita o status do hotel*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ht.status);
								verifica = 1;
							break;
							/*caso for alguma opção diferente das listadas acima, mostra mensagem de erro*/
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
					/*se verifica igual a 1, uma opção de edição valida foi escolhida*/
					if(verifica == 1){
						/*salva o dado alterado junto com os que não foram no arquivo temporario*/
						fwrite(&ht,sizeof(struct hotel),1,arquivo2);
						/*mostra mensagem de sucesso na tela*/
						verde("\nDados alterados com sucesso!\n\n");
						/*remove o arquivo original*/
						remove(url);
						/*renomeiao a arquivo temporario*/
						rename(urltemp,url);
						/*fecha os arquivos*/
						fclose(arquivo);
						fclose(arquivo2);
					}
				}
				break;
			/*mostra mensagem de erro para opções de salvamento ainda nao implementadas*/
			default:
				vermelho("\nOpcao ainda não implementada ou não existente\n\n");		
			break;
		}
	}	
}
/*função para editar os dados no produto*/
/*recebe por parametro o tipo de salvamento*/
void editaproduto(int tipo,char url[50],char modoabertura[5],char urltemp[50]){

}
/*função para editar os dados de categoria*/
/*recebe por parametro o tipo de salvamento*/
void editacategoria(int tipo,char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct de categorias para ter acesso a suas variaveis*/
	struct categorias c;
	/*cria os dois ponteiros*/
	FILE *arquivo;
	FILE *arquivo2;
	int verifica;
	int codigo;
	int op;
	ciano("\nEdição de Categorias!\n");
	/*recebe o codigo que sera editado*/
	printf("Digite o código da categoria que será editada: ");
	scanf("%i",&codigo);
	/*abre os arquivos, original e temporario*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica se houve erros na abertura dos arquivos*/
	/*se houve erros, mostra mensagem na tela*/
	if(arquivo2 == NULL || arquivo == NULL){
		vermelho("\nErro em localizar o arquivo de categorias!\n");
	}
	else{
		/*se estiver tudo ok..*/
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*caso for o tipo 1, arquivo texto*/
			case 1:
				/*verifica recebe o valor 0, para ser utilizado como verificador de valores de edição validos*/
				verifica = 0;
				/*le o arquivo todo, armazenando uma categoria por vez*/
				while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status) != EOF){
					/*verifica se o codigo que foi lido é diferente do codigo digitado pelo usuario*/
					if(c.codigo != codigo){
						/*se for salva os dados no arquivo temporario*/
						fprintf(arquivo2,"%u",c.codigo);
						fprintf(arquivo2,"\n%s",c.descricao);
						fprintf(arquivo2,"\n%.2f",c.valor);
						fprintf(arquivo2,"\n%i",c.quantidadeadultos);
						fprintf(arquivo2,"\n%i",c.quantidadecriancas);
						fprintf(arquivo2,"\n%s\n\n",c.status);
					}
					/*se for igual*/
					/*verifica se ja esta no final do arquivo, para evitar bugs*/
					else{
						if(feof(arquivo)){
							/*se estiver sai do laço*/
							break;
						}
						/*mostra a categoria selecionada*/
						azulclaro("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n\n",c.status);
						/*recebe a opção de edição*/
						branco("Digite o que será editado: \n1 - Descrição\n2 - Valor\n3 - Quantidade de Adultos\n4 - Quantidade de Crianças\n5 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica essa opção de edição*/
						/*valores validos, recebem o verifica como 1*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso for o tipo 1, edita a descrição da categoria*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",c.descricao);
								verifica = 1;
							break;
							/*caso for o tipo 2, edita o valor da categoria*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Valor: ");
								scanf("%f",&c.valor);
								verifica = 1;
							break;
							/*caso for o tipo 3, edita a quantidade de adultos*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Adultos: ");
								scanf("%i",&c.quantidadeadultos);
								verifica = 1;
							break;
							/*caso for o tipo 4, edita a quantidade de crianças*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Crianças: ");
								scanf("%i",&c.quantidadecriancas);
								verifica = 1;
							break;
							/*caso for o tipo 5, edita o status da categoria*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",c.status);
								verifica = 1;
							break;
							/*para valores fora da lista acima, mostra mensagem de erro na tela*/
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
				}
			/*se o verifica for igual a 1*/
			if(verifica == 1){
				/*salva o dado alterado mais os que continuaram o mesmo no arquivo temporario*/
				fprintf(arquivo2,"%u",c.codigo);
				fprintf(arquivo2,"\n%s",c.descricao);
				fprintf(arquivo2,"\n%.2f",c.valor);
				fprintf(arquivo2,"\n%i",c.quantidadeadultos);
				fprintf(arquivo2,"\n%i",c.quantidadecriancas);
				fprintf(arquivo2,"\n%s\n\n",c.status);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados alterados com sucesso!\n");
				/*remove o arquivo original*/
				remove(url);
				/*renomeia o arquivo temporario*/
				rename(urltemp,url);
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
			}
			break;
			/*tipo de salvamento 2, arquivo binario*/
			case 2:
				/*verifica recebe 0 para serem verificados valores validos de edição futuramente*/
				verifica = 0;
				/*le o arquivo inteiro, salvando um categoria por vez*/
				while(!feof(arquivo)){
					/*le cada categoira*/
					fread(&c,sizeof(struct categorias),1,arquivo);
					/*verifica se ja esta no final do arquivo para evitar erros*/
					if(feof(arquivo)){
						/*se estiver sai do laço*/
						break;
					}
					/*verifica se o codigo lido é difrente do codigo digitado*/
					if(c.codigo != codigo){
						/*se for salva os dados no arquivo temporario*/
						fwrite(&c,sizeof(struct categorias),1,arquivo2);
					}
					/*se for igual*/
					else{
						/*verifica o final do arquivo para evitar bugs*/
						if(feof(arquivo)){
							/*se estiver sai do laço*/
							break;
						}
						/*mostra a categoria selecionada*/
						azulclaro("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n\n",c.status);
						/*recebe as opções de edição*/
						branco("Digite o que será editado: \n1 - Descrição\n2 - Valor\n3 - Quantidade de Adultos\n4 - Quantidade de Crianças\n5 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica as opções de edição*/
						switch(op){
							/*caso 0, não vai haver edição*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso for o tipo 1, edita a descrição da categoria*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",c.descricao);
								verifica = 1;
							break;
							/*caso for o tipo 2, edita o valor da categoria*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite o novo Valor: ");
								scanf("%f",&c.valor);
								verifica = 1;
							break;
							/*caso for o tipo 3, edita a quantidade de adultos*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Adultos: ");
								scanf("%i",&c.quantidadeadultos);
								verifica = 1;
							break;
							/*caso for o tipo 4, edita a quantidade de crianças*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Quantidade de Crianças: ");
								scanf("%i",&c.quantidadecriancas);
								verifica = 1;
							break;
							/*caso for o tipo 5, edita o status da categoria*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",c.status);
								verifica = 1;
							break;
							/*para valores fora da lista acima, mostra mensagem de erro na tela*/
							default:
								vermelho("\nOpção invalida!!\n");
							break;
						}
					}
				}
				/*verifica igual a 1, opção de edição valida*/
				if(verifica == 1){
					/*salva o dado alterado e os dados antigos no arquivo temporario*/
					fwrite(&c,sizeof(struct categorias),1,arquivo2);
					/*mostra mensagem de sucesso na tela*/
					verde("\nDados alterados com sucesso!\n\n");
					/*remove o arquivo original*/
					remove(urltemp);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
					/*fecha os dois arquivos*/
					fclose(arquivo);		
					fclose(arquivo2);
				}	
			break;
			/*mostra mensagem de erro para opções de salvamento ainda nao implementadas*/
			default:
				vermelho("\nOpcao ainda não implementada ou não existente\n\n");		
			break;
		}
	}
}
/*função para editar os dados de acomodações*/
void editaacomodacao(int tipo,char url[50],char modoabertura[5],char urltemp[50],char urlcategoria[50]){
	/*cria dois ponteiros do tipo arquivo para ter acesso aos dois arquivos, temporario e original*/
	FILE *arquivo;
	FILE *arquivo2;
	int op,codigo,verifica;
	/*chama a struct de acomodações para ter acesso a suas variaveis*/
	struct acomodacoes ac;
	ciano("\nEdição de Acomodações!\n");
	/*cebece o codigo que sera editado*/
	printf("Digite o código da Acomodação que será editada: ");
	scanf("%i",&codigo);
	/*abre os arquivos, o original e o temporario*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*se houver erros na abertura dos arquivos, mostra mensagem de erro na tela*/
	if(arquivo2 == NULL || arquivo == NULL){
		vermelho("\nErro em localizar o arquivo de acomodações\n");
	}/*se estiver tudo ok*/
	else{
		/*verifica o tipo de salvamento configurado*/
		switch(tipo){
			/*se for o tipo 1, arquivo texto*/
			case 1:
				/*le o arquivo todo, armazenando por vez, cada acomodação*/
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,
				&ac.extra.banheira,&ac.categoriaselecionada,ac.status) != EOF){
					/*verifica se o codigo da acomodação lida é diferente do codigo digitado pelo usuário*/
					if(ac.codigo != codigo){
						/*se o codigo for diferente do codigo digitado*/
						fprintf(arquivo2,"%u",ac.codigo);
						fprintf(arquivo2,"\n%s",ac.descricao);
						fprintf(arquivo2,"\n%i",ac.extra.tv);
						fprintf(arquivo2,"\n%i",ac.extra.tvcabo);
						fprintf(arquivo2,"\n%i",ac.extra.arcondicionado);
						fprintf(arquivo2,"\n%i",ac.extra.frigobar);
						fprintf(arquivo2,"\n%i",ac.extra.banheiro);
						fprintf(arquivo2,"\n%i",ac.extra.camacasal);
						fprintf(arquivo2,"\n%i",ac.extra.camasolteiro);
						fprintf(arquivo2,"\n%i",ac.extra.hidromassagem);
						fprintf(arquivo2,"\n%i",ac.extra.banheira);
						fprintf(arquivo2,"\n%i",ac.categoriaselecionada);
						fprintf(arquivo2,"\n%s\n\n",ac.status);
					}
					/*se o codigo for igual ao digitado*/
					else{
						/*verifica o final do arquivo, para evitar bug de repetições*/
						if(feof(arquivo)){
							/*caso esteja, sai do while*/
							break;
						}
						/*mostra a acomodação selecionada*/
						azulclaro("\nAcomodação Selecionada: \n\n");
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
						printf("\nCategoria da Acomodação: %i\n\n",ac.categoriaselecionada);
						/*armazena o opção de edição do usuário*/
						branco("Digite o que será editado: \n1 - Descrição\n2 - Categoria Selecionada\n3 - TV\n4 - TV a Cabo\n5 - Ar Condicionado\n6 - Frigobar\n7 - Banheiro\n8 - Cama de Casal"
						"\n9 - Cama de Solteiro\n10 - Hidromassagem\n11 - Banheira\n12 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*variavel verifica, para verificar as opções de edição validas*/
						verifica = 0;
						switch(op){
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*se for o caso 1, altera a descrição*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",ac.descricao);
								verifica = 1;	
							break;
							case 2:
							/*se for o caso 2, altera a categoria*/
								consultacategoria(tipo,urlcategoria,modoabertura);
								setbuf(stdin,NULL);
								printf("Digite a nova Categoria Selecionada: ");
								scanf("%i",&ac.categoriaselecionada);
								verifica = 1;
							break;
							case 3:
							/*se for o caso 3, altera a quantidade de tvs*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's: ");
								scanf("%i",&ac.extra.tv);
								verifica = 1;
							break;
							case 4:
							/*se for o caso 4, altera a quantidade de tvs a cabo*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's a Cabo: ");
								scanf("%i",&ac.extra.tvcabo);
								verifica = 1;
							break;
							case 5:
							/*se for o caso 5, altera a quantidade de ar condicionado*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Ares Condicionados: ");
								scanf("%i",&ac.extra.arcondicionado);
								verifica = 1;
							break;
							case 6:
							/*caso 6, altera a quantidade de frigobares*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Frigobares: ");
								scanf("%i",&ac.extra.frigobar);
								verifica = 1;
							break;
							case 7:
							/*se for o caso 7, altera a quantidade de banheiros*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiros: ");
								scanf("%i",&ac.extra.banheiro);
								verifica = 1;
							break;
							case 8:
							/*se for o caso 8, altera a quantidade de camas de casal*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Casal: ");
								scanf("%i",&ac.extra.camacasal);
								verifica = 1;
							break;
							case 9:
							/*se for o caso 9, altera a quantidade de camas de solteiro*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Solteiro: ");
								scanf("%i",&ac.extra.camasolteiro);
								verifica = 1;
							break;
							case 10:
							/*se for o caso 10, altera a quantidade de hidromassagens*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Hidromassagens: ");
								scanf("%i",&ac.extra.hidromassagem);
								verifica = 1;
							break;
							case 11:
							/*se for o caso 11, altera a quantidade de banheiras*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiras: ");
								scanf("%i",&ac.extra.banheira);
								verifica = 1;
							break;
							case 12:
							/*se for o caso 12, altera o status */
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ac.status);
								verifica = 1;	
							break;
							/*opção invalida*/
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}
					}
				}
			/*se o verifica receber 1, quer dizer que foi uma das opções validas*/
			if(verifica == 1){
				/*então altera os dados*/
				fprintf(arquivo2,"%u",ac.codigo);
				fprintf(arquivo2,"\n%s",ac.descricao);
				fprintf(arquivo2,"\n%i",ac.extra.tv);
				fprintf(arquivo2,"\n%i",ac.extra.tvcabo);
				fprintf(arquivo2,"\n%i",ac.extra.arcondicionado);
				fprintf(arquivo2,"\n%i",ac.extra.frigobar);
				fprintf(arquivo2,"\n%i",ac.extra.banheiro);
				fprintf(arquivo2,"\n%i",ac.extra.camacasal);
				fprintf(arquivo2,"\n%i",ac.extra.camasolteiro);
				fprintf(arquivo2,"\n%i",ac.extra.hidromassagem);
				fprintf(arquivo2,"\n%i",ac.extra.banheira);
				fprintf(arquivo2,"\n%i",ac.categoriaselecionada);
				fprintf(arquivo2,"\n%s\n\n",ac.status);
				/*mostra mensagem na tela*/
				verde("\nDados alterados com sucesso!\n");
				/*remove o arquivo original*/
				remove(url);
				/*e altera o nome do arquivo temporario*/
				rename(urltemp,url);
			}
		break;
		/*caso 2, tipo de salvamento binário*/
		case 2:
			/*verifica o arquivo*/
			while(!feof(arquivo)){
				/*faz a leitura de cada struct*/
				fread(&ac,sizeof(struct acomodacoes),1,arquivo);
				/*verifica se já esta no final do arquivo para evitar bugs*/
				if(feof(arquivo)){
					break;
				}
				/*verifica se o codigo lido é diferente do código digitado*/
				if(ac.codigo != codigo){
					/*se for salva os dados no arquivo temporario*/
					fwrite(&ac,sizeof(struct acomodacoes),1,arquivo2);
				}
				/*se for o codigo igual*/
				else{
					/*verifica novamente o final do arquivo*/
					if(feof(arquivo)){
						/*sai do laço caso necessário*/
						break;
					}
					/*mostra a acomodação selecionada*/
					azulclaro("\nAcomodação Selecionada: \n\n");
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
					printf("\nCategoria da Acomodação: %i\n\n",ac.categoriaselecionada);
					/*o usuário digita qual sua opção de edição*/
					branco("Digite o que será editado: \n1 - Descrição\n2 - Categoria Selecionada\n3 - TV\n4 - TV a Cabo\n5 - Ar Condicionado\n6 - Frigobar\n7 - Banheiro\n8 - Cama de Casal"
					"\n9 - Cama de Solteiro\n10 - Hidromassagem\n11 - Banheira\n12 - Status\n0 - Cancelar\n: ");
					scanf("%i",&op);
					/*zera a variavel de verificação*/
					verifica = 0;
					/*um switch para verificar a opção de edição selecionada*/
					switch(op){
							/*caso 0, remove o arquivo temporario e sai do processo*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*se for o caso 1, altera a descrição*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite a nova Descrição: ");
								scanf("%[^\n]s",ac.descricao);
								verifica = 1;	
							break;
							case 2:
							/*se for o caso 2, altera a categoria*/
								consultacategoria(tipo,urlcategoria,modoabertura);
								setbuf(stdin,NULL);
								printf("Digite a nova Categoria Selecionada: ");
								scanf("%i",&ac.categoriaselecionada);
								verifica = 1;
							break;
							case 3:
							/*se for o caso 3, altera a quantidade de tvs*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's: ");
								scanf("%i",&ac.extra.tv);
								verifica = 1;
							break;
							case 4:
							/*se for o caso 4, altera a quantidade de tvs a cabo*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de TV's a Cabo: ");
								scanf("%i",&ac.extra.tvcabo);
								verifica = 1;
							break;
							case 5:
							/*se for o caso 5, altera a quantidade de ar condicionado*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Ares Condicionados: ");
								scanf("%i",&ac.extra.arcondicionado);
								verifica = 1;
							break;
							case 6:
							/*caso 6, altera a quantidade de frigobares*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Frigobares: ");
								scanf("%i",&ac.extra.frigobar);
								verifica = 1;
							break;
							case 7:
							/*se for o caso 7, altera a quantidade de banheiros*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiros: ");
								scanf("%i",&ac.extra.banheiro);
								verifica = 1;
							break;
							case 8:
							/*se for o caso 8, altera a quantidade de camas de casal*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Casal: ");
								scanf("%i",&ac.extra.camacasal);
								verifica = 1;
							break;
							case 9:
							/*se for o caso 9, altera a quantidade de camas de solteiro*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Camas de Solteiro: ");
								scanf("%i",&ac.extra.camasolteiro);
								verifica = 1;
							break;
							case 10:
							/*se for o caso 10, altera a quantidade de hidromassagens*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Hidromassagens: ");
								scanf("%i",&ac.extra.hidromassagem);
								verifica = 1;
							break;
							case 11:
							/*se for o caso 11, altera a quantidade de banheiras*/
								setbuf(stdin,NULL);
								printf("Digite a nova quantidade de Banheiras: ");
								scanf("%i",&ac.extra.banheira);
								verifica = 1;
							break;
							case 12:
							/*se for o caso 12, altera o status */
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",ac.status);
								verifica = 1;	
							break;
							/*opção invalida*/
							default:
								vermelho("\nOpção inválida!!\n");
							break;
					}	
				}
			}
			/*se o verifica for igual a 1, uma opção valida de salvamento foi digitada*/
			if(verifica == 1){
				/*então salva o quarto modificado junto com os outros no arquivo junto com os outros no arquivo temporario*/
				fwrite(&ac,sizeof(struct categorias),1,arquivo2);
				/*mostra mensagem de sucesso na tela*/
				verde("\nDados alterados com sucesso!\n\n");
				/*remove o arquivo original*/
				remove(url);
				/*renomeia o arquivo temporario*/
				rename(urltemp,url);
				/*fecha os arquivos*/
				fclose(arquivo);
				fclose(arquivo2);				
			}
		break;
		/*opção de salvamento ainda não implementada*/
		default:
			vermelho("\nOpção de Salvamento ainda não implementada!\n");
		break;
		}
	}
}
/*função para realizar a edição de dados dos fornecedores*/
/*recebe por parametro o tipo de salvamento, o modo de abertura, e o url original e temporario*/
void editafornecedor(int tipo,char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct dos forncedores para ter acesso a suas variaveis*/
	struct fornecedores f;
	/*cria dois ponteiros de arquivos para abrir os arquivos original e temporario*/
	FILE *arquivo;
	FILE *arquivo2;
	int op,codigo,verifica;
	ciano("\nEdição de Fornecedores!\n");
	/*armazena o codigo do fornecedor que sera editado*/
	printf("Digite o código do Fornecedor que será editado: ");
	scanf("%i",&codigo);
	/*abre os dois arquivos*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(urltemp,modoabertura);
	/*verifica erros em sua abertura*/
	if(arquivo2 == NULL || arquivo == NULL){
		/*se houver, mostra mensagem na tela*/
		vermelho("\nErro em localizar o arquivo de fornecedor!\n");
	}
	/*se estiver tudo ok...*/
	else{
		/*verifica o tipo de salvamento*/
		switch(tipo){
			/*no caso 1, o salvamento é arquivo texto*/
			case 1:
				/*le o arquivo, armazenando cada fornecedor cadastrado na struct por vez*/
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
					f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
					f.trepresentante,f.status) != EOF){
					/*verifica se o codigo lido é diferente do codigo digitado*/
					if(f.codigo != codigo){
						/*se for salva os dados desse fornecedor no arquivo temporario*/
						fprintf(arquivo2,"%u",f.codigo);
						fprintf(arquivo2,"\n%s",f.nomefantasia);
						fprintf(arquivo2,"\n%s",f.razaosocial);
						fprintf(arquivo2,"\n%s",f.cnpj);
						fprintf(arquivo2,"\n%s",f.insc);
						fprintf(arquivo2,"\n%s",f.rua);
						fprintf(arquivo2,"\n%s",f.numero);
						fprintf(arquivo2,"\n%s",f.bairro);
						fprintf(arquivo2,"\n%s",f.cep);
						fprintf(arquivo2,"\n%s",f.complemento);
						fprintf(arquivo2,"\n%s",f.cidadeestado.cidade);
						fprintf(arquivo2,"\n%s",f.cidadeestado.estado);
						fprintf(arquivo2,"\n%s",f.telefone);
						fprintf(arquivo2,"\n%s",f.celular);
						fprintf(arquivo2,"\n%s",f.email);
						fprintf(arquivo2,"\n%s",f.nrepresentante);
						fprintf(arquivo2,"\n%s",f.trepresentante);
						fprintf(arquivo2,"\n%s\n\n",f.status);
					}
					/*caso for igual o codigo*/
					else{
						/*zera a variavel de verificação*/
						verifica = 0;
						/*verifica se já esta no final do arquivo para evitar erros*/
						if(feof(arquivo)){
							/*sai do laço caso necessário*/
							break;
						}
						/*mostra fornecedor selecionado*/
						azulclaro("Fornecedor Selecionado: \n\n");
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
						/*recebe a opção que o usuário deseja editar*/
						branco("Digite o que será editado: \n1 - Nome Fantasia\n2 - Razão Social\n3 - CNPJ\n4 - Inscrição Estadual"
							"\n5 - Rua\n6 - Número\n7 - Bairro\n8 - CEP\n9 - Complemento\n10 - Cidade\n11 - Estado\n12 - Telefone"
							"\n13 - Celular\n13 - E-mail\n15 - Representante\n16 - Telefone do Representante\n17 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica essa opção*/
						switch(op){
							/*caso 0, sai da edição, remove o arquivo temporario e mostra mensagem de função abortado*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso 1, edita o nome fantasia*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",f.nomefantasia);
								verifica = 1;
							break;
							/*caso 2, edita a razão social*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite a nova Razão Social: ");
								scanf("%[^\n]s",f.razaosocial);
								verifica = 1;
							break;
							/*caso 3, edita o cnpj*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ: ");
								scanf("%[^\n]s",f.cnpj);
								verifica = 1;
							break;
							/*caso 4, edita a inscrição estadual*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",f.nomefantasia);
								verifica = 1;
							break;
							/*caso 5, edita a rua*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a novo Rua: ");
								scanf("%[^\n]s",f.rua);
								verifica = 1;
							break;
							/*caso 6, edita o número*/
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",f.numero);
								verifica = 1;
							break;
							/*caso 7, edita o bairro*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",f.bairro);
								verifica = 1;
							break;
							/*caso 8 edita o cep*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",f.cep);
								verifica = 1;
							break;
							/*caso 8, edita o complemento*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",f.complemento);
								verifica = 1;
							break;
							/*caso 10, edita a cidade*/
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a novo Cidade: ");
								scanf("%[^\n]s",f.cidadeestado.cidade);
								verifica = 1;
							break;
							/*caso 11, edita o estado*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",f.cidadeestado.estado);
								verifica = 1;
							break;
							/*caso 12, edita o telefone*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",f.telefone);
								verifica = 1;
							break;
							/*caso 13, edita o celular*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",f.celular);
								verifica = 1;
							break;
							/*caso 14, edita o email*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo E-Mail: ");
								scanf("%[^\n]s",f.email);
								verifica = 1;
							break;
							/*caso 15, edita o representante*/
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Representante: ");
								scanf("%[^\n]s",f.nrepresentante);
								verifica = 1;
							break;
							/*caso 16, edita o telefone do representante*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Representante: ");
								scanf("%[^\n]s",f.trepresentante);
								verifica = 1;
							break;
							/*caso 17, edita o status*/
							case 17:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",f.status);
								verifica = 1;
							break;
							/*opção invalida*/
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}
					}
				}
				/*se o verifica for igual 1, quer dizer que uma opção de edição valida foi selecionada*/
				if(verifica == 1){
					/*salva os dados no arquivo temporario*/
					fprintf(arquivo2,"%u",f.codigo);
					fprintf(arquivo2,"\n%s",f.nomefantasia);
					fprintf(arquivo2,"\n%s",f.razaosocial);
					fprintf(arquivo2,"\n%s",f.cnpj);
					fprintf(arquivo2,"\n%s",f.insc);
					fprintf(arquivo2,"\n%s",f.rua);
					fprintf(arquivo2,"\n%s",f.numero);
					fprintf(arquivo2,"\n%s",f.bairro);
					fprintf(arquivo2,"\n%s",f.cep);
					fprintf(arquivo2,"\n%s",f.complemento);
					fprintf(arquivo2,"\n%s",f.cidadeestado.cidade);
					fprintf(arquivo2,"\n%s",f.cidadeestado.estado);
					fprintf(arquivo2,"\n%s",f.telefone);
					fprintf(arquivo2,"\n%s",f.celular);
					fprintf(arquivo2,"\n%s",f.email);
					fprintf(arquivo2,"\n%s",f.nrepresentante);
					fprintf(arquivo2,"\n%s",f.trepresentante);
					fprintf(arquivo2,"\n%s\n\n",f.status);
					/*mostra mensagem de sucesos*/
					verde("\nDados alterados com sucesso!\n");
					/*remove o arquivo original*/
					remove(url);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
				}
			break;
			case 2:
					while(!feof(arquivo)){
						fread(&f,sizeof(struct fornecedores),1,arquivo);
						if(feof(arquivo)){
							break;
						}
						if(f.codigo != codigo){
							fwrite(&f,sizeof(struct fornecedores),1,arquivo2);
						}
						else{
							/*zera a variavel de verificação*/
						verifica = 0;
						/*verifica se já esta no final do arquivo para evitar erros*/
						if(feof(arquivo)){
							/*sai do laço caso necessário*/
							break;
						}
						/*mostra fornecedor selecionado*/
						azulclaro("Fornecedor Selecionado: \n\n");
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
						/*recebe a opção que o usuário deseja editar*/
						branco("Digite o que será editado: \n1 - Nome Fantasia\n2 - Razão Social\n3 - CNPJ\n4 - Inscrição Estadual"
							"\n5 - Rua\n6 - Número\n7 - Bairro\n8 - CEP\n9 - Complemento\n10 - Cidade\n11 - Estado\n12 - Telefone"
							"\n13 - Celular\n13 - E-mail\n15 - Representante\n16 - Telefone do Representante\n17 - Status\n0 - Cancelar\n: ");
						scanf("%i",&op);
						/*verifica essa opção*/
						switch(op){
							/*caso 0, sai da edição, remove o arquivo temporario e mostra mensagem de função abortado*/
							case 0:
								remove(urltemp);
								vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
							break;
							/*caso 1, edita o nome fantasia*/
							case 1:
								setbuf(stdin,NULL);
								printf("Digite o novo Nome Fantasia: ");
								scanf("%[^\n]s",f.nomefantasia);
								verifica = 1;
							break;
							/*caso 2, edita a razão social*/
							case 2:
								setbuf(stdin,NULL);
								printf("Digite a nova Razão Social: ");
								scanf("%[^\n]s",f.razaosocial);
								verifica = 1;
							break;
							/*caso 3, edita o cnpj*/
							case 3:
								setbuf(stdin,NULL);
								printf("Digite o novo CNPJ: ");
								scanf("%[^\n]s",f.cnpj);
								verifica = 1;
							break;
							/*caso 4, edita a inscrição estadual*/
							case 4:
								setbuf(stdin,NULL);
								printf("Digite a nova Inscrição Estadual: ");
								scanf("%[^\n]s",f.nomefantasia);
								verifica = 1;
							break;
							/*caso 5, edita a rua*/
							case 5:
								setbuf(stdin,NULL);
								printf("Digite a novo Rua: ");
								scanf("%[^\n]s",f.rua);
								verifica = 1;
							break;
							/*caso 6, edita o número*/
							case 6:
								setbuf(stdin,NULL);
								printf("Digite o novo Número: ");
								scanf("%[^\n]s",f.numero);
								verifica = 1;
							break;
							/*caso 7, edita o bairro*/
							case 7:
								setbuf(stdin,NULL);
								printf("Digite o novo Bairro: ");
								scanf("%[^\n]s",f.bairro);
								verifica = 1;
							break;
							/*caso 8 edita o cep*/
							case 8:
								setbuf(stdin,NULL);
								printf("Digite o novo CEP: ");
								scanf("%[^\n]s",f.cep);
								verifica = 1;
							break;
							/*caso 8, edita o complemento*/
							case 9:
								setbuf(stdin,NULL);
								printf("Digite o novo Complemento: ");
								scanf("%[^\n]s",f.complemento);
								verifica = 1;
							break;
							/*caso 10, edita a cidade*/
							case 10:
								setbuf(stdin,NULL);
								printf("Digite a novo Cidade: ");
								scanf("%[^\n]s",f.cidadeestado.cidade);
								verifica = 1;
							break;
							/*caso 11, edita o estado*/
							case 11:
								setbuf(stdin,NULL);
								printf("Digite o novo Estado: ");
								scanf("%[^\n]s",f.cidadeestado.estado);
								verifica = 1;
							break;
							/*caso 12, edita o telefone*/
							case 12:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone: ");
								scanf("%[^\n]s",f.telefone);
								verifica = 1;
							break;
							/*caso 13, edita o celular*/
							case 13:
								setbuf(stdin,NULL);
								printf("Digite o novo Celular: ");
								scanf("%[^\n]s",f.celular);
								verifica = 1;
							break;
							/*caso 14, edita o email*/
							case 14:
								setbuf(stdin,NULL);
								printf("Digite o novo E-Mail: ");
								scanf("%[^\n]s",f.email);
								verifica = 1;
							break;
							/*caso 15, edita o representante*/
							case 15:
								setbuf(stdin,NULL);
								printf("Digite o novo Representante: ");
								scanf("%[^\n]s",f.nrepresentante);
								verifica = 1;
							break;
							/*caso 16, edita o telefone do representante*/
							case 16:
								setbuf(stdin,NULL);
								printf("Digite o novo Telefone do Representante: ");
								scanf("%[^\n]s",f.trepresentante);
								verifica = 1;
							break;
							/*caso 17, edita o status*/
							case 17:
								setbuf(stdin,NULL);
								printf("Digite o novo Status: ");
								scanf("%[^\n]s",f.status);
								verifica = 1;
							break;
							/*opção invalida*/
							default:
								vermelho("\nOpção inválida!!\n");
							break;
						}
					}
				}
				/*se o verifica for igual 1, quer dizer que uma opção de edição valida foi selecionada*/
				if(verifica == 1){
					/*salva os dados no arquivo temporario*/
					fwrite(&f,sizeof(struct fornecedores),1,arquivo2);
					/*mostra mensagem de sucesos*/
					verde("\nDados alterados com sucesso!\n");
					/*remove o arquivo original*/
					remove(url);
					/*renomeia o arquivo temporario*/
					rename(urltemp,url);
							
				}
			break;
			/*Opção invalida*/
			default:
				vermelho("\nOpção de salvamento ainda não implementada!\n");
			break;
		}
	}
}
/*função para editar os usuários cadastrados*/
/*recebe por parametro o url, url do arquivo e o modo de abertura*/
void editausuario(char url[50],char modoabertura[5],char urltemp[50]){
	/*chama a struct para acessar suas variaveis*/
	struct usuarios u;
	/*cria dos ponteiros do tipo arquivo para acessar o arquivo temporario e o original*/
	FILE *arquivo;
	FILE *arquivo2;
	int t;
	int op,codigo,verifica;
	ciano("\nEdição de Usuários!\n");
	/*recebe o codigo que será editado*/
	printf("Digite o código do Usuário que será editado: ");
	scanf("%i",&codigo);
	/*abre os arquivos*/
	arquivo = fopen(url,modoabertura);
	arquivo2 = fopen(url,modoabertura);
	/*verifica se houve erros na abertura*/
	if(arquivo2 == NULL || arquivo == NULL){
		vermelho("\nErro em localizar o arquivo de usuários!\n");
	}
	/*se estiver tudo ok*/
	else{
		/*le o arquivo*/
		while(!feof(arquivo)){
			/*le os dados do usuário e armazena na struct por vez*/
			fread(&u,sizeof(struct usuarios),1,arquivo);
			/*verifica se já está no final do arquivo*/
			if(feof(arquivo)){
				/*se estiver sai do loop*/
				break;
			}
			/*verifica se o codigo lido é diferente do codigo digitado*/
			if(u.codigo != codigo){
				/*se for salva os dados no arquivo temporario*/
				fwrite(&u,sizeof(struct usuarios),1,arquivo2);
			}
			/*se for igual */
			else{
				/*a varivavel de verificação recebe 0*/
				verifica = 0;
				/*mostra o usuário selecionado*/
				azulclaro("Usuário Selecionado: \n\n");
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
				/*recebe a opção de edição*/
				printf("Digite o que será editado: \n1 - Nome do Usuário\n2 - Login\n3 - Senha\n4 - Permissão\n5 - Status\n: ");
				scanf("%i",&op);
				switch(op){
					/*caso o, sai do função*/
					case 0:
					/*remove o arquivo temporario*/
						remove(urltemp);
						vermelhoclaro("\nProcesso Abortado com Sucesso!\n");
					break;
					/*caso 1, edita o nome do usuário*/
					case 1:
						verifica = 1;
						setbuf(stdin,NULL);
						printf("Digite o novo Nome: ");
						scanf("%[^\n]s",u.nome);
					break;
					/*caso 2, edita o login do usuário*/
					case 2:
						verifica = 1;
						setbuf(stdin,NULL);
						printf("Digite o novo Login: ");
						scanf("%[^\n]s",u.login);
					break;
					/*edita a senha do usuário*/
					case 3:
						verifica = 1;
						setbuf(stdin,NULL);
						printf("Digite a nova Senha: ");
						scanf("%[^\n]s",u.senha);
					break;
					/*edita o nível de permissão do usuáriop*/
					case 4:
						verifica = 1;
						setbuf(stdin,NULL);
						printf("Digite o nível de acesso do usuário\n1 - Acesso Mínimo;\n2 - Acesso Básico;\n3 - Acesso Comum;\n4 - Acesso Alto;\n5 - Acesso Máximo;\nDigite a nova Permissão: ");
						scanf("%i",&u.permissao);
					break;
					/*edita o status do usuário*/
					case 5:
						verifica = 1;
						setbuf(stdin,NULL);
						printf("Digite o novo Status: ");
						scanf("%[^\n]s",u.status);
					break;
					/*opção invalida*/
					default:
						vermelho("\nOpção Inválida!\n");
					break;
				}
			}
		}
	}
	/*se verifica for igual a 1, uma opção valida de edição foi escolhida*/
	if(verifica == 1){
		/*salva os dados no arquivo temporario*/
		fwrite(&u,sizeof(struct usuarios),1,arquivo2);
		/*mostra mensagem de sucesos*/
		verde("\nDados alterados com sucesso!\n\n");
		/*remove o arquivo original*/
		remove(url);
		/*renomeia o arquivo temporario*/
		rename(urltemp,url);
		/*fecha os arquivos*/
		fclose(arquivo);
		fclose(arquivo2);
	}

}
#endif