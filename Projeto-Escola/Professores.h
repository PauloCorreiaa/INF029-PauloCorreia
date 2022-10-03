// Struct para cadastro de professores
typedef struct {
  int dia, mes, ano;
} data;

typedef struct {
  
	int matricula;
	char nome[101], sexo;
  data nascimento;
  long int cpf;	
} Professor;

//Funções
//Validação de Nome
int validarTexto(char string[]);

//Menu professores
int menuProfessores(void);

//Leitura dados do aluno (matrícula, nome, cpf, nascimento e sexo)
int inserirMatriculas(Professor lista[], int qtd_aluno); 

//Listar alunos matriculados
void listarMatriculas(Professor lista[], int qtd_aluno);

//Listar nome e matrícula
void listarMatriculasExclusao(Professor lista[], int qtd_aluno);

//Excluir professor
void excluirMatricula(Professor lista[], int qtd_aluno){	

//Função principal de professores
int mainProfessores(Professor lista[], int qtd_aluno);