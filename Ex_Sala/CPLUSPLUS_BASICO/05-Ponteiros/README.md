# Ponteiros em C++

Esta pasta contém exemplos de código que demonstram o uso de ponteiros em C++. Esses exemplos são projetados para ajudar os iniciantes a entender como declarar, inicializar e manipular ponteiros, bem como explorar conceitos avançados como aritmética de ponteiros e ponteiros para funções.

## Arquivos

### pointers_basics.cpp

Este exemplo demonstra a declaração e uso básico de ponteiros, incluindo a obtenção de endereços de variáveis e a desreferenciação de ponteiros.

### pointers_arithmetic.cpp

Este exemplo mostra a aritmética de ponteiros, que permite mover o ponteiro através de um array.

### pointers_to_arrays.cpp

Este exemplo ilustra como passar arrays para funções usando ponteiros e como acessar os elementos do array através do ponteiro.

### function_pointers.cpp

Este exemplo demonstra o uso de ponteiros para funções, permitindo que funções sejam passadas como argumentos para outras funções.

### null_void_pointers.cpp

Este exemplo mostra o uso de ponteiros nulos (`nullptr`) e ponteiros void (`void*`), que podem apontar para qualquer tipo de dado.

## Conceitos

### Ponteiros

- **Declaração e Inicialização**: Ponteiros são declarados usando o operador `*` e inicializados com o endereço de uma variável.
- **Desreferenciação**: O operador `*` é usado para acessar o valor apontado pelo ponteiro.

### Aritmética de Ponteiros

- **Incremento/Decremento**: Ponteiros podem ser incrementados ou decrementados para apontar para elementos adjacentes em um array.

### Ponteiros para Arrays

- **Passagem para Funções**: Arrays podem ser passados para funções usando ponteiros, permitindo a manipulação dos elementos do array dentro da função.

### Ponteiros para Funções

- **Declaração**: Ponteiros para funções são declarados usando a sintaxe `void (*ptr)()`.
- **Chamada de Funções**: Ponteiros para funções podem ser usados para chamar a função para a qual apontam.

### Ponteiros Nulos e Void

- **Ponteiros Nulos**: Um ponteiro nulo (`nullptr`) não aponta para nenhum endereço válido.
- **Ponteiros Void**: Um ponteiro void (`void*`) pode apontar para qualquer tipo de dado, mas deve ser convertido para um tipo específico antes de ser desreferenciado.

## Como Executar os Exemplos

Para compilar e executar qualquer um dos exemplos, use um compilador C++ como `g++`:

```sh
g++ pointers_basics.cpp -o pointers_basics
./pointers_basics

g++ pointers_arithmetic.cpp -o pointers_arithmetic
./pointers_arithmetic

g++ pointers_to_arrays.cpp -o pointers_to_arrays
./pointers_to_arrays

g++ function_pointers.cpp -o function_pointers
./function_pointers

g++ null_void_pointers.cpp -o null_void_pointers
./null_void_pointers
