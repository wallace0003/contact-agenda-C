//Definindo o máximo para cada campo
#define total 255
#define max_nome 70
#define max_email 150

// definindo meu struct
typedef struct {
  char nome[max_nome];
  char sobrenome[max_nome];
  char email[max_email];
  int telefone;
} Contatos;


// Funções
int criar_contato(Contatos contato[], int *posicao);

int listar_contatos(Contatos contato[], int *posicao);

int deletar_contato(Contatos contato[], int *posicao);

int salvar_em_binario(Contatos contato[], int *posicao);

int carregar_de_binario(Contatos contato[], int *posicao);

int contem_apenas_letras(const char *str);

void clearBuffer();
