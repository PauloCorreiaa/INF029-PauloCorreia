/*
1) Crie um programa que tenha uma função soma e a função main. A função main deve ler dois valores, enviar para a função soma. A função soma deve realizar a soma e retornar o valor. A Função main deve imprimir o resultado da soma.
*/

#include <stdio.h>

int soma (int x, int y);
void linha(char c, int num);

int main()
{
	int a, b;
	
	linha('*', 15);
	puts("\nDigite 2 números inteiros:");
	printf("Número 01 = "); scanf("%d", &a);
	printf("Número 02 = "); scanf("%d", &b);
	linha('*', 15);	
	printf("\n%d + %d = %d\n", a, b, soma(a, b));		
	
	return 0;
}

int soma (int x, int y)
{
	int resultado;
	resultado = x + y;
	return (resultado);
}

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}