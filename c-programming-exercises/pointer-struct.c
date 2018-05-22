#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    struct{
        char titulo[30];
        int codigo;
        float valor;
    }livro;

    char numstr[8];

    FILE *fpont;

    if ((fpont == fopen("e:/livros.txt", "wb")) == NULL){

        printf("não posso abrir o arquivo livros");
        exit(1);
        }

    do{
        printf("Digite o nome do livro: ");
        gets(livro.titulo);
        printf("digite o cod do livro: ");
        gets(numstr);
        livro.codigo = atoi(numstr);
        printf("digite o preco: ");
        gets(numstr);
        livro.valor = atof(numstr);

        fwrite(&livro, sizeof(livro), 1, fpont);

        printf("adiciona outro registro no arquivo...");
    }while(getche() == 's');

    fclose(fpont);

return 0;
}
