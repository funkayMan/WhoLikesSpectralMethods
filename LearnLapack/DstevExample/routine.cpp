#include<iostream>

extern "C" void dstev_(char *jobz, int *n, double *D, double *E, double *Z, int *LDZ, double *WORK, int *INFO);

int main() {
	char c = 'V';
	const int n = 5;
	int LDZ = n;
	int info;
	int N = n;
	
	
	double D[n];  // Diagonal elements
	// D becomes the eigenvalues.
	double E[n];  // n-1 subdiagonal elements
	
	D[0]=0.0;
	int i;
	for(i=1;i<N;i++)
	{
		D[i]=D[i-1]+1.0;
	}
	
	E[0]=0.0;
	for(i=1;i<N-1;i++)
	{
		E[i]=E[i-1]+2.0;
	}
	
	std::cout << "diag values are: " << std::endl;
	for(i=0;i<n;i++)
	{
		std::cout << D[i] << std::endl;
	}
	std::cout<< "\n\n";
	
	std::cout << "subdiag values are: " << std::endl;
	for(i=0;i<n-1;i++)
	{
		std::cout << E[i] << std::endl;
	}
	std::cout<< "\n\n";
	
	double Z[n][n];
	double WORK[n];
	
	dstev_(&c,&N,D,E,&Z[0][0],&LDZ,WORK,&info);
	
	std::cout << info << std::endl;
	

	std::cout << "eigenvalues: " << std::endl;
	for(i=0;i<n;i++)
	{
		std::cout << D[i] << std::endl;
	}
	
	std::cout<< "\n\n";	
	std::cout << "eigenvectors: " << std::endl;
	int j;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{ 
			std::cout << Z[i][j] << "\t";
		}
		std::cout  << std::endl;
	}
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
