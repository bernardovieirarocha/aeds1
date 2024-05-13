// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

// ENUNCIADO: Faça um programa que permita realizar cálculos bizarros em um
// número positivo X fornecido pelo usuário até que seja determinado o fim da
// execução. Seu programa deve, primeiramente, ler tal número e, em seguida, ler
// qual a opção desejada pelo usuário, que pode ser uma das seguintes:

// 0. Saída do programa

// 1. Remoção do algarismo em X que se encontra no índice fornecido pelo usuário
// (contando a partir de 0, da direita para esquerda)

// 2. Adição de um algarismo em X no índice fornecido pelo usuário (contando a
// partir de 0, da direita para esquerda)

// 3. Imprimir a quantidade de algarismos de X

// 4. Ler um número positivo Y e definir X como a alternância dos algarismos, da
// direita para esquerda, em X e em Y (por exemplo, X=123 e Y=89, então X=18293)

// 5. Ler um número positivo Y e definir X como a concatenação dos algarismos,
// da direita para esquerda, de X e de Y (por exemplo, X=123 e Y=89, então
// X=12389)

// 6. Inverter a ordem dos algarismos de X (por exemplo, X=12345 então X=54321)

// 7. Remover os algarismos pares de X

// Toda e qualquer valor de opção que não seja as descritas acima, considere a
// funcionalidade de imprimir X

// RESTRIÇÕES: Não se pode utilizar nenhum conceito (ainda) não visto em sala de
// aula. Além disso, leituras e impressões de valores (i.e., scanf e printf)
// DEVEM estar SOMENTE na função main. Exceto a impressão de X, todas as opções
// devem estar modularizadas e implementadas usando RECURSÃO. É PROIBIDO o uso
// de variáveis globais e uso de vetores.
#include <math.h>
#include <stdio.h>

int remocaoAlgarismo(int indice, int numero, int mult, int contador,
                     int resultado) {
  // Se o numero for igual a zero, todos os digitos ja foram percorridos e a
  // remocao esta completa.
  if (numero == 0) {
    return resultado;
  } else if (indice == contador) {
    // Se o indice for igual ao contador, o digito atual deve ser removido.
    // Divide-se por 10 para continuar iterando sobre os digitos e ignorar esse
    // digito.
    numero /= 10;
    return remocaoAlgarismo(indice, numero, mult, ++contador, resultado);
  } else {
    // Caso contrario, o digito atual precisa ser reconstruido no numero
    // resultante.
    int digit = numero % 10;
    // Dividir por 10 para passar para o proximo digito.
    numero /= 10;
    // Adiciona o digito ao resultado multiplicado pela posicao que ele ocupava
    // ou a posicao corrente.
    resultado += mult * digit;
    mult *= 10;
    return remocaoAlgarismo(indice, numero, mult, ++contador, resultado);
  }
}

int quantosAlgarismo(int numero) {
  // Se o numero eh igual a 0 significa que ja acabou e pode parar de contar
  if (numero == 0) {
    return 0;
  } else {
    // A contagem eh incrementada a cada chamada recursiva, indicando que ainda
    // ha algarismos para contar enquanto o numero for diferente de zero, pois
    // ainda eh possível dividir. Adiciona 1 para contar o algarismo atual e
    // continua a contagem com a parte restante do numero.
    return 1 + quantosAlgarismo(numero / 10);
  }
}

int adicaoAlgarismo(int numero, int novoAlg, int indice) {
  if (indice == 0) {
    // Ao chegar no indice desejado adicione o novo algarismo.
    return (numero * 10) + novoAlg;
  }
  // Divide o numero por 10 percorrendo todos os algarismos ate chegar no indice
  // desejado
  int novoNumero = adicaoAlgarismo(numero / 10, novoAlg, --indice);
  // Concatenamos o novo numero com o resto dos digitos que sobraram em
  // 'numero', ou seja, aqueles que estão a direita da posição onde o novo
  // algarismo foi adicionado. Isso é feito à medida que a função retorna na
  // pilha recursiva.
  return (novoNumero * 10) + (numero % 10);
}

