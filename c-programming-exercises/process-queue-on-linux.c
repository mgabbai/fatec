#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (){

	int pid = 999, altera, remove, cr = 0, cr2, vazio = 0, somasiclo = 0, loop = 0, acrescenta = 0;
	int ppid[20], siclo[20], op = 10, i, j, encerrando[100],  l = 0;
	char nome[20][8], c[10], limpa[20][7] ={{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '},
						{' ',' ',' ', ' ', ' ', ' ', ' '}};
	int contagem = 0;


	while (op>0){

		system("clear");
		printf("\t\t\tFila de Prontos\n\n***OBS: Para sair de qualquer opcao indesejada, digite 0***");
		printf("\n\n1. Criar Processo\n2. Alterar Processo\n3. Remover Processo\n4. Listar Tabela\n5. Limpar tabela de processos\n6. Escalonar\n7. Creditos\n0. Sair\n\nDigite a opção desejada: ");
		scanf("%d", &op);


		switch(op){
			case 1 :
				if (acrescenta < 7){

					system("clear");
					ppid[contagem] = pid + 1;
					printf("Digite o nome do processo: ");
					scanf(" %s",&nome[contagem]);
					printf("Digite quantos siclos ele tera: ");
					scanf("%d",&siclo[contagem]);
					contagem = contagem + 1;
					pid = pid + 1;
					acrescenta++;

				}else{

					system("clear");
					printf("Fila esta cheia!!!");
					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");

				}


				system("clear");
				break;

			case 2 :

				system("clear");

				if(pid == 999){

					printf("Crie um processo primeiro!!!");

					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");
					system("clear");
					break;

				}

				printf("Qual processo voce deseja alterar?\n\nPID\t\tNOME\t\tSICLOS\n");

				for (i = 0; i < contagem; i++){
					if(ppid[i] == 0){

				}
				else{
					printf("%d\t\t%s\t\t%d\n", ppid[i], nome[i], siclo[i]);
				}
				}

				printf("\nDigite o PID do processo a ser alterado: ");
				scanf("%d", &altera);

				for (i = 0; i < contagem; i++){
					if (ppid[i] == altera){
						printf("Digite o novo nome do processo: ");
						scanf(" %s",&nome[i]);
						printf("Digite o novo siclo: ");
						scanf("%d", &siclo[i]);
					}
				}


				printf("\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				altera = 0;
				break;

			case 3 :

				system("clear");

				if(pid == 999){

					printf("Crie um processo primeiro!!!");

					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");
					system("clear");
					break;

				}

				printf("Qual processo voce deseja remover?\n\nPID\t\tNOME\t\tSICLOS\n");
				for (i = 0; i < contagem; i++){

				if(ppid[i] == 0){

				}
					else{
					printf("%d\t\t%s\t\t%d\n", ppid[i], nome[i], siclo[i]);
					}

				}

					//cr = remove;
					printf("\nDigite o PID do processo a ser removido: ");
					scanf("%d", &remove);
				for (i = 0; i < contagem; i++){

					if(ppid[i] == remove){
						/*if (contagem<6){
							j = i + 1;
							ppid[i] = ppid[j];
							siclo[i] = siclo [j];
							int l;
							l = i + 1;
							for(j=0;j<7;j++){
								nome[i][j] = nome[l][j];
							}
						}*/ //else {if(contagem == 6){
						 	ppid[i] = vazio;
							nome[i][i] = limpa[i][i];
							siclo[i] = vazio;
							//}
						 // }
						acrescenta--;
					}


				}

					if (remove == 0){
						remove = cr;
					}



				printf("\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				break;

			case 4 :
				system("clear");

				if(pid == 999){

					printf("Crie um processo primeiro!!!");

					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");
					system("clear");
					break;

				}

				printf("PID\t\tNOME\t\tSICLOS\n");
				for (i = 0; i < contagem; i++){

					if(ppid[i] == 0){

					}
					else{
					printf("%d\t\t%s\t\t%d\n", ppid[i], nome[i], siclo[i]);
					}

				}

				printf("\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				break;

			case 5 :
				if(pid == 999){
					system("clear");
					printf("Crie um processo primeiro!!!");

					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");
					system("clear");
					break;

				}
				for (i = 0; i < 20; i++){
					ppid[i] = vazio;
					nome[i][i] = limpa[i][i];
					siclo[i] = vazio;

				}
				pid = 999;
				contagem = 0;
				acrescenta = 0;
				system("clear");
				printf("Tabela Limpa\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				break;

			case 6 :

				system("clear");

				if(pid == 999){

					printf("Crie um processo primeiro!!!");

					printf("\n\n");
					system("read -p \"Pressione ENTER para continuar\" saindo");
					system("clear");
					break;

				}

				printf("\t\t\tEscalonando\n\n");

				for(i = 0; i < contagem; i++){
					if (i == 0){
					somasiclo = siclo[i];
					}else {
						if(siclo[i] > somasiclo){
							somasiclo = siclo[i];
						}
					}
				}

				for(i = 0; i <= somasiclo;i++){

					for(j=0;j < contagem; j++){
						if (ppid == 0){

						}
						else{
							if(siclo[j] > 0){
								printf("\n%d\n",ppid[j]);
								sleep(3);
								siclo[j] = siclo[j] - 1;

							}
							  else {


						 	if(ppid[j] == 0){
						 	}
						 	else{

						 		encerrando[l] = ppid[j];
						 		l++;
								ppid[j] = vazio;

							}
							 }
						}
					}

				}
				system("clear");
				printf("\n\nA ordem de encerramento do programa é: ");

				printf("\n\n");

				for(i=0;i<30;i++){
					if(encerrando[i] > 0){
						if(encerrando[i] >= 1000 && encerrando[i] <= 1022){
							printf("%d \n", encerrando[i]);
						}
					}
					else{

					}
				}

j = 0;
				while(j < 1){



			for (i = 0; i < 20; i++){
					ppid[i] = vazio;
					nome[i][i] = limpa[i][i];
					siclo[i] = vazio;

				}
				pid = 999;
				contagem = 0;
				acrescenta = 0;
				printf("\n***OBS: Apos o escalonamento sua fila de processos foi limpa***");
				printf("\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				j++;
				}

				break;


			case 7 :

				system("clear");
				printf("\t\t\tCREDITOS\n\nThailis\tRA: 0040481611044\nPedro\tRA: 0040481611001\nMarcio\tRA: 0040481611046\n\n");
				system("read -p \"Pressione ENTER para continuar\" saindo");
				break;

		}
	}

return 0;
}

