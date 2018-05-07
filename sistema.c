#include <stdio.h>
#include <stdlib.h>

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

void imprimir(double **matrix, int dim){
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
	imprimir(M, dim);
}
