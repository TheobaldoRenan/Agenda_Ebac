#include <stdio.h>       //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>	     //biblioteca de aloca��o de mem�ria.Criar banco de dados na maquina
#include <locale.h>	     //biblioteca de aloca��es de texto por regi�o.
#include <string.h>		 //biblioteca de administra��o de strings

int
 registro()																		// Fun��o de Registrar Nomes
{
	char arquivo[40];														//inicio de cria��o de variaveis tipo string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];															//final de cria��o de variaveis tipo string
	
	printf("Digite o CPF a ser cadastrado: \n");							// coletar informa��o do usuario 
	printf("CPF: ");	
	scanf("%s", cpf);														//%s refere-se a strings
	
	strcpy(arquivo,cpf);													//copia o valor da string
	
	FILE *file;																//criando o banco de dados
	file = fopen(arquivo, "w");												// cria o arquivo e o "W" significa escrever
	fprintf(file,cpf);														// salvando valor da variavel
	fclose(file);															// fechando o arquivo
	
	file = fopen(arquivo, "a");												//atualizando o arquivo e o "A" significa atualizar 
	fprintf(file, ",");														//colocando um virgula entre os arquivo
	fclose(file);															//fechando o arquivo
	
	printf(" \n Digite o NOME a ser cadastrado:\n" );					    	//solicitando o nome para cadastro
	printf("Nome: ");
	scanf("%s",nome);														//lendo o nome e salvando a variavel nome
	
	file = fopen(arquivo, "a");												//abrindo o arquivo para atualizar
	fprintf(file,nome);														//escrevendo a variavel nome no arquivo
	fclose(file);															// fechando o arquivo
	
	file = fopen(arquivo, "a");												//atualizando o arquivo
	fprintf(file, ",");														//colocando um virgula entre os arquivo
	fclose(file);
	
	printf("\n Digite o SOBRENOME a ser cadastrado:\n");					    //solicitando o sobrenome para cadastro 
	printf(" Sobrenome: ");
	scanf("%s",sobrenome);													//lendo o nome e salvando a variavel nome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");												//atualizando o arquivo
	fprintf(file, ",");														//colocando um virgula entre os arquivo
	fclose(file);
	
	printf("\n Digite o CARGO a ser cadastrado:\n");
	printf("Cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}


int consulta()																	//fun��o de Consultar Nomes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("\n\n Digite o CPF a ser consultado:");								//recebendo o usuario a ser consultado
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");														//lendo o arquivo
	
	if(file == NULL)															//verificando se o CPF existe
	{
		printf("\n\n");
		printf("CPF N�O ENCONTRADO !!! \n\n\n");	
	}

	while(fgets(conteudo,200,file) != NULL)										//buscando ate 200 caracteres dentro do arquivo at� for nulo
	{
		printf("\n Informa��es do usu�rio selecionado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()																	//fun��o de Deletar Nomes
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: \n\n ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);	
	
	
	if (file == NULL)															// Se o cpf nao tiver cadastrado exibe mensagem
	{
		printf("\t\n\n Usuario n�o encontrado !! \n\n");
		system("pause");
	}

	remove(cpf);
	
	
	if (file != NULL)
	{
		printf("\t\n\n Usuario Deletado com Sucesso ! \n\n\n");						// caso encontrado mensagem de confirma��o de exclus�o
		system("pause");
	}
}



int main ()																		//Fun��o Principal - Tela de MENU
{
	int opcao=0;																	//Definindo as variaveis  do menu
	int loop=1;
	char getpassword[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\t\t_____  Cart�rio da EBAC  _____ \n\n");
	printf("LOGIN DE ADMIN !! \n\n Digite a senha: ");
	scanf("%s",getpassword);
	
	comparacao = strcmp(getpassword,"Admin");										//comparando 2 strings. verificando se a senha esta correta
	
	if (comparacao == 0)
	{
		
		for(loop=1;loop=1;)																//criando loop do programa
		{	
		
			system("cls");
		
			setlocale(LC_ALL, "Portuguese");											//Setando a lingua de saida para PORTUGUES
	
			printf("\t\t\t\t_____  Cart�rio da EBAC  _____ \n\n");						//Inicio Menu
			printf("Escolha a op��o desejada:\n\n");
			printf("\t 1 - Registrar Nomes.\n\n");
			printf("\t 2 - Consultar Nomes.\n\n");
			printf("\t 3 - Excluir Nomes.\n\n");
			printf("\t 4 - SAIR \n\n ");										
			printf("Op��o:");															//Final Menu
			scanf("%d", &opcao);														// Escolha do usuario
		
	
		
		
			system("cls");																// limpando a tela ap�s escolha do menu
	
				switch(opcao)															// inicio da sele��o do menu
				{
				case 1:
					registro();															//chamada de fun��o
				break;																	//final da fun��o caso seja 1
			
				case 2:
					consulta();															//chamada de fun��o
				break;																	//final da fun��o caso seja 2
			
				case 3:
					deletar();															//chamada de fun��o
				break;																	// final da fun��o caso seja 3
			
				case 4:
					printf(" \t\t OBRIGADO POR UTILIZAR O SISTEMA. \n\n\n\n");			//mensagem de saida do programa
					return 0;															//saindo do programa
				break;
				
										
				default:																//reorna valor padr�o caso nenhuma op�ao acima seja efetivada
					printf(" !!!    Op��o invalida    !!!  \n\n\n");					//comunicando falha na escolha de op��o
					system("pause");
				break;
	
				}
			}	
	}
		
		else
			system("cls");
			printf("\t\t\n\n!!!! SENHA INCORRETA !!!!\n\n\n\n");
	
}

