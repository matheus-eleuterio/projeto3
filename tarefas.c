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
    printf("A agenda atingiu seu limite máximo de contatos. Não é possível "
           "adicionar mais contatos.\n");
    return;
  }
  printf("\nNome: ");
  scanf("%s", agenda[qnt_contatos].nome);
  printf("Sobrenome: ");
  scanf("%s", agenda[qnt_contatos].sobrenome);
  printf("E-mail: ");
  scanf("%s", agenda[qnt_contatos].email);
  printf("Telefone (DDD+apenas números): ");
  scanf("%s", agenda[qnt_contatos].telefone);
  qnt_contatos++;

  printf("Contato adicionado a agenda com sucesso!\n");
}

void listar_contatos() {}

void deletar_contato() {}

void salvar_agenda() {}

void carregar_agenda() {}
