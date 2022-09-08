/*
8) Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve imprimir os dados do cliente.
*/

#include <stdio.h>
#include <string.h>

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

pessoa cadastrarCliente(pessoa C)
{	
	char ch;
	
	puts("\nCadastro de clientes:");
	printf("Nome = "); scanf("%s", C.nome);		
	puts("Data de nascimento");
	printf("\tDia = "); scanf("%d", &C.nascimento.dia);
	printf("\tMês = "); scanf("%d", &C.nascimento.mes);
	printf("\tAno = "); scanf("%d", &C.nascimento.ano);
	printf("Cpf = "); scanf("%ld", &C.cpf);
	__fpurge(stdin);
	printf("Sexo\n\tf = feminino\n\tm = masculino\n\to = outro\n\tSua resposta = ");	
	scanf("%c", &C.sexo);
	
	return C;
} 

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}