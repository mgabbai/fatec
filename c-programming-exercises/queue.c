#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


typedef struct no{
    int codigo;
    char nome[30];
    struct no *next, *back;
}no;

struct no *auxiliar = NULL, *fim = NULL, *inicio = NULL;

int cont = 0;

void EnterData(){
    printf("Entre com o codigo: ");
    scanf("%d", &fim->codigo);
    printf("Entre com o nome: ");
    scanf(" %s", &fim->nome);
}

void Enqueue(){
    if (cont < 5){
        if (inicio == NULL){
            fim = (no*)malloc(sizeof(no));
            auxiliar = fim;
            fim->next = NULL;
            inicio = fim;
            EnterData();
            cont++;
        }
        else{
            auxiliar = inicio;
            fim = inicio;
            while(fim->next != NULL){
                fim = fim->next;
                auxiliar = auxiliar->next;
            }
            fim = (no*)malloc(sizeof(no));
            auxiliar->next = fim;
            auxiliar = fim;
            fim->next = NULL;
            EnterData();
            cont++;
        }
    }
    else{
        printf("Fila está cheia... aguarde até que um elemento seja removido e tente novamente!");
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

void Deque(){
    if (inicio == NULL){
        printf("Queue Underflow...");
    }
    else{
        if(inicio->next == NULL){
            free(inicio);
            inicio = NULL;
            fim = NULL;
            printf("Removido o ultimo elemento da Fila");
            cont--;
        }
        else{
            auxiliar = inicio;
            inicio = inicio->next;
            free(auxiliar);
            printf("Removido elemento da fila");
            cont--;
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

void SeaQueue (){
    if (inicio == NULL){
        printf("Não há processos!");
    }
    else{
        printf("Digite o codigo que deseja encontrar: ");
        int codigo, posicao = 0, num_posicao = 1;
        char nome_posicao[30];
        scanf("%d", &codigo);
        auxiliar = inicio;
        while (auxiliar != NULL){
            if (auxiliar->codigo == codigo){
                posicao = num_posicao;
                strcpy(nome_posicao, auxiliar->nome);
            }else{
                num_posicao++;
            }
            auxiliar = auxiliar->next;
        }
        if (posicao == 0){
            printf("Codigo não encontrado!");
        }
        if (posicao > 0){
            printf("A posição do codigo %d é: %d-%s", codigo,posicao, nome_posicao);
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

void ExibeQueue(){
    if (inicio == NULL){
        printf("Não há elementos na lista!");
    }
    else{
        auxiliar = inicio;
        while (auxiliar != NULL){
            printf("%d - %s\n", auxiliar->codigo, auxiliar->nome);
            auxiliar = auxiliar->next;
        }
    }
    printf("\n\n\n");
    system("pause");
    system("cls");
}

int main (){
    setlocale(LC_ALL, "Portuguese");
    printf("\t\t\tBem vindo a Fila no INSS\n\n\n");
    int op;
    while (op != 0){
        printf("\t\t\tFila do INSS\n\n1. Enqueue (inserção)\n2. Deque (remover)\n3. SeaQueue (posição)\n4. Exibir fila\n0. Sair\n\nDigite a opção desejada: ");
        scanf("%d", &op);
        switch (op){
        case 1:
            system("cls");
            Enqueue();
            break;
        case 2:
            system("cls");
            Deque();
            break;
        case 3:
            system("cls");
            SeaQueue();
            break;
        case 4:
            system("cls");
            ExibeQueue();
            break;
        }


    }

return 0;
}
