#include<stdio.h> //biblioteca de comunicação com usuario
#include<stdlib.h> //biblioteca de alocação de espaço em memoria
#include<locale.h> //biblioteca de alocação de texto por região
#include<string.h> //biblioteca responsável oir cuidar das string

int registro() //função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaves/ string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	// final da criação de variavel dos string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria arquivo novo e o "w" escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre novamente o arquivo e atualiza
	fprintf(file, ",\n"); //separação dados
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuario
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file,nome); //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file, ",\n"); //define "," separando as informações
	fclose(file); //fecha o arquivo	
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informação do usuario
	scanf("%s",sobrenome); //%s refere-se e string
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza
	fprintf(file,sobrenome); //salva o valor da variave
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file, ",\n");  //define "," separando as informações
	fclose(file); //fecha o arquivo		
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informação do usuario
	scanf("%s", cargo);//%s refere-se e string
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza
	fprintf(file,cargo); //salva o valor da variave
	fclose(file); //fecha o arquivo	
	
	file = fopen(arquivo, "a"); //abre o arquivo e atualiza
	fprintf(file, ",\n");  //define "," separando as informações
	fclose(file); //fecha o arquivo		
	
	system("pause");//pausa na tela 
			
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
	//inicio criação de variaves/ string
	char cpf[40];
	char conteudo[200];
	// final da criação de variavel dos string
	
	printf("Digite o CPF a ser consultado: ");//coletando informação do usuario
	scanf("%s", cpf);//%s refere-se e string
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre arquivo para leitura
	
	if(file==NULL) //se o CPF for nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");//informação ao usuario
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto tiver conteudo ate 200
	{
		printf("\nEssas são as informações do usuário: \n\n");//informação ao usuario
		printf("%s" ,conteudo);
		printf("\n\n"); //formatação quebra linha
	}
	
	system("pause");//pausa na tela 
	
}

int deletar()
{
	// criação de variaves/ string
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");//coletando informação do usuario
	scanf("%s", cpf);//%s refere-se e string
	
	remove(cpf); //removendo CPF
		
	FILE *file;
	file = fopen(cpf, "r");//abre arquivo para leitura
					
	if(file==NULL) ////se o CPF for nulo
	{
		printf("O usuário não se encontra no sistema.\n");//informação ao usuario
		system("pause");//pausa na tela 
	}
	
	
}

int main() 
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "portuguese"); // Definindo a linguagem
	
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
		printf("### Cartório da EBAC ###\n\n"); // inicio do Menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do sistema\n\n");	
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //limpar tela
		
		switch(opcao) // inicio da seleção menu
		{
			case 1:
			registro(); // chamada de funçoes
			break;//encerramento
			
			case 2:
			consulta();// chamada de funçoe
			break;//encerramento
					
			case 3:
			deletar();// chamada de funçoe
			break;//encerramento
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
			default:
			printf("Esta opção não está disponível\n");//informação ao usuario	
			system("pause");//pausa na tela 
			break;//encerramento
							
		}
		    
		printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
	}
} 
	