int alternancia(int num1, int num2, int pos, int result, int multiplicador,
                int tamN1, int tamN2, int maiorN) {
  // Se a pos for maior que o tamanho do maior numero, a alternancia esta
  // completa.
  if (pos > maiorN) {
    return result;
  }
  // Obtem os dois ultimos digitos de ambos os num.
  int digitN1 = num1 % 10;
  int digitN2 = num2 % 10;

  // Verfica se ainda ha digitos para serem alternados,
  // construindo o resultado conforme a presenca deles em cada respectivo
  // numero.
  if (pos < tamN1) {
    result = result + digitN1 * multiplicador;
    // Aumenta o multiplicador para posicionar corretamente os proximo digitos,
    // pois a logica da alternancia eh uma construcao da direita para a
    // esquerda.
    multiplicador *= 10;
  }
  if (pos < tamN2) {
    result = result + digitN2 * multiplicador;
    multiplicador *= 10;
  }
  // Chama a funcao recursiva, dividindo os numeros por 10 para percorrer os
  // digitos e incrementando a pos para avançar na alternancia.
  return alternancia(num1 / 10, num2 / 10, ++pos, result, multiplicador, tamN1,
                     tamN2, maiorN);
}

int concatenacao(int *num1, int num2, int numAlg) {
  // Se o num2 for igual a zero, todos os digitos foram concatenados.
  if (num2 == 0) {
    return *num1;
  }

  // Basicamente divisor se tornar 10ˆpos para poder pegar os digitos de num2 e
  // construir o resultado. Para tanto eh preciso subtrair 1 do numAlg, pois a
  // primeira posicao seria o 0 para que 10^0 seja 1.
  int divisor = 1;
  for (int i = 0; i < numAlg - 1; ++i) {
    divisor *= 10;
  }
  // Construcao do numero resultante.
  *num1 = (*num1) * 10 + num2 / divisor;
  return concatenacao(num1, num2 % divisor, numAlg - 1);
}

int inverterOrdem(int *num1, int res) {
  // Se o numero for 0 acabou a inversao perpassei todos os digitos.
  if (*num1 == 0) {
    // num(ponteiro) se torna o resultado para continuar a calculadora.
    *num1 = res;
    return res;
  }
  // A cada iteracao, o ultimo digito de num1 eh adicionado a direita de res,
  // invertendo a ordem dos digitos.
  res = res * 10 + (*num1) % 10;
  *num1 /= 10;
  return inverterOrdem(num1, res);
}

int removerPares(int *num, int res, int multiplicador) {
  if (*num == 0) {
    // Condicao de fim e reatribuicao do valor final
    *num = res;
    return res;
  }
  // Pega o ultimo digito atual de num
  int digit = (*num) % 10;

  if (digit % 2 != 0) {
    // Se for par reconstroi
    res = res + digit * multiplicador;
    // O multiplicador eh atualizado para posicionar corretamente o proxima
    // digito.
    multiplicador *= 10;
  }
  // Se nao for par passa pro proximo digito
  *num = (*num / 10);
  return removerPares(num, res, multiplicador);
}

int main(void) {

  int num;
  scanf("%d%*c", &num);

  int opt;
  scanf("%d%*c", &opt);

  while (opt != 0) {

    if (opt == 1) {
      int indice = 3;
      scanf("%d%*c", &indice);
      num = remocaoAlgarismo(indice, num, 1, 0, 0);
      // printf("%d\n", num);
    } else if (opt == 2) {
      int indice;
      scanf("%d%*c", &indice);
      int novo_algarismo;
      scanf("%d%*c", &novo_algarismo);
      num = adicaoAlgarismo(num, novo_algarismo, indice);
      // printf("%d\n", num);
    } else if (opt == 3) {
      printf("%d\n", quantosAlgarismo(num));
    } else if (opt == 4) {
      int num2;
      scanf("%d%*c", &num2);
      int tamN1 = quantosAlgarismo(num);
      int tamN2 = quantosAlgarismo(num2);
      int maiorN;
      if (tamN1 > tamN2) {
        maiorN = tamN1;
      } else {
        maiorN = tamN2;
      }
      num = alternancia(num, num2, 0, 0, 1, tamN1, tamN2, maiorN);
      // printf("%d\n", num);
    } else if (opt == 5) {
      int num2;
      scanf("%d%*c", &num2);
      int numAlg = quantosAlgarismo(num2);
      concatenacao(&num, num2, numAlg);
      // printf("%d\n", num);
    } else if (opt == 6) {
      inverterOrdem(&num, 0);
      // printf("%d\n", num);
    } else if (opt == 7) {
      removerPares(&num, 0, 1);
      // printf("%d\n", num);
    } else {
      printf("%d\n", num);
    }

    scanf("%d%*c", &opt);
  }

  return 0;
}
