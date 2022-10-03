/*
9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:

	• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
	• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
	• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
	• função validarNacimento: recebe o data digitada, e valida é uma data válida.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Structs para cadastro de cliente
typedef struct
{
	int dia, mes, ano;
} data;

typedef struct
{
	char nome[101], sexo;
	data nascimento;
	long int cpf;	
} pessoa;

//Protótipos das funções utilizadas
int validarTexto(char string[]);
//char validarSexo(char ch);
pessoa cadastrarCliente(pessoa C);
void linha(char c, int num);

//Programa Cadastro de cliente
int main()
{	
	//Declarações
	int i; 
	pessoa cliente;

	//Cabeçalho
	linha('*', 21);
	cliente = cadastrarCliente(cliente);
	linha('*', 21);	

	//Cadastro de cliente
	puts("\nCadastro de Novo Cliente: ");	
	printf("Nome = %s", cliente.nome);
	/*printf("\nNascimento = %d/%d/%d", cliente.nascimento.dia, cliente.nascimento.mes, cliente.nascimento.ano);
	printf("\nCpf = %ld", cliente.cpf);
	printf("\nSexo = %c", cliente.sexo);*/
		
	return 0;
}

//Funções
//Validação de Nome
int validarTexto(char string[])
{
	int i, tam_str, tam_max, validador = 0;	
	tam_max = 20;
	
	tam_str = strlen(string);
	if(tam_str > tam_max || string[0] == '\0')							
			validador++;
	
	return validador;
}

//Validação de sexo
/*char validarSexo(char ch)
{
	char confirmaSexo[11];
	switch(ch)
	{
		case 'F': 
		case 'f': 					
			ch = confirmaSexo[11];
			confirmaSexo[11] = {"feminino"};		
			break;		
		
		case 'M': 
		case 'm':		
			ch = confirmaSexo[11];
			confirmaSexo[11] = {"masculino"};
			break;
		
		case 'O': 
		case 'o':			
			ch = confirmaSexo[11];
			confirmaSexo[11] = {"Outro"};
			break;
		
		default: printf("Digite novamente");		
	}

	return confirmaSexo;
}
*/
//Funções
//Leitura dos dados do cliente (nome, cpf, nascimento e sexo)
pessoa cadastrarCliente(pessoa C)
{		
	char texto[101];
	
	puts("\nCadastro de clientes:");
	printf("Nome = "); fgets(texto, 101, stdin);
	linha('*', 21);	
	if(validarTexto(texto) > 0)		
			printf("\nNome não cadastrado.\nLimite de caracteres excedido.\n");						
	else
		{
			strcpy(C.nome, texto);
			printf("\nNome = %s", C.nome);
		}	

	/*puts("Data de nascimento");
	printf("\tDia = "); scanf("%d", &C.nascimento.dia);
	printf("\tMês = "); scanf("%d", &C.nascimento.mes);
	printf("\tAno = "); scanf("%d", &C.nascimento.ano);
	
	printf("Cpf = "); scanf("%ld", &C.cpf);
	__fpurge(stdin);
	
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = ");	
	scanf("%c", &C.sexo);*/
	//C.sexo = validarSexo(C.sexo);
	
	return C;
}

//Validação de CPF
//void validarCPF

//Validação de data de nascimento
//void validarNascimento

//Impressão de linha de caracteres
void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}