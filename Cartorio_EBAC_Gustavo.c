#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro()//Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio de cria��o de vari�veis/strings
	char cpf[40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];
	//Final de cria��o de vari�veis
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	printf("Digite o CPF do usu�rio(a) a ser cadastrado(a): ");// Coletando informa��o do usu�rio
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //copiando as informa��es da string cpf na string arquivo

	FILE *file; //O programa deve buscar na biblioteca como criar um arquivo, 
	file = fopen(arquivo, "w"); //O programa ir� criar o arquivo e nomea-lo com as informa��es contidas na vari�vel "arquivo"
	
	//Copiando o cpf coletado para o banco de dados e organizando internamente o arquivo de texto
	fprintf(file,"CPF: "); 
	fprintf(file,cpf); 
	fprintf(file,"\n");
	fclose(file); 
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o nome do usu�rio, salvando no banco de dados e organizando internamente o arquivo de texto
	printf("Digite o nome do usu�rio(a): ");
	scanf("%s",nome); 
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fprintf(file," ");
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o sobrenome do usu�rio, salvando no banco de dados e organizando internamente o arquivo de texto	
	printf("Digite o sobrenome do usu�rio(a): ");
	scanf("%s",sobrenome);
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,"\n");
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o cargo do usu�rio, salvando no banco de dados e organizando internamente o arquivo de texto	
	printf("Digite o cargo do usu�rio(a):");
	scanf("%s",cargo);
	file = fopen(arquivo,"a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	

	system("cls"); // Apagando o menu e mudando de tela
	
	file = fopen(cpf,"r"); //Ler as informa��es coletadas
	
	// Mensagem de confirma��o de cadastro do usu�rio(a)
	printf("\n \t O(a) usu�rio(a) foi cadastrado(a) com sucesso. \n\n");
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s",conteudo);		
	}
	printf("\n\n"); //organiza��o da tela
	fclose(file);
	system("pause");
	
	
}//fim da vari�vel consulta

int consulta()//Fun��o respons�vel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//In�cio de cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//Final de cria��o de vari�veis
	
	//Coletando dados do usu�rio
	printf("Por favor, digite o CPF do usu�rio(a) a ser consultado: "); 
	scanf("%s",cpf); 
	printf("\n");
	//Final da coleta de dados do usu�rio
	
	FILE *file; //Busca na biblioteca opera��es com arquivos
	file = fopen(cpf,"r");//O programa ir� ler o arquivo cpf criado no banco de dados
	
	//Resposta caso os dados coletados n�o constem a nenhum usu�rio cadastrado
	if(file == NULL)
	{
		printf("\t O usu�rio(a) n�o est� cadastrado.\n");
	}
	//fim da resposta caso n�o encontre usu�rios cadastrados.
	
	//Resposta caso os dados coletados constem a algum usu�rio cadastrado
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s",conteudo);	
	}
	//Fim da resposta caso encontre usu�rio cadastrado

	printf("\n\n"); //organiza��o da tela do programa
	system("pause");
	
}//Fim da vari�vel registro


