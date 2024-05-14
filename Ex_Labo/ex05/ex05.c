// ATENÇÃO: Este é um exercício para ser feito em sala de aula. Logo, entregas
// de alunos(as) que não estiverem presentes no dia da aplicação, terão suas
// entregas desconsideradas. Além disso, códigos que não estiverem indentados,
// comentados e/ou não respeitarem as restrições também serão desconsiderados. É
// importante frisar que comentários redundantes e/ou irrelevantes para o
// entendimento da solução não serão considerados.

// ENUNCIADO: Você deve fazer um programa que leia do(a) usuário(a) uma
// sequência de 10 números positivos entre 0 e 100 que serão passados por ele(a)
// e, em seguida, oferecer as seguintes opções: 0. Sair do programa
// 1. Atualizar o valor em um índice específico (fornecido pelo(a) usuário(a))
// da sequência
// 2. Exibir sequência
// 3. Exibir sequência em ordem reversa
// 4. Exibir a somatória de todos os valores da sequência
// 5. Exibir a contagem de números duplicados da sequência
// 6. Exibir os valores únicos (i.e., sem repetição) da sequência
// 7. Exibir a frequência de todos os valores da sequência
// 8. Exibir o valor máximo, mínimo e médio (com duas casas decimais) da
// sequência
// 9. Exibir os valores pares e ímpares da sequência (sem repetição)
// 10. Exibir a sequência rotacionada M vezes (quantidade fornecida pelo(a)
// usuário(a)) para a esquerda
// 11. Exibir a sequência rotacionada M vezes (quantidade fornecida pelo(a)
// usuário(a)) para a direita

// RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula
// (por ex., cadeias de caracteres)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int sequencia[10];
  int unico = 0;
  int frequencia[10];
  float media = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d%*c", &sequencia[i]);
    frequencia[i] = -1;
  }
  int option;
  scanf("%d%*c", &option);
  while (option != 0) {
    if (option == 0) {
      break; // Redundancia; Fiz isso na laboratorio e deixei assim.
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
      // Cria uma nova sequencia para nao interferir na definida pelo usuario,
      // pois ele colocar em ordem muda o index das posicoes, afetando o
      // resultado final.
      int sequencia_crescente[10] = {0};
      for (int i = 0; i < 10; ++i) {
        sequencia_crescente[i] = sequencia[i];
      }

      // Coloca a nova sequencia em ordem crescente para poder mostrar os
      // repetidos conforme o estabelecido nos exemplos de saida
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia_crescente[j] > sequencia_crescente[j + 1]) {
            //  Inverte se tiverem fora de ordem crescente
            int temp = sequencia_crescente[j];
            sequencia_crescente[j] = sequencia_crescente[j + 1];
            sequencia_crescente[j + 1] = temp;
          }
        }
      }
      // Exibi os valores unicos, isto eh sem repetir e tambem em ordem
      // crescente.
      for (int i = 0; i < 10; i++) {
        unico = 1; // Assume que o valor incialmente eh unico nunca visto
        for (int j = i + 1; j <= 10; j++) {
          if (sequencia_crescente[i] == sequencia_crescente[j]) {
            unico = 0; // Se tiver repetido ja indica que nao eh unico.
          }
        }
        if (unico) { // So exibe os valores considerados unicos
          printf("%d ", sequencia_crescente[i]);
        }
      }
      printf("\n");
    } else if (option == 7) {
      // Cria uma nova sequencia para nao interferir na definida pelo usuario,
      // pois ele colocar em ordem muda o index das posicoes, afetando o
      // resultado final.
      int sequencia_crescente[10] = {0};
      for (int i = 0; i < 10; ++i) {
        sequencia_crescente[i] = sequencia[i];
      }

      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia_crescente[j] > sequencia_crescente[j + 1]) {
            //  Inverte se tiverem fora de ordem crescente
            int temp = sequencia_crescente[j];
            sequencia_crescente[j] = sequencia_crescente[j + 1];
            sequencia_crescente[j + 1] = temp;
          }
        }
      }
      // contador pra ver quantas vezes repetiu e o flag pra ser ja foi
      // encontrado uma vez.
      int contador;

      for (int i = 0; i < 10; i++) {
        contador = 1;
        for (int j = i + 1; j < 10; j++) {
          if (sequencia_crescente[i] == sequencia_crescente[j]) {
            //
            contador++;
            frequencia[j] =
                0; // Diz que a posicao(correspondente) ja foi contada.
          }
        }
        if (frequencia[i] != 0) {
          frequencia[i] = contador; // so guarda o valor da posicao inicial e
                                    // ignora a correspondente
        }
      }

      // Percorre as frequencias e imprimi
      for (int i = 0; i < 10; i++) {
        if (frequencia[i] != 0) {
          printf("%d:%d ", sequencia_crescente[i], frequencia[i]);
        }
      }

      printf("\n");
    } else if (option == 8) {
      int acc = 0;
      int max = sequencia[0];
      int min = sequencia[0];
      // Loop descobre o max e o minimo do vetor
      for (int i = 0; i < 10; i++) {
        if (sequencia[i] > max) {
          max = sequencia[i];
        }
        if (sequencia[i] < min) {
          min = sequencia[i];
        }
        // Ja soma os valores no acumulador
        acc += sequencia[i];
      }
      // calcula a media no final
      media = acc / 10.0;
      printf("%d %d %.2f\n", min, max, media);
    } else if (option == 9) {
      // Cria uma nova sequencia para nao interferir na definida pelo usuario,
      // pois ele colocar em ordem muda o index das posicoes, afetando o
      // resultado final.
      int sequencia_crescente[10] = {0};
      for (int i = 0; i < 10; ++i) {
        sequencia_crescente[i] = sequencia[i];
      }

      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
          if (sequencia_crescente[j] > sequencia_crescente[j + 1]) {
            //  Inverte se tiverem fora de ordem crescente
            int temp = sequencia_crescente[j];
            sequencia_crescente[j] = sequencia_crescente[j + 1];
            sequencia_crescente[j + 1] = temp;
          }
        }
      }

      // Cria uma nova sequencia sem duplicados e tambem consequentemente jah em
      // ordem crescente.
      int sequencia_sem_duplicados[10] = {0};
      int tamanho_sequencia_sem_duplicados = 0;

      for (int i = 0; i < 10; i++) {
        int duplicado = 0; // Considera incialmente nao duplicado
        for (int j = 0; j < tamanho_sequencia_sem_duplicados; j++) {
          // verifica se o elemento atual da sequencia_crescente ja existe na
          // sequencia_sem_duplicados.
          if (sequencia_crescente[i] == sequencia_sem_duplicados[j]) {
            // Se um elemento duplicado eh encontrado, a variavel duplicado é
            // alterada para 1 e o loop interno eh interrompido com break.
            duplicado = 1;
            break;
          }
        }
        if (!duplicado) {
          // Se o elemento não foi encontrado como duplicado, ele eh adicionado
          // a sequencia_sem_duplicados e o tamanho da sequencia sem duplicatas
          // eh incrementado.
          sequencia_sem_duplicados[tamanho_sequencia_sem_duplicados] =
              sequencia_crescente[i];
          tamanho_sequencia_sem_duplicados++;
        }
      }

      printf("P: ");
      for (int i = 0; i < tamanho_sequencia_sem_duplicados; i++) {
        if (sequencia_sem_duplicados[i] % 2 == 0) {
          // Ao percorrer os elemento da sequencia sem duplicatas e em ordem
          // crescente verifica que se ele eh par e se sim imprime-o
          printf("%d ", sequencia_sem_duplicados[i]);
        }
      }
      printf(" I: ");
      for (int i = 0; i < tamanho_sequencia_sem_duplicados; i++) {
        if (sequencia_sem_duplicados[i] % 2 != 0) {
          // Ao percorrer os elemento da sequencia sem duplicatas e em ordem
          // crescente verifica que se ele eh impar e se sim imprime-o
          printf("%d ", sequencia_sem_duplicados[i]);
        }
      }
      printf("\n");
    } else if (option == 10) {
      int qtd_rotacoes;
      scanf("%d%*c", &qtd_rotacoes);
      // Cria uma nova sequencia baseada na recebida pelo usuario para nao
      // afetar, interferir na sequencia corrente, ja que nos testes, observa-se
      // que essa mudanca nao eh persistente.
      int sequencia_rotacionada[10] = {0};
      for (int i = 0; i < 10; ++i) {
        sequencia_rotacionada[i] = sequencia[i];
      }

      for (int i = 0; i < qtd_rotacoes; i++) {
        int temp = sequencia_rotacionada[0]; // Primeiro elemento da sequencia
        for (int i = 0; i < 9; i++) {
          // Move cada elemento para a esquerda, comecando pelo segundo, para
          // substituir o elemento anterior na sequência.
          sequencia_rotacionada[i] = sequencia_rotacionada[i + 1];
        }
        // Coloca o primeiro elemento original no final de sequencia e conclui
        // uma rotacao para esquerda.
        sequencia_rotacionada[9] = temp;
      }
      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia_rotacionada[i]);
      }
      printf("\n");
    } else if (option == 11) {

      int qtd_rotacoes;
      scanf("%d%*c", &qtd_rotacoes);
      // Cria uma nova sequencia baseada na recebida pelo usuario para nao
      // afetar, interferir na sequencia corrente, ja que nos testes, observa-se
      // que essa mudanca nao eh persistente.
      int sequencia_rotacionada[10] = {0};
      for (int i = 0; i < 10; ++i) {
        sequencia_rotacionada[i] = sequencia[i];
      }

      // Dessa forma com base num numero pre determinado de rotacoes o loop
      // abaixo, pega o ultimo do vetor coloca como primeiro e move todos os
      // elementos pra direita e assim por diante o numero de vezes desejadas.
      for (int i = 0; i < qtd_rotacoes; i++) {
        // Armazena o ultimo elemento.
        int temp = sequencia_rotacionada[9];
        for (int i = 9; i > 0; i--) {
          // Move cada um dos elementos para direita começando pelo ultimo para
          // abrir espaco para o elemento temporario
          sequencia_rotacionada[i] = sequencia_rotacionada[i - 1];
        }
        // Insere o temporario no inicio da sequencia, concluindo a rotacao pra
        // direita.
        sequencia_rotacionada[0] = temp;
      }

      for (int i = 0; i < 10; i++) {
        printf("%d ", sequencia_rotacionada[i]);
      }
      printf("\n");

    } else {
      printf("Opcao invalida\n");
    }

    scanf("%d", &option);
  }
  return 0;
}
