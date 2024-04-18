#include <stdio.h>
#include "contato.h"


int main(){
  Contatos contatos[total];
  int posicao = 0;
  while (1){
    int opcao;
    printf("\n");
    printf("1 - Criar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("4 - Salvar contatos em arquivo binário\n");
    printf("5 - Carregar contatos de arquivo binário\n");
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");
    scanf("%d" , &opcao);
    printf("\n");

    if (opcao == 1) {
    criar_contato(contatos, &posicao);
    }

    else if(opcao == 2){
    listar_contatos(contatos, &posicao);
    }

    else if(opcao == 3){
      deletar_contato();
    }

    else if(opcao == 4){
      salvar_em_binario();
    }

    else if (opcao == 5){
      carregar_de_binario();
    }

    else if(opcao == 0){
      printf("Saindo...\n");
      break;
    }

    else{
      printf("Opção inválida!\n");
    }
    clearBuffer();
  }
  
  
}