// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Paulo Correia
//  email: paulo.mo.correia@gmail.com
//  Matrícula: 20202160015	
//  Semestre: 2022.2
// #################################################

#ifndef TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H
#define TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H

typedef struct{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 
} Data_Quebrada;

typedef struct{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
void linha(char c, int num); //imprimir linha caracteres
int q1(char data[]); //validação data
DiasMesesAnos q2(char datainicial[], char datafinal[]); //operações 
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
Data_Quebrada quebraData(char data[]);

#endif  // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H