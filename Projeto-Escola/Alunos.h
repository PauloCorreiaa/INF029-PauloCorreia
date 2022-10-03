// Struct para cadastro de aluno
typedef struct {
  int dia, mes, ano;
} data;

typedef struct {
  
	int matricula;
	char nome[101], sexo;
  data nascimento;
  long int cpf;	
} Aluno;

//Funções
//Validação de Nome
int validarTexto(char string[]);

//Menu Alunos
int menuAlunos(void);

//Leitura dados do aluno (matrícula, nome, cpf, nascimento e sexo)
int inserirMatriculas(Aluno lista[], int qtd_aluno); 

//Listar alunos matriculados
void listarMatriculas(Aluno lista[], int qtd_aluno);

//Listar nome e matrícula
void listarMatriculasExclusao(Aluno lista[], int qtd_aluno);

//Excluir aluno da lista
void excluirMatricula(Aluno lista[], int qtd_aluno){	

//Função Principal de Alunos
int mainAlunos(Aluno lista[], int qtd_aluno);