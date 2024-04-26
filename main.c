#include "tarefas.h"
#include <stdio.h>

int main() {
  Contato agenda[LIMITE_CONTATOS];
  int qnt_contatos = 0;
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
      erro = adicionar_contato(agenda, &qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao adicionar contato: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;

    case 2:
      printf("Você selecionou a opção de listar contatos.\n");
      erro = listar_contatos(agenda, qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao listar contatos: %s\n", mensagemErro(erro));
      }
      break;
    case 3:
      printf("Você selecionou a opção de deletar um contato.\n");
      erro = deletar_contato(agenda, &qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao deletar contato: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 4:
      printf("Você selecionou a opção de salvar agenda.\n");
      erro = salvar_agenda(agenda, qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao salvar agenda: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 5:
      printf("Você selecionou a opção de carregar agenda.\n");
      erro = carregar_agenda(agenda, &qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao carregar agenda: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 0:
      printf("\nVocê saiu do programa.\n");
      break;
    default:
      if (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 &&
          opcao != 5) {
        printf("\nOpção inválida. Tente novamente.\n");
      }
    }
  } while (opcao != 0);

  return 0;
}