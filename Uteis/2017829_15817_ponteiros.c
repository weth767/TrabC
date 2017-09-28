
#include <stdio.h>
#include <stdlib.h>


struct ponto {
    int x, y;
};

int exemplo01();
int exemplo02();
int exemplo03();
int exemplo04();
int exemplo05();
int exemplo06();
int exemplo07();
int exemplo08();
int exemplo09();
int exemplo10();
int exemplo11();
int exemplo12();
int exemplo13();
int exemplo14();
int exemplo15();

void imprime_vetor(int *n, int m);
void imprime_matriz(int m[][2], int n);
void imprime_struct_valor(struct ponto p);
void instancia_struct_referencia(struct ponto *p);

    
int main(){
    
    exemplo14();
    return 0;
}


int exemplo01(){    
    int a = 12;
    int *p;
    
    p = &a;
    
    printf("Conteúdo de p: %p\n",p);
    printf("Endereço de p: %p\n",&p);
    printf("Conteúdo da posição apontada por p: %d\n",*p);
    
    p++;
    
    printf("\n-----------------------------------------------------------------\n");
    printf("Conteúdo de p após p++: %p\n",p);
    printf("Endereço de p após p++: %p\n",&p);
    printf("Conteúdo da posição apontada por p após p++: %d\n",*p);

    p--;
    
    printf("-----------------------------------------------------------------\n");
    printf("Conteúdo de p após p--: %p\n",p);
    printf("Endereço de p após p--: %p\n",&p);
    printf("Conteúdo da posição apontada por p após p--: %d\n",*p);
    
    return 0;
    
    
}
    
    
int exemplo02(){
    int *ptr, xyz = 20;
    ptr = &xyz;
    printf("Conteudo apontado por ptr (1): %d \n",*ptr);
    (*ptr)++;
    printf("Conteudo apontado por ptr (2): %d \n",*ptr);
    *ptr = (*ptr) * 10;
    printf("Conteudo apontado por ptr (3): %d \n",*ptr);
    return 0;
}

int exemplo03(){
    int *p, *p1, x, y;
    p = &x;
    p1 = &y;
    if(p > p1)
        printf("O ponteiro p aponta para uma posicao a frente de p1\n");
    else
        printf("O ponteiro p NAO aponta para uma posicao a frente de p1\n");
    return 0;
}

int exemplo04(){
    int *p, *p1, x = 10, y = 20;
    p = &x;
    p1 = &y;
    if(*p > *p1)
        printf("O conteudo de p e maior do que o conteudo de p1\n");
    else
        printf("O conteudo de p NAO e maior do que o conteudo de p1\n");
    return 0;
}

int exemplo05(){
    
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (int i = 0; i < 7; i++) {
        printf("%d\t",numeros[i]);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    
    for (int c = 0; c < 7; c++) {
        printf("%p\t",ptr_numeros);
        ptr_numeros++;
    }
}

int exemplo06(){
    
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (int i = 0; i < 7; i++) {
        printf("%d\t",numeros[i]);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    
    for (; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%p\t",ptr_numeros);
    }
}

int exemplo07(){
    int numeros[7] = {10,30,2,4,8,22,50};
    int *ptr_numeros = numeros;
    
    for (; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%d\t",*ptr_numeros);
    }
    
    printf("\n ------- imprimindo agora os endereços -------\n");
    
    for (ptr_numeros=numeros; ptr_numeros != numeros+7; ptr_numeros++) {
        printf("%p\t",ptr_numeros);
    }
}

int exemplo08(){
    
    int vet[5] = {1,2,3,4,5};
    int *p, indice = 2;
    p = vet;
    //vet[0] é equivalente a *p;
    printf("\nValor de *p: %d\n",*p);
    printf("É equivalente a vet[0]: %d\n",vet[0]);
    //vet[indice] é equivalente a *(p+indice);
    printf("\nValor de vet[indice]: %d\n",vet[indice]);
    printf("É equivalente a *(p+indice): %d\n",*(p+indice));
    //vet é equivalente a &vet[0];
    printf("\nValor de vet: %p\n",vet);
    printf("É equivalente a &vet[0]: %p\n",&vet[0]);
    //&vet[indice] é equivalente a (vet+indice);
    printf("\nValor de &vet[indice]: %p\n",&vet[indice]);
    printf("É equivalente a (vet+indice): %p\n",(vet+indice));
    return 0;
}

int exemplo09(){
    int mat[2][2] = {{1,2},{3,4}};
    int i,j;
    printf("-------- imprimindo arrays multidimensionais da forma tradicional --------\n");
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            printf("%d\n", mat[i][j]);
    
    printf("-------- outra forma, usando ponteiros --------\n");

    int *p = &mat[0][0];
    for(i=0;i<4;i++)
        printf("%d\n", *(p+i));
    return 0;
}

void Troca(int*a,int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int exemplo10(int *n){
    *n=*n+1; //ou poderia ser (*n)++
}

int exemplo11(){
    int x = 1;
    int y = 3;
    //chamando exemplo10 para incrementar 1 em x
    exemplo10(&x);

    printf("Antes: %d e %d\n",x,y);
    Troca(&x,&y);
    printf("Depois: %d e %d\n",x,y);
    return 0;
}

void imprime_vetor(int *n, int m){
    int i;
    for (i=0; i<m;i++)
        printf("%d \t", n[i]);
}

int exemplo12(){
    int v[5] = {1,2,3,4,5};
    imprime_vetor(v,5);
    return 0;
}


void imprime_matriz(int m[][2], int n){
    int i,j;
    for (i=0; i<n;i++){
        for (j=0; j<2;j++)
            printf("%d \t", m[i][j]);
        printf("\n");
    }        
}

int exemplo13(){
    int mat[3][2] = {{1,2},{3,4},{5,6}};
    imprime_matriz(mat,3);
    return 0;
}

void imprime_struct_valor(struct ponto p){
    printf("x = %d\n",p.x);
    printf("y = %d\n",p.y);
}

int exemplo14(){
    struct ponto p1 = {10,20};
    imprime_struct_valor(p1);
    return 0;
}

void instancia_struct_referencia(struct ponto *p){
    (*p).x = 10;
    (*p).y = 20;
}

int exemplo15(){
    struct ponto p1;
    instancia_struct_referencia(&p1);
    printf("x = %d\n",p1.x);
    printf("y = %d\n",p1.y);
    return 0;
}
