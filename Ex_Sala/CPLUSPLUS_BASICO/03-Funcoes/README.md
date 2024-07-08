# Funções em C++

Esta pasta contém exemplos de código que demonstram o uso de funções em C++. Esses exemplos são projetados para ajudar os iniciantes a entender como declarar, definir e usar funções, bem como explorar conceitos avançados como recursão e sobrecarga de funções.

## Arquivos

### function_declaration.cpp

Este exemplo demonstra a declaração e definição de uma função simples, além de como chamá-la.

### parameter_passing.cpp

Este exemplo mostra como passar parâmetros para funções, tanto por valor quanto por referência, e a diferença entre os dois métodos.

### recursion.cpp

Este exemplo ilustra o conceito de recursão, usando uma função recursiva para calcular o fatorial de um número.

### function_overloading.cpp

Este exemplo demonstra a sobrecarga de funções, onde várias funções podem ter o mesmo nome mas diferentes listas de parâmetros.

### inline_functions.cpp

Este exemplo mostra como definir funções inline, que podem melhorar o desempenho ao evitar a sobrecarga de chamadas de função.

## Conceitos

### Declaração e Definição de Funções

- **Declaração de Função**: Informa ao compilador sobre a existência de uma função antes de sua definição real.
- **Definição de Função**: Fornece o corpo real da função, onde a lógica é implementada.

### Passagem de Parâmetros

- **Por Valor**: Passa uma cópia do argumento para a função.
- **Por Referência**: Passa a referência real do argumento, permitindo que a função modifique o valor original.

### Recursão

A recursão ocorre quando uma função chama a si mesma direta ou indiretamente, permitindo a resolução de problemas complexos de forma mais simples e elegante.

### Sobrecarga de Funções

A sobrecarga de funções permite definir múltiplas funções com o mesmo nome, contanto que suas listas de parâmetros sejam diferentes.

### Funções Inline

Funções inline sugerem ao compilador que substitua a chamada da função pelo próprio corpo da função, o que pode melhorar o desempenho.

## Como Executar os Exemplos

Para compilar e executar qualquer um dos exemplos, use um compilador C++ como `g++`:

```sh
g++ function_declaration.cpp -o function_declaration
./function_declaration

g++ parameter_passing.cpp -o parameter_passing
./parameter_passing

g++ recursion.cpp -o recursion
./recursion

g++ function_overloading.cpp -o function_overloading
./function_overloading

g++ inline_functions.cpp -o inline_functions
./inline_functions
