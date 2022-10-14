#define TAM_NOME 51
static int cod = 300;

//Struct disciplinas
typedef struct{
	char nome[TAM_NOME];
	int codigo;
	char nome_professor[TAM_NOME];
	int qtd_aluno;
} Disciplina;

//Funções
//Validação de Nome
//int validarNome (char n[]);

//Menu disciplinas
int menuDisciplinas (Disciplina discpl[], int qtd_disciplina);

//Leitura dados da disciplina (nome, professor, código)
int CadastrarDisciplina(Disciplina discpl[], int qtd);

//Listar disciplinas
void ListarDisciplina (Disciplina discpl[], int qtd);

//Buscar disciplina
int LocalizarDisciplina (Disciplina discpl[], int qtd);

//Excluir disciplina
int ExcluirDisciplina (Disciplina discpl[], int qtd);

//Atualizar disciplina
void AtualizarDisciplina (Disciplina discpl[], int qtd);