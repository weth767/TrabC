#ifndef EXCLUSAO_H
#define EXCLUSAO_H

#include <stdio.h>
#include <string.h>
#include "structs.h"

void excluihospede(int tipo,int codigo){
	FILE *arquivo;
	struct hospede h;
	switch(tipo){
		case 1:
			arquivo = fopen("saves/hospede.txt","a+");
			if(arquivo == NULL){
				printf("\nErro em localizar o arquivo do hospede!!\n\n");
			}
			else{
				while(!feof(arquivo) && )
			}
		break;
		case 2:

		break;
	}
}

#endif