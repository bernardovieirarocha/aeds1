#include <stdio.h>
#include <stdlib.h>

int qtd_algarismos(int n1) {
  int quociente = 1;
  int qtd_algarismo = 0;
  int divisor = 1;
  do {
    quociente = n1 / divisor;
    if (quociente > 0) {
      qtd_algarismo++;
    }
    divisor *= 10;
  } while (quociente > 0);
  return qtd_algarismo;
}

int main() {
  int escolha;
  int num1, num2;
  printf("Escreva o número da operação que deseja: ");
  scanf("%d%*c", &escolha);
  while (escolha != 0) {
    printf("\nEscreva os dois números envolvidos (a serem operados): ");
    scanf("%d %d%*c", &num1, &num2);
    if (escolha == 1) {
      printf("O resultado da soma é: %d \n", num1 + num2);
    } else if (escolha == 2) {
      printf("O resultado da soma é: %d \n", num1 - num2);

    } else if (escolha == 3) {
      printf("O resultado da soma é: %d \n", num1 / num2);

    } else if (escolha == 4) {
      printf("O resultado da soma é: %d \n", num1 * num2);

    } else if (escolha == 5) {
      int exponenciacao = 1;
      for (int i = 0; i < num2; i++) {
        exponenciacao *= num1;
      }
      printf("O resultado da exponenciação é: %d \n", exponenciacao);
    } else if (escolha == 6) {
      if (num1 < 0) {
        num1 *= -1;
      }
      if (num2 < 0) {
        num2 *= -1;
      }

      int position = qtd_algarismos(num1) - num2 + 1;
      int result = 0;
      int multiplier = 1;
      int contador = 0;

      while (num1 > 0) {
        int digit = num1 % 10;
        num1 /= 10;
        if (++contador == position) {
          continue;
        }
        result += multiplier * digit;
        multiplier *= 10;
      }
      printf("O resultado Remoção do %d-ésimo dígito é %d \n", num2, result);
    } else if (escolha == 7) {
      int x = num1;
      int y = num2;
      if (num1 < 0) {
        num1 *= -1;
      }
      if (num2 < 0) {
        num2 *= -1;
      }
      int result = 0;
      int multiplier = 1;
      while (num1 > 0 || num2 > 0) {
        int diferenca = qtd_algarismos(num1) - qtd_algarismos(num2);
        if (diferenca > 0) {
          for (int i = 0; i < diferenca; i++) {
            num2 *= 10;
          }
        } else if (diferenca < 0) {
          diferenca = diferenca * -1;
          for (int i = 0; i < diferenca; i++) {
            num1 *= 10;
          }
        }
        int digitSum = (num1 % 10) + (num2 % 10);
        result += multiplier * (digitSum);
        num1 /= 10;
        num2 /= 10;
        if (digitSum >= 10) {
          multiplier *= 100;
        } else {
          multiplier *= 10;
        }
      }
      printf("O resultado da soma dos dígitos de %d e %d é: %d\n", x, y,
             result);
    } else if (escolha == 8) {
      if (num1 < 0) {
        num1 *= -1;
      }
      if (num2 < 0) {
        num2 *= -1;
      }
      int result = 0;
      int multiplier = 1;
      int qtd_algarismo_num1 = qtd_algarismos(num1);
      int qtd_algarismo_num2 = qtd_algarismos(num2);
      int maior_num = 0;
      if (qtd_algarismo_num1 > qtd_algarismo_num2) {
        maior_num = qtd_algarismo_num1;
      } else {
        maior_num = qtd_algarismo_num2;
      }

      for (int i = 0; i < maior_num; i++) {
        // O i nesse caso ta basicamente contanto pra ter certeza que ele não ta
        // fazendo esse código mais vezes que tem algarismo pra alternar
        if (i < qtd_algarismo_num1) {
          // Em cada um desses ifs ele ta verificando se o num1 tem um algarismo
          // para ser alternado ou se já não tem mais, senão tiver eh porque o
          // num2 tem pra simplesmente colocar ao fim
          int divisor = 1;
          for (int j = 1; j < qtd_algarismo_num1 - i; j++) {
            // Aqui ele quer entender em que posicão está o primeiro, segundo,
            // terceiro.. número, nas dezenas, cententas, milhares ou unidades.
            divisor *= 10;
          }
          // Aqui ele pega o resultado anterior e multiplica por 10 pra abrir
          // espaço para uma nova concatenação e pega o valor completo de num1 e
          // dividi pela "posicão que ele ocupa" Enum1_1: em 456 para pegar o
          // primeiro deve dividir por 100 e encontrará 4 ; Enum1_2: 456 para
          // pegar o segundo deve dividir por 10 e econtrará 45 e pegando o
          // resto econtrará 5 e assim por diante.
          result = result * 10 + ((num1 / divisor) % 10);
        }
        if (i < qtd_algarismo_num2) {
          // A mesma lógica descrita no outro if aplica aqui. Só vale lembrar
          // que em cada if ele vai pegando um algarismo por vez da esquerda pra
          // direita e colocando no result, enum1ecutando pro num1 e pro num2
          // por isso pega alternância.
          int divisor = 1;
          for (int j = 1; j < qtd_algarismo_num2 - i; j++) {
            divisor *= 10;
          }
          result = result * 10 + ((num2 / divisor) % 10);
        }
      }

      printf("O resultado da alternância dos dígitos de %d e %d é: %d\n", num1,
             num2, result);
    } else if (escolha == 9) {
      if (num1 < 0) {
        num1 *= -1;
      }
      if (num2 < 0) {
        num2 *= -1;
      }
      int num1_invertido = 0;
      while (num1 > 0) {
        num1_invertido = num1_invertido * 10 + num1 % 10;
        num1 /= 10;
      }
      num1 = num1_invertido;
      while (num2 > 0) {
        num1 = num1 * 10 + num2 % 10;
        num2 /= 10;
      }
      printf("O resultado da construção do número cujos dígitos são aqueles "
             "em num1 e em num2, mas em ordem reversa é: %d \n",
             num1);
    }
    printf("Escreva o número da operação que deseja: ");
    scanf("%d%*c", &escolha);
  }
  return 0;
}
