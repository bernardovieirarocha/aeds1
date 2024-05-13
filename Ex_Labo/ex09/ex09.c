// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados. ENUNCIADO: Faça um programa
// que leia as dimensões N e M de uma matriz (i.e., linhas e colunas) e a opção
// desejada pelo usuário, sendo uma das seguintes:

// 1. Dobrar o valor de todo elemento dentro da matriz

// 2. Transpor a matriz

// 3. Espelhar a matriz no sentido horizontal

// 4. Espelhar a matriz no sentido vertical

// 5. Espelhar a matriz na diagonal

// A linha seguinte da entrada contém os valores da matriz de maneira vetorizada
// (ou seja, na forma 1 x (N*M) ). Após a realização de qualquer uma das
// operações acima, deve-se imprimir a matriz na forma não vetorizada. Ou seja,
// X x Y onde X é a quantidade de linhas e Y a quantidade de colunas da matriz
// resultante.

// RESTRIÇÕES: Não se pode utilizar nenhum conceito (ainda) não visto em sala de
// aula. É OBRIGATÓRIO o uso da modularização, incluindo para ler e imprimir a
// matriz, e TODAS as funções devem ser feitas usando RECURSÃO. NÃO É PERMITIDO
// o uso de variáveis globais e do operador []. Além disso, NÃO SE PODE utilizar
// conceitos (ainda) não vistos em sala de aula.

#include <stdio.h>
#include <stdlib.h>

void ler_dados(int *matriz, int l, int c, int indice) {
  // Se o indice for igual ao total de numeros na matriz acabou a leitura
  if (indice == l * c) {
    return;
  }
  // Ler os numeros pulando o ponteiro 1 sizeof(int) a cada chamada até a parada
  scanf("%d%*c", matriz + indice);
  // Funcao recursiva que incrementa o indice
  return ler_dados(matriz, l, c, indice + 1);
}

void imprimir_dados(int *matriz, int l, int c, int indice) {
  // Se o contador  for igual ao total de numeros da matriz acabou a impressao,
  // foram perpassados todos os numeros
  if (indice == l * c) {
    return;
  }
  // Imprmir o valor *() de cada espaço de sizeof(int) alocado na matriz.
  printf("%d ", *(matriz + indice));
  // Verifica se o indice atual excede o numero de colunas e se sim eh preciso
  // pular a linha
  if ((indice + 1) % c == 0) {
    printf("\n");
  }
  return imprimir_dados(matriz, l, c, indice + 1);
}

void dobrar_valores(int *matriz, int l, int c, int indice) {
  // Se o contador  for igual ao total de numeros da matriz, perspassou todos os
  // numeros e acabou a execucao desse funcao
  if (indice == l * c) {
    return;
  }
  // Pega o valor da matriz na posicao atual e dobra e logo depois atribui esse
  // valor para aquela mesma posicao
  int temp = *(matriz + indice) * 2;
  *(matriz + indice) = temp;
  // Incrementa o indice para avançar as posicoes
  return dobrar_valores(matriz, l, c, indice + 1);
}

void transpor_matriz(int *matriz, int *matrizT, int l, int c, int i, int j) {
  //  Quando i atinge o número de linhas l, a função retorna, indicando que a
  //  transposição foi concluída, uma vez que i e j percorrem a matriz.
  if (i == l) {
    return;
  }
  // O elemento da matriz original na posição (i, j) é copiado para a posição
  // (j, i) na matriz transposta matrizT.
  *(matrizT + (j * l) + i) = *(matriz + (i * c) + j);

  // Se j atingir c - 1, a função recursivamente avança para a próxima linha (i
  // + 1) e reseta j para 0; caso contrário, incrementa j.
  if (j == c - 1) {
    return transpor_matriz(matriz, matrizT, l, c, i + 1, 0);
  }
  return transpor_matriz(matriz, matrizT, l, c, i, j + 1);
}

