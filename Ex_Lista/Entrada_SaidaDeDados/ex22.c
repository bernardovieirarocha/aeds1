#include <stdio.h>

int main(void) {
	int pratos,acomp,bebidas;
	int t_possibilidades;
	printf("Digite a qtd de opcoes de pratos principais, acompanhamentos e bebidas: ");
	scanf(" %d %d %d", &pratos,&acomp,&bebidas);
	if (pratos > 0 && acomp > 0 && bebidas > 0){
		t_possibilidades = pratos * acomp * bebidas;
		printf("O total de possibilidades de refeicoes eh: %d", t_possibilidades);
	} else {
		printf("Valores negativos ou nulos nao sao permitidos\n");
	}
	return 0;
}