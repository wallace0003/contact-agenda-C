#include "contato.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int contem_apenas_letras(const char *str) {
  if (*str == '\0') {
      return 0; 
  }
  while (*str) {
    if (!isalpha(*str) && *str != ' ') { // Verifica se o caractere não é uma letra ou espaço
      return 0;
    }
    str++;
  }
  return 1;
}

int criar_contato(Contatos contato[], int *posicao) {
    // Verificando se a posição não excedeu o total.
    if (*posicao >= total) {
        printf("Não é possível adicionar mais contatos, sua lista de contatos está cheia.\n");
        return 0;
    }

    Contatos novo_contato;

    // Pedindo para o usuário os dados e salvando-os no struct
    clearBuffer();
    printf("Nome: ");
    fgets(novo_contato.nome, max_nome, stdin);
    novo_contato.nome[strcspn(novo_contato.nome, "\n")] = '\0'; // Removendo o caractere de nova linha

    // Verificando se o nome contém apenas letras
    if (!contem_apenas_letras(novo_contato.nome)) {
        printf("O nome não pode estar vazio e só pode conter apenas letras\n");
        return 0;
    }

    printf("Sobrenome: ");
    fgets(novo_contato.sobrenome, max_nome, stdin);
    novo_contato.sobrenome[strcspn(novo_contato.sobrenome, "\n")] = '\0'; // Removendo o caractere de nova linha

    // Verificando se o sobrenome contém apenas letras
    if (!contem_apenas_letras(novo_contato.sobrenome)) {
        printf("O sobrenome não pode estar vazio e deve conter apenas letras.\n");
        return 0;
    }

    int emailValido = 0;

    while (emailValido == 0) {
        printf("E-mail: ");
        fgets(novo_contato.email, max_email, stdin);
        novo_contato.email[strcspn(novo_contato.email, "\n")] = '\0'; // Removendo o caractere de nova linha

        // Verificando se o e-mail contém '@'
        if (strchr(novo_contato.email, '@') == NULL) {
            printf("Digite um email válido, com o caractere '@'.\n");
        } else {
            emailValido = 1;
        }
    }

    printf("Número: (Ex: 11987345601): ");
    scanf("%llu", &novo_contato.telefone);

    // Verificando se já existe um contato com o mesmo telefone
    for (int i = 0; i < *posicao; i++) {
        if (contato[i].telefone == novo_contato.telefone) {
            printf("Já existe um contato com este número de telefone.\n");
            return 0;
        }
    }

    // Armazena no array correto
    contato[*posicao] = novo_contato;
    (*posicao)++; // Incrementa a posição

    printf("Contato adicionado com sucesso!\n");

    return 1; // Retorna 1 indicando que o contato foi criado com sucesso
}

int listar_contatos(Contatos contato[], int *posicao) {
  // Verificação de há contatos
  if (*posicao == 0) {
    printf("Não há contatos, impossível listá-los.");
    return 0;
  }

  // Looping para printar os contatos
  for (int i = 0; i < *posicao; i++) {
    printf("Posição: %d\t", i + 1);
    printf("Nome: %s\t", contato[i].nome);
    printf("Sobrenome: %s\t", contato[i].sobrenome);
    printf("Email: %s\t", contato[i].email);
    printf("Contato: %llu\n", contato[i].telefone);
  }
  return 1; // Retorna 1 indicando que os contatos foram listados com sucesso
}

int deletar_contato(Contatos contatos[], int *posicao) {
  // Verificando se há contatos que possam ser excluídos...
  clearBuffer();
  if (*posicao == 0) {
    printf("Não há contatos para serem deletados.\n");
    return 0;
  }

  int num_deletar;
  printf("Digite o número que deseja deletar: ");
  scanf("%llu", &num_deletar);

  int encontrou_contato = 0;
  for (int i = 0; i < *posicao; i++) {
    if (contatos[i].telefone == num_deletar) {
      encontrou_contato = 1;
      // Deslocando contatos para preencher o espaço do contato excluído
      for (int j = i; j < *posicao - 1; j++) {
        strcpy(contatos[j].nome, contatos[j + 1].nome);
        strcpy(contatos[j].sobrenome, contatos[j + 1].sobrenome);
        strcpy(contatos[j].email, contatos[j + 1].email);
        contatos[j].telefone = contatos[j + 1].telefone;
      }
      break; // Saia do loop assim que o contato for encontrado e excluído
    }
  }

  if (!encontrou_contato) {
    printf("Número de telefone não encontrado na lista de contatos.\n");
    return 0;
  }

  (*posicao)--; // Decrementa o número de contatos

  printf("Contato deletado com sucesso.\n");

  return 1;
}

int salvar_binario_pessoais(Contatos contato[], int *posicao) {
  FILE *f = fopen("Contatos_pessoais.bin", "wb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo para leitura\n");
    return 0;
  }
  int qtd = fwrite(contato, total, sizeof(Contatos), f);
  if (qtd == 0) {
    printf("Erro ao ler os contatos do arquivo\n");
    return 0;
  }
  qtd = fwrite(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }
  if (fclose(f)) {
    printf("Erro ao fechar o arquivo após a leitura\n");
    return 0;
  }

  printf(
      "\nArquivo foi salvo em arquivo binario com o nome: 'Contatos_pessoais.bin'. \n");
  return 1;
}

int carregar_binario_pessoais(Contatos contato[], int *posicao) {

  FILE *f = fopen("Contatos_pessoais.bin", "rb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 0;
  }

  int qtd = fread(contato, total, sizeof(Contatos), f);
  if (qtd == 0) {
    printf("Erro ao ler os contatos do arquivo\n");
    return 0;
  }

  qtd = fread(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }

  if (fclose(f)) {
    printf("Erro ao fechar o arquivo\n");
    return 0;
  }

  printf("\nContatos carregados com sucesso!\n");
  return 1;
}

int salvar_binario_trabalho(Contatos contato[], int *posicao) {
  FILE *f = fopen("Contatos_trabalho.bin", "wb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo para leitura\n");
    return 0;
  }
  int qtd = fwrite(contato, total, sizeof(Contatos), f);
  if (qtd == 0) {
    printf("Erro ao ler os contatos do arquivo\n");
    return 0;
  }
  qtd = fwrite(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }
  if (fclose(f)) {
    printf("Erro ao fechar o arquivo após a leitura\n");
    return 0;
  }

  printf(
      "\nArquivo foi salvo em arquivo binario com o nome: 'Contatos_trabalho.bin'. \n");
  return 1;
}

int carregar_binario_trabalho(Contatos contato[], int *posicao) {

  FILE *f = fopen("Contatos_trabalho.bin", "rb");
  if (f == NULL) {
    printf("Erro ao abrir o arquivo\n");
    return 0;
  }

  int qtd = fread(contato, total, sizeof(Contatos), f);
  if (qtd == 0) {
    printf("Erro ao ler os contatos do arquivo\n");
    return 0;
  }

  qtd = fread(posicao, 1, sizeof(int), f);
  if (qtd == 0) {
    printf("Erro ao ler a posição do arquivo\n");
    return 0;
  }

  if (fclose(f)) {
    printf("Erro ao fechar o arquivo\n");
    return 0;
  }

  printf("\nContatos carregados com sucesso!\n");
  return 1;
}



void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}
