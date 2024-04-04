#include <stdio.h>
	
	int main (void) {
		float media_atv[5] = {0};
		float media_turma = 0;
		float media_aluno[60] = {0};
		float notas_turma[60][5] = {0};
		
		for(unsigned int aluno = 0; aluno < 60; ++aluno)
		{
			for(unsigned int nota = 0; nota < 5; ++nota)
			{
				scanf("%f%*c", &(notas_turma[aluno][nota]));
				media_aluno[aluno] += (notas_turma[aluno][nota])/5;
				media_atv[nota] += (notas_turma[aluno][nota])/60;
				media_turma += (media_aluno[aluno])/300;
			}			
		}
		printf("A media da turma eh: %.2f\n", media_turma);
		for(int a = 0; a < 60; ++a)
		{
			printf("A media do aluno (%d) eh: %.2f\n", a, media_aluno[a]);
		}
		for(int a = 0; a < 5; ++a)
		{
			printf("A media da atv (%d) eh: %.2f\n", a, media_atv[a]);
		}
		return 0;
	}
	
	
	