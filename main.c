#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

int main() {
  Contato agenda_pessoal[LIMITE_CONTATOS];
  Contato agenda_trabalho[LIMITE_CONTATOS];
  int qnt_contatos_pessoal = 0;
  int qnt_contatos_trabalho = 0;
  int tipo_agenda = escolher_agenda();
  Contato *agenda;
  int *qnt_contatos;
  const char *nome_arquivo;

  if (tipo_agenda == 1) {
    agenda = agenda_pessoal;
    qnt_contatos = &qnt_contatos_pessoal;
    nome_arquivo = ARQUIVO_PESSOAL;
  } else {
    agenda = agenda_trabalho;
    qnt_contatos = &qnt_contatos_trabalho;
    nome_arquivo = ARQUIVO_TRABALHO;
  }

  int opcao;
  ERROS erro;

  while (1) {
    if (tipo_agenda == 1) {
      printf("\nMenu da agenda pessoal:\n");
    } else {
      printf("\nMenu da agenda de trabalho:\n");
    }
    printf("\n1. Adicionar contato\n");
    printf("2. Listar contatos\n");
    printf("3. Deletar contato\n");
    printf("4. Salvar agenda em arquivo binário\n");
    printf("5. Carregar agenda do arquivo binário\n");
    printf("6. Editar contato\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Você selecionou a opção de adicionar contato.\n");
      erro = adicionar_contato(agenda, qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao adicionar contato: %s\n\n", mensagemErro(erro));
      } else {
        printf("\n\n%s\n", mensagemErro(erro));
      }
      break;
    case 2:
      printf("Você selecionou a opção de listar contatos.\n");
      erro = listar_contatos(agenda, *qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao listar contatos: %s\n\n", mensagemErro(erro));
      }
      break;
    case 3:
      printf("Você selecionou a opção de deletar contato.\n");
      erro = deletar_contato(agenda, qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao deletar contato: %s\n\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 4:
      printf("Você selecionou a opção de salvar agenda em arquivo binário.\n");
      erro = salvar_agenda(agenda, *qnt_contatos, nome_arquivo, tipo_agenda);
      if (erro != OK) {
        printf("\nErro ao salvar agenda: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 5:
      printf(
          "Você selecionou a opção de carregar agenda do arquivo binário.\n");
      erro = carregar_agenda(agenda, qnt_contatos, nome_arquivo, &tipo_agenda);
      if (erro != OK) {
        printf("\nErro ao carregar agenda: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 6:
      printf("Você selecionou a opção de alterar contato.\n");
      erro = editar_contato(agenda, *qnt_contatos);
      if (erro != OK) {
        printf("\nErro ao editar contato: %s\n", mensagemErro(erro));
      } else {
        printf("\n%s\n", mensagemErro(erro));
      }
      break;
    case 0:
      printf("\nVocê saiu do programa.\n");
      exit(0);
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  }
  return 0;
}