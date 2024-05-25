#include "tarefas.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ERROS escolher_agenda() {
  int escolha;
  do {
    printf("Qual agenda você deseja acessar? (1 - Pessoal | 2 - Trabalho): ");
    scanf("%d", &escolha);
  } while (escolha != 1 && escolha != 2);
  return escolha;
}

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

  if (verificar_telefone(agenda, *qnt_contatos,
                         agenda[*qnt_contatos].telefone) == TELEFONE_EXISTE) {
    return TELEFONE_EXISTE;
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
    }
  }

  if (!contato_existe) {
    return NAO_ENCONTRADO;
  }
  return OK;
}

ERROS salvar_agenda(Contato *agenda, int qnt_contatos, const char *nome_arquivo,
                    int tipo_agenda) {
  FILE *arquivo = fopen(nome_arquivo, "wb");

  if (arquivo == NULL) {
    return ABRIR;
  }

  fwrite(&tipo_agenda, sizeof(int), 1, arquivo);
  fwrite(&qnt_contatos, sizeof(int), 1, arquivo);
  fwrite(agenda, sizeof(Contato), qnt_contatos, arquivo);
  fclose(arquivo);
  return OK;
}

ERROS carregar_agenda(Contato *agenda, int *qnt_contatos,
                      const char *nome_arquivo, int *tipo_agenda) {
  FILE *arquivo = fopen(nome_arquivo, "rb");

  if (arquivo == NULL) {
    return ABRIR;
  }

  fread(tipo_agenda, sizeof(int), 1, arquivo);
  fread(qnt_contatos, sizeof(int), 1, arquivo);
  fread(agenda, sizeof(Contato), *qnt_contatos, arquivo);
  fclose(arquivo);

  return OK;
}

ERROS validar_email(const char *email) {
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
    return 1; // 1 quando valida positivo
  } else {
    return 0; // 0 pra quando falha
  }
}

ERROS verificar_telefone(Contato *agenda, int qnt_contatos,
                         const char *telefone) {
  for (int i = 0; i < qnt_contatos; i++) {
    if (strcmp(agenda[i].telefone, telefone) == 0) {
      return TELEFONE_EXISTE;
    }
  }
  return OK;
}

ERROS editar_contato(Contato *agenda, int qnt_contatos) {
  if (qnt_contatos == 0) {
    return SEM_CONTATOS;
  }
  char telefone[15];
  printf("Digite o telefone do contato que deseja editar: ");
  scanf(" %[^\n]", telefone);
  clearBuffer();

  for (int i = 0; i < qnt_contatos; i++) {
    if (strcmp(agenda[i].telefone, telefone) == 0) {
      int opcao;
      printf("\nSelecione o que deseja editar:\n");
      printf("1. Nome\n");
      printf("2. Sobrenome\n");
      printf("3. E-mail\n");
      printf("4. Telefone\n");
      printf("0. Cancelar\n");
      printf("Escolha uma opção: ");
      scanf("%d", &opcao);
      clearBuffer();

      if (opcao < 0 || opcao > 4) {
        return OPCAO_INVALIDA;
      }

      switch (opcao) {
      case 1:
        printf("\nDigite o novo nome: ");
        scanf(" %[^\n]", agenda[i].nome);
        break;
      case 2:
        printf("\nDigite o novo sobrenome: ");
        scanf(" %[^\n]", agenda[i].sobrenome);
        break;
      case 3:
        printf("\nDigite o novo e-mail: ");
        scanf(" %[^\n]", agenda[i].email);
        break;
      case 4:
        printf("\nDigite o novo telefone: ");
        scanf(" %[^\n]", agenda[i].telefone);
        break;
      case 0:
        printf("\nOperação cancelada.\n");
      }
      return OK;
    }
  }
  return NAO_ENCONTRADO;
}


void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

const char *mensagemErro(ERROS erro) {
  switch (erro) {
  case OK:
    return "Operação realizada com sucesso.\n";

  case MAX_CONTATOS:
    return "A agenda atingiu seu limite máximo de contatos. Não é possível "
           "adicionar mais contatos.";

  case SEM_CONTATOS:
    return "A agenda não possui contatos.";

  case NAO_ENCONTRADO:
    return "Não foi possível encontrar o contato. Verifique o número "
           "digitado.";

  case ABRIR:
    return "Erro ao abrir arquivo.";

  case EMAIL_INVALIDO:
    return "Insira um e-mail válido.";

  case TELEFONE_EXISTE:
    return "Esse telefone já consta em nossa agenda. Insira outro número.";

  case OPCAO_INVALIDA:
    return "Opção inválida! Selecione uma opção de 1 a 4.";

  case CANCELAR:
    return "Operação cancelada";

  default:
    return "Erro desconhecido.";
  }
}