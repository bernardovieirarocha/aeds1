# Conceitos Básicos de C++

Esta pasta contém exemplos de código que cobrem os conceitos básicos da programação em C++. Esses exemplos são projetados para ajudar os iniciantes a entender a sintaxe e as construções fundamentais da linguagem.

## Arquivos

### basic_syntax.cpp

Este exemplo demonstra a sintaxe básica de um programa C++, incluindo comentários, a função `main`, e a exibição de mensagens na tela.

### data_types.cpp

Este exemplo mostra os diferentes tipos de dados básicos em C++, como inteiros, números de ponto flutuante, caracteres e booleanos. Ele também demonstra como declarar variáveis e exibir seus valores.

### variables_and_constants.cpp

Este exemplo ilustra como declarar e usar variáveis e constantes em C++. Ele inclui operações aritméticas básicas e a exibição de resultados.

## Conceitos

### Sintaxe Básica

A sintaxe básica de um programa C++ inclui a definição da função `main`, que é o ponto de entrada do programa. Comentários podem ser adicionados para melhorar a legibilidade do código.

### Tipos de Dados

C++ suporta vários tipos de dados básicos, incluindo:
- `int`: Inteiros
- `float`: Números de ponto flutuante de precisão simples
- `double`: Números de ponto flutuante de dupla precisão
- `char`: Caracteres individuais
- `bool`: Valores booleanos (`true` ou `false`)

### Variáveis e Constantes

- **Variáveis** são usadas para armazenar dados que podem mudar durante a execução do programa.
- **Constantes** são valores imutáveis definidos usando a palavra-chave `const`.

## Como Executar os Exemplos

Para compilar e executar qualquer um dos exemplos, use um compilador C++ como `g++`:

```sh
g++ basic_syntax.cpp -o basic_syntax
./basic_syntax

g++ data_types.cpp -o data_types
./data_types

g++ variables_and_constants.cpp -o variables_and_constants
./variables_and_constants
```