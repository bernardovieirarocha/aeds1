// ATENÇÃO : Este é um exercício para ser feito em sala de aula.Logo,
//     entregas de alunos(as)
// que não estiverem presentes no dia da aplicação,
//     terão suas entregas desconsideradas.

//     ENUNCIADO : Você deve fazer um programa que leia do(a)
//                     usuário(a) uma sequência de
//                 10 números que serão passados por ele(a) e,
//     em seguida,
//     oferecer as seguintes opções : 0. Sair do programa
//     1. Atualizar o valor em um índice
//     específico(fornecido pelo(a) usuário(a)) da sequência 2. Exibir sequência
//     3. Exibir sequência em ordem reversa
//     4. Exibir a somatória de todos os valores da sequência
//     5. Exibir a contagem de números duplicados da sequência 6. Exibir os
//     valores únicos(i.e., sem repetição) da sequência
//     7. Exibir a frequência de todos os valores da sequência
//     8. Exibir o valor máximo,
//     mínimo e médio(com duas casas decimais) da sequência
//     9. Exibir o valor da mediana da sequência
//     10. Exibir a sequência em ordem crescente
//     11. Exibir a sequência em ordem decrescente
//     12. Exibir os valores pares e ímpares da
//     sequência(sem repetição) 13. Exibir a sequência rotacionada M
//     vezes(quantidade fornecida pelo(a) usuário(a)) para a esquerda
//     14. Exibir a sequência rotacionada M
//     vezes(quantidade fornecida pelo(a) usuário(a)) para a direita

//     RESTRIÇÕES : Não se pode utilizar nenhum conceito não visto em sala de
//                  aula(por ex., cadeias de caracteres)

#include <stdio.h>
#include <stdlib.h>

int main() {

  int sequencia[10];
  int frequencia[10] = {0};
  int repetido = 0;
  float media = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d%*c", &sequencia[i]);
  }
  int option;
  scanf("%d%*c", &option);
  while (option != 0) {
    if (option == 0) {
      break;
    } else if (option == 1) {
      int index, newvalue;
      scanf("%d%*c", &index);
      scanf("%d%*c", &newvalue);
      sequencia[index] = newvalue;
    } else if (option == 2) {
      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");
    } else if (option == 3) {
      for (int i = 9; i >= 0; i--) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");
    } else if (option == 4) {
      float acc = 0;
      for (int i = 0; i < 10; i++) {
        acc += sequencia[i];
      }
      printf("%.0f\n", acc);
    } else if (option == 5) {
      int contagem[11] = {
          0}; // Basicamente serve para lembrar q eu ja vi aquele numero alguma
              // vez e ja sei q ele se repete. Tem 11 porque preciso ter certeza
              // que eh impossivel estourar quaisquer limites.
      int contador_duplicados = 0;
      for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j <= 10; j++) {
          if (sequencia[i] == sequencia[j] && contagem[sequencia[i]] == 0) {
            // somente executa se o codigo nunca viu esse numero antes.
            contagem[sequencia[i]]++;
            contador_duplicados++;
          }
        }
      }
      printf("%d\n", contador_duplicados);
    } else if (option == 6) {
      for (int i = 0; i < 10; i++) {
        repetido = 1;
        for (int j = i + 1; j <= 10; j++) {
          if (sequencia[i] == sequencia[j]) {
            repetido = 0;
          }
        }
        if (repetido) {
          printf("%d ", sequencia[i]);
        }
      }
      printf("\n");
    } else if (option == 7) {
      for (int i = 0; i < 10; i++) {
        int freq = 1;
        for (int j = i + 1; j <= 10; j++) {
          if (sequencia[i] == sequencia[j]) {
            freq++;
            frequencia[j] =
                -1; // Diz que a posicao(correspondente) ja foi contada.
          }
        }
        if (frequencia[i] != -1) {
          frequencia[i] = freq; // so guarda o valor da posicao inicial e ignora
                                // a correspondente.
        }
      }
      for (int i = 0; i < 10; i++) {
        if (frequencia[i] != -1) {
          printf("%d:%d ", sequencia[i], frequencia[i]);
        }
      }
      printf("\n");
    } else if (option == 8) {
      int acc = 0;
      int max = sequencia[0];
      int min = sequencia[0];
      for (int i = 0; i < 10; i++) {
        if (sequencia[i] > max) {
          max = sequencia[i];
        }
        if (sequencia[i] < min) {
          min = sequencia[i];
        }
        acc += sequencia[i];
      }
      media = acc / 10.0;
      printf("%d %d %.2f\n", max, min, media);
    } else if (option == 9) {
      int temp = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia[j] > sequencia[j + 1]) {
            //  Inverte se tiverem fora de ordem crescente
            int temp = sequencia[j];
            sequencia[j] = sequencia[j + 1];
            sequencia[j + 1] = temp;
          }
        }
      }
      float mediana = (sequencia[4] + sequencia[5]) / 2.0;
      printf("%.2f\n", mediana);

    } else if (option == 10) {
      int temp = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia[j] > sequencia[j + 1]) {
            //  Inverte se tiverem fora de ordem crescente
            int temp = sequencia[j];
            sequencia[j] = sequencia[j + 1];
            sequencia[j + 1] = temp;
          }
        }
      }
      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");
    } else if (option == 11) {
      int temp = 0;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia[j] > sequencia[j + 1]) {
            //  Inverte se tiverem fora de ordem decrescente
            int temp = sequencia[j];
            sequencia[j] = sequencia[j + 1];
            sequencia[j + 1] = temp;
          }
        }
      }
      for (int i = 9; i >= 0; i--) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");

    } else if (option == 12) {
      printf("P:");
      for (int i = 0; i < 10; i++) {
        if (sequencia[i] % 2 == 0) {
          // eh par
          printf("%d,", sequencia[i]);
        }
      }
      printf(" I:");
      for (int i = 0; i < 10; i++) {
        if (sequencia[i] % 2 != 0) {
          // eh impar
          printf("%d,", sequencia[i]);
        }
      }
      printf("\n");
    } else if (option == 13) {
      int qtd_rotacoes;
      scanf("%d%*c", &qtd_rotacoes);
      for (int i = 0; i < qtd_rotacoes; i++) {
        int temp = sequencia[0];
        for (int i = 0; i < 9; i++) {
          sequencia[i] = sequencia[i + 1];
        }
        sequencia[9] = temp;
      }
      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");
    } else if (option == 14) {
      int qtd_rotacoes;
      scanf("%d%*c", &qtd_rotacoes);
      for (int i = 0; i < qtd_rotacoes; i++) {
        int temp = sequencia[9];
        for (int i = 9; i > 0; i--) {
          sequencia[i] = sequencia[i - 1];
        }
        sequencia[0] = temp;
      }
      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia[i]);
      }
      printf("\n");

    } else {
      printf("Opcao invalida\n");
    }

    scanf("%d", &option);
  }
  return 0;
}
