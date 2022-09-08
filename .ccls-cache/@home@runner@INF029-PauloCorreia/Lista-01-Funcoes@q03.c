/*
3) Faça um programa que tenha uma função que recebe um número inteiro e retorna o fatorial deste número. Esta função deve ainda verificar se é possível calcular o fatorial, se não for, ela deve
de alguma forma retornar para a main que deu algum erro. A função main deve solicitar o valor do usuário e imprimir o fatorial dele, ou se não é possível calcular o fatorial 
*/

#include <stdio.h>

double fat(int n);
void linha(char c, int num);

int main()
{
	int num, fatorial;

	linha('*', 15);
	printf("\nDigite um número inteiro: "); 
	scanf("%d", &num);		
	fatorial = fat(num);
	linha('*', 15);
	printf("\n%d! = %d", num, fatorial);

	return 0;
}

double fat(int n)
{
	int i;
	double resultado = 1;
	for(i=1; i<=n; i++)
		resultado *= i;
	
	return resultado;
};

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}