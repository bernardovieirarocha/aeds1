# Estruturas e Uniões em C++

Esta pasta contém exemplos de código que demonstram o uso de estruturas e uniões em C++. Esses exemplos são projetados para ajudar os iniciantes a entender como declarar, inicializar e manipular essas construções de dados.

## Arquivos

### structures.cpp

Este exemplo demonstra a declaração e uso básico de estruturas, incluindo a inicialização e acesso aos membros da estrutura.

### unions.cpp

Este exemplo mostra a declaração e uso de uniões, que permitem armazenar diferentes tipos de dados no mesmo espaço de memória.

### nested_structures.cpp

Este exemplo ilustra como definir e usar estruturas aninhadas, onde uma estrutura contém outra estrutura como membro.

## Conceitos

### Estruturas

- **Declaração**: Estruturas são definidas usando a palavra-chave `struct` seguida do nome da estrutura e dos membros entre chaves.
- **Inicialização**: Estruturas podem ser inicializadas atribuindo valores a seus membros.
- **Acesso aos Membros**: Membros da estrutura são acessados usando o operador `.` (ponto).

### Uniões

- **Declaração**: Uniões são definidas usando a palavra-chave `union` e permitem armazenar diferentes tipos de dados no mesmo espaço de memória.
- **Uso**: Apenas um dos membros da união pode armazenar um valor válido a qualquer momento.

### Estruturas Aninhadas

- **Definição**: Estruturas aninhadas são definidas declarando uma estrutura dentro de outra.
- **Acesso**: Membros da estrutura aninhada são acessados usando uma sequência de operadores `.` (ponto).

## Como Executar os Exemplos

Para compilar e executar qualquer um dos exemplos, use um compilador C++ como `g++`:

```sh
g++ structures.cpp -o structures
./structures

g++ unions.cpp -o unions
./unions

g++ nested_structures.cpp -o nested_structures
./nested_structures
