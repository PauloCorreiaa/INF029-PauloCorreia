static int MATRICULA_PROFESSOR = 200;

// Struct professores
typedef struct{  
	int matricula;
	char nome[101], sexo;
  int dia, mes, ano;
  long int cpf;	
} Professor;

//Funções
//Validação de Nome
int validarTextoProf(char string[]);

//Menu professores
int menuProfessores(void);

//Leitura dados do professor (matrícula, nome, cpf, nascimento e sexo)
int inserirMatriculaProf(Professor lista[], int qtd_professores); 

//Listar professores matriculados
void listarMatriculasProf(Professor lista[], int qtd_professores);

//Listar nome e matrícula
void listarMatriculasExclusaoProf(Professor lista[], int qtd_professores);

//Excluir professor
int excluirMatriculaProf(Professor lista[], int qtd_professores);	

//Função Principal professores
int mainProfessores(Professor lista[], int qtd_professores);