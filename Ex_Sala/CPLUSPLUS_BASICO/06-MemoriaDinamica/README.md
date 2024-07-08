# Alocação Dinâmica em C++

Este diretório contém exemplos de código que demonstram como usar a alocação dinâmica de memória em C++. A alocação dinâmica é uma técnica que permite alocar memória em tempo de execução, ao invés de em tempo de compilação, proporcionando maior flexibilidade e uso eficiente de recursos.

## Arquivos

### alocacaodinamica.cpp

- Este exemplo demonstra a alocação e desalocação de memória para variáveis simples usando `new` e `delete`.
- Este exemplo mostra como alocar e desalocar memória para arrays dinâmicos, além de inicializar e acessar seus elementos.
- Este exemplo ilustra a alocação dinâmica de arrays multidimensionais usando ponteiros de ponteiros, mostrando a diferença em complexidade em comparação com arrays unidimensionais.

### smart_pointers.cpp

Este exemplo ilustra o uso de `smart pointers` (`unique_ptr`, `shared_ptr` e `weak_ptr`) para gerenciar memória automaticamente e evitar vazamentos de memória.

## Conceitos

### Alocação Dinâmica

A alocação dinâmica permite ao programador requisitar memória durante a execução do programa. Isso é feito usando os operadores `new` e `delete`.

- `new`: Aloca memória no heap e retorna um ponteiro para essa memória.
- `delete`: Desaloca a memória previamente alocada com `new`.

### Arrays Dinâmicos

Arrays dinâmicos permitem que o tamanho do array seja determinado durante a execução do programa. Eles são alocados usando `new[]` e desalocados usando `delete[]`.

### Smart Pointers

Smart pointers são uma funcionalidade introduzida na biblioteca padrão do C++ para ajudar a gerenciar a memória automaticamente. Eles garantem que a memória será desalocada quando o smart pointer sair de escopo.

- `unique_ptr`: Garante que apenas um ponteiro possua o recurso.
- `shared_ptr`: Permite que múltiplos ponteiros compartilhem a posse do recurso.
- `weak_ptr`: Proporciona uma referência não possessiva que não impede que o recurso seja desalocado.

## Como Executar os Exemplos

Para compilar e executar qualquer um dos exemplos, use um compilador C++ como `g++`:

```sh
g++ dynamic_allocation.cpp -o dynamic_allocation
./dynamic_allocation

g++ dynamic_arrays.cpp -o dynamic_arrays
./dynamic_arrays

g++ smart_pointers.cpp -o smart_pointers
./smart_pointers
```
