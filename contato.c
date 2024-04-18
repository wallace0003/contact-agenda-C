#include <stdio.h>
#include <string.h>
#include "contato.h"


//Função para criar contato.
int criar_contato(Contatos contato[], int *posicao) {
    // Verificando se a posição não estendeu o total.
    if (*posicao >= total) {
        printf("Não é possível adicionar mais contatos, sua lista de contatos está cheia.\n");
        return 0;
    }

    // Pedindo para o usuário os dados e salvando-os no struct
    clearBuffer();
    printf("Nome: ");
    fgets(contato[*posicao].nome, max_nome, stdin);
    contato[*posicao].nome[strcspn(contato[*posicao].nome, "\n")] = '\0';

    printf("Sobrenome: ");
    fgets(contato[*posicao].sobrenome, max_nome, stdin);
    contato[*posicao].sobrenome[strcspn(contato[*posicao].sobrenome, "\n")] = '\0';

    printf("E-mail: ");
    fgets(contato[*posicao].email, max_email, stdin);
    contato[*posicao].email[strcspn(contato[*posicao].email, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &contato[*posicao].telefone);

    (*posicao)++; // Incrementa a posição

    return 1; // Retorna 1 indicando que o contato foi criado com sucesso
}

int listar_contatos(Contatos contato[], int *posicao){
  //Verificação de há contatos
  if(*posicao == 0){
    printf("Não há contatos");
    return 0;
  }
  //Looping para printar os contatos
  for(int i=0; i<*posicao; i++){
    printf("Posição: %d\t", i+1);
    printf("Nome: %s\t", contato[i].nome);
    printf("Sobrenome: %s\t", contato[i].sobrenome);
    printf("Email: %s\t", contato[i].email);
    printf("Contato: %d\n", contato[i].telefone);
  }
  return 1; // Retorna 1 indicando que os contatos foram listados com sucesso
}


int deletar_contato(){
  printf("função de deletar contato foi chamada\n");
}

int salvar_em_binario(){
  printf("Função de salvar em binario foi chamada\n");
}

int carregar_de_binario(){
  printf("Função de carregar de binario foi chamada\n");
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}