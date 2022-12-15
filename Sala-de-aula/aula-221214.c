/*
Aula 14/12/2022 - Anotações
Recursão
	vantagens e desvantagens
		principal desvantagem é a custosa alocação de memória para os sistemas operacionais

	caracteríticas
		condição de parada = como encerrar o loop
		regra geral = método/lógica

	atividades
		lista sobre recursão
		https://programacaodescomplicada.files.wordpress.com/2012/10/lista-recursc3a3o.pdf
*/
//código exemplo recursão
#include <stdio.h>

//função fatorial
double fatorial(int n){
	double fat;
	//validação números positivos
	if(n < 0)
		return -1;
	//validação constante
	if(n == 1)
		return 1;	
	//chamada recursiva
	else{
		fat = n * fatorial(n - 1)
			return fat;}
	}		