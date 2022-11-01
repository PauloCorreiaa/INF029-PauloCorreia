#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structs
typedef struct{
    int iDia; 
    int iMes;
    int iAno;
    int valido; //0 se inválido, e 1 se válido 
} data_int;

//Principal
int main(){
	int num = 120;
	int i, j; //contadores str
	char str[250], str_invertida[250];

	//converter int/str
	for(i = 0, j = '\0'; i != '/0'; i++, j--){		
		str[i] = num / 10;
		str_invertida[j] = str[i];
		if((num % 10) < 10)
			str[i] = num % 10;
			str_invertida[j] = str[i];}

	printf("\nEntrada = %s\nEntrada invertida = %s", num, str_invertida);
	//converter str/int
	//num = (int)num_str;}
	
	return 0;
}

	

