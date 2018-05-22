

int main (){
    setlocale(LC_ALL, "Portuguese");

    printf("Digite o CPF a ser validado: ");

    char valor_cpf [13];

    gets(valor_cpf);

    int i, cpf[13];

    for (i = 0; i < 11 ;i++){
        cpf[i] = valor_cpf[i] - '0';

    }

    /*for (i = 0; i < 11; i++){
    printf("%d", cpf[i]);
    }*/

    int contador = 10, pesos[9], mult[9], soma = 0;

    for (i = 0; i < 9; i++){
        pesos[i] = contador;
        contador--;
    }

    for (i = 0; i <= 8; i++){
        mult[i] = cpf[i] * pesos[i];
    }

    for (i = 0; i <= 8; i++){
        soma = soma + mult[i];
    }

    int resultado = soma % 11;
    int resto = 11 - resultado;
    int dig, dig2;

    if (resto > 9){
        dig = 0;
        //printf("\n\n\n primeiro digito é %d", dig);
    }else {
        dig = resto;
       // printf("\n\n\n primeiro digito é %d", dig);
    }

    contador = 11;
    mult[9];
    pesos[9];
    soma = 0;

    for (i = 0; i < 9; i++){
        pesos[i] = contador;
        contador--;
    }
    for (i = 0; i < 9; i++){
        mult[i] = cpf[i] * pesos [i];
    }
    for (i = 0; i < 9; i++){
        soma = soma + mult[i];
    }

    soma = soma + (2 * dig);

    resultado = soma % 11;
    resto = 11 - resultado;

    if (resto > 9){
        dig2 = 0;
        //printf("\n\n\n segundo digito é %d", dig2);
    }
    else{
        dig2 = resto;
        //printf("\n\n\n segundo digito é %d", dig2);
    }


    i = 9;
    int j = 10;

    if (dig == cpf[i] && dig2 == cpf[j]){
        printf("\n\nCPF Válido!\n\n");
    }
    else {
        printf("\n\nCPF Inválido!\n\n");
    }

    system("pause");

return 0;
}
