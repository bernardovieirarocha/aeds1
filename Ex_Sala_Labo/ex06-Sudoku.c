#include <stdio.h>
const int M = 9;
const int N = 9;

int verificar_linha(int linha_user, int sudoku[M][N]) {
        for (int i = 0; i < 9; ++i){
            for (int j = i  +1 ; j < 9; ++j){
                if (sudoku[linha_user][i] == sudoku[linha_user][j]){
                    return 1; // 'S'
                }
            }
    	}

    return 0; // 'N'
}


int verificar_coluna(int coluna_user, int sudoku[M][N]) {
        for (int i = 0; i < 9; ++i){
            for (int j = i  +1 ; j < 9; ++j){
                if (sudoku[i][coluna_user] == sudoku[j][coluna_user]){
                    return 1; // 'S'
                }
            }
    	}

    return 0; // 'N'
}

int verificar_quadrante(int quadrante, int sudoku[M][N]) {
	// Descobrir no Quadrante especificado qual o max e o min que devo percorrer em loop
    int linha_min = 3 * (quadrante / 3);
	int coluna_min = 3*(quadrante % 3);
	int linha_max  = linha_min +2;
	int coluna_max = coluna_min+2;
	
	// Loop que transforma a matriz 3x3 em um um vetor linear de 9 posicoes, ja q basta eu saber se tem repetido ou nao.
	int vet_linear[9];
	int index_contador = 0;
	for (int i = linha_min ; i <= linha_max; ++i) {
		for (int j = coluna_min ; j <= coluna_max; ++j){
			vet_linear[index_contador] = sudoku[i][j];
			index_contador++;
		}
	}
	// Percorre o vetor linear criado para verificar se tem algum valor repetido na matriz no quadrante
	int anterior;
    for (int i = 0; i < 9; ++i){
		// salva o valor anterior
		anterior = vet_linear[i];
        for (int j = i  +1 ; j < 9; ++j){
			// compara com todos os outros valores do vetor
            if (anterior == vet_linear[j]){
                return 1;  // 'S'
            } 
        }
	 }
	 
	 return 0; // 'N'
}



int main(void) {
    int sudoku[9][9];
    int opt;

    for (int i = 0 ; i < 9; ++i) {
        for (int j=0; j <9; ++j) {
            scanf("%d%*c", &sudoku[i][j]);
        }
    }

    //Digite a opcao (1-5) que deseja executar:
    scanf(" %d%*c", &opt);

    while (opt != 0 ){
        if(opt == 1) {
            int linha,coluna,novo_algarismo;
            scanf("%d%*c %d%*c %d%*c", &linha,&coluna,&novo_algarismo);
            sudoku[linha][coluna] = novo_algarismo;
        } else if (opt==2) {
            int linha;
            scanf("%d%*c", &linha);
			
			int tem_repetido = verificar_linha(linha,sudoku) ? 'S': 'N' ;
	       
			printf("%c\n",tem_repetido);
			
        } else if (opt==3) {
            int coluna;
            scanf("%d%*c", &coluna);
			
			int tem_repetido = verificar_coluna(coluna,sudoku) ? 'S': 'N' ;
	       
			printf("%c\n",tem_repetido);
			
        } else if (opt == 4 ) {
			int quadrante;
			scanf("%d%*c", &quadrante);
		
			int tem_repetido = verificar_quadrante(quadrante, sudoku) ? 'S': 'N';
			
			printf("%c\n", tem_repetido);
		
        } else if (opt == 5) {
			int colunas_ok = 1;
			int linhas_ok = 1;
			int quadrantes_ok = 1;
			for (int i = 0; i < 9 ; ++i) {
				if (verificar_coluna(i, sudoku)){
					colunas_ok = 0;
				}
				if (verificar_linha(i, sudoku)) {
					linhas_ok = 0;
				}
				if (verificar_quadrante(i, sudoku)){
					quadrantes_ok = 0;
				}
			}
			
			if (linhas_ok && colunas_ok &&  quadrantes_ok){
				printf("N\n"); // Matriz perfeita, jogo de sudoku ganho.
			} else {
				printf("S\n"); // tem repeticao em algum lugar
			}
			
        } else {
			for (int i = 0; i < 9; i++) {
			    for (int j = 0; j < 9; j++) {
			      printf("%d ", sudoku[i][j]);

			      // Separar quadrantes com espaços e linhas em branco
			      if (j == 2 || j == 5) {
			        printf(" ");
			      }
			    }

			    // Separar linhas com linhas em branco
			    if (i == 2 || i == 5) {
			      printf("\n\n");
			    } else {
			      printf("\n");
			    }
			  }		
			
        }

        //Digite a opcao (1-5) que deseja executar:
        scanf(" %d%*c", &opt);
    }




    return 0;
}