#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas string

int registro() //fun��o respos�vel pelo cadastro no sistema
{
	//inicio da cria��o de vari�veis(strings)
	char arquivo[40];
	char cpf[40];//40 � o n�mero m�ximo de vari�veis dentro da string (podemos escolher o valor)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	
	printf("Voc� selecionou a op��o 'Registrar Nomes'! \n\n"); 
	system("pause");
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); //$s salva as strings, no caso a string cpf
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //w significa escrever 
	fprintf(file, "CPF:");
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //a significa atualizar o arquivo que j� foi criado
	fprintf(file, ". Nome:"); // apenas adicionando a virgula entre os itens do cadastro
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ". Sobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ". Cargo:");
	fclose(file);
	
	printf("Digite o cargo do cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ".");
	fclose(file);
	
	system("cls");//limpa a tela 
	printf("Nome salvo!\n\n");
	system("pause");//pausa a tela para o usu�rio ler a mensagem retornada
		
}
int consulta()
{
	printf("Voc� selecionou a op��o 'Consultar nomes'! \n\n");
	system("pause");
	system("cls");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//r significa ler, quando o sistema l� o arquivo em busco de algum valor
	
	system("cls");
	
	if(file == NULL)//NULL � quando n�o existe o valor solicitado pelo usu�rio no arquivo
	{
		printf("N�o foi poss�vel localizar o CPF! \n");
	}
	else
	{
		printf("Essas s�o as informa��es sobre o usu�rio:\n");
		while(fgets(conteudo, 200, file)!=NULL)
		{
			printf("%s", conteudo);
			printf("\n\n");
		}
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	printf("Voc� escolheu:\n\nDeletar nomes!\n");
	system("pause");
	system("cls");
	
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	system("cls");
	
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("Este CPF n�o est� cadastrado no sistema!\n");
		system("pause");
	}
	else
	{
		printf("CPF deletado com sucesso!\n");	
		while(fgets(cpf, 40, file) != NULL);
		remove(cpf);
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //definindo a vari�vel
	int laco=1; //definindo a vari�vel
	char senhadigitada[10];
	setlocale(LC_ALL, "Portuguese"); //Identificando a linguagem do c�digo
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	if(strcmp(senhadigitada, "admin") == 0)
	{
	
	
		for(laco=1;laco=1;)
		{
			system("cls"); //"Limpa" a tela
		
	
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
			printf("Escolha a op��o que deseja:\n\n");
			printf("\t1-Registrar nomes\n");
			printf("\t2-Consultar nomes\n");
			printf("\t3-Deletar nomes\n"); 
			printf("\t4-Sair do sistema\n\n\n"); //Fim do Menu
			printf("Digite sua op��o:"); //Local onde o cliente faz a escolha 
	
			scanf("%d", &opcao); //Armazenando escolha do cliente no menu
	
		
			system("cls");
		
		
			switch(opcao)
			{	
				case 1://In�cio da escolha do cliente
				registro(); 
				break;
			
				case 2:
				consulta();//chamada ("ativa��o") da fun��o que foi criada com esse nome 
				break;
			
				case 3:	
				deletar();
				break;
			
				case 4:
				printf("EBAC agradece, at� a pr�xima.\n");
				return 0;
				break;
				
				default:
				printf("Esta op��o n�o existe :(\nEscolha um n�mero de 1 a 3.\n");
				system("pause");
				break;//Fim da escolha do cliente
				
			}
		}
	}
	
	else
		system("cls");
		printf("Senha incorreta!\n");
		
}
