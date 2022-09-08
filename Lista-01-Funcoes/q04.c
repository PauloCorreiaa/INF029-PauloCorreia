/*
4) Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor para fazer o retorno.
*/

#include <stdio.h>
void ler3Numeros(int v[]);
void linha(char c, int num);

int main()
{	
	int i, vetor[3];

	linha('*', 15);
	ler3Numeros(vetor);
	linha('*', 15);
	puts("\nNúmeros digitados:");
	for(i=0; i<3; i++)
	{		
		printf("%d\t", vetor[i]);
	}
	
	return 0;
}

void ler3Numeros(int v[])
{
	int j;	
		
	printf("\nDigite 3 números inteiros:\n");
	for(j=0; j<3; j++)
	{
		printf("Número %d = ", j+1); 
		scanf("%d", &v[j]);
	};	
} 

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}