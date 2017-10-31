#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "structs.h"
#include "cores.h"
/*função para a configuração inicial*/
void configsave(int op,char mlogin[20],char msenha[20]){
	/*recebe por parametro a opção de salvamento, o login e a senha master*/
	FILE * arquivo;
	/*cria um ponteiro de arquivo*/
	struct config c;
	/*chama a struct de config, para ter acesso a suas variaveis*/
	c.opcao = op;
	/*passa os dados para a struct*/
	strcpy(c.master_login,mlogin);
	strcpy(c.master_senha,msenha);
	/*abre o arquivo*/
	arquivo = fopen("config/config.bin","ab");
	/*verifica se o houve erro na abertura do arquivo*/
	/*se houve mostra mensagem na tela*/
	if(arquivo == NULL){
		vermelho("Erro em realizar o salvamento da configuração!\n");
	}
	/*se estiver tudo ok, salva as configurações e mostra mensagem de sucesso*/
	else{
		fwrite(&c,sizeof(struct config),1,arquivo);
		verde("\nConfigurações realizadas com sucesso!\n\n");
	}/*fecha o arquivo*/
	fclose(arquivo);
}

/*função verifica save*/
int verificasave(){
	/*função que faz a verifcação de tipo de salvamento*/
	FILE *arquivo;
	/*cria um ponteiro de arquivo*/
	int op;
	/*abre o arquivo da configuração*/
	arquivo = fopen("config/config.bin","ab+");
	/*verifica se o arquivo teve algum problema na abertura*/
	/*se teve mostra mensagem na tela*/
	if(arquivo == NULL){
		vermelho("\nErro em realizar a busca das configurações, não foram encontradas configurações!\n\n");
	}
	/*se estiver tudo certo, le o arquivo e retorna o tipo de configuração feita*/
	else{
		fread(&op,sizeof(int),1,arquivo);
		return op;
	}
	/*fecha o arquivo*/
	fclose(arquivo);
}

/**int teste(int argc, char *argv[]){
    
    struct stat st = {0};
    
    if (stat("/home/alunos/Desktop/TrabC/", &st) == -1) {
        if(mkdir("/home/alunos/Desktop/TrabC/saves", 0700) == 0){

        }
    }        
    
    return 0;
 }*/

#endif