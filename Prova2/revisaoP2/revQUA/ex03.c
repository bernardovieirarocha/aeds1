#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE *resp = NULL;
  FILE *gaba = NULL;
  char ch1;
  char ch2;
  bool res = true;
  resp = fopen("resp.txt", "r");
  gaba = fopen("gabarito.txt", "r");

  if (resp != NULL && gaba != NULL) {

    // fscanf(resp, "%c", &ch1) != EOF && fscanf(gaba, "%c", &ch2) != EOF
    while (!feof(resp) && !feof(gaba)) {
      fscanf(resp, "%c", &ch1);
      fscanf(gaba, "%c", &ch2);

      if (ch1 == ' ' || ch1 == '\n') {
        fscanf(resp, "%c", &ch1);
      }
      if (ch2 == ' ' || ch1 == '\n') {
        fscanf(gaba, "%c", &ch2);
      }

      if (ch1 >= 65 && ch1 <= 90) {
        // letra maiscula
        ch1 += 32;
      }
      if (ch2 >= 65 && ch2 <= 90) {
        // letra maiscula
        ch2 += 32;
      }

      if (ch1 != ch2) {
        resp = false;
      }
    }
    if (resp) {
      printf("sim");
    } else {
      printf("nao");
    }
  }
  fclose(resp);
  fclose(gaba);
  return 0;
}

// /*
// 	EXERCICIO 7
// 	Faca um programa que leia dois arquivos resp.txt e gabarito.txt e
// imprima 	"SIM" se forem iguais, ou "NAO", caso contrario. ATENCAO!
// Desconsidere 	espacos em branco e mudancas maiuscula/minuscula
// */
// #include <stdio.h> // scanf, printf
// #include <stdlib.h> // malloc, free, NULL, FILE, fopen, fclose
// #include <stdbool.h> // bool, true, false

// int main()
// {
// 	char char_resp = '\0', char_gab = '\0'; // Char lidos em cada arquivo
// 	FILE *resp = NULL, *gab = NULL; // Resposta e Gabarito

// 	resp = fopen("resp.txt", "r");
// 	if(resp == NULL)
// 	{
// 		printf("ERRO! Nao foi possivel abrir o arquivo \"resp.txt\"\n");
// 		return 1;
// 	}
// 	gab = fopen("gabarito.txt", "r");
// 	if(gab == NULL)
// 	{
// 		fclose(resp); // Se chegou aqui, resp abriu o arquivo, e temos
// de fechar 		printf("ERRO! Nao foi possivel abrir o arquivo
// \"gabarito.txt\"\n"); 		return 1;
// 	}

// 	// Pega o 1o char de cada arquivo
// 	char_resp = fgetc(resp);
// 	char_gab = fgetc(gab);
// 	// Enquanto houver caractere para ser lido dos dois arquivos
// 	while((char_resp != EOF) && (char_gab != EOF))
// 	{
// 		while((char_resp != EOF) && // Enquanto nao chegou no fim ou e
// branco e similares
// 					((char_resp == '\n') || (char_resp == '
// ') || (char_resp == '\r')))
// 		{
// 			char_resp = fgetc(resp); // Pega o proximo
// 		}
// 		while((char_gab != EOF) && // Enquanto nao chegou no fim ou e
// branco e similares
// 					((char_gab == '\n') || (char_gab == ' ')
// || (char_gab == '\r')))
// 		{
// 			char_gab = fgetc(gab); // Pega o proximo
// 		}

// 		// Se for uma letra maiuscula
// 		if((char_resp >= 'A') && (char_resp <= 'Z'))
// 		{
// 			char_resp += 32; // Joga pra minuscula
// 		}
// 		// Se for uma letra maiuscula
// 		if((char_gab >= 'A') && (char_gab <= 'Z'))
// 		{
// 			char_gab += 32; // Joga pra minuscula
// 		}

// 		// Se forem diferentes, pode parar pois nao tem porque continuar
// 		if(char_gab != char_resp) { break; }
// 		else
// 		{
// 			// Continua a olhar os proximos
// 			char_resp = fgetc(resp);
// 			char_gab = fgetc(gab);
// 		}
// 	}

// 	// Se ambos nao terminaram no fim de cada arquivo
// 	if((char_resp != char_gab) && ((char_gab == EOF) || (char_resp == EOF)))
// 	{
// 		printf("NAO\n"); // Um terminou antes do outro, logo sao
// diferentes
// 	}
// 	else
// 	{
// 		printf("SIM\n"); // Se terminaram juntos, sao iguais
// 	}

// 	fclose(resp);
// 	fclose(gab);

// 	return 0;
// }