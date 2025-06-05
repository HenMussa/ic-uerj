#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função para distribuir as partículas e armazenar os dados obtidos. 
void distribuicao(int N){
	FILE *ftp;
	ftp = fopen("dados.csv", "w+");
	fprintf(ftp, "Partícula,Esquerda,Direita,PorcentagemEsquerda,PorcentagemDireita\n");

	srand(time(NULL));
	int esquerda = 0;
	int direita = 0;

	// roda um loop para cada partícula, onde decide se iá para esquerda ou direita 
	for (int i = 1; i <= N; ++i)
	{	
		// a função rand() % 2 escolhe um inteiro dentro do intervalo fechado de 0 à 1
		// se r == 0, então a parícula vai para a esquerda da caixa, caso contrário, para a direita.
		int r = rand() % 2;
		if (r == 0) {
			++esquerda;
		} else {
			++direita;
		}
		//Porcentagem de distribuição
		double percEs = ((double)esquerda*100)/(double)i;
		double percDi = ((double)direita*100)/(double)i;
		
		fprintf(ftp, "%i,%i,%i,%f%%,%f%%\n", i, esquerda, direita, percEs, percDi);
	}
	fclose(ftp);
}

void input(){
	int N;

	puts("\nDigite o número de partículas: \n");
	scanf("%i", &N);
	distribuicao(N);
} 

void main()
{
	input();
}