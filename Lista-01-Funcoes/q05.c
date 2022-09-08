/*
5) Crie um programa que tenha uma função ler4Numeros. Essa função deve ler quatro números do usuário e retornar os quatro números. A função main deve imprimir esses quatro números. Utilize struct para fazer o retorno.
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
	char nome[101];
	int idade;
} usuarios;

void ler4Numeros(usuarios v[]);
void linha(char c, int num);

int main()
{	
	int i; 
	usuarios lista[4];

	linha('*', 13);
	ler4Numeros(lista);
	linha('*', 13);
	puts("\nIdades digitadas: ");
	for(i=0; i<4; i++)
	{		
		printf("%d\t", lista[i].idade);
	}
	
	return 0;
}

void ler4Numeros(usuarios v[])
{
	int j;
	
	puts("\nCadastro de idades");
	for(j=0; j<4; j++)
	{
		printf("Nome %d = ", j+1); 
		scanf("%s", v[j].nome);		
		printf("Idade %d = ", j+1); 
		scanf("%d", &v[j].idade);
		putchar('\n');
	};	
} 

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}