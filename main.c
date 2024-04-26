#include "tarefas.h"
#include <stdio.h>

int main() {
  int opcao;
  ERROS erro;

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
      printf("Você selecionou a opção de adicionar contato.\n");
      erro = adicionar_contato();
      if (erro != OK) {
        printf("Erro ao adicionar contato: %d\n", erro);
      }
      break;
    case 2:
      printf("Você selecionou a opção de listar contatos.\n");
      erro = listar_contatos();
      if (erro != OK) {
        printf("Erro ao listar contatos: %d\n", erro);
      }
      break;
    case 3:
      printf("Você selecionou a opção de deletar um contato.\n");
      erro = deletar_contato();
      if (erro != OK) {
        printf("Erro ao deletar contato: %d\n", erro);
      }
      break;
    case 4:
      printf("Você selecionou a opção de salvar agenda.\n");
      erro = salvar_agenda();
      if (erro != OK) {
        printf("Erro ao salvar agenda: %d\n", erro);
      }
      break;
    case 5:
      printf("Você selecionou a opção de carregar agenda.\n");
      erro = carregar_agenda();
      if (erro != OK) {
        printf("Erro ao carregar agenda: %d\n", erro);
      }
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
