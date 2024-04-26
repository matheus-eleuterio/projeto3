#ifndef TAREFAS_H
#define TAREFAS_H

#define LIMITE_CONTATOS 255

typedef struct {
  char nome[20];
  char sobrenome[40];
  char email[80];
  char telefone[11];
} Contato;

extern Contato agenda[LIMITE_CONTATOS];
extern int qnt_contatos;

typedef enum {
  OK,
  MAX_CONTATOS,
  SEM_CONTATOS,
  NAO_ENCONTRADO,
  ABRIR,
  FECHAR,
  ESCREVER,
  LER
} ERROS;

ERROS adicionar_contato();
ERROS listar_contatos();
ERROS deletar_contato();
ERROS salvar_agenda();
ERROS carregar_agenda();

#endif
