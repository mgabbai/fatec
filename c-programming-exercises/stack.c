#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int contador = 0;
int MAX = 5;
int cod = 0;
char anim[30];


typedef struct no {
    int codigo;
    char animal[30];
    struct no  *next, *back;
}no;
struct no *auxiliar = NULL, *topo = NULL;

void EnterData(){
    printf("%d - ", cod);
    fflush(stdin);
    gets(topo->animal);

    int i = 0;
    int substituiu = 0;
    while (i < strlen(topo->animal)){

        if (topo->animal[i] == ' '){
            topo->animal[i] = '_';
            substituiu = 1;
        }
        i++;
    }
    if (substituiu > 0){
        printf("\n\nNão é permitidos espaços, substituimos os espaços por '_' underscore\n");
    }
    topo->codigo = cod;


}

void Push(){
    if (IsEmpty() == 'v'){
        topo = (no*)malloc(sizeof(no));
        topo->next = NULL;
        topo->back = NULL;
        auxiliar = topo;
        contador++;
        EnterData();
        cod++;
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
            contador++;
            EnterData();
            cod++;
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");

}
void Pop(){
    if (IsEmpty() == 'v')//vazio
    {
        printf("Pilha Vazia!!!");
    }else{
        auxiliar = topo->back;
        free(topo);
        topo = auxiliar;
        contador--;
        printf("Registro removido com sucesso!");

    }

    printf("\n\n\n");
    system("pause");
    system("cls");

}
void Top(){
    if (IsEmpty() == 'v')//vazio
    {
        printf("Pilha Vazia!!!");
    }else{
        printf("O Topo da pilha e: %d - %s", topo->codigo, topo->animal);

    }

    printf("\n\n\n");
    system("pause");
    system("cls");

}

void Exibir(){

    if (IsEmpty() == 'v')//vazio
    {
        printf("Pilha Vazia!!!");
    }else{
        auxiliar = topo;
       while(auxiliar!= NULL){
            printf("%d - %s\n", auxiliar->codigo, auxiliar->animal);
            auxiliar = auxiliar->back;
       }
        auxiliar = topo;
    }

    printf("\n\n");
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
    printf("\t\t\t\tBEM VINDO A PILHA - CADASTRO DE ANIMAIS\n\n\n");

    int opcao;
    while (opcao != 0){
        printf("1. Inserir (PUSH)\n2. Remover (POP)\n3. Consultar o topo da lista (TOP)\n4. Exibir Pilha\n0. Sair\n\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 0){

            switch(opcao)
            {
            case 1 :
                system("cls");
                Push();
                break;
            case 2 :
                system("cls");
                Pop();
                break;
            case 3 :
                system("cls");
                Top();
                break;
            case 4 :
                system("cls");
                Exibir();
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
