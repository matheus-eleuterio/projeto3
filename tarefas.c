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

void adicionar_contato() {}

void listar_contatos() {}

void deletar_contato() {}

void salvar_agenda() {}

void carregar_agenda() {}
