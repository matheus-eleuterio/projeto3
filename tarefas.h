#ifndef TAREFAS_H
#define TAREFAS_H

#define LIMITE_CONTATOS 255


typedef struct {
  char nome[20];
  char sobrenome[40];
  char email[80];
  char telefone[11];
} Contato;

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

void clearBuffer();

const char *mensagemErro(ERROS erro);


typedef struct {
  char nome[20];
  char sobrenome[40];
  char email[80];
  char telefone[11];
} Contato;

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

void clearBuffer();

const char *mensagemErro(ERROS erro);

#endif
