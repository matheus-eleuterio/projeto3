#ifndef TAREFAS_H
#define TAREFAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 255

typedef enum {
  OK,
  ERRO_MAX_CONTATOS,
  ERRO_SEM_CONTATOS,
  ERRO_NAO_ENCONTRADO,
  ERRO_ABRIR,
  ERRO_FECHAR,
  ERRO_ESCREVER,
  ERRO_LER
} ERROS;

struct Contato {
  char nome[20];
  char sobrenome[40];
  char email[80];
  char telefone[11];
};

extern struct Contato agenda[MAX_CONTATOS];
extern int qnt_contatos;

void adicionar_contato();
void listar_contatos();
void deletar_contato();
void salvar_agenda();
ERROS carregar_agenda();

#endif
