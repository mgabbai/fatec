#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

/*

    SEMANTICA
    auxiliar->next = corrente;
    corrente->back = auxiliar;
    corrent->next = NULL;

*/

typedef struct no

{
    int codigo;
    char nome[10];
    struct no *next, *back;
}no;

struct no *auxiliar, *corrente, *inicio, *auxiliar2, *fim;


int achou = 0;

int xcod = 0;


void EnterData()
{

printf("Entre com o codigo: ");
scanf("%d", &corrente->codigo);
printf("Entre com o nome: ");
scanf(" %s", &corrente->nome);

}

int insere (no*Lista)
{

    if (inicio == NULL){

        corrente = (no*)malloc(sizeof(no));
        auxiliar = corrente;
        inicio = corrente;
        corrente->next = NULL;
        corrente->back = NULL;
        EnterData();

    }
    else{
    corrente = inicio;
    auxiliar = inicio;
    while (corrente->next != NULL){
        corrente = corrente->next;
        auxiliar = auxiliar->next;
    }

        corrente = (no*)malloc(sizeof(no));
        auxiliar->next = corrente;
        corrente->next = NULL;
        corrente->back = auxiliar;
        auxiliar = corrente;
        fim = corrente;
        EnterData();

    }
        system("cls");
}

int Mostra (no*Lista)
{


    if (inicio == NULL){
        printf("Lista Vazia!!!\n\n");
    }
   auxiliar = inicio;
   corrente = inicio;

    while (auxiliar != NULL){

            printf("%d - ", auxiliar->codigo);
            printf(" %s\n", auxiliar->nome);

            auxiliar = auxiliar->next;


    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

int Encontrar(no*Lista){

    if (inicio == NULL)
    {
        printf("Lista Vazia!!!\n\n\n");

    }

    else
    {
    system("cls");
    achou = 0;
    xcod = 0;
    auxiliar = inicio;

    printf("\n\nDigite o codigo que deseja encontrar registros: ");
    scanf("%d", &xcod);
    system("cls");
    while (auxiliar != NULL){
        if (auxiliar->codigo == xcod)
        {
            printf("Codigo: %d - Nome: %s\n\n\n", auxiliar->codigo, auxiliar->nome);
            achou = 1;
            break;

        }
        else
        {

        }
        auxiliar = auxiliar->next;

    }

    if (achou == 0)
    {
        printf("Registro n�o encontrado!\n\n\n");
    }

    }
    system("pause");
    system("cls");
}

int Remover (no*Lista){
//free(ponteiro) - remove da lista
//Para remover � necess�rio verificar aonde � a remo��o EX:
//BLOCO1 - BLOCO2 - BLOCO3 - BLOCO4 - BLOCO5 - BLOCO6
//se BLOCO1 � necess�rio recuperar o ponteiro inicio e apontar para o proximo endere�o que ser� o novo inicio
//se BLOBO3 � necess�rio fazer com que o BLOCO2 aponte para o BLOCO4, assim voce consegue remover o BLOCO3
//se BLOCO6 � necessario recuperar o ponteiro 'corrente' que estava no fim, apontar para o anterior e remover o ultimo BLOCO


    if (inicio == NULL)
    {
        printf("Lista Vazia!!!\n\n\n");

    }else{

    printf("\n\nDigite o codigo que deseja remover: ");
    scanf("%d", &xcod);
    system("cls");
    auxiliar = inicio;
    corrente = inicio;

    achou = 0;


// I Etapa - Se o primeiro da lista for quem deseja remover

    if (auxiliar->codigo == xcod)
    {
        printf("Registro removido com Sucesso!\n\n\n");
        inicio = inicio->next;
        inicio->back = NULL;
        free(auxiliar);
        achou = 1;
    }
// II Etapa - Se o elemento � do meio da lista
// III Etapa - Se o ultimo elemento � quem deseja remover
    else
    {
        corrente = auxiliar->next;
        while (corrente->next != NULL)
        {

            if (corrente->codigo == xcod)
            {
                corrente = corrente->next;
                corrente->back = auxiliar;
                corrente = auxiliar->next;
                auxiliar->next = corrente->next;
                printf("Registro removido do meio da lista!\n\n\n");
                free(corrente);
                achou = 1;
                printf("o fim � %d", fim->codigo);
                break;

            } else
            {
                auxiliar = auxiliar->next;
                corrente = corrente->next;
            }

        }

    }

    if (achou == 0 && corrente->codigo == xcod)
    {
        fim = fim->back;
        auxiliar->next = NULL;
        achou = 1;
        free(corrente);
        printf("Registro removido no fim da Lista!\n\n\n");
        fim->next = NULL;

    }

    if (achou == 0)
    {
            printf("Registro n�o encontrado!\n\n\n");
    }

}
    system("pause");
    system("cls");
}

int class (no*Lista){

    corrente = (no*)malloc(sizeof(no));
    EnterData();
    auxiliar=inicio;
    achou=0;

    if(inicio == NULL)
    {
        printf("\n\nPrimeiro elemento na lista!\n\n");
        auxiliar = corrente;
        inicio = corrente;
        corrente->next=NULL;
    }
    else
    {
        if(corrente->codigo < auxiliar->codigo)
        {
            printf("\n\nClassificado no inicio da lista!\n\n");
            corrente->next=auxiliar;
            inicio=corrente;
            achou = 1;
        }
        else
        {
            auxiliar2=auxiliar->next;

            while(auxiliar2 != NULL)
            {
                if(auxiliar->codigo < corrente->codigo && auxiliar2->codigo > corrente->codigo)
                {
                    achou = 1;
                    auxiliar->next = corrente;
                    corrente->next = auxiliar2;

                    printf("\n\nClassificado no meio da Lista!\n\n");
                    break;
                }
                else
                {
                    auxiliar=auxiliar->next;
                    auxiliar2=auxiliar2->next;
                }
            }
        }

    }
    if (achou == 0)
    {
        if(corrente->codigo > auxiliar->codigo)
        {
            auxiliar->next = corrente;
            corrente->next = NULL;
            printf("\n\nClassificado no fim da Lista!\n\n");
        }
    }
    system("pause");
    system("cls");
}


int main (){

setlocale(LC_ALL, "Portuguese");

    inicio = NULL;
    auxiliar = NULL;
    corrente = NULL;
    int op;
    char opcao;

    printf("Bem vindo ao programa da aula do TONI\n\n\nVamos Come�ar?");


    while (op != 0){

        printf("\t\t\tPROGRAMA AULA DO TONI\n\n1.Incluir\n2.Exibir\n3.Pesquisa\n4.Remo��o\n0.Sair\n\n\nDigite a op��o desejada: ");
        scanf("%d", &op);

        switch(op){

            case 1 :
                system("cls");
                insere(inicio);
            break;
            case 2 :
                system("cls");
                Mostra(inicio);
            break;
            case 3 :
                system("cls");
                Encontrar(inicio);
            break;
            case 4 :
                system("cls");
                Remover(inicio);
            break;
        }


    }


return 0;
}
