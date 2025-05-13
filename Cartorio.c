#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Cria o arquivo e o w significa escrever
    fprintf(file,cpf); //Salva o valor da variavel
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a");  //Abre o arquivo
    fprintf(file,",");
    fclose(file); //Fecha o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Cadastrando o nome do usu�rio
    scanf("%s",nome); //Refere-se a string
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,nome); 
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,",");
    fclose(file); //Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");  //Cadastrando sobrenome do usu�rio
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,sobrenome);
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,",");
    fclose(file); //Fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");  //Cadastrando o cargo do usu�rio
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,cargo);
    fclose(file); //Fecha o arquivo
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //Abrir o arquivo (file)
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se o arquivo for nulo
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //Se o usu�rio n�o for encontrado no sistema
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	else
	{
		fclose(file);
		
		if (remove(cpf) == 0) //Tenta remover o arquivo correspondente ao CPF
		{
			printf("\nUsu�rio deletado com sucesso!\n\n");
			system("pause");
		}
		
		else
		{
			printf("\nErro ao deletar o usu�rio.\n\n");
			system("pause");
		}
	}
}



int main()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //Ele � o respons�vel por limpar a tela
	    
	    switch(opcao) //Inicio da sele��o
	    {
	    	case 1:
	    	registro(); //Chamada de fun��es
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		
		    default:
		    printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
		} //Fim da sele��o
	
    }
}