int *espelhar_horizontal(int *matriz, int *matrizE, int l, int c, int i,
                         int j) {
  //  Quando i atinge o numero de linhas l, a funcao retorna o ponteiro para
  //  poder ser passada como parametro no espelhamento diagonal.
  if (i == l) {
    return matrizE;
  }
  // o elemento da matriz original na posição (i, j) é copiado para a posição
  // (i, c - (j + 1)) na matriz espelhada matrizE. Isso significa que elemento
  // correspondente é copiado para a mesma linha i, porém na coluna oposta. Isso
  // garante que a matriz resultante seja um espelhamento horizontal da matriz
  // original.
  *(matrizE + (i * c) + (c - (j + 1))) = *(matriz + (i * c) + j);
  // Se j atingir o numero de colunas c - 1, significa que a linha atual foi
  // completamente espelhada, então de forma recursiva passa pra próxima linha
  // (i + 1) e reinicia a contagem das colunas (j = 0). Caso contrário, a
  // funcao incrementa j e continua a copiar os elementos da linha atual.
  if (j == c - 1) {
    return espelhar_horizontal(matriz, matrizE, l, c, i + 1, 0);
  }
  return espelhar_horizontal(matriz, matrizE, l, c, i, j + 1);
}

int *espelhar_vertical(int *matriz, int *matrizE, int l, int c, int i, int j) {
  // Quando i atinge o número de linhas l, a função retorna a matriz espelhada
  // matrizE.
  if (i == l) {
    return matrizE;
  }
  // Para cada elemento na posição (i, j) da matriz original, ele é copiado para
  // a posição (l - i - 1, j) na matriz espelhada matrizE.  Para, assim
  // ,espelhar verticalmente, mantendo a coluna como j, isto é preservando a
  // coluna atual na matriz original.
  *(matrizE + ((l - i - 1) * c) + j) = *(matriz + (i * c) + j);

  // Se j atingir o número de colunas c - 1, a função chama recursivamente
  // espelhar_vertical para a próxima linha (i + 1). Caso contrário, a função
  // incrementa j e continua a copiar os elementos da linha atual.
  if (j == c - 1) {
    return espelhar_vertical(matriz, matrizE, l, c, i + 1, 0);
  }
  return espelhar_vertical(matriz, matrizE, l, c, i, j + 1);
}

void espelhar_diagonal(int *matriz, int *matrizE, int *matrizRES, int l, int c,
                       int i, int j) {
  // Função que espelha a diagonal principal de uma matriz
  // Basicamente chama as duas funções recursivas para poder espelhar elas
  // horizontalmente e verticalmente.
  espelhar_vertical(espelhar_horizontal(matriz, matrizE, l, c, 0, 0), matrizRES,
                    l, c, 0, 0);
  return;
}

int main(void) {
  int l, c, opt;
  scanf("%d%*c %d%*c %d%*c", &l, &c, &opt);
  // Matriz original
  int *matriz = malloc(l * c * sizeof(int));
  // Matriz a ser operada como resultado
  int *operated_matriz = malloc(l * c * sizeof(int));
  // Matriz espelhada diagonal resultado das duas operacoes: 1 entre matriz
  // original e a operada e 2 entre a operada e final.
  int *matrizE_diagonal = malloc(l * c * sizeof(int));
  ler_dados(matriz, l, c, 0);
  if (opt == 1) {
    dobrar_valores(matriz, l, c, 0);
    imprimir_dados(matriz, l, c, 0);
  } else if (opt == 2) {
    transpor_matriz(matriz, operated_matriz, l, c, 0, 0);
    // Se a matriz for quadrada (l == c), não há distinção entre linhas e
    // colunas. Portanto, é passado dessa forma para que possa identificar
    // corretamente a quebra de linha nos dois casos.
    imprimir_dados(operated_matriz, c, l, 0);
  } else if (opt == 3) {
    espelhar_horizontal(matriz, operated_matriz, l, c, 0, 0);
    imprimir_dados(operated_matriz, l, c, 0);
  } else if (opt == 4) {
    espelhar_vertical(matriz, operated_matriz, l, c, 0, 0);
    imprimir_dados(operated_matriz, l, c, 0);
  } else if (opt == 5) {
    espelhar_diagonal(matriz, operated_matriz, matrizE_diagonal, l, c, 0, 0);
    imprimir_dados(matrizE_diagonal, l, c, 0);
  }

  // Libera na memoria todas as matrizes usadas
  free(operated_matriz);
  free(matrizE_diagonal);
  free(matriz);
  return 0;
}