int deletar()//Fun��o respons�vel por deletar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//In�cio de cria��o de vari�veis/strings
	char cpf[40];
	int confirmar=0;
	char conteudo[200];
	//Fim da cria��o de vari�veis
	
	//In�cio da coleta de dados do usu�rio
	printf("Digite o CPF do usu�rio(a) a ser deletado(a): ");
	scanf("%s", cpf);
	//Fim da coleta de dados do usu�rio
	
	//O programa ir� buscar na biblioteca como gerenciar arquivos e ler (r) o que est� escrito no arquivo com o nome da coleta de dados
	FILE *file;
	file = fopen(cpf,"r"); 
	//fim de gerenciamento de arquivos

	system("cls"); //Organiza��o da tela do programa
	
	//Inicio da resposta caso o dado coletado n�o conste no sistema do banco de dados
	if (file == NULL)
	{
		printf("\tO(a) usu�rio(a) n�o est� cadastrado(a) no sistema.\n\n");
		system("pause");
	}
	//Fim da resposta caso dado coletado n�o conste no sistema
	
	//Inicio da resposta caso o dado coletado conste no sistema do banco de dados
	if (file != NULL)
	{
		//Inicio de coleta de dados e mensagens para o usu�rio
		printf("\nO(a) usu�rio(a) ");
		printf("%s",cpf);
		printf(" ser� deletado(a), deseja confimar esta opera��o? \n\n");
		printf("\tDigite 1 para confirmar\n");
		printf("\tDigite 2 para cancelar\n\n");
		printf("Digite a op��o desejada: ");
		scanf("%d",&confirmar);
		//Fim da coleta de dados
		
		system("cls"); // Organiza��o da tela do programa
		
		//Confirma��o de exclus�o do usu�rio
		switch(confirmar)
		{
			//Inicio da resposta caso o usu�rio confirme que deseja excluir o usu�rio
			case 1:
			fclose(file);
			remove(cpf);
			printf("O(a) usu�rio(a) foi deletado(a).\n\n");
			system("pause");
			break;
			//fim da resposta caso o usu�rio confirme que deseja excluir o usu�rio
			
			//Inicio da resposta caso o usu�rio cancela a inte��o de exclus�o do usu�rio
			case 2://cancela o processo de exclus�o
			printf("Opera��o cancelada, o usu�rio(a) continuar� no banco de dados.\n\n");
			system("pause");
			break;
			//Fim da resposta caso o usu�rio cancela a inte��o de exclus�o do usu�rio
			
			//Inicio da resposta caso o usu�rio digite incorretamente a op��o
			default://Op��o caso haja erro de digita��o
			printf("Esta op��o n�o est� dispon�vel, por favor repita o processo.\n\n");
			system("pause");
			break;
			//fim da resposta caso o usu�rio digite incorretamente a op��o	
		}//fim da vari�vel switch e da confirma��o de exclus�o do usu�rio
	}//Fim da coleta de dados
}//fim da vari�vel deletar


int main()//Fun��o principal 
{
	//Incio de cria��o de vari�veis
	int opcao=0; // Definindo vari�vel opcao
	int laco=1; // Definindo vari�vel laco
	//Fim de cria��o de vari�veis


	//Inicio da fun��o de retorno ao menu
	for(laco=1;laco=1;) 
	{  
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		
		system("cls"); //Organiza��o da tela do programa

		//In�cio do menu principal e escolha do usu�rio a qual fun��o ele quer acessar
		printf("\t####Cart�rio da EBAC####\n"); 
		printf("\t      Bem vindo(a)!\n\n");
		printf("Digite o n�mero da op��o desejada:\n\n");
		printf("\t 1 - Registrar usu�rio(a)\n");
		printf("\t 2 - Consultar usu�rio(a)\n");
		printf("\t 3 - Deletar usu�rio(a)\n\n");
		printf("Op��o:  "); 
		//fim do menu principal e da escolha do usu�rio
	
		scanf("%d", &opcao); //Armazenamento da escolha de menu do usu�rio
	
		system("cls"); //Organiza��o da tela do programa
	
		//Inicio da op��o selecionada no menu principal
		switch(opcao) 
		{
			//Inicio da chamada da fun��o registro
			case 1: 
			registro();
			break;
			//fim da chamada da fun��o registro
			
			//Inicio da chamada da fun��o consulta
			case 2:
			consulta();
			break;
			//Fim da chamada da fun��o consulta
			
			//Inicio da chamada da fun��o deletar
			case 3:
			deletar();
			break;
			//Fim da chamada da fun��o deletar
			
			//Inicio caso haja algum erro de digita��o
			default:
			printf("essa opc�o n�o est� dispon�vel\n\n");
			system("pause");
			break;	
			//Fim caso haja algum erro de digita��o		
			
		}//Fim da sele��o do menu principal
	} //fim da fun��o de retorno ao menu
} //fim da fun��o principal


