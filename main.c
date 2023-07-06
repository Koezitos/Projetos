#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#define SIZE 200

char nome [SIZE] [50], rua [SIZE] [50], email [SIZE] [50], comorb[SIZE] [50], diag[SIZE] [50], bairro[SIZE][50];
char cidade[SIZE][50], estado[SIZE][50], cep[SIZE][50], mes[SIZE][50], tel[SIZE][50], cpf[SIZE][50];
int dia[SIZE], ano[SIZE], anotu=2022, op, idade[SIZE], numcasa[SIZE], opc;
void cadastro();
void gravar();
void teste_idade();


int main(void){
    char usuario [15];
    char usuario1 [15] = "unip";
    char senha [15];
    char senha1 [15] = "unip";
    int login_teste = 0;
    setlocale(LC_ALL, "Portuguese");


    printf("\t|----------------------------------------|");
    printf("\n\t|\t\t\t\t\t |");
    printf("\n\t|\t***SEJA BEM VINDO(A)*** \t |");
    printf("\n\t|\t***CADASTRO DE PACIENTES***\t |\n");
    printf("\t|\t\t\t\t\t |");
    printf("\n\t|----------------------------------------|");

    while(!login_teste){
        printf("\n\nDigite o Login: ");
        scanf("%s", usuario);

        printf("\n\nDigite a Senha: ");
        scanf("%s", senha);

        if (strcmp(usuario, usuario1) == 0 && strcmp(senha, senha1) == 0){
            printf("\n\nLOGADO!\n\n");
            login_teste = 1;
        }
        else
            printf("\n\nDADOS INVALIDOS!\n\n");
    }

    if(login_teste==1){

    do{
        system("cls");
        printf("Escolha uma opção\n\t\t");
        printf("\n1 - Cadastrar \n2 - Sair\n");
        scanf("%d", &op);
        switch(op){

    case 1:
        system("cls");
        cadastro();
        gravar();
        teste_idade();
        break;


    case 2:
        printf("Encerrando...");
        system("exit");
        break;

    default:
        printf("Opção Inválida!!!!");
        break;

        }
    }while(op<2);

}
}

void gravar(){
    int i;
    FILE *pont_arq;

  pont_arq = fopen ("Pacientes Covid19.txt", "w");

    for(i=0;i<SIZE;i++){
            if(numcasa[i]!=0){
    fprintf(pont_arq, "\nNome:%sCPF:%s\nTelefone:%s\nE-mail:%s\nData de Nascimento:%d/%s/%d\n", nome[i], cpf[i], tel[i], email[i], dia[i],mes[i],ano[i]);
    fprintf(pont_arq, "Rua:%sNúmero da casa:%d\nBairro:%sCidade:%sEstado:%sCEP:%s\nData do diagnóstico:%s\n", rua[i], numcasa[i], bairro[i], cidade[i], estado[i], cep[i], diag[i]);

            }else{
            break;}
    }  printf("Paciente(s) Cadastrado(s) com sucesso!!");
    fclose(pont_arq);
}

void cadastro(){
   static int linha;

   do{
    printf("Nome:");
    gets(nome[linha]);
    fgets (nome[linha], SIZE, stdin);
    printf("\nCPF:");
    scanf("%s", &cpf[linha]);
    printf("\nTelefone:");
    scanf("%s", &tel[linha]);
    printf("\nRua:");
    gets(rua[linha]);
    fgets (rua[linha], SIZE, stdin);
    printf("\nNúmero da Casa:");
    scanf("%d", &numcasa[linha]);
    printf("\nBairro:");
    gets(bairro[linha]);
    fgets (bairro[linha], SIZE, stdin);
    printf("\nCidade:");
    fgets (cidade[linha], SIZE, stdin);
    printf("\nEstado:");
    fgets (estado[linha], SIZE, stdin);
    printf("\nCEP:");
    scanf("%s", &cep[linha]);
    printf("\nDia de nascimento:");
    scanf("%d", &dia [linha]);
    printf("\nMês de nascimento:");
    scanf("%s", &mes [linha]);
    printf("\nAno de nascimento:");
    scanf("%d", &ano[linha]);
    printf("\nE-mail:");
    scanf("%s", &email[linha]);
    printf("\nData do diagnóstico:");
    scanf("%s", &diag[linha]);
    printf("\nDigite 1 para continuar ou outro valor para sair");
    scanf("\n%d", &op);
    system("cls");
    linha++;
   } while(op==1);

}


void teste_idade(){

int i;

do{

idade[i]=anotu-ano[i];
if(idade>65){
printf("\n\nPossui comorbidade (1 - sim 2 - não):");
        scanf("%d", &opc);
}
        if(idade>65 && opc==1){
      printf("\nComorbidade:");
      scanf("%s",comorb[i]);
    FILE *arq_teste;

  arq_teste = fopen ("Grupo de Risco.txt", "w");

    for(i=0;i<SIZE;i++){
            if(idade[i]!=0){
    fprintf(arq_teste, "CEP:%s\nIdade:%d\nComorbidade:%s", cep[i], idade[i], comorb[i]);
            }
    }
    fclose(arq_teste);
    }else{
    break;}

}while(idade[i]>65);
}









