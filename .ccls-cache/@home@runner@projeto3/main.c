#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int opcao;

  do {
    printf("\n1. Adicionar contato\n");
    printf("2. Listar contatos\n");
    printf("3. Deletar contato\n");
    printf("4. Salvar agenda em arquivo binário\n");
    printf("5. Carregar agenda do arquivo binário\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Você selecionou a opção de adicionar contato\n");
      adicionar_contato();
      break;
    case 2:
      printf("Você selecionou a opção de listar contatos\n");
      break;
    case 3:
      printf("Você selecionou a opção de deletar um contato\n");
      break;
    case 4:
      printf("Você selecionou a opção de salvar agenda\n");
      break;
    case 5:
      printf("Você selecionou a opção de carregar agenda\n");
      break;
    case 0:
      printf("Você saiu do programa.\n");
      break;
    default:
      printf("Opção inválida! Entre com uma opção válida ou digite 0 para "
             "sair.\n");
    }
  } while (opcao != 0);

  return 0;
}
