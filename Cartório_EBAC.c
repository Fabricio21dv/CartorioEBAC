#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas string

int registro() //função resposável pelo cadastro no sistema
{
	//inicio da criação de variáveis(strings)
	char arquivo[40];
	char cpf[40];//40 é o número máximo de variáveis dentro da string (podemos escolher o valor)
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	
	printf("Você selecionou a opção 'Registrar Nomes'! \n\n"); 
	system("pause");
	system("cls");
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cpf); //$s salva as strings, no caso a string cpf
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); //w significa escrever 
	fprintf(file, "CPF:");
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //a significa atualizar o arquivo que já foi criado
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
	system("pause");//pausa a tela para o usuário ler a mensagem retornada
		
}
int consulta()
{
	printf("Você selecionou a opção 'Consultar nomes'! \n\n");
	system("pause");
	system("cls");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//r significa ler, quando o sistema lê o arquivo em busco de algum valor
	
	system("cls");
	
	if(file == NULL)//NULL é quando não existe o valor solicitado pelo usuário no arquivo
	{
		printf("Não foi possível localizar o CPF! \n");
	}
	else
	{
		printf("Essas são as informações sobre o usuário:\n");
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
	printf("Você escolheu:\n\nDeletar nomes!\n");
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
		printf("Este CPF não está cadastrado no sistema!\n");
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
	int opcao=0; //definindo a variável
	int laco=1; //definindo a variável
	char senhadigitada[10];
	setlocale(LC_ALL, "Portuguese"); //Identificando a linguagem do código
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador.\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	if(strcmp(senhadigitada, "admin") == 0)
	{
	
	
		for(laco=1;laco=1;)
		{
			system("cls"); //"Limpa" a tela
		
	
			printf("### Cartório da EBAC ###\n\n"); //Início do menu
			printf("Escolha a opção que deseja:\n\n");
			printf("\t1-Registrar nomes\n");
			printf("\t2-Consultar nomes\n");
			printf("\t3-Deletar nomes\n"); 
			printf("\t4-Sair do sistema\n\n\n"); //Fim do Menu
			printf("Digite sua opção:"); //Local onde o cliente faz a escolha 
	
			scanf("%d", &opcao); //Armazenando escolha do cliente no menu
	
		
			system("cls");
		
		
			switch(opcao)
			{	
				case 1://Início da escolha do cliente
				registro(); 
				break;
			
				case 2:
				consulta();//chamada ("ativação") da função que foi criada com esse nome 
				break;
			
				case 3:	
				deletar();
				break;
			
				case 4:
				printf("EBAC agradece, até a próxima.\n");
				return 0;
				break;
				
				default:
				printf("Esta opção não existe :(\nEscolha um número de 1 a 3.\n");
				system("pause");
				break;//Fim da escolha do cliente
				
			}
		}
	}
	
	else
		system("cls");
		printf("Senha incorreta!\n");
		
}
