#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#define PI 3.14159265

int main (){
    setlocale(LC_ALL, "Portuguese");

    printf("-----------------------------------------------------------\n");
    printf(" NR\tQUADRADO\tCUBO\t COS\t  SEN\t    TAN\n");
    printf("-----------------------------------------------------------\n");

    int i, quadrado, cubo;
    double c, v;
    c = 0;


    for (i = 1; i <= 60; i++){
        printf(" %d", i);



        quadrado = c * c;
        cubo = c * c * c;

        v = PI /180;

        printf("\t%d\t\t%d\t %.4lf\t  %.4lf    %.4lf\n", quadrado, cubo, cos(c*v), sin(c*v), tan(c*v));

        if (i % 10 == 0){
            system("pause");
            system("cls");

            printf("-----------------------------------------------------------\n");
            printf(" NR\tQUADRADO\tCUBO\t COS\t  SEN\t    TAN\n");
            printf("-----------------------------------------------------------\n");


        }

        c++;

    }

return 0;
}
