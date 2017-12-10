#ifndef IMPORTACAO_EXPORTACAO_H
#define IMPORTACAO_EXPORTACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "cores.h"
#include "structs.h"
#include "consulta.h"
#include "salvar.h"


/*função para exportar os arquivos*/
/*recebe por parametro a url de destino, o modo de abertura e os selecionados*/
void exporta_tabelas(int tipo,char modoabertura[5]){
	/*chama as structs para armazenar os dados lidos nelas**/
	struct hospede h;
	struct hotel ht;
	struct acomodacoes ac;
	struct categorias c;
	struct produtos p;
	struct fornecedores f;
	struct usuarios u;
	struct entradaprodutos ep; 
	struct saidaprodutos sp; 
	struct reserva r;
	struct checks ch;
	struct contas ct;

	FILE *arquivo;
	FILE *arquivo_abertura;
	/**/

	ciano("\nExportação de dados!\n");
	/*pega o url para onde vao salvar o arquivo*/
	char url[50];
	printf("Digite o nome do arquivo(será salvo na área de trabalho): ");
	scanf("%s",url);
	char caminho[50];
	strcpy(caminho,"../");
	strcat(caminho,url);
	strcpy(url,caminho);
	strcat(url,".xml");
	/*s14 espaços, que são a quantidade de arquivos*/
	int selecionados[15];
	
	int contador = 0;
	/*variavel contador, para contar quantos arquivos serão exportados*/
	/*seta 0, em todos os espaços por default*/
	/*um for de 0 a 13, para verificar os arquivos selecionados*/
	for(int i = 0; i < 15; i++){
		selecionados[i] = 0;
	}
	/*depois disso*/
	/*verifica quais serão selecionados*/
	
	/*pergunta se vai exportar o hospedes*/
	printf("Exportar hospedes(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[1]);
	/*verifica se os hospedes vao ser exportados*/
	if(selecionados[1] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar o hoteis*/
	printf("Exportar hoteis(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[2]);
	/*verifica se os hoteis vao ser exportados*/
	if(selecionados[2] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as acmodações*/
	printf("Exportar acomodações(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[3]);
	/*verifica se as acomodações vao ser exportados*/
	if(selecionados[3] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as categorias*/
	printf("Exportar categorias(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[4]);
	/*verifica se as categorias vao ser exportados*/
	if(selecionados[4] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar os produtos*/
	printf("Exportar produtos(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[5]);
	/*verifica se os produtos vao ser exportados*/
	if(selecionados[5] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar os fornecedores*/
	printf("Exportar fornecedores(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[6]);
	/*verifica se os fornecedores vao ser exportados*/
	if(selecionados[6] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar os usuários*/
	printf("Exportar usuários(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[7]);
	/*verifica se os usuários vao ser exportados*/
	if(selecionados[7] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as entradas de produtos*/
	printf("Exportar entrada de produtos(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[8]);
	/*verifica se as entrada de produtos vao ser exportados*/
	if(selecionados[8] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as saida de produtos*/
	printf("Exportar saida de produtos(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[9]);
	/*verifica se as saida de produtos vao ser exportados*/
	if(selecionados[9] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as reservas*/
	printf("Exportar reservas(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[10]);
	/*verifica se as reservas vao ser exportados*/
	if(selecionados[10] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar os checks*/
	printf("Exportar checks(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[11]);
	/*verifica se os checks vao ser exportados*/
	if(selecionados[11] == 1){
		/*soma o contador*/
		contador++;
	}
	/*pergunta se vai exportar as contas*/
	printf("Exportar contas(1 - para sim, 0 - para não): ");
	scanf("%i",&selecionados[12]);
	/*verifica se as contas vao ser exportados*/
	if(selecionados[12] == 1){
		/*soma o contador*/
		contador++;
	}
	selecionados[0] = contador;
	/*verifica se foram selecionados pelo menos 1 tabela*/
	if(selecionados[0] > 0){
		/*se foi, cria o ponteiro de arquivo e já o abre com o url de destino e o */
		arquivo = fopen(url,modoabertura);
		/*verifica o tipo de salvamento*/
		/*verifica erros na abertura dos arquivos*/
		if(arquivo == NULL){
			/*verifica se há erros*/
			vermelho("\nErro na abertura do arquivo de exportaçao!\n");
		}
		else{
			switch(tipo){
				case 1:
					/*se estiver tudo ok, continua a execução*/
					/*primeira coisa, printar a tag dados*/
					fprintf(arquivo, "%s\n","<dados>");
					/*depois disso verifica quais structs foram selecionados*/
					/*selecionados 1, arquivo de hospede*/
					if(selecionados[1] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/hospedes.txt") == 1 && verifica_vazio(1,"saves/hospedes.txt") > 0){
							arquivo_abertura = fopen("saves/hospedes.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de hospedes!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-hospedes>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %i\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %i/%i/%i\n %s\n %s\n %s\n %s\n %s\n\n",
									&h.codigo,h.nome,&h.sexo,h.cpf,h.rg,h.rua,h.numero,h.bairro,h.cidadeestado.cidade,h.cidadeestado.estado,h.cep,
									h.complemento,&h.data_nascimento.dia,&h.data_nascimento.mes,&h.data_nascimento.ano,h.telefone,h.celular,h.estadocivil,
									h.email,h.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",h.codigo);
									fprintf(arquivo,"\t\t\t<nome>%s</nome>\n",h.nome);
									fprintf(arquivo,"\t\t\t<sexo>%i</sexo>\n",h.sexo);
									fprintf(arquivo,"\t\t\t<cpf>%s</cpf>\n",h.cpf);
									fprintf(arquivo,"\t\t\t<rg>%s</rg>\n",h.rg);
									fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",h.rua);
									fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",h.numero);
									fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",h.bairro);
									fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",h.complemento);
									fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",h.cep);
									fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",h.cidadeestado.cidade);
									fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",h.cidadeestado.estado);
									fprintf(arquivo,"\t\t\t<data_nascimento>%i/%i/%i</data_nascimento>\n",h.data_nascimento.dia,h.data_nascimento.mes,h.data_nascimento.ano);
									fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",h.telefone);
									fprintf(arquivo,"\t\t\t<celular>%s</celular>\n",h.celular);
									fprintf(arquivo,"\t\t\t<estado_civil>%s</estado_civil>\n",h.estadocivil);
									fprintf(arquivo,"\t\t\t<email>%s</email>\n",h.email);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",h.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-hospedes>");
							}
						}else{
							vermelho("\nErro, arquivo de hospedes não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					if(selecionados[2] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/hoteis.txt") == 1 && verifica_vazio(1,"saves/hoteis.txt") > 0){
							arquivo_abertura = fopen("saves/hoteis.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de hoteis\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-hoteis>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",
									&ht.codigo,ht.razaosocial,ht.nomefantasia,ht.cnpj,ht.insc,ht.rua,ht.numero,ht.bairro,ht.cidadeestado.cidade,
									ht.cidadeestado.estado,ht.cep,ht.complemento,ht.telefone,ht.email,ht.nomeresponsavel,ht.telefoneresponsavel,ht.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ht.codigo);
									fprintf(arquivo,"\t\t\t<razao_social>%s</razao_social>\n",ht.razaosocial);
									fprintf(arquivo,"\t\t\t<nome_fantasia>%s</nome_fantasia>\n",ht.nomefantasia);
									fprintf(arquivo,"\t\t\t<cnpj>%s</cnpj>\n",ht.cnpj);
									fprintf(arquivo,"\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n",ht.insc);
									fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",ht.rua);
									fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",ht.numero);
									fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",ht.bairro);
									fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",ht.complemento);
									fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",ht.cep);
									fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",ht.cidadeestado.cidade);
									fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",ht.cidadeestado.estado);
									fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",h.telefone);
									fprintf(arquivo,"\t\t\t<responsavel>%s</responsavel>\n",ht.nomeresponsavel);
									fprintf(arquivo,"\t\t\t<telefone_responsavel>%s</telefone_responsavel>\n",ht.telefoneresponsavel);
									fprintf(arquivo,"\t\t\t<email>%s</email>\n",ht.email);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ht.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-hoteis>");
							}
						}else{
							vermelho("\nErro, arquivo de hoteis não existe ou está vazio!!\n");
						}
						fclose(arquivo_abertura);
					}
					/*selecionados 3 == 1*/
					if(selecionados[3] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/acomodacoes.txt") == 1 && verifica_vazio(1,"saves/acomodacoes.txt") > 0){
							arquivo_abertura = fopen("saves/acomodacoes.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de acomodações!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-acomodacoes>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %i\n %s",&ac.codigo,ac.descricao,&ac.extra.tv,
										&ac.extra.tvcabo,&ac.extra.arcondicionado,&ac.extra.frigobar,&ac.extra.banheiro,&ac.extra.camacasal,
										&ac.extra.camasolteiro,&ac.extra.hidromassagem,&ac.extra.banheira,&ac.categoriaselecionada,ac.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ac.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",ac.descricao);
									fprintf(arquivo,"\t\t\t<tv>%i</tv>\n",ac.extra.tv);
									fprintf(arquivo,"\t\t\t<tv_cabo>%i</tv_cabo>\n",ac.extra.tvcabo);
									fprintf(arquivo,"\t\t\t<ar_condicionado>%i</ar_condicionado>\n",ac.extra.arcondicionado);
									fprintf(arquivo,"\t\t\t<frigobar>%i</frigobar>\n",ac.extra.frigobar);
									fprintf(arquivo,"\t\t\t<banheiro>%i</banheiro>\n",ac.extra.banheiro);
									fprintf(arquivo,"\t\t\t<cama_casal>%i</cama_casal>\n",ac.extra.camacasal);
									fprintf(arquivo,"\t\t\t<cama_solteiro>%i</cama_solteiro>\n",ac.extra.camasolteiro);
									fprintf(arquivo,"\t\t\t<banheira>%i</banheira>\n",ac.extra.banheira);
									fprintf(arquivo,"\t\t\t<hidromassagem>%i</hidromassagem>\n",ac.extra.hidromassagem);
									fprintf(arquivo,"\t\t\t<categoria>%i</categoria>\n",ac.categoriaselecionada);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ac.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-acomodacoes>");
							}
						}else{
							vermelho("\nErro, arquivo de acomodações não existe ou está vazio!!\n");
						}
						fclose(arquivo_abertura);	
					}
					/**/
					if(selecionados[4] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/categorias.txt") == 1 && verifica_vazio(1,"saves/categorias.txt") > 0){
							arquivo_abertura = fopen("saves/categorias.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de categorias!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-categorias>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %f\n %i\n %i\n %s",&c.codigo,c.descricao,&c.valor,&c.quantidadeadultos,&c.quantidadecriancas,
									c.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",c.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",c.descricao);
									fprintf(arquivo,"\t\t\t<valor>%.2f</valor>\n",c.valor);
									fprintf(arquivo,"\t\t\t<adultos>%i</adultos>",c.quantidadeadultos);
									fprintf(arquivo,"\t\t\t<criancas>%i</criancas>",c.quantidadecriancas);
									fprintf(arquivo,"\t\t\t<status>%s</status>",c.status);
									
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-categorias>");
							}
						}else{
							vermelho("\nErro, arquivo de categorias não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[5] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/produtos.txt") == 1 && verifica_vazio(1,"saves/produtos.txt") > 0){
							arquivo_abertura = fopen("saves/produtos.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-produtos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %i\n %i\n %f\n %f\n %s\n",&p.codigo,p.descricao,&p.estoque,&p.estoqueminimo,
									&p.lucro,&p.precovenda,p.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",p.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",p.descricao);
									fprintf(arquivo,"\t\t\t<estoque>%i</estoque>\n",p.estoque);
									fprintf(arquivo,"\t\t\t<estoque_minimo>%i</estoque_minimo>\n",p.estoqueminimo);
									fprintf(arquivo,"\t\t\t<lucro>%.2f</lucro>\n",p.lucro);
									fprintf(arquivo,"\t\t\t<preco_venda>%.2f</preco_venda>\n",p.precovenda);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",p.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-produtos>");
							}
						}else{
							vermelho("\nErro, arquivo de produtos não existe ou está vazio!!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[6] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/fornecedores.txt") == 1 && verifica_vazio(1,"saves/fornecedores.txt") > 0){
							arquivo_abertura = fopen("saves/fornecedores.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de fornecedores\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-fornecedores>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n %s\n",&f.codigo,
										f.nomefantasia,f.razaosocial,f.cnpj,f.insc,f.rua,f.numero,f.bairro,f.cep,f.complemento,f.cidadeestado.cidade,
										f.cidadeestado.estado,f.telefone,f.celular,f.email,f.nrepresentante,f.trepresentante,f.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",f.codigo);
									fprintf(arquivo,"\t\t\t<razao_social>%s</razao_social>\n",f.razaosocial);
									fprintf(arquivo,"\t\t\t<nome_fantasia>%s</nome_fantasia>\n",f.nomefantasia);
									fprintf(arquivo,"\t\t\t<cnpj>%s</cnpj>\n",f.cnpj);
									fprintf(arquivo,"\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n",f.insc);
									fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",f.rua);
									fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",f.numero);
									fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",f.bairro);
									fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",f.complemento);
									fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",f.cep);
									fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",f.cidadeestado.cidade);
									fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",f.cidadeestado.estado);
									fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",f.telefone);
									fprintf(arquivo,"\t\t\t<celular>%s</celular>\n",f.celular);
									fprintf(arquivo,"\t\t\t<representante>%s</representante>\n",f.nrepresentante);
									fprintf(arquivo,"\t\t\t<telefone_representante>%s</telefone_representante>\n",f.trepresentante);
									fprintf(arquivo,"\t\t\t<email>%s</email>\n",f.email);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",f.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
								}
								fprintf(arquivo,"\t%s\n","</tabela-fornecedores>");
							}
						}else{
							vermelho("\nErro, arquivo de fornecedores não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[7] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/usuarios.bin") == 1 && verifica_vazio(1,"saves/usuarios.bin") > 0){
							arquivo_abertura = fopen("saves/usuarios.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de usuários!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-usuarios>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&u,sizeof(struct usuarios),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",u.codigo);
									fprintf(arquivo,"\t\t\t<nome>%s</nome>\n",u.nome);
									fprintf(arquivo,"\t\t\t<login>%s</login>\n",u.login);
									fprintf(arquivo,"\t\t\t<senha>%s</senha>\n",u.senha);
									fprintf(arquivo,"\t\t\t<permissao>%i</permissao>\n",u.permissao);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",u.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
								}
								fprintf(arquivo,"\t%s\n","</tabela-usuarios>");
							}
						}else{
							vermelho("\nErro, arquivo de usuários não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}

					if(selecionados[8] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/entradaprodutos.txt") == 1 && verifica_vazio(1,"saves/entradaprodutos.txt") > 0){
							arquivo_abertura = fopen("saves/entradaprodutos.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de entrada de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-entradaprodutos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									/*le o código e a quantidade de produtos distintos*/
									fscanf(arquivo_abertura,"%u\n %i\n",&ep.codigo,&ep.produtos_distintos);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ep.codigo);
									fprintf(arquivo,"\t\t\t<produtos_distintos>%i</produtos_distintos>\n",ep.produtos_distintos);
									/*um for para ler a quantidade de produtos comprados*/
									for(int i = 0; i < ep.produtos_distintos; i++){
										/*pega esses valores*/
										fscanf(arquivo_abertura,"%u;%u;%i;%f;%s\n",&ep.codigoproduto[i],&ep.codigofornecedor[i],&ep.quantidade[i],&ep.precocusto[i],
											ep.status[i]);
										/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
										if(feof(arquivo_abertura)){
											break;
										}
										fprintf(arquivo,"\t\t\t\t<codigo_produto>%u</codigo_produto>\n",ep.codigoproduto[i]);
										fprintf(arquivo,"\t\t\t\t<codigo_fornecedor>%u</codigo_fornecedor>\n",ep.codigofornecedor[i]);
										fprintf(arquivo,"\t\t\t\t<quantidade>%i</quantidade>\n",ep.quantidade[i]);
										fprintf(arquivo,"\t\t\t\t<preco_custo>%.2f</preco_custo>\n",ep.precocusto[i]);
										fprintf(arquivo,"\t\t\t\t<status>%s</status>\n",ep.status[i]);
									}
									/*pega o restante dos valores*/
									fscanf(arquivo_abertura,"%f\n %f\n %f\n\n",&ep.frete,&ep.imposto,&ep.totalnota);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
											break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t\t<frete>%.2f</frete>\n",ep.frete);
									fprintf(arquivo,"\t\t\t<imposto>%.2f</imposto>\n",ep.imposto);
									fprintf(arquivo,"\t\t\t<total_nota>%.2f</total_nota>\n",ep.totalnota);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-entradaprodutos>");
							}
						}else{
							vermelho("\nErro, arquivo de entrada de produtos não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[9] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/saidaprodutos.txt") == 1 && verifica_vazio(1,"saves/saidaprodutos.txt") > 0){
							arquivo_abertura = fopen("saves/saidaprodutos.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de saida de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-saidaprodutos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %i\n",&sp.codigo,&sp.produtos_distintos);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo)){
										break;
									}
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",sp.codigo);
									fprintf(arquivo,"\t\t\t<produtos_distintos>%i</produtos_distintos>\n",sp.produtos_distintos);
									/*depois de lido a quantidade de produtos distintos*/
									/*le os outros dados que estão em forma de vetores*/
									for(int i = 0; i < sp.produtos_distintos; i++){
										/*le o resto dos dados*/
										fscanf(arquivo_abertura,"%u,%i,%f,%s\n",&sp.codigoproduto[i],&sp.quantidade[i],&sp.precovenda[i],sp.status[i]);
										/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
										if(feof(arquivo)){
											break;
										}
										fprintf(arquivo,"\t\t\t\t<codigo_produto>%u</codigo_produto>\n",sp.codigoproduto[i]);
										fprintf(arquivo,"\t\t\t\t<quantidade>%i</quantidade>\n",sp.quantidade[i]);
										fprintf(arquivo,"\t\t\t\t<preco_custo>%.2f</preco_custo>\n",sp.precovenda[i]);
										fprintf(arquivo,"\t\t\t\t<status>%s</status>\n",sp.status[i]);
									}
									fscanf(arquivo_abertura,"%f\n\n",&sp.totalpagar);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo)){
										break;
									}
									fprintf(arquivo,"\t\t\t<total_pagar>%.2f</total_pagar>\n",sp.totalpagar);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									/*depois de lido todos os dados*/
									/*salvou no arquivo*/
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-saidaprodutos>");
							}
						}else{
							vermelho("\nErro, arquivo de saida de produtos não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[10] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/reservas.txt") == 1 && verifica_vazio(1,"saves/reservas.txt") > 0){
							arquivo_abertura = fopen("saves/reservas.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de reservas!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-reservas>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %u\n %u\n %i/%i/%i\n %i/%i/%i\n %s\n\n",&r.codigo,&r.codigo_acomodacao,&r.codigo_hospede,
									&r.data_entrada.dia,&r.data_entrada.mes,&r.data_entrada.ano,&r.data_saida.dia,&r.data_saida.mes,&r.data_saida.ano,
									r.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",r.codigo);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",r.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",r.codigo_hospede);
									fprintf(arquivo,"\t\t\t<data_entrada>%i/%i/%i</data_entrada>\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
									fprintf(arquivo,"\t\t\t<data_saida>%i/%i/%i</data_saida>\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",r.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-reservas>");
							}
						}else{
							vermelho("\nErro, arquivo de reservas não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[11] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/checks.txt") == 1 && verifica_vazio(1,"saves/checks.txt") > 0){
							arquivo_abertura = fopen("saves/checks.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de checks!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-checks>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo_abertura,"%u\n %u\n %u\n %i\n %i/%i/%i\n %i/%i/%i\n %f\n %i\n %s\n\n",&ch.codigo,&ch.codigo_hospede,&ch.codigo_acomodacao,&ch.tipo,
									&ch.data_checkin.dia,&ch.data_checkin.mes,&ch.data_checkin.ano,&ch.data_checkout.dia,&ch.data_checkout.mes,&ch.data_checkout.ano,
									&ch.valor_total,&ch.pago,ch.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ch.codigo);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",ch.codigo_hospede);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",ch.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<tipo>%u</tipo>\n",ch.tipo);
									fprintf(arquivo,"\t\t\t<data_checkin>%i/%i/%i</data_checkin>\n",ch.data_checkin.dia,ch.data_checkin.mes,ch.data_checkin.ano);
									fprintf(arquivo,"\t\t\t<data_checkout>%i/%i/%i</data_checkout>\n",ch.data_checkout.dia,ch.data_checkout.mes,ch.data_checkout.ano);
									fprintf(arquivo,"\t\t\t<valor_total>%.2f</valor_total>\n",ch.valor_total);
									fprintf(arquivo,"\t\t\t<pago>%i</pago>\n",ch.pago);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ch.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-checks>");
							}
						}else{
							vermelho("\nErro, arquivo de checks não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[12] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(1,"saves/contas.txt") == 1 && verifica_vazio(1,"saves/contas.txt") > 0){
							arquivo_abertura = fopen("saves/contas.txt","r");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de contas!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-contas>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fscanf(arquivo,"%u\n %u\n %u\n %f\n %f\n %i\n %s\n\n",&ct.codigo,&ct.codigo_hospede,&ct.codigo_acomodacao,
									&ct.valor,&ct.valor_total,&ct.pago,ct.status);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ct.codigo);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",ct.codigo_hospede);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",ct.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<valor>%.2f</valor>\n",ct.valor);
									fprintf(arquivo,"\t\t\t<valor_total>%.2f</valor_total>\n",ct.valor_total);
									fprintf(arquivo,"\t\t\t<pago>%i</pago>\n",ct.pago);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ct.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								/*salva o final dessa tabela*/
								fprintf(arquivo,"\t%s\n","</tabela-contas>");
							}
						/*mostra mensagem de erro caso o arquivo não existe ou esteja vazio*/
						}else{
							vermelho("\nErro, arquivo de checks não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/*salva o final dos dados*/
					fprintf(arquivo, "%s\n","</dados>");
					/*e fecha o arquivo*/
					fclose(arquivo);
				break;


				case 2:/*leitura dos arquivos binarios*/
					/*se estiver tudo ok, continua a execução*/
					/*primeira coisa, printar a tag dados*/
					fprintf(arquivo, "%s\n","<dados>");
					/*depois disso verifica quais structs foram selecionados*/
					/*selecionados 1, arquivo de hospede*/
					if(selecionados[1] == 1){
						if(verifica_existencia_arquivo(2,"saves/hospedes.bin") == 1 && verifica_vazio(2,"saves/hospedes.bin") > 0){
							/*se ele foi selecionado, salva seus dados no arquivo*/
							arquivo_abertura = fopen("saves/hospedes.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de hospedes!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-hospedes>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&h,sizeof(struct hospede),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",h.codigo);
									fprintf(arquivo,"\t\t\t<nome>%s</nome>\n",h.nome);
									fprintf(arquivo,"\t\t\t<sexo>%i</sexo>\n",h.sexo);
									fprintf(arquivo,"\t\t\t<cpf>%s</cpf>\n",h.cpf);
									fprintf(arquivo,"\t\t\t<rg>%s</rg>\n",h.rg);
									fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",h.rua);
									fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",h.numero);
									fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",h.bairro);
									fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",h.complemento);
									fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",h.cep);
									fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",h.cidadeestado.cidade);
									fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",h.cidadeestado.estado);
									fprintf(arquivo,"\t\t\t<data_nascimento>%i/%i/%i</data_nascimento>\n",h.data_nascimento.dia,h.data_nascimento.mes,h.data_nascimento.ano);
									fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",h.telefone);
									fprintf(arquivo,"\t\t\t<celular>%s</celular>\n",h.celular);
									fprintf(arquivo,"\t\t\t<estado_civil>%s</estado_civil>\n",h.estadocivil);
									fprintf(arquivo,"\t\t\t<email>%s</email>\n",h.email);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",h.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								/*salva o final dos dados*/
								fprintf(arquivo,"\t%s\n","</tabela-hospedes>");
							}
						/*mostra mensagem de erro para arquivos vazios ou não existentes*/
						}
						else{
							vermelho("\nErro, arquivo de acomodações não existe ou está vazio!!\n");
						}
						/*fecha o arquivo de abertura*/
						fclose(arquivo_abertura);
						/**/
						if(selecionados[2] == 1){
							/*se ele foi selecionado, salva seus dados no arquivo*/
							if(verifica_existencia_arquivo(2,"saves/hoteis.bin") == 1 && verifica_vazio(2,"saves/hoteis.bin") > 0){
								arquivo_abertura = fopen("saves/hoteis.bin","rb");
								/*verifica erros na abertura*/
								if(arquivo_abertura == NULL){
									/*mostra mensagem*/
									vermelho("\nErro na abertura do arquivo de hoteis\n");
								}
								/*se estiver tudo ok, continua a execução*/
								else{
									/*le o arquivo todo*/
									fprintf(arquivo,"\t%s\n","<tabela-hoteis>");
									while(!feof(arquivo_abertura)){
										/*comando para leitura*/
										fread(&ht,sizeof(struct hotel),1,arquivo_abertura);
										/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
										if(feof(arquivo_abertura)){
											break;
										}
										/*depois de lido, salva os dados no arquivo de exportação*/
										fprintf(arquivo,"\t\t%s\n","<registro>");
										fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ht.codigo);
										fprintf(arquivo,"\t\t\t<razao_social>%s</razao_social>\n",ht.razaosocial);
										fprintf(arquivo,"\t\t\t<nome_fantasia>%s</nome_fantasia>\n",ht.nomefantasia);
										fprintf(arquivo,"\t\t\t<cnpj>%s</cnpj>\n",ht.cnpj);
										fprintf(arquivo,"\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n",ht.insc);
										fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",ht.rua);
										fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",ht.numero);
										fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",ht.bairro);
										fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",ht.complemento);
										fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",ht.cep);
										fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",ht.cidadeestado.cidade);
										fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",ht.cidadeestado.estado);
										fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",h.telefone);
										fprintf(arquivo,"\t\t\t<responsavel>%s</responsavel>\n",ht.nomeresponsavel);
										fprintf(arquivo,"\t\t\t<telefone_responsavel>%s</telefone_responsavel>\n",ht.telefoneresponsavel);
										fprintf(arquivo,"\t\t\t<email>%s</email>\n",ht.email);
										fprintf(arquivo,"\t\t\t<status>%s</status>\n",ht.status);
										fprintf(arquivo,"\t\t%s\n","</registro>");
									}
									fprintf(arquivo,"\t%s\n","</tabela-hoteis>");
								}
							}else{
								vermelho("\nErro, arquivo de hoteis não existe ou está vazio!!\n");
							}
							fclose(arquivo_abertura);
						}
					}
					/*selecionados 3 == 1*/
					if(selecionados[3] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/acomodacoes.bin") == 1 && verifica_vazio(2,"saves/acomodacoes.bin") > 0){
							arquivo_abertura = fopen("saves/acomodacoes.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de acomodações!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-acomodacoes>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&ac,sizeof(struct acomodacoes),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ac.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",ac.descricao);
									fprintf(arquivo,"\t\t\t<tv>%i</tv>\n",ac.extra.tv);
									fprintf(arquivo,"\t\t\t<tv_cabo>%i</tv_cabo>\n",ac.extra.tvcabo);
									fprintf(arquivo,"\t\t\t<ar_condicionado>%i</ar_condicionado>\n",ac.extra.arcondicionado);
									fprintf(arquivo,"\t\t\t<frigobar>%i</frigobar>\n",ac.extra.frigobar);
									fprintf(arquivo,"\t\t\t<banheiro>%i</banheiro>\n",ac.extra.banheiro);
									fprintf(arquivo,"\t\t\t<cama_casal>%i</cama_casal>\n",ac.extra.camacasal);
									fprintf(arquivo,"\t\t\t<cama_solteiro>%i</cama_solteiro>\n",ac.extra.camasolteiro);
									fprintf(arquivo,"\t\t\t<banheira>%i</banheira>\n",ac.extra.banheira);
									fprintf(arquivo,"\t\t\t<hidromassagem>%i</hidromassagem>\n",ac.extra.hidromassagem);
									fprintf(arquivo,"\t\t\t<categoria>%i</categoria>\n",ac.categoriaselecionada);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ac.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
								}
								fprintf(arquivo,"\t%s\n","</tabela-acomodacoes>");
							}
						}else{
							vermelho("\nErro, arquivo de acomodações não existe ou está vazio!!\n");
						}
						fclose(arquivo_abertura);	
					}
					/**/
					if(selecionados[4] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/categorias.bin") == 1 && verifica_vazio(2,"saves/categorias.txt") > 0){
							arquivo_abertura = fopen("saves/categorias.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de categorias!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-categorias>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&c,sizeof(struct categorias),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",c.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",c.descricao);
									fprintf(arquivo,"\t\t\t<valor>%.2f</valor>\n",c.valor);
									fprintf(arquivo,"\t\t\t<adultos>%i</adultos>\n",c.quantidadeadultos);
									fprintf(arquivo,"\t\t\t<criancas>%i</criancas>\n",c.quantidadecriancas);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",c.status);
									
									fprintf(arquivo,"\t\t%s\n","</registro>");
								}
								fprintf(arquivo,"\t%s\n","</tabela-categorias>");
							}
						}else{
							vermelho("\nErro, arquivo de categorias não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[5] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/produtos.bin") == 1 && verifica_vazio(2,"saves/produtos.bin") > 0){
							arquivo_abertura = fopen("saves/produtos.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-produtos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&p,sizeof(struct produtos),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",p.codigo);
									fprintf(arquivo,"\t\t\t<descricao>%s</descricao>\n",p.descricao);
									fprintf(arquivo,"\t\t\t<estoque>%i</estoque>\n",p.estoque);
									fprintf(arquivo,"\t\t\t<estoque_minimo>%i</estoque_minimo>\n",p.estoqueminimo);
									fprintf(arquivo,"\t\t\t<lucro>%.2f</lucro>\n",p.lucro);
									fprintf(arquivo,"\t\t\t<preco_venda>%.2f</preco_venda>\n",p.precovenda);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",p.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-produtos>");
							}
						}else{
							vermelho("\nErro, arquivo de produtos não existe ou está vazio!!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[6] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/fornecedores.bin") == 1 && verifica_vazio(2,"saves/fornecedores.bin") > 0){
							arquivo_abertura = fopen("saves/fornecedores.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de fornecedores\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-fornecedores>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&f,sizeof(struct fornecedores),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",f.codigo);
									fprintf(arquivo,"\t\t\t<razao_social>%s</razao_social>\n",f.razaosocial);
									fprintf(arquivo,"\t\t\t<nome_fantasia>%s</nome_fantasia>\n",f.nomefantasia);
									fprintf(arquivo,"\t\t\t<cnpj>%s</cnpj>\n",f.cnpj);
									fprintf(arquivo,"\t\t\t<inscricao_estadual>%s</inscricao_estadual>\n",f.insc);
									fprintf(arquivo,"\t\t\t<rua>%s</rua>\n",f.rua);
									fprintf(arquivo,"\t\t\t<numero>%s</numero>\n",f.numero);
									fprintf(arquivo,"\t\t\t<bairro>%s</bairro>\n",f.bairro);
									fprintf(arquivo,"\t\t\t<complemento>%s</complemento>\n",f.complemento);
									fprintf(arquivo,"\t\t\t<cep>%s</cep>\n",f.cep);
									fprintf(arquivo,"\t\t\t<cidade>%s</cidade>\n",f.cidadeestado.cidade);
									fprintf(arquivo,"\t\t\t<estado>%s</estado>\n",f.cidadeestado.estado);
									fprintf(arquivo,"\t\t\t<telefone>%s</telefone>\n",f.telefone);
									fprintf(arquivo,"\t\t\t<celular>%s</celular>\n",f.celular);
									fprintf(arquivo,"\t\t\t<representante>%s</representante>\n",f.nrepresentante);
									fprintf(arquivo,"\t\t\t<telefone_representante>%s</telefone_representante>\n",f.trepresentante);
									fprintf(arquivo,"\t\t\t<email>%s</email>\n",f.email);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",f.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
								}
								fprintf(arquivo,"\t%s\n","</tabela-fornecedores>");
							}
						}else{
							vermelho("\nErro, arquivo de fornecedores não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[7] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/usuarios.bin") == 1 && verifica_vazio(2,"saves/usuarios.bin") > 0){
							arquivo_abertura = fopen("saves/usuarios.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de usuários!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-usuarios>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&u,sizeof(struct usuarios),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>\n");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",u.codigo);
									fprintf(arquivo,"\t\t\t<nome>%s</nome>\n",u.nome);
									fprintf(arquivo,"\t\t\t<login>%s</login>\n",u.login);
									fprintf(arquivo,"\t\t\t<senha>%s</senha>\n",u.senha);
									fprintf(arquivo,"\t\t\t<permissao>%i</permissao>",u.permissao);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",u.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								fprintf(arquivo,"\t%s\n","</tabela-usuarios>");
							}
						}else{
							vermelho("\nErro, arquivo de usuários não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}

					if(selecionados[8] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/entradaprodutos.bin") == 1 && verifica_vazio(2,"saves/entradaprodutos.bin") > 0){
							arquivo_abertura = fopen("saves/entradaprodutos.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de entrada de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-entradaprodutos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									/*le o código e a quantidade de produtos distintos*/
									fread(&ep,sizeof(struct entradaprodutos),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*salva no xml*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ep.codigo);
									fprintf(arquivo,"\t\t\t<produtos_distintos>%i</produtos_distintos>\n",ep.produtos_distintos);
									/*pega esses valores de cada produto comprado e coloca na mesma linha*/
									for(int i = 0; i < ep.produtos_distintos; i++){
										fprintf(arquivo,"\t\t\t\t<codigo_produto>%u</codigo_produto>\n",ep.codigoproduto[i]);
										fprintf(arquivo,"\t\t\t\t<codigo_fornecedor>%u</codigo_fornecedor>\n",ep.codigofornecedor[i]);
										fprintf(arquivo,"\t\t\t\t<quantidade>%i</quantidade>\n",ep.quantidade[i]);
										fprintf(arquivo,"\t\t\t\t<preco_custo>%.2f</preco_custo>\n",ep.precocusto[i]);
										fprintf(arquivo,"\t\t\t\t<status>%s</status>\n",ep.status[i]);
									}
									/*salva o restante dos dados*/
									fprintf(arquivo,"\t\t\t<frete>%.2f</frete>\n",ep.frete);
									fprintf(arquivo,"\t\t\t<imposto>%.2f</imposto>\n",ep.imposto);
									fprintf(arquivo,"\t\t\t<total_nota>%.2f</total_nota>\n",ep.totalnota);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								/*salva o final da tabela*/
								fprintf(arquivo,"\t%s\n","</tabela-entradaprodutos>");
							}
						/*mostra erro para arquivo vazio ou nao existente*/
						}else{
							vermelho("\nErro, arquivo de entrada de produtos não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[9] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/saidaprodutos.bin") == 1 && verifica_vazio(2,"saves/saidaprodutos.bin") > 0){
							arquivo_abertura = fopen("saves/saidaprodutos.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de saida de produtos!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-saidaprodutos>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&sp,sizeof(struct saidaprodutos),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*salva os dados no xml*/
									fprintf(arquivo,"\t\t%s\n","<registro>\n");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",sp.codigo);
									fprintf(arquivo,"\t\t\t<produtos_distintos>%i</produtos_distintos>\n",sp.produtos_distintos);
									/*salva os produtos comprados em cada linha*/
									for(int i = 0; i < sp.produtos_distintos; i++){
										fprintf(arquivo,"\t\t\t\t<codigo_produto>%u</codigo_produto>\n",sp.codigoproduto[i]);
										fprintf(arquivo,"\t\t\t\t<quantidade>%i</quantidade>\n",sp.quantidade[i]);
										fprintf(arquivo,"\t\t\t\t<preco_custo>%.2f</preco_custo>\n",sp.precovenda[i]);
										fprintf(arquivo,"\t\t\t\t<status>%s</status>\n",sp.status[i]);
									}
									/*salva o resto dos dados*/
									fprintf(arquivo,"\t\t\t<total_pagar>%.2f</total_pagar>\n",sp.totalpagar);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									/*depois de lido todos os dados*/
									
								}
								/*final da tabela de saida de produtos*/
								fprintf(arquivo,"\t%s\n","</tabela-saidaprodutos>");
							}
						/*em caso de arquivo vazio ou não existente, mostra mensagem de erro*/
						}else{
							vermelho("\nErro, arquivo de saida de produtos não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[10] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/reservas.bin") == 1 && verifica_vazio(2,"saves/reservas.bin") > 0){
							arquivo_abertura = fopen("saves/reservas.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de reservas!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-reservas>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&r,sizeof(struct reserva),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",r.codigo);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",r.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",r.codigo_hospede);
									fprintf(arquivo,"\t\t\t<data_entrada>%i/%i/%i</data_entrada>\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
									fprintf(arquivo,"\t\t\t<data_saida>%i/%i/%i</data_saida>\n",r.data_entrada.dia,r.data_entrada.mes,r.data_entrada.ano);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",r.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
								
								}
								/*salva o final da tabela*/
								fprintf(arquivo,"\t%s\n","</tabela-reservas>");
							}
						/*erro em caso de arquivo vazio ou nao existente*/
						}else{
							vermelho("\nErro, arquivo de reservas não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[11] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/checks.bin") == 1 && verifica_vazio(2,"saves/checks.bin") > 0){
							arquivo_abertura = fopen("saves/checks.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de checks!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-checks>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&ch,sizeof(struct checks),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ch.codigo);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",ch.codigo_hospede);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",ch.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<tipo>%u</tipo>\n",ch.tipo);
									fprintf(arquivo,"\t\t\t<data_checkin>%i/%i/%i</data_checkin>\n",ch.data_checkin.dia,ch.data_checkin.mes,ch.data_checkin.ano);
									fprintf(arquivo,"\t\t\t<data_checkout>%i/%i/%i</data_checkout>\n",ch.data_checkout.dia,ch.data_checkout.mes,ch.data_checkout.ano);
									fprintf(arquivo,"\t\t\t<valor_total>%.2f</valor_total>\n",ch.valor_total);
									fprintf(arquivo,"\t\t\t<pago>%i</pago>\n",ch.pago);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ch.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								/*fim de tabela de checks*/
								fprintf(arquivo,"\t%s\n","</tabela-checks>");
							}
						/*mensagem de erro, arquivo vazio ou nao existente*/
						}else{
							vermelho("\nErro, arquivo de checks não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/**/
					if(selecionados[12] == 1){
						/*se ele foi selecionado, salva seus dados no arquivo*/
						if(verifica_existencia_arquivo(2,"saves/contas.bin") == 1 && verifica_vazio(2,"saves/contas.bin") > 0){
							arquivo_abertura = fopen("saves/contas.bin","rb");
							/*verifica erros na abertura*/
							if(arquivo_abertura == NULL){
								/*mostra mensagem*/
								vermelho("\nErro na abertura do arquivo de contas!\n");
							}
							/*se estiver tudo ok, continua a execução*/
							else{
								/*le o arquivo todo*/
								fprintf(arquivo,"\t%s\n","<tabela-contas>");
								while(!feof(arquivo_abertura)){
									/*comando para leitura*/
									fread(&ct,sizeof(struct contas),1,arquivo_abertura);
									/*verifica o final do arquivo para evitar erros, e sai do laço caso esteja*/
									if(feof(arquivo_abertura)){
										break;
									}
									/*depois de lido, salva os dados no arquivo de exportação*/
									fprintf(arquivo,"\t\t%s\n","<registro>");
									fprintf(arquivo,"\t\t\t<codigo>%u</codigo>\n",ct.codigo);
									fprintf(arquivo,"\t\t\t<codigo_hospede>%u</codigo_hospede>\n",ct.codigo_hospede);
									fprintf(arquivo,"\t\t\t<codigo_acomodacao>%u</codigo_acomodacao>\n",ct.codigo_acomodacao);
									fprintf(arquivo,"\t\t\t<valor>%.2f</valor>\n",ct.valor);
									fprintf(arquivo,"\t\t\t<valor_total>%.2f</valor_total>\n",ct.valor_total);
									fprintf(arquivo,"\t\t\t<pago>%i</pago>\n",ct.pago);
									fprintf(arquivo,"\t\t\t<status>%s</status>\n",ct.status);
									fprintf(arquivo,"\t\t%s\n","</registro>");
									
								}
								/*final da tabela de contas*/
								fprintf(arquivo,"\t%s\n","</tabela-contas>");
							}
						/*mensagem de ero para arquivo nao existente ou vazio*/
						}else{
							vermelho("\nErro, arquivo de checks não existe ou está vazio!\n");
						}
						fclose(arquivo_abertura);
					}
					/*final dos dados*/
					fprintf(arquivo, "%s\n","</dados>");
					fclose(arquivo);
				break;
				default:/*erro para opções de salvamento invalidas*/
					vermelho("\nOpção de salvamento ainda não implementada!\n");
				break;
			}
		}	
	}
	else{
		vermelho("\nNão foram selecionados arquivos para exportação!\n");
	}
	verde("\nArquivo de exportação gerado com sucesso!\n");
}
/*função para importar as tabelas externas*/
void importa_tabelas(int tipo,char modoabertura[5]){
	/*cria um ponteiro para abrir o arquivo*/
	FILE *arquivo;
	char url[50];
	printf("Digite o url do arquivo a ser importado: ");
	scanf("%s",url);
	arquivo = fopen(url,modoabertura);
	if(arquivo == NULL){
		vermelho("\nErro na abertura do arquivo!\n");
	}
	else{
		switch(tipo){
			case 1:
				/*le o arquivo*/
				while(!feof(arquivo)){
					
				}
			break;
		}
	}
}
#endif