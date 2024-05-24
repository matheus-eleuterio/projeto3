#include "tarefas.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ERROS adicionar_contato(Contato *agenda, int *qnt_contatos) {
  if (*qnt_contatos >= LIMITE_CONTATOS) {
    return MAX_CONTATOS;
  }

  printf("\nNome: ");
  scanf(" %[^\n]", agenda[*qnt_contatos].nome);
  printf("Sobrenome: ");
  scanf(" %[^\n]", agenda[*qnt_contatos].sobrenome);

  char email[80];
  printf("E-mail: ");
  scanf(" %[^\n]", email);

  if (!validar_email(email)) {
    return EMAIL_INVALIDO;
  }

  strcpy(agenda[*qnt_contatos].email, email);

  printf("Telefone (DDD+apenas números): ");
  scanf(" %[^\n]", agenda[*qnt_contatos].telefone);
  if (!validar_email(email)) {
    return EMAIL_INVALIDO;
  }

  (*qnt_contatos)++;
  return OK;
}

ERROS listar_contatos(Contato *agenda, int qnt_contatos) {
  if (qnt_contatos == 0) {
    return SEM_CONTATOS;
  }

  printf("\nLista de contatos:\n");
  for (int i = 0; i < qnt_contatos; i++) {
    printf("\n%d) Nome: %s %s | Email: %s | Telefone: %s\n", i + 1,
           agenda[i].nome, agenda[i].sobrenome, agenda[i].email,
           agenda[i].telefone);
  }
  clearBuffer();
  return OK;
}

ERROS deletar_contato(Contato *agenda, int *qnt_contatos) {
  if (*qnt_contatos == 0) {
    return SEM_CONTATOS;
  }

  char telefone[15];
  printf("\nDigite o telefone do contato que deseja deletar: ");
  scanf(" %[^\n]", telefone);

  int contato_existe = 0;
  for (int i = 0; i < *qnt_contatos; i++) {
    if (strcmp(telefone, agenda[i].telefone) == 0) {
      contato_existe = 1;
      for (int j = i; j < *qnt_contatos - 1; j++) {
        agenda[j] = agenda[j + 1];
      }
      (*qnt_contatos)--;
      return OK;
      break;
    }
  }

  if (!contato_existe) {
    return NAO_ENCONTRADO;
  }
  return OK;
}

ERROS salvar_agenda(Contato *agenda, int qnt_contatos) {
  FILE *arquivo = fopen("agenda.bin", "wb");

  if (arquivo == NULL) {
    return ABRIR;
  }

  fwrite(agenda, sizeof(Contato), qnt_contatos, arquivo);
  fclose(arquivo);
  return OK;
}

ERROS carregar_agenda(Contato *agenda, int *qnt_contatos) {
  FILE *arquivo = fopen("agenda.bin", "rb");

  if (arquivo == NULL) {
    return ABRIR;
  }

  *qnt_contatos = fread(agenda, sizeof(Contato), LIMITE_CONTATOS, arquivo);
  fclose(arquivo);

  return OK;
}

ERROS validar_email(char *email) {
  regex_t regex;
  int reti;
  reti = regcomp(&regex, "[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}",
                 REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "!!Erro!!\n");
    return 0;
  }
  reti = regexec(&regex, email, 0, NULL, 0);
  regfree(&regex);
  if (!reti) {
    return 1; // 1 quando valida posito
  } else {
    return 0; // 0 pra quando falha
  }
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

const char *mensagemErro(ERROS erro) {
  switch (erro) {
  case OK:
    return "Operação realizada com sucesso.";

  case MAX_CONTATOS:
    return "A agenda atingiu seu limite máximo de contatos. Não é possível "
           "adicionar mais contatos.";

  case SEM_CONTATOS:
    return "A agenda não possui contatos.";

  case NAO_ENCONTRADO:
    return "Não foi possível encontrar o contato. Verifique o número "
           "digitado";

  case ABRIR:
    return "Erro ao abrir arquivo.";

  case EMAIL_INVALIDO:
    return "Insira um e-mail válido.";

  default:
    return "Erro desconhecido.";
  }
}
