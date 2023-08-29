#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro()//Função responsável por cadastrar os usuários no sistema
{
	//Início de criação de variáveis/strings
	char cpf[40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char conteudo[200];
	//Final de criação de variáveis
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	printf("Digite o CPF do usuário(a) a ser cadastrado(a): ");// Coletando informação do usuário
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //copiando as informações da string cpf na string arquivo

	FILE *file; //O programa deve buscar na biblioteca como criar um arquivo, 
	file = fopen(arquivo, "w"); //O programa irá criar o arquivo e nomea-lo com as informações contidas na variável "arquivo"
	
	//Copiando o cpf coletado para o banco de dados e organizando internamente o arquivo de texto
	fprintf(file,"CPF: "); 
	fprintf(file,cpf); 
	fprintf(file,"\n");
	fclose(file); 
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o nome do usuário, salvando no banco de dados e organizando internamente o arquivo de texto
	printf("Digite o nome do usuário(a): ");
	scanf("%s",nome); 
	file = fopen(arquivo, "a");
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fprintf(file," ");
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o sobrenome do usuário, salvando no banco de dados e organizando internamente o arquivo de texto	
	printf("Digite o sobrenome do usuário(a): ");
	scanf("%s",sobrenome);
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fprintf(file,"\n");
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	
	//Coletando o cargo do usuário, salvando no banco de dados e organizando internamente o arquivo de texto	
	printf("Digite o cargo do usuário(a):");
	scanf("%s",cargo);
	file = fopen(arquivo,"a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	//Fim do ajuste e comando para fechar o arquivo de texto
	

	system("cls"); // Apagando o menu e mudando de tela
	
	file = fopen(cpf,"r"); //Ler as informações coletadas
	
	// Mensagem de confirmação de cadastro do usuário(a)
	printf("\n \t O(a) usuário(a) foi cadastrado(a) com sucesso. \n\n");
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s",conteudo);		
	}
	printf("\n\n"); //organização da tela
	fclose(file);
	system("pause");
	
	
}//fim da variável consulta

int consulta()//Função responsável por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//Início de criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//Final de criação de variáveis
	
	//Coletando dados do usuário
	printf("Por favor, digite o CPF do usuário(a) a ser consultado: "); 
	scanf("%s",cpf); 
	printf("\n");
	//Final da coleta de dados do usuário
	
	FILE *file; //Busca na biblioteca operações com arquivos
	file = fopen(cpf,"r");//O programa irá ler o arquivo cpf criado no banco de dados
	
	//Resposta caso os dados coletados não constem a nenhum usuário cadastrado
	if(file == NULL)
	{
		printf("\t O usuário(a) não está cadastrado.\n");
	}
	//fim da resposta caso não encontre usuários cadastrados.
	
	//Resposta caso os dados coletados constem a algum usuário cadastrado
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("%s",conteudo);	
	}
	//Fim da resposta caso encontre usuário cadastrado

	printf("\n\n"); //organização da tela do programa
	system("pause");
	
}//Fim da variável registro


int deletar()//Função responsável por deletar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	//Início de criação de variáveis/strings
	char cpf[40];
	int confirmar=0;
	char conteudo[200];
	//Fim da criação de variáveis
	
	//Início da coleta de dados do usuário
	printf("Digite o CPF do usuário(a) a ser deletado(a): ");
	scanf("%s", cpf);
	//Fim da coleta de dados do usuário
	
	//O programa irá buscar na biblioteca como gerenciar arquivos e ler (r) o que está escrito no arquivo com o nome da coleta de dados
	FILE *file;
	file = fopen(cpf,"r"); 
	//fim de gerenciamento de arquivos

	system("cls"); //Organização da tela do programa
	
	//Inicio da resposta caso o dado coletado não conste no sistema do banco de dados
	if (file == NULL)
	{
		printf("\tO(a) usuário(a) não está cadastrado(a) no sistema.\n\n");
		system("pause");
	}
	//Fim da resposta caso dado coletado não conste no sistema
	
	//Inicio da resposta caso o dado coletado conste no sistema do banco de dados
	if (file != NULL)
	{
		//Inicio de coleta de dados e mensagens para o usuário
		printf("\nO(a) usuário(a) ");
		printf("%s",cpf);
		printf(" será deletado(a), deseja confimar esta operação? \n\n");
		printf("\tDigite 1 para confirmar\n");
		printf("\tDigite 2 para cancelar\n\n");
		printf("Digite a opção desejada: ");
		scanf("%d",&confirmar);
		//Fim da coleta de dados
		
		system("cls"); // Organização da tela do programa
		
		//Confirmação de exclusão do usuário
		switch(confirmar)
		{
			//Inicio da resposta caso o usuário confirme que deseja excluir o usuário
			case 1:
			fclose(file);
			remove(cpf);
			printf("O(a) usuário(a) foi deletado(a).\n\n");
			system("pause");
			break;
			//fim da resposta caso o usuário confirme que deseja excluir o usuário
			
			//Inicio da resposta caso o usuário cancela a inteção de exclusão do usuário
			case 2://cancela o processo de exclusão
			printf("Operação cancelada, o usuário(a) continuará no banco de dados.\n\n");
			system("pause");
			break;
			//Fim da resposta caso o usuário cancela a inteção de exclusão do usuário
			
			//Inicio da resposta caso o usuário digite incorretamente a opção
			default://Opção caso haja erro de digitação
			printf("Esta opção não está disponível, por favor repita o processo.\n\n");
			system("pause");
			break;
			//fim da resposta caso o usuário digite incorretamente a opção	
		}//fim da variável switch e da confirmação de exclusão do usuário
	}//Fim da coleta de dados
}//fim da variável deletar


int main()//Função principal 
{
	//Incio de criação de variáveis
	int opcao=0; // Definindo variável opcao
	int laco=1; // Definindo variável laco
	//Fim de criação de variáveis


	//Inicio da função de retorno ao menu
	for(laco=1;laco=1;) 
	{  
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
		
		system("cls"); //Organização da tela do programa

		//Início do menu principal e escolha do usuário a qual função ele quer acessar
		printf("\t####Cartório da EBAC####\n"); 
		printf("\t      Bem vindo(a)!\n\n");
		printf("Digite o número da opção desejada:\n\n");
		printf("\t 1 - Registrar usuário(a)\n");
		printf("\t 2 - Consultar usuário(a)\n");
		printf("\t 3 - Deletar usuário(a)\n\n");
		printf("Opção:  "); 
		//fim do menu principal e da escolha do usuário
	
		scanf("%d", &opcao); //Armazenamento da escolha de menu do usuário
	
		system("cls"); //Organização da tela do programa
	
		//Inicio da opção selecionada no menu principal
		switch(opcao) 
		{
			//Inicio da chamada da função registro
			case 1: 
			registro();
			break;
			//fim da chamada da função registro
			
			//Inicio da chamada da função consulta
			case 2:
			consulta();
			break;
			//Fim da chamada da função consulta
			
			//Inicio da chamada da função deletar
			case 3:
			deletar();
			break;
			//Fim da chamada da função deletar
			
			//Inicio caso haja algum erro de digitação
			default:
			printf("essa opcão não está disponível\n\n");
			system("pause");
			break;	
			//Fim caso haja algum erro de digitação		
			
		}//Fim da seleção do menu principal
	} //fim da função de retorno ao menu
} //fim da função principal


