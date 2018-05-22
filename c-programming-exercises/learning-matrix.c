#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL, "Portuguese");

    int i, j, linha [10], colum [10], matriz[10][10], linha1 = 0, linha2 = 0, linha3 = 0, linha4 = 0, col1 = 0, col2 = 0, col3 = 0, col4 = 0;

    printf("\t\tSomando linhas e colunas da Matriz\n\n\n");

    for(i = 1; i <= 4; i++){

        for(j = 1; j <= 4; j++){

            printf("Digite o valor da linha %d, coluna %d: ", i, j);
            scanf("%d", &matriz [i][j]);

            // soma das linhas

            if (i == 1){
                linha1 = linha1 + matriz [i][j];
            }

            else if (i == 2){
                linha2 = linha2 + matriz [i][j];
            }
             else if (i == 3){
                linha3 = linha3 + matriz [i][j];
            }

            else if (i == 4){
                linha4 = linha4 + matriz [i][j];
            }

            // soma das colunas

            if (j == 1){
                col1 = col1 + matriz [i][j];
            }

            else if (j == 2){
                col2 = col2 + matriz [i][j];
            }
             else if (j == 3){
                col3 = col3 + matriz [i][j];
            }

            else if (j == 4){
                col4 = col4 + matriz [i][j];
            }

            // soma das colunas por vetor

            if (j == 1){
                 colum[j] = col1;
            }
            else if (j == 2){
                 colum[j] = col2;
            }

            else if (j == 3){
                 colum[j] = col3;
            }

            else if (j == 4){
                 colum[j] = col4;
            }


        }


            if (i == 1){
                linha[i] = linha1;
            }

            else if (i == 2){
                linha[i] = linha2;
            }
             else if (i == 3){
                linha[i] = linha3;
            }

            else if ( i == 4){
                linha[i] = linha4;
            }



        printf("\n\n\n");
    }


    printf("\t\t\tSoma das linhas\n\n\n");



  for (i = 1; i <=4; i++){

        printf("Soma da linha %d:", i);
        printf("\n%d\n", linha[i]);
    }

    printf("\n\n\t\t\tSoma das colunas\n");

    for (i = 1; i <=4; i++){

        printf("Soma da coluna %d: ", i);
        printf("\n%d\n", colum[i]);

    }




    printf("\n\n\n");
    system("pause");

return 0;
}
