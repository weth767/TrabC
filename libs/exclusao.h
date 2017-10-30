#ifndef EXCLUSAO_H
#define EXCLUSAO_H

#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "cores.h"

/*função excluir hospede*/
/*recebe o tipo de salvamento como parametro*/
void excluihospede(int tipo){
	/*cria dois ponteiros, um para o arquivo e outro para um arquivo temporário*/
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	/*chama a struct para ter acesso a suas variaveis*/
	struct hospede h;
	/*armazena o codigo que será excluido*/
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*se for tipo 1, é salvamento em texto*/
		case 1:
		/*abre o arquivo normal e o arquivo temporario*/
			arquivo = fopen("saves/hospedes.txt","a+");
			arquivo2 = fopen("saves/temphospede.txt","a+");
			/*verifica erro na abertura dos dois arquivo*/
			/*caso tenho mostra mensagem de erro*/
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			/*se estiver tudo ok, varre o arquivo*/
			else{
				/*faz a leitura do arquivo até que chegue ao final dele, armazenando os dados da struct hospede*/
				while( fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&h.codigo,h.nome,h.cpf,h.rg,h.rua,h.numero,
					h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,h.complemento,h.datanascimento,h.telefone,h.celular,h.estadocivil,h.email,h.status) != EOF){
					/*verifica se o codigo que o usuário digitou é diferente do codigo lido, se for salva no arquivo temporario*/
					if(h.codigo != codigo){
						fprintf(arquivo2,"%u",h.codigo);
						fprintf(arquivo2,"\n%s",h.nome);
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
					/*se for igual, mostra na tela o hospede selecionado*/
					else{
						azulclaro("\nHospede selecionado: \n\n");
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
						printf("\nStatus: %s\n",h.status);
					}
					
				}
				/*pergunta ao usuário se ele realmente deseja*/
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*caso a resposta seja sim*/
				if(op == 1){
					/*exclui o hospode*/
					/*remove o arquivo*/
					remove("saves/hospedes.txt");
					/*renomeia o temporario com os outros dados que não foram excluidos*/
					rename("saves/temphospede.txt","saves/hospedes.txt");
					/*mostra mensagem de sucesso*/
					verde("\nDado excluido com sucesso!\n\n");
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
		}
		break;
		/*tipo 2, salvamento em binário*/
		case 2:
		/*abre o arquivo normal e o temporário*/
			arquivo = fopen("saves/hospedes.bin","ab+");
			arquivo2 = fopen("saves/temphospede.bin","ab+");
			/*verifica erros na abertura dos dois arquivos*/
			/*caso haja erro, mostra mensagem na tela*/
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			/*se estiver tudo ok, passa para proxima parte*/
			else{
				/*le o arquivo até seu final*/
				while(!feof(arquivo)){
					/*fread(struct,tamanho,quantidade,ponteiro)*/
					fread(&h,sizeof(struct hospede),1,arquivo);
					/*verifica se o codigo lido é diferente do digitado pelo usuário*/
					if(h.codigo != codigo){
						/*se for salva no arquivo temporário*/
						fwrite(&h,sizeof(struct hospede),1,arquivo2);
					}
					/*se for igual*/
					else{
						/*verifica se já está no final do arquivo, para evitar bugs*/
						if(feof(arquivo)){
							/*se estiver, sai do laço*/
							break;
						}
						/*mostra o hospede selecionado*/
						azulclaro("\nHospede selecionado: \n\n");
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
						printf("\nStatus: %s\n",h.status);
					}
				}
				/*pergunta ao usuário se ele realmente deseja excluir*/
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*se a resposta for sim*/
				if(op == 1){
					/*remove o arquivo original*/
					remove("saves/hospedes.bin");
					/*renomeia o arquivo temporario*/
					rename("saves/temphospede.bin","saves/hospedes.bin");
					/*e mostra mensagem de sucesso*/
					verde("\nDado excluido com sucesso!\n\n");
				}
				/*fecha os arquivos*/
				fclose(arquivo);
				fclose(arquivo2);		
			}
		break;
		/*mostra mensagem de erro, para opções de salvamento não implementadas*/
		default:
			vermelho("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}
/*função exclui hotel, recebe como parametro o tipo de salvamento*/
void excluihotel(int tipo){
	/*cria dois ponteiros, um para o arquivo e um para o arquivo temporário*/
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	/*chama a struct para ter acesso a suas variaveis*/
	struct hotel ht;
	/*recebe o cdigo que o usuário deseja excluir*/
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	/*verifica o tipo de salvamento*/
	switch(tipo){
		/*caso for o tipo 1, é arquivo texto*/
		case 1:
		/*abre o arquivo original e o arquivo temporário*/
			arquivo = fopen("saves/hoteis.txt","a+");
			arquivo2 = fopen("saves/temphotel.txt","a+");
			/*verifica erro nos dois arquivos*/
			/*se houver erros, mostra mensagem na tela*/
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo do hotel!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo do hotel!!\n\n");
			}
			/*se estiver tudo ok, se */
			else{
				/*varre o arquivo, até o seu final, armazenando os valores na struct de hotel*/
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,
					ht.insc,ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,ht.cidadeestado.estado,ht.cep,
					ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status) !=EOF){
					/*verifica se o código lido é diferente do código digitado pelo usuário*/
					/*se for salva no arquivo temporário*/
					if(ht.codigo != codigo){
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
						fprintf(arquivo2,"\n%s",ht.telefoneresponsavel);
						fprintf(arquivo2,"\n%s\n\n",ht.status);	
					}
					/*se for igual, mostra para o usuário o hotel selecionado*/
					else{
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
					}
				}
				/*pergunta ao usuário se ele realmente deseja excluir */
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*se a resposta for sim*/
				if(op == 1){
					/*remove o arquivo original*/
					remove("saves/hoteis.txt");
					/*renomeia o arquivo temporário*/
					rename("saves/temphotel.txt","saves/hoteis.txt");
					/*mostra mensagem de sucesso*/
					verde("\nDado excluido com sucesso!\n\n");
				}
				/*fecha os dois arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		/*para o tipo de salvamento 2, arquivo binário*/
		case 2:
			/*abre os dois arquivos*/
			arquivo = fopen("saves/hoteis.bin","ab+");
			arquivo2 = fopen("saves/temphotel.bin","ab+");
			/*verifica se houve erro na abertura dos arquivos*/
			/*se houver erro mostra mensagem na tela*/
			if(arquivo2 == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			if(arquivo == NULL){
				vermelho("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			/*se estiver tudo ok*/
			else{
				/*varre o arquivo até o final*/
				while(!feof(arquivo)){
					/*le os dados do arquivo, salvando na struct*/
					fread(&ht,sizeof(struct hotel),1,arquivo);
					/*verifica se o código lido é diferente do código */
					if(ht.codigo != codigo){
						/*salva os dados no arquivo temporário*/
						fwrite(&ht,sizeof(struct hotel),1,arquivo2);
					}
					/*se for código igual*/
					else{
						/*verifica se já está no final do arquivo*/
						/*se estiver sai do laço*/
						if(feof(arquivo)){
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
					}
				}
				/*pergunta se o usuário realmente quer excluir o hotel*/
				setbuf(stdin,NULL);	
				amarelo("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				/*se sim*/
				if(op == 1){
					/*remove o arquivo original*/
					remove("saves/hoteis.bin");
					/*renomeia o arquivo temporario*/
					rename("saves/temphotel.bin","saves/hoteis.bin");
					/*mostra mensagem de sucesso*/
					verde("\nDado excluido com sucesso!\n\n");
				}
				/*fecha os arquivos*/
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		/*mostra mensagem de erro, para opções de salvamento não implementadas*/
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluicategoria(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct categorias c;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/categorias.txt","a+");
			arquivo2 = fopen("saves/tempcategoria.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,c.status) != EOF){
					if(c.codigo != codigo){
						fprintf(arquivo2,"%u",c.codigo);
						fprintf(arquivo2,"\n%s",c.descricao);
						fprintf(arquivo2,"\n%.2f",c.valor);
						fprintf(arquivo2,"\n%i",c.quantidadeadultos);
						fprintf(arquivo2,"\n%i",c.quantidadecriancas);
						fprintf(arquivo2,"\n%s\n\n",c.status);	
					}
					else{
						printf("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n",c.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/categorias.txt");
					rename("saves/tempcategoria.txt","saves/categorias.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/categorias.bin","ab+");
			arquivo2 = fopen("saves/tempcategoria.bin","ab+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da categoria!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&c,sizeof(struct categorias),1,arquivo);
					if(c.codigo != codigo){
						fwrite(&c,sizeof(struct categorias),1,arquivo2);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						printf("\nCategoria Selecionada: \n\n");
						printf("Código: %i, Descrição: %s",c.codigo,c.descricao);
						printf("\nNúmero de Adultos: %i, Número de Crianças: %i",c.quantidadeadultos,c.quantidadecriancas);
						printf("\nStatus: %s\n",c.status);	
					}
				}
				setbuf(stdin,NULL);	
				printf("\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/categorias.txt");
					rename("saves/tempcategoria.txt","saves/categorias.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluiacomodacao(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct acomodacoes ac;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/acomodacoes.txt","a+");
			arquivo2 = fopen("saves/tempacomodacao.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da acomodação!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da acomodação!!\n\n");	
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,&ac.extra.tvcabo,
					&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,
					&ac.categoriaselecionada,ac.status) != EOF){
					if(ac.codigo != codigo){
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
					else{
						printf("\nAcomodação Selecionada: \n\n");
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
					}
					
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/acomodacoes.txt");
					rename("saves/tempacomodacao.txt","saves/acomodacoes.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/acomodacoes.bin","ab");
			arquivo2 = fopen("saves/tempacomodacao.bin","ab");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo da acomodação!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo da acomodação!!\n\n");	
			}
			else{
				while(!feof(arquivo)){
					fread(&ac,sizeof(struct acomodacoes),1,arquivo);
					if(ac.codigo != codigo){
						fwrite(&ac,sizeof(struct acomodacoes),1,arquivo2);
					}
					else{
						printf("\nAcomodação Selecionada: \n\n");
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
					}
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/acomodacoes.bin");
					rename("saves/tempacomodacao.bin","saves/acomodacoes.bin");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluiproduto(int tipo){
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	struct produtos p;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/produtos.txt","a+");
			arquivo2 = fopen("saves/tempproduto.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do produto!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do produto!!\n\n");
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,&p.precocusto,&p.precovenda,p.status)!= EOF){
					if(p.codigo != codigo){
						fprintf(arquivo2,"%u",p.codigo);
						fprintf(arquivo2,"\n%s",p.descricao);
						fprintf(arquivo2,"\n%i",p.estoque);
						fprintf(arquivo2,"\n%i",p.estoqueminimo);
						fprintf(arquivo2,"\n%.2f",p.precocusto);
						fprintf(arquivo2,"\n%.2f",p.precovenda);
						fprintf(arquivo2,"\n%s\n\n",p.status);
					}
					else{
						printf("Produto Selecionado: \n\n");
						printf("Código: %u",p.codigo);
						printf("\nDescrição: %s",p.descricao);
						printf("\nEstoque: %i",p.estoque);
						printf("\nEstoque Minimo: %i",p.estoqueminimo);
						printf("\nPreço de Custo: R$%.2f",p.precocusto);
						printf("\nPreço de Venda: R$%.2f",p.precovenda);
						printf("\nStatus: %s\n\n",p.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/produtos.txt");
					rename("saves/tempproduto.txt","saves/produtos.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			arquivo = fopen("saves/produtos.bin","ab+");
			arquivo2 = fopen("saves/tempproduto.bin","ab+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do produto!!\n\n");	
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do produto!!\n\n");
			}
			else{
				while(!feof(arquivo)){
					fread(&p,sizeof(struct produtos),1,arquivo);
					if(p.codigo != codigo){
						fwrite(&p,sizeof(struct produtos),1,arquivo2);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						printf("Produto Selecionado: \n\n");
						printf("Código: %u",p.codigo);
						printf("\nDescrição: %s",p.descricao);
						printf("\nEstoque: %i",p.estoque);
						printf("\nEstoque Minimo: %i",p.estoqueminimo);
						printf("\nPreço de Custo: R$%.2f",p.precocusto);
						printf("\nPreço de Venda: R$%.2f",p.precovenda);
						printf("\nStatus: %s\n\n",p.status);
					}
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/produtos.bin");
					rename("saves/tempproduto.bin","saves/produtos.bin");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluifornecedor(int tipo){
	struct fornecedores f;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	switch(tipo){
		case 1:
			arquivo = fopen("saves/fornecedores.txt","a+");
			arquivo2 = fopen("saves/tempfornecedor.txt","a+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do fornecedor!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do fornecedor!!\n\n");	
			}
			else{
				while(fscanf(arquivo,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,f.nomefantasia,f.razaosocial,
						f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,
						f.trepresentante,f.status) != EOF){
					if(f.codigo != codigo){
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
					else{
						printf("Fornecedor Selecionado: \n\n");
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
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/fornecedores.txt");
					rename("saves/tempfornecedor.txt","saves/fornecedores.txt");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		case 2:
			fopen("saves/fornecedores.bin","ab+");
			fopen("saves/tempfornecedor.bin","ab+");
			if(arquivo2 == NULL){
				printf("\nErro em localizar o arquivo do fornecedor!!\n\n");
			}
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do fornecedor!!\n\n");	
			}
			else{
				while(!feof(arquivo)){
					fread(&f,sizeof(struct fornecedores),1,arquivo);
					if(f.codigo != codigo){
						fwrite(&f,sizeof(struct fornecedores),1,arquivo2);
					}
					else{
						if(feof(arquivo)){
							break;
						}
						printf("Fornecedor Selecionado: \n\n");
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
				}
				setbuf(stdin,NULL);	
				printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
				scanf("%i",&op);
				if(op == 1){
					remove("saves/fornecedores.bin");
					rename("saves/tempfornecedor.bin","saves/fornecedores.bin");
					printf("\nDado excluido com sucesso!\n\n");
				}
				fclose(arquivo);
				fclose(arquivo2);
			}
		break;
		default:
			printf("\nOpcao ainda não implementada ou não existente\n\n");
		break;
	}
}

void excluiusuario(){
	struct usuarios u;
	FILE *arquivo;
	FILE *arquivo2;
	int codigo;
	int op;
	int t;
	printf("Digite o código a ser excluido: ");
	scanf("%u",&codigo);
	arquivo = fopen("saves/usuarios.bin","ab+");
	arquivo2 = fopen("saves/tempusuario.bin","ab+");
	if(arquivo2 == NULL){
		printf("\nErro em localizar o arquivo do usuário!!\n\n");
	}
	if(arquivo == NULL){
		printf("\nErro em localizar o arquivo do usuário!!\n\n");	
	}
	else{
		while(!feof(arquivo)){
			fread(&u,sizeof(struct usuarios),1,arquivo);
			if(u.codigo != codigo){
				fwrite(&u,sizeof(struct usuarios),1,arquivo2);
			}
			else{
				if(feof(arquivo)){
					break;		
				}
				printf("Usuário Selecionado: \n\n");
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
			}
		}
		setbuf(stdin,NULL);	
		printf("\n\nDeseja realmente realizar a exclusão(1 para sim e 0 para não): ");		
		scanf("%i",&op);
		if(op == 1){
				remove("saves/usuarios.bin");
				rename("saves/tempusuario.bin","saves/usuarios.bin");
				printf("\nDado excluido com sucesso!\n\n");
		}
		fclose(arquivo);
		fclose(arquivo2);
	}

}

void resetaconfig(){
	remove("config/config.bin");
}
#endif