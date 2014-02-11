/*
LGLquadrature.()
abcissa - Legendre Gauss-Lobatto abcissa
weights - Gauss-Lobatto Weights
nSize - Polynomial Degree
legPoly - Legendre Polynomials on the abcissa
gamma - normalization parameters
Function performs calculation of quadrature and weights for Legendre-
Gauss-Lobatto Quadrature as outlined in "CALCULATION OF GAUSS
QUADRATURE RULES" Gene H. Golub and John H. Welsch
ftp://reports.stanford.edu/pub/cstr/reports/cs/tr/67/81/CS-TR-67-81.pdf
To build this file use the command to compile:
g++ -I /home/wookie/eigen-3.0.5/ ClassQuadrature.cpp -o classquad

Use ./classquad to execute.

By: Tyler Arsenault
*/

#include <math.h>
#include "LegendreQuad.h"
#include <iostream>
//~ #define MATSIZE 20

extern "C" void dstev_(char *jobz, int *n, double *D, double *E, double *Z, int *LDZ, double *WORK, int *INFO);

int LegendreQuad::setElementSize(int value){
nSize=value;
return nSize;}

int LegendreQuad::getElementSize()
{
  return nSize;
}

void LegendreQuad::Eigs()
{
	double fBeta = 1/sqrt(3);

	int nSize1=nSize+1;
	int i;
	
// These are the diagonal elements of chebyshev matrix
	double D[nSize1];
	
	for(i=0;i<nSize1;i++)
	{
		D[i]=0.0;
	}
	
	
// The sub diagonal elements of the Chebchev matrix
	double E[nSize]; 
	E[0]=fBeta;

// this i is used for the calculation (not indexing)
	double ii=1.0; 
	for(i=1;i<nSize-1;i++)
	{
		ii += 1.0;
		E[i] = sqrt((2.0*ii-1.0)/(2.0*ii+1.0))*ii/(2.0*ii-1.0);
	}
	std::cout<< "ii is " << ii << std::endl;
	ii=ii+1.0;
	E[nSize-1] = sqrt(ii/(2.0*ii-1.0));
	
//***************************************************
// 			      Print Cheby. Matrix			   **
//***************************************************

	std::cout<<"The off diagonals "<< std::endl;
	for(i=0;i<nSize; i++)
	{
		std::cout << E[i] << std::endl;
	}
	std::cout << "\n\n";

	std::cout<<"The diagonals "<< std::endl;
	for(i=0;i<nSize+1; i++)
	{
		std::cout << D[i] << std::endl;
	}
	
	
//***************************************************
//**	  Find the eigen values of Cheby. Mat.	   **
//**											   **
//***************************************************
	char c = 'V';		// Retrieve Eig.vecs.
	int LDZ = nSize1;	// Leading dim. or Mat.
	int info;			// Succes of DSTEV
	int N = nSize1;			// Order of mat.
	double Z[nSize1][nSize1];		// Eigenvectors
	double WORK[nSize1];

// D will be the eigenvalues, Z the eigenvectors
// Call DSTEV LAPACK function
// for more info, call "man dstev" in unix shell
	dstev_(&c,&N,D,E,&Z[0][0],&LDZ,WORK,&info);
	std::cout << "INFO = " << info << std::endl;
//***************************************************
// 			      Print Eigen Things			   **
//***************************************************
	std::cout << "eigenvalues: " << std::endl;
	for(i=0;i<nSize1;i++)
	{
		std::cout << D[i] << std::endl;
	}

	std::cout<< "\n\n";	
	std::cout << "eigenvectors: " << std::endl;
	int j;
	for(j=0;j<nSize1;j++)
	{
		for(i=0;i<nSize1;i++)
		{ 
			std::cout << Z[i][j] << "\t";
		}
		std::cout  << std::endl;
	}

//***************************************************
//  Write Legendre-Gauss-Lobatto Points and Weights
//
//***************************************************
	for(i=0;i<nSize1;i++)
	{
		setCollocation(-1.0*D[i],i);
		setWeight(2*Z[1][i]*Z[1][i],i);
		std::cout << -1.0*D[i] << "\t " << 2*Z[1][i]*Z[1][i] << std::endl;
	}
	
}


double LegendreQuad::getCollocation(int n)
{
  return(x[n]);
}

double LegendreQuad::getWeight(int n)
{
  return(w[n]);
}


void LegendreQuad::setCollocation(double val,int n)
{
  x[n] = val;
}

void LegendreQuad::setWeight(double val,int n)
{
  w[n] = val;
}

