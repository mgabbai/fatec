#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int contador = 0;
int MAX = 30;
int cod = 0;
char anim[30];
char oper[30];
char notacao[30];
char notPolonesa[30];


typedef struct no {
    char operadores;
    struct no  *next, *back;
}no;
struct no *auxiliar = NULL, *topo = NULL;

void Push(){

        printf("Notação: ");
        fflush(stdin);
        gets(notacao);

        int i = 0;
        int j = 0;
        int p = 0;
        int o = 0;
        while (i < strlen(notacao)){
            if (notacao[i] != '(' && notacao[i] != '-' && notacao[i] != '+' && notacao[i] != '*' && notacao[i] != '/' && notacao[i] != ')')
            {
                notPolonesa[p] = notacao[i];
                p++;
            }
            else
            {   if (notacao[i] == '-' || notacao[i] == '*' || notacao[i] == '/' || notacao[i] == '+'){
                    if (IsEmpty() == 'v'){
                        topo = (no*)malloc(sizeof(no));
                        topo->next = NULL;
                        topo->back = NULL;
                        auxiliar = topo;
                        topo->operadores = notacao[i];
                        contador++;
                        j++;
                    }
                        else{
                            if(IsFull() == 'f'){
                                printf("Stack Overflow!\n\n");
                            }
                            else{
                                topo = (no*)malloc(sizeof(no));
                                auxiliar->next = topo;
                                topo->back = auxiliar;
                                topo->next = NULL;
                                auxiliar = topo;
                                topo->operadores = notacao[i];
                                contador++;
                                cod++;
                                }
                        }
                }
                else
                {
                    if (notacao[i] == ')'){
                            if (IsEmpty() == 'v')//vazio
                            {
                                printf("Pilha Vazia!!!");
                            }
                            else{
                                auxiliar = topo->back;
                                notPolonesa[p] = topo->operadores;
                                o++;
                                p++;
                                free(topo);
                                topo = auxiliar;
                                contador--;
                            }
                    }
                }
            }
          i++;
        }
        int auxiliar = contador;
    for(i=0; i < auxiliar;i++){
        if (IsEmpty() == 'v')//vazio
        {
          printf("Pilha Vazia!!!");
        }
        else{
            auxiliar = topo->back;
            notPolonesa[p] = topo->operadores;
            o++;
            p++;
            free(topo);
            topo = auxiliar;
            contador--;
        }


    }
    printf("\n\n");
        printf("A notação polonesa do valor digitado é: %s\n\n\n\n", notPolonesa);
        system("pause");
        system("cls");
}

int IsEmpty(){
    if (topo == NULL){
        return 'v';
    }
    else {
        return 0;
    }

}
int IsFull(){
    if (contador >= MAX){
        return 'f';
    }
    else{
        return 0;
    }

}

int main (){
    setlocale(LC_ALL, "");
    printf("\t\t\t\tBEM VINDO A PILHA\n\n\n");

    int opcao;
    while (opcao != 0){
        printf("1. Inserir notação(PUSH)\n0. Sair\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao == 1 || opcao == 0){

            switch(opcao)
            {
            case 1 :
                system("cls");
                Push();
                break;

            }
        }else{
            system("cls");
            printf("\t\t\tVALOR INCORRETO!\n\n\n");
            system("pause");
            system("cls");
        }
    }

return 0;
}
