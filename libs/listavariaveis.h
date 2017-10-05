int listahospede(char variavel[25]){
/*
fprintf(arquivo,"%u",h.codigo);
fprintf(arquivo,"\n%s",h.nome);
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
fprintf(arquivo,"\n%s\n\n",h.status);*/
	if(strcmp(variavel,"nome") == 0){
		return 1;
	}
	else if(strcmp(variavel,"cpf") == 0){
		return 2;
	}
	else if(strcmp(variavel,"rg") == 0){
		return 3;
	}
	else if(strcmp(variavel,"rua") == 0){
		return 4;
	}
	else if(strcmp(variavel,"numero") == 0){
		return 5;
	}
	else if(strcmp(variavel,"bairro") == 0){
		return 6;
	}
	else if(strcmp(variavel,"cidade") == 0){
		return 7;
	}
	else if(strcmp(variavel,"estado") == 0){
		return 8;
	}
	else if(strcmp(variavel,"cep") == 0){
		return 9;
	}
	else if(strcmp(variavel,"complemento") == 0){
		return 10;
	}
	else if(strcmp(variavel,"datanascimento") == 0){
		return 11;
	}
	else if(strcmp(variavel,"telefone") == 0){
		return 12;
	}
	else if(strcmp(variavel,"celular") == 0){
		return 13;
	}
	else if(strcmp(variavel,"estadocivil") == 0){
		return 14;
	}
	else if(strcmp(variavel,"email") == 0){
		return 15;
	}
	else if(strcmp(variavel,"status") == 0){
		return 16;
	}

}