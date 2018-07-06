#include <stdio.h>
#include <stdlib.h>

double subsreversa (double **matrix, double *root, const int dim) {
	int j, k, n;
	double sum;
	root[dim-1] = matrix[dim-1][dim]/matrix[dim-1][dim-1];
	k = dim-2;
	while (k>=0) {
		sum = matrix[k][dim];
		for (j=k+1; j<dim; j++) 
			sum = sum - matrix[k][j]*root[j];
		root[k] = sum/matrix[k][k];
		k--;
	}
}

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
	printf("Matriz: \n");
	for(i=0;i<dim;i++) {
		for(j=0;j<dim+1;j++) { 
			printf("%5.2lf\t",matrix[i][j]);
		}	  
		printf("\n");
	}
	printf("\n");
}

int main(int argc, char **argv) {
	double **M;
	double *raizes;
	int i, dim;

	M=ler(argv[1], &dim);
	imprime(M, dim);
	triangsup(M,dim);
	imprime(M, dim);
	raizes = malloc(dim*sizeof(double));
	subsreversa(M,raizes,dim);
	for (i=0; i<dim; i++)
		printf("x%1d = %5.2lf\n", i, raizes[i]);
	return 0;
}
