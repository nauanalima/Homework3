#include <stdio.h>
#include <stdlib.h>

double triangsup (double **matrix, int dim) {
	int i, j, k;
	double aux;
	for(j=0; j<=dim; j++) {
		for (i=j+1; i<dim; i++) {
			aux = matrix[i][j]/matrix[j][j];
			for (k=0; k<dim+1; k++)
				matrix[i][k] = matrix[i][k] - aux*matrix[j][k];		
		}
	}
	return **matrix;
}

double **ler(char *archive, int *dimension) {
	int i, j, dim;
	double **matrix, a;
	FILE *arch;

	arch = fopen(archive, "r");

	fscanf(arch,"%d",&dim);

	matrix = malloc(dim*sizeof(double *));
	for (i=0; i<dim; i++)
		matrix[i] = (double *)malloc(dim*sizeof(double));

	for(i=0; i<dim; i++)	{
		for (j=0; j<dim+1; j++)
			fscanf(arch,"%lf",&matrix[i][j]);
	}
	*dimension = dim;
	return matrix;

}

void imprime(double **matrix, int dim){
	int i, j;
	for(i=0;i<dim;i++) {
		for(j=0;j<dim+1;j++) { 
			printf("%5.2lf\t",matrix[i][j]);
		}	  
		printf("\n");
	}
}

int main(int argc, char **argv) {
	double **M;
	double *raizes;
	int i, dim;

	M=ler(argv[1], &dim);
	imprime(M, dim);
	triangsup(M,dim);
	imprime(M, dim);

}
