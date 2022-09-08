/*
7) Crie um programa que tenha uma função ler3Palavras. Essa função deve ler três palavras do usuário e retornar as três palavras. A função main deve imprimir essas três palavras
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
	char palavra[101];
} usuarios;

void ler4Palavras(usuarios v[]);
void linha(char c, int num);

int main()
{	
	int i; 
	usuarios lista[4];

	linha('*', 15);
	ler4Palavras(lista);
	linha('*', 15);
	puts("\nPalavras digitadas: ");
	for(i=0; i<4; i++)
	{		
		printf("%s\n", lista[i].palavra);
	}
	
	return 0;
}

void ler4Palavras(usuarios v[])
{
	int j, len;
	
	puts("\nCadastro de palavras");
	for(j=0; j<4; j++)
	{
		printf("Palavra %d = ", j+1); 
		fgets(v[j].palavra, sizeof(v[j].palavra), stdin);
		len = strlen(v[j].palavra);
		if(v[j].palavra[len - 1] == '\n')
			 v[j].palavra[len - 1] = '\0';
	};	
}

void linha(char c, int num)
{
	int i;

	for(i=1; i<num; i++)
		printf("%c ", c);
}