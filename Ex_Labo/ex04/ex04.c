// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

// ENUNCIADO: Faça um programa que permita a realizar cálculos bizarros entre
// dois números x e y. Primeiro, deve-se ler os números x e y do usuário (que
// podem não ter a mesma quantidade de algarismos) e, em seguida, ler a opção
// desejada do usuário (um inteiro) que pode ser uma das seguintes:

// 1. Remoção do y-ésimo dígito de x, contado da direita para a esquerda (então,
// y = 0 é o primeiro algarismo)

// 2. Construção do número cujos dígitos alternam entre aqueles em y e em x
// (então, o primeiro algarismo à esquerda é o último algarismo de y, em
// seguida, o segundo algarismo da resposta é o último de x)

// 3. Construção do número cujos dígitos são aqueles em x e em y (então, da
// direita para esquerda, temos os algarismos de x e, depois, os de y)

// RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula
// (por ex., biblioteca math.h) ou vetores.
#include <stdio.h>
#include <stdlib.h>

int qtd_algarismos(int n1) {
  int quociente = 1;
  int qtd_algarismo = 0;
  int divisor = 1;
  do {
    // Divide o número pelo divisor que aumenta de 10
    // em 10 para precorrer os digitos.
    quociente = n1 / divisor;
    if (quociente > 0) {
      // Verifica se ainda a algarismos a serem contados. Se sim incrementa a
      // qtd_alg
      qtd_algarismo++;
    }
    // Atualiza o divisor para a proxima divisao, perfazendo o numero
    divisor *= 10;
  } while (quociente > 0); // Continua ate nao ter mais digitos
  return qtd_algarismo;
}

int main(void) {
  int escolha = 1;
  int num1;
  int num2;
  while (escolha != 0) {
    scanf("%d%*c %d%*c", &num1, &num2);
    scanf("%d%*c", &escolha);
    if (escolha == 1) {
      // A pos eh igual ao num2, pois o enunciado determina que comeca-se em 0 e
      // conta-se da direita pra esquerda
      int position = num2;
      int result = 0;
      int multiplier = 1;
      // Comeca na "posicao 0" e vai contando as posicoes.
      int contador = 0;

      while (num1 > 0) {
        // Pega o ultimo digito atual do num1
        int digit = num1 % 10;
        // Atualiza o numero para pegar o prox digito, na prox iteracao
        num1 /= 10;
        // Se o contador atual for igual a posicao que desejo , significa
        // que encontrei o numero na qual desejo remover.
        if (contador == position) {
          // Acrescento o contador e dou continue pra ignorar essa iteracao e
          // comecar a proxima, alem de falar que ja perpassei essa posicao e
          // devo percorrer a prox pos.
          ++contador;
          continue;
        }
        // Se o numero/posicao for desejavel, recolocar ele ao resultado
        // multiplicando o digito pelo seu fator correspondente de posicao que
        // seria 10^pos, mas usa-se uma variavel que faz a mesma coisa
        // multiplicando-se por 10 a cada iteracao.
        result += multiplier * digit;
        multiplier *= 10;
        // Incrementa contador para percorrer a prox posicao.
        ++contador;
      }
      printf("%d\n", result);
    } else if (escolha == 2) {
      int res = 0;
      int multiplicador = 1;
      int pos = 0;
      int tamN1 = qtd_algarismos(num1);
      int tamN2 = qtd_algarismos(num2);

      // Loop para multiplicar os digitos e acumular no resultado.
      while (num1 > 0 || num2 > 0) {
        // Obtem os digitos atual de num1.
        int digitN1 = num1 % 10;
        int digitN2 = num2 % 10;

        // Verifica se ainda ha digitos em num2 . Comeca no Num2, pois a logica
        // apresentada nos testes (.txt) era essa.
        if (pos < tamN2) {
          res += digitN2 * multiplicador;
          // Atualiza o multiplicador para a próxima posição.
          multiplicador *= 10;
        }
        // Verifica se ainda ha digitos em num1 .
        if (pos < tamN1) {
          res += digitN1 * multiplicador;
          // Atualiza o multiplicador para a próxima posição.
          multiplicador *= 10;
        }
        // Avança para a proxima posicao e percorre os numeros.
        ++pos;
        num1 /= 10;
        num2 /= 10;
      }
      printf("%d\n", res);
    } else if (escolha == 3) {
      int tamN2 = qtd_algarismos(num2);
      // Aumenta o numero possivel, pois para concatenacao pode criar valores
      // muito grandes.
      unsigned int res = 0;
      int pos = 0;
      while (num1 > 0 || num2 > 0) {
        int multiplicador = 1;
        // Calcula o valor do multiplicador para a posicao atual.
        for (int i = 0; i < pos; ++i) {
          multiplicador *= 10;
        }
        // Verifica se ainda há dígitos em num2 para multiplicar.
        if (pos < tamN2) {
          // Coloque os digitos de num2 primeiro, pois esses se tornarao os
          // ultimos e a logica dos testes sera seguida.
          res += (num2 % 10) * multiplicador;
          num2 /= 10;
        } else {
          // Senao tiver mais coloque (direita pra esquerda) todos os digitos de
          // num1;
          res += (num1 % 10) * multiplicador;
          num1 /= 10;
        }
        pos++; // Avanca pra proxima posicao
      }
      printf("%d\n", res);
    }
    escolha = 0;
    scanf("%d%*c %d%*c %d%*c", &num1, &num2, &escolha);
  }
  return 0;
}
