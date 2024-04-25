#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 255

struct Contato {
  char nome[20];
  char sobrenome[40];
  char email[80];
  char telefone[11];
};

struct Contato agenda[MAX_CONTATOS];
int qnt_contatos = 0;

void adicionar_contato() {
  if (qnt_contatos >= MAX_CONTATOS) {
    printf("\nA agenda atingiu seu limite máximo de contatos. Não é possível "
           "adicionar mais contatos.\n");
    return;
  }
  printf("\nNome: ");
  scanf(" %[^\n]", agenda[qnt_contatos].nome);
  printf("Sobrenome: ");
  scanf(" %[^\n]", agenda[qnt_contatos].sobrenome);
  printf("E-mail: ");
  scanf(" %[^\n]", agenda[qnt_contatos].email);
  printf("Telefone (DDD+apenas números): ");
  scanf(" %[^\n]", agenda[qnt_contatos].telefone);
  qnt_contatos++;

  printf("Contato adicionado a agenda com sucesso!\n");
}

void listar_contatos() {
  if (qnt_contatos == 0) {
    printf("\nA agenda não possui contatos.\n");
    return;
  }

  printf("\nLista de contatos:\n");
  for (int i = 0; i < qnt_contatos; i++) {
    printf("\n%d) Nome: %s %s | Email: %s | Telefone: %s\n", i + 1,
           agenda[i].nome, agenda[i].sobrenome, agenda[i].email,
           agenda[i].telefone);
  }

  getchar();
}

void deletar_contato() {
  if (qnt_contatos == 0) {
    printf("\nNão existem contatos para deletar!\n");
    return;
  }
  char telefone[15];
  printf("\nDigite o telefone do contato que deseja deletar: ");
  scanf(" %[^\n]", telefone);

  int contato_existe = 0;
  for (int i = 0; i < qnt_contatos; i++) {
    if (strcmp(telefone, agenda[i].telefone) == 0) {
      contato_existe = 1;
      for (int j = i; j < qnt_contatos - 1; j++) {
        agenda[j] = agenda[j + 1];
      }
      qnt_contatos--;
      printf("Contato deletado com sucesso!\n");
      break;
    }
  }

  if (!contato_existe) {
    printf(
        "Não foi possível encontrar o contato. Verifique o número digitado.\n");
  }
}

void salvar_agenda() {
  FILE *arquivo = fopen("agenda.bin", "wb");

  if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo!\n");
      return;
  }

  fwrite(agenda, sizeof(struct Contato), qnt_contatos, arquivo);
  fclose(arquivo);

  printf("\nAgenda salva em arquivo binário!\n");
}

void carregar_agenda() {}
