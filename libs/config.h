#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void configsave(int op){
	FILE * arquivo;
	arquivo = fopen("config/config.bin","ab");
	if(arquivo == NULL){
		printf("Erro em realizar o salvamento da configuração!\n");
	}
	else{
		fwrite(&op,sizeof(int),1,arquivo);
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

#endif