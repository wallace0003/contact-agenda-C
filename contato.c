#include "contato.h"
#include <stdio.h>
#include <string.h>




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
    // Evitando se deixar o /n no final para não dar nenhum bug.
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
    printf("Não há contatos, impossível listá-los.");
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


int deletar_contato(Contatos contatos[], int *posicao) {
    // Verificando se há contatos que possam ser excluídos...
    clearBuffer();
    if (*posicao == 0) {
        printf("Não há contatos para serem deletados.\n");
        return 0;
    }

    int num_deletar;
    printf("Digite o número que deseja deletar: ");
    scanf("%d", &num_deletar);

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

    return 1;
}


int salvar_em_binario(Contatos contato[], int *posicao) {
    FILE *f = fopen("Contatos.bin", "wb");
        if(f == NULL){
           printf("Erro ao abrir o arquivo para leitura\n");
            return 0;
        }
        int qtd = fwrite(contato, total, sizeof(Contatos), f);
        if(qtd == 0){
            printf("Erro ao ler os contatos do arquivo\n");
            return 0;
        }
        qtd = fwrite(posicao, 1, sizeof(int), f);
        if(qtd == 0){
            printf("Erro ao ler a posição do arquivo\n");
            return 0;
        }
        if(fclose(f)){
            printf("Erro ao fechar o arquivo após a leitura\n");
            return 0;
        }
        
        printf("\nArquivo foi salvo em arquivo binario com o nome de - Contatos.bin !! \n");
        return 1;
}

int carregar_de_binario(Contatos contato[], int *posicao) {
    
FILE *f = fopen("Contatos.bin", "rb");
    if(f == NULL){
        return 0;
    }

    int qtd = fread(contato, total, sizeof(Contatos), f);
    if(qtd == 0){
        return 0;
    }

    qtd = fread(posicao, 1, sizeof(int), f);
    if(qtd == 0){
        return 0;
    }

    if(fclose(f)){
        return 0;    
    }   
       

    printf("\nTarefa carregada com sucesso!\n");
    return 1;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
