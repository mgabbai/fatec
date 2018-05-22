#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

typedef struct no

{
    int codigo;
    char nome[10];
    struct no *next;
}no;

struct no *auxiliar, *corrente, *inicio, *auxiliar2;


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
    auxiliar = corrente;
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
        printf("Registro não encontrado!\n\n\n");
    }

    }
    system("pause");
    system("cls");
}

int Remover (no*Lista){
//free(ponteiro) - remove da lista
//Para remover é necessário verificar aonde é a remoção EX:
//BLOCO1 - BLOCO2 - BLOCO3 - BLOCO4 - BLOCO5 - BLOCO6
//se BLOCO1 é necessário recuperar o ponteiro inicio e apontar para o proximo endereço que será o novo inicio
//se BLOBO3 é necessário fazer com que o BLOCO2 aponte para o BLOCO4, assim voce consegue remover o BLOCO3
//se BLOCO6 é necessario recuperar o ponteiro 'corrente' que estava no fim, apontar para o anterior e remover o ultimo BLOCO


    if (inicio == NULL)
    {
        printf("Lista Vazia!!!\n\n\n");

    }else{

    printf("\n\nDigite o codigo que deseja remover: ");
    scanf("%d", &xcod);

    auxiliar = inicio;
    corrente = inicio;

    achou = 0;


// I Etapa - Se o primeiro da lista for quem deseja remover

    if (auxiliar->codigo == xcod)
    {
        printf("Registro removido com Sucesso!\n\n\n");
        inicio = inicio->next;
        free(auxiliar);
        achou = 1;
    }
// II Etapa - Se o elemento é do meio da lista
// III Etapa - Se o ultimo elemento é quem deseja remover
    else
    {
        while (corrente->next != NULL)
        {
            corrente = corrente->next;
            if (corrente->codigo == xcod)
            {
                printf("Registro removido com Sucesso!\n\n\n");
                auxiliar->next = corrente->next;
                free(corrente);
                achou = 1;
                break;

            }
            auxiliar = auxiliar->next;
        }

    }

    if (achou == 0)
    {
            printf("Registro não encontrado!\n\n\n");
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

    printf("Bem vindo ao programa da aula do TONI\n\n\nVamos Começar?");


    while (op != 0){

        printf("\t\t\tPROGRAMA AULA DO TONI\n\n1.Incluir\n2.Exibir\n3.Pesquisa\n4.Remoção\n0.Sair\n\n\nDigite a opção desejada: ");
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
