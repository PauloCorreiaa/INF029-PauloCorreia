static int MATRICULA_ALUNO = 100;

// Struct alunos
typedef struct{  
	int matricula;
	char nome[101], cpf[12], sexo;
  int dia, mes, ano;	
} Aluno;

//Funções
//Validação de Nome
int validarTextoAluno(char string[]);

//Menu Alunos
//int menuAlunos(void);

//Leitura dados do aluno (matrícula, nome, cpf, nascimento e sexo)
int inserirAluno(Aluno lista[], int qtd_aluno); 

//Listar alunos matriculados
void listarAluno(Aluno lista[], int qtd_aluno);

//Listar nome e matrícula
void listarExclusaoAluno(Aluno lista[], int qtd_aluno);

//Excluir aluno da lista
int excluirAluno(Aluno lista[], int qtd_aluno);	

//Função Principal de Alunos
int menuAlunos(Aluno lista[], int qtd_aluno);