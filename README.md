# Projeto: Agenda de contatos, parte 2

### Descrição

Este projeto consiste em desenvolver uma aplicação de agenda de contatos em linguagem C. A aplicação permite ao usuário adicionar, listar, deletar e editar contatos de duas agendas (Pessoal e Trabalho). Além disso, a agenda pode ser salva e carregada a partir de um arquivo binário.

### Funcionalidades

1. Seleção de agenda: Permite ao usuário selecionar em qual tipo de agenda ele quer salvar determinado contato, sendo elas: Agenda Pessoal e Agenda de Trabalho.
1. Adicionar Contato: Permite adicionar um novo contato fornecendo nome, sobrenome, e-mail e telefone.
2. Listar Contatos: Exibe uma lista de todos os contatos cadastrados, mostrando nome, sobrenome, e-mail e telefone.
3. Deletar Contato: Permite deletar um contato da agenda fornecendo o telefone do contato a ser deletado.
4. Salvar Agenda: Salva a agenda de contatos selcionada pelo usuário em um arquivo binário para persistência de dados.
5. Carregar Agenda: Carrega a agenda de contatos selecionada pelo usuário a partir de um arquivo binário.
6. Editar Contato: Permite editar as informações de um contato, como nome, sobrenome, e-mail e telefone.
7. Validar e verificar o e-mail: O programa válida se o e-mail é um e-mail válido (abc@def.com) e depois verifica se já existe algum contato cadastrado com esse e-mail.
8. Validar e verificar o telefone: O programa válida se o telefone é um telefone válido (DDD+número) e depois verifica se já existe algum contato cadastrado com esse número de telefone.

### Estrutura do Projeto

- *main.c*: main.c: Contém a função principal do programa e o menu de navegação.
- *tarefas.c*: Implementa as funções de operações da agenda, como adicionar contato, listar contatos, deletar contato, editar contato, salvar agenda e carregar agenda.
- *tarefas.h*: Cabeçalho do programa, onde são definidas as estruturas de dados utilizadas e os protótipos das funções.

**Execução do código**

Siga os passos:

1) É necessário ter um compilador de C instalado na sua máquina. Neste projeto usaremos o GCC.
2) Abra o terminal na pasta que esta salvo os arquivos que compoem o projeto.
3) Digite "gcc main.c tarefas.c -o "agenda" no terminal para compilar o programa.
4) Digite "./agenda" no terminal para executar o programa.
5) Selecione uma das opções apresentadas no menu.

Projeto desenvolvido por Matheus Eleutério, Danilo Chiarelli e Jeferson Roque para a disciplina CC2632.
