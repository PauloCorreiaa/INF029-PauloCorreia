/*
2) Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores (primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o resultado da subtração.
*/

#include <stdio.h>

int subtracao (int x, int y, int z);
void linha(char c, int num);

int main()
{
	int a, b, c;
	
	linha('*', 15);
	puts("\nDigite 3 números inteiros:");
	printf("Número 01 = "); scanf("%d", &a);
	printf("Número 02 = "); scanf("%d", &b);
	printf("Número 02 = "); scanf("%d", &c);
	linha('*', 15);

	printf("\n%d - %d - %d = %d\n", a, b, c, subtracao(a, b, c));
	
	return 0;
}

int subtracao (int x, int y, int z)
{
	int resultado;
	resultado = x - y - z;
	return (resultado);
}

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}