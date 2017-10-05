#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "structs.h"

void configsave(int op,char mlogin[20],char msenha[20]){
	FILE * arquivo;
	struct config c;
	c.opcao = op;
	strcpy(c.master_login,mlogin);
	strcpy(c.master_senha,msenha);
	arquivo = fopen("config/config.bin","ab");
	if(arquivo == NULL){
		printf("Erro em realizar o salvamento da configuração!\n");
	}
	else{
		fwrite(&c,sizeof(struct config),1,arquivo);
		printf("\nConfigurações realizadas com sucesso!\n\n");
	}
	fclose(arquivo);
}


int verificasave(){
	FILE *arquivo;
	int op;
	arquivo = fopen("config/config.bin","a+b");
	if(arquivo == NULL){
		printf("\nErro em realizar a busca das configurações, não foram encontradas configurações!\n\n");
	}
	else{
		fread(&op,sizeof(int),1,arquivo);
		return op;
	}
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