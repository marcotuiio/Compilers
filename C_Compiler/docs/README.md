# Meu Compilador de C, Marco Tulio C Compiler the *mtcc*

###### Sim obvio que sou narcisista a ponto de colocar meu nome no executável

## Versão minimizada do compilador de C, proposta pelo professor da disciplina de Compiladores I e II em 2023.1 e 2023.2. na UEL.

### Objetivo

O objetivo deste projeto é implementar um compilador de C, que seja capaz de compilar um subconjunto da linguagem C, gerando código de máquina para a arquitetura MIPS.

#### Especicicações léxicas, sintáticas, semânticas e geração de código estão inclusas na pasta docs

### Estrutura do projeto

Utiliza flex e bison para a análise léxica e sintática, respectivamente.

Utiliza AST para análise semântica e minimal munch para geração de código.

#### Saídas esperadas e teste estão inclusos na pasta com nomes indicativos

### Compilação

Para compilar o projeto, basta executar o comando `make` na raiz do projeto.

Incluso um simples script em python para testar tudo de uma vez só, apenas altere os diretórios dos arquivos de entrada, saída e src.

### Execução

Para executar o projeto, basta executar o comando `./mtcc <arquivo.c>` na raiz do projeto.

No terminal, será exibido o erro de compilação, caso haja, ou uma mensagem de sucesso, caso contrário.

No mesmo diretório da entrada, será gerado um arquivo `arquivo.asm` com o código de máquina gerado.

### Autor
Marco Tulio Alves de Barros

Melhorias são bem vindas, entre em contato: marcotulio-barros@hotmail.com