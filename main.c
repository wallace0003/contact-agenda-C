#include "contato.h"
#include <stdio.h>

int main() {
  Contatos contatosPessoais[total];
  Contatos ContatosTrabalho[total];
  int posicaoPessoais = 0;
  int posicaoTrabalho = 0;

  while (1) {
    int opcao;
    int escolhaContatos;
    printf("\n");
    printf("1 - Criar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("4 - Salvar contatos em arquivo binário\n");
    printf("5 - Carregar contatos de arquivo binário\n");
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1) {
        
      printf("1 -> Agenda pessoal\n");
      printf("2 -> Agenda de trabalho\n");
      printf("Opção: ");
      scanf("%d", &escolhaContatos);
      if (escolhaContatos == 1){
          criar_contato(contatosPessoais, &posicaoPessoais);
      }
      else if (escolhaContatos == 2){
          criar_contato(ContatosTrabalho, &posicaoTrabalho);
      }
      else{
          printf("Opção inválida\n");
      }
        
    }

    else if (opcao == 2) {
        
        printf("1 -> Agenda pessoal\n");
        printf("2 -> Agenda de trabalho\n");
        printf("Opção: ");
        scanf("%d", &escolhaContatos);
        if (escolhaContatos == 1){
            listar_contatos(contatosPessoais, &posicaoPessoais);
        }
        else if (escolhaContatos == 2){
            listar_contatos(ContatosTrabalho, &posicaoTrabalho);
        }

        else{
            printf("Opção inválida\n");
        }
        
    }

    else if (opcao == 3) {
        
      printf("1 -> Agenda pessoal\n");
      printf("2 -> Agenda de trabalho\n");
      printf("Opção: ");
      scanf("%d", &escolhaContatos);
      if (escolhaContatos == 1){
          deletar_contato(contatosPessoais, &posicaoPessoais);
      }
      else if (escolhaContatos == 2){
          deletar_contato(ContatosTrabalho, &posicaoTrabalho);
      }

      else{
          printf("Opção inválida\n");
      }
        
    }

    else if (opcao == 4) {
        
        printf("1 -> Agenda pessoal\n");
        printf("2 -> Agenda de trabalho\n");
        printf("Opção: ");
        scanf("%d", &escolhaContatos);
        if (escolhaContatos == 1){
            salvar_em_binario(contatosPessoais, &posicaoPessoais);
        }
        else if (escolhaContatos == 2){
            salvar_em_binario(ContatosTrabalho, &posicaoTrabalho);
        }

        else{
            printf("Opção inválida\n");
        }


      
      
    }

    else if (opcao == 5) {
        
        printf("1 -> Agenda pessoal\n");
        printf("2 -> Agenda de trabalho\n");
        printf("Opção: ");
        scanf("%d", &escolhaContatos);
        if (escolhaContatos == 1){
            carregar_de_binario(contatosPessoais, &posicaoPessoais);
        }
        else if (escolhaContatos == 2){
            carregar_de_binario(ContatosTrabalho, &posicaoTrabalho);
        }
        else{
            printf("Opção inválida\n");
        }

      
    }

    else if (opcao == 0) {
      printf("Saindo...\n");
      break;
    }

    else {
      printf("Opção inválida!\n");
    }
  }
}