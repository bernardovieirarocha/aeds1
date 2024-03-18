#include <stdio.h>

int main(void) {
    int nota;
    printf("Escreva sua nota: ");
    scanf("%d", &nota);
    int aprovado = 'N' + 5 * (nota/60);
    printf("%c\n",aprovado);
    int recuperacao = 'N' + 5 * (nota/45) * (1-nota/60);
    printf("%c\n",recuperacao);
    int reprovado = 'N'+ 5 * (1-nota/45) * (1-nota/90);
    printf("%c\n",reprovado);
    return 0;
}

// O que foi enviado pelo canvas ao Felipe de Castro Belém
// #include <stdio.h>

// int main(void) {
//   int nota;
//   printf("Coloque sua nota: ");
//   scanf("%d", &nota);
//   int aprovado = 'N' + 5 * (nota / 60);
//   printf("Aprovado: %c\n", aprovado);
  
//   int recuperacao = 'N' + 5 * (nota / 45) * (1-nota / 60);
//   printf("Recuperação: %c\n", recuperacao);
  
//   int reprovou = 'N' + 5 * (1-nota / 45) * (1-nota/90);
//   printf("Reprovou: %c\n", reprovou);
//   return 0;
// }
