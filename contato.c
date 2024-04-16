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

int listar_contatos(){
  printf("Função de listar contatos foi chamada\n");
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