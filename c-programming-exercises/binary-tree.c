#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>


typedef struct tree{
    int codigo;
    char nome[30];
    struct tree *next, *back, *down;
}tree;

struct tree *corrente, *auxiliar, *raiz;

void EnterData(){
    printf("Digite o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("Digite o nome: ");
    scanf(" %s", &corrente->nome);
}

void aloca_abaixo(){
    while (auxiliar->down != NULL){
        auxiliar = auxiliar->down;
    }
    corrente->next = NULL;
    corrente->back = NULL;
    corrente->down = NULL;
    auxiliar->down = corrente;
}
void aloca_direita(){
    while (auxiliar->next != NULL){
        auxiliar = auxiliar->next;
    }
    corrente->next = NULL;
    corrente->back = NULL;
    corrente->down = NULL;
    auxiliar->next = corrente;
}
void aloca_esquerda(){
    while (auxiliar->back != NULL){
        auxiliar = auxiliar->back;
    }
    corrente->next = NULL;
    corrente->back = NULL;
    corrente->down = NULL;
    auxiliar->back = corrente;
}

void Inserir(){
    char resp;
    int op;

    do{
        corrente = (tree*)malloc(sizeof(tree));
        corrente->next = NULL;
        corrente->back = NULL;
        corrente->down = NULL;
        auxiliar = raiz;
        EnterData();

        if (raiz == NULL){
            raiz = corrente;
            auxiliar = corrente;
        }
        else{
            printf("\n\nInforme o caminho a ser alocado\n\n1. A direita\n2. A esquerda\n3. Abaixo\n\nDigite a opção escolhida: ");
            scanf("%d", &op);

            switch(op){
                case 1:
                    aloca_direita();
                    break;
                case 2:
                    aloca_esquerda();
                    break;
                case 3:
                    aloca_abaixo();
                    break;
            }
        }

        system("cls");

        printf("Deseja continuar a inserir outro lado? (s/n): ");
        scanf(" %c", &resp);
        resp = toupper(resp);

        system ("cls");
    } while (resp != 'N');

}

void Pesquisa(){
    int show = 0;
    char pesquisar[20];
    printf("Digite o nome a ser procurado: ");
    scanf(" %s", &pesquisar);

    if (raiz == NULL){
        printf("Arvore vazia...");
    }
    else{
        if (strcmp(pesquisar, raiz->nome) == 0){
            show = 1;
        }
        auxiliar = raiz;
        auxiliar = auxiliar->next;
            while(auxiliar != NULL){
                if (strcmp(pesquisar, auxiliar->nome) == 0){
                    show = 1;
                }
                auxiliar = auxiliar->next;
            }

        auxiliar = raiz;
        auxiliar = auxiliar->back;

        while(auxiliar != NULL){
                if (strcmp(pesquisar, auxiliar->nome) == 0){
                    show = 1;
                }
                auxiliar = auxiliar->back;
        }

        auxiliar = raiz;
        auxiliar = auxiliar->down;

        while(auxiliar != NULL){
                if (strcmp(pesquisar, auxiliar->nome) == 0){
                    show = 1;
                }
                auxiliar = auxiliar->down;
        }

        if (show == 1){
            printf("Registro encontrado...");
        }
        else{
            printf("Registro não encontrado...");
        }


    }

    printf("\n\n\n");
    system("pause");
    system("cls");


}

void Exibir(){

    if (raiz == NULL){
        printf("Arvore vazia...");
    }
    else{
        auxiliar = raiz;
            while(auxiliar != NULL){
                printf("%s", auxiliar->nome);
                auxiliar = auxiliar->next;
            }

        auxiliar = raiz;
        auxiliar = auxiliar->back;

        while(auxiliar != NULL){
                printf("%s", auxiliar->nome);
                auxiliar = auxiliar->back;
            }


        auxiliar = raiz;
        auxiliar = auxiliar->down;

        while(auxiliar != NULL){
                printf("%s", auxiliar->nome);
                auxiliar = auxiliar->down;
            }

    }

    printf("\n\n\n");
    system("pause");
    system("cls");


}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    printf("\t\t\tBEM VINDO!!\n\n\n");

    while(op != 0){
        printf("1. Inserir\n2. Pesquisar\n3. Exibir\n\nDigite a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                system("cls");
                Inserir();
                break;
            case 2:
                system("cls");
                Pesquisa();
                break;
            case 3:
                system("cls");
                Exibir();
                break;
        }
    }



}
