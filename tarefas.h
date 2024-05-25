#ifndef TAREFAS_H
#define TAREFAS_H

#include <regex.h>

#define LIMITE_CONTATOS 255
#define ARQUIVO_PESSOAL "agenda_pessoal.bin"
#define ARQUIVO_TRABALHO "agenda_trabalho.bin"

typedef struct {
    char nome[50];
    char sobrenome[50];
    char email[80];
    char telefone[15];
} Contato;

typedef enum {
    OK,   
    MAX_CONTATOS,
    SEM_CONTATOS,
    NAO_ENCONTRADO,
    ABRIR,
    EMAIL_INVALIDO,
    TELEFONE_EXISTE,
    OPCAO_INVALIDA,
    CANCELAR
} ERROS;

ERROS adicionar_contato(Contato *agenda, int *qnt_contatos);
ERROS listar_contatos(Contato *agenda, int qnt_contatos);
ERROS deletar_contato(Contato *agenda, int *qnt_contatos);
ERROS salvar_agenda(Contato *agenda, int qnt_contatos, const char *nome_arquivo, int tipo_agenda);
ERROS carregar_agenda(Contato *agenda, int *qnt_contatos, const char *nome_arquivo, int *tipo_agenda);
ERROS validar_email(const char *email);
ERROS verificar_telefone(Contato *agenda, int qnt_contatos, const char *telefone);
ERROS editar_contato(Contato *agenda, int qnt_contatos);
ERROS escolher_agenda();

void clearBuffer();
const char *mensagemErro(ERROS erro);

#endif