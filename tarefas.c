#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_CONTATOS 255

Contato agenda[LIMITE_CONTATOS];
int qnt_contatos = 0;

ERROS adicionar_contato() {
  if (qnt_contatos >= LIMITE_CONTATOS) {
    printf("\nA agenda atingiu seu limite máximo de contatos. Não é possível "
           "adicionar mais contatos.\n");
    return MAX_CONTATOS;
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

  printf("\nContato adicionado na agenda com sucesso!\n");
  return OK;
}

ERROS listar_contatos() {
  if (qnt_contatos == 0) {
    printf("\nA agenda não possui contatos.\n");
    return SEM_CONTATOS; // Vinculando o erro SEM_CONTATOS à função
  }

  printf("\nLista de contatos:\n");
  for (int i = 0; i < qnt_contatos; i++) {
    printf("\n%d) Nome: %s %s | Email: %s | Telefone: %s\n", i + 1,
           agenda[i].nome, agenda[i].sobrenome, agenda[i].email,
           agenda[i].telefone);
  }

  getchar(); // Limpar o buffer
  return OK;
}

ERROS deletar_contato() {
  if (qnt_contatos == 0) {
    printf("\nNão existem contatos para deletar!\n");
    return SEM_CONTATOS;
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
      printf("\nContato deletado com sucesso!\n");
      break;
    }
  }

  if (!contato_existe) {
    printf(
        "Não foi possível encontrar o contato. Verifique o número digitado.\n");
    return NAO_ENCONTRADO;
  }

  return OK;
}

ERROS salvar_agenda() {
  FILE *arquivo = fopen("agenda.bin", "wb");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return ABRIR;
  }

  fwrite(agenda, sizeof(Contato), qnt_contatos, arquivo);
  fclose(arquivo);

  printf("\nAgenda salva em arquivo binário!\n");
  return OK;
}

ERROS carregar_agenda() {
  FILE *arquivo = fopen("agenda.bin", "rb");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo!\n");
    return ABRIR;
  }

  qnt_contatos = fread(agenda, sizeof(Contato), LIMITE_CONTATOS, arquivo);
  fclose(arquivo);

  printf("\nAgenda carregada do arquivo binário!\n");
  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

