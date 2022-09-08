/*
9) Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado com sucesso ou se houve erro, informando onde foi o erro:

	• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres;
	• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para
masculino; f e F para feminino, o e O para outro).
	• função validarCPF: recebe o cpf digitado, e valida é um cpf válido;
	• função validarNacimento: recebe o data digitada, e valida é uma data válida.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int validarNome(char string[]);
//char validarSexo(char ch);
pessoa cadastrarCliente(pessoa C);

void linha(char c, int num);

int main()
{	
	int i; 
	pessoa cliente;

	linha('*', 13);
	cliente = cadastrarCliente(cliente);
	linha('*', 13);	
	
	puts("\nCliente cadastrado: ");
	printf("Nome = %s", cliente.nome);
	printf("\nNascimento = %d/%d/%d", cliente.nascimento.dia, cliente.nascimento.mes, cliente.nascimento.ano);
	printf("\nCpf = %ld", cliente.cpf);
	printf("\nSexo = %c", cliente.sexo);
		
	return 0;
}

//Funções
int validarNome(char string[])
{
	int tam_nome, validador = 0;
	
	tam_nome = strlen(string);
	if(tam_nome > 21)		
		validador++;	
	
	return validador;
}

char validarSexo(char ch)
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

pessoa cadastrarCliente(pessoa C)
{	
	int Valid_Nome = 0;
	
	puts("\nCadastro de clientes:");
	printf("Nome = "); fgets(C.nome, 101, stdin);
	Valid_Nome = validarNome(C.nome);
	if(Valid_Nome > 0)
		printf("20 caracteres permitido. Nome não cadastrado.\n");
	puts("Data de nascimento");
	printf("\tDia = "); scanf("%d", &C.nascimento.dia);
	printf("\tMês = "); scanf("%d", &C.nascimento.mes);
	printf("\tAno = "); scanf("%d", &C.nascimento.ano);
	
	printf("Cpf = "); scanf("%ld", &C.cpf);
	__fpurge(stdin);
	
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = ");	
	scanf("%c", &C.sexo);
	//C.sexo = validarSexo(C.sexo);
	
	return C;
}



void validarCPF


void validarNascimento


void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}

*/