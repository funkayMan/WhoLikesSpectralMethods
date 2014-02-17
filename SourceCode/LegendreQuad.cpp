/*

Function performs calculation of quadrature and weights for Legendre-
Gauss-Lobatto Quadrature as outlined in "CALCULATION OF GAUSS
QUADRATURE RULES" Gene H. Golub and John H. Welsch
ftp://reports.stanford.edu/pub/cstr/reports/cs/tr/67/81/CS-TR-67-81.pdf
To build this file use the command to compile:


By: Tyler Arsenault
*/

#include <math.h>
#include "LegendreQuad.h"
#include <iostream>

// LAPACK tridiagonal eigen decomp. type 'man dstev' for details
extern "C" void dstev_(char *jobz, int *n, double *D, double *E, 
double *Z, int *LDZ, double *WORK, int *INFO);


// BLAS matrix product type 'man dgemm' for details, using BLAS for speed/parallelization
extern "C" void dgemm_(char *TRANSA, char *TRANSB, int *M, int *N,
 int *K, double *ALPHA, double *A, int *LDA, double *B, int *LDB, 
 double *BETA, double *C, int *LDC);

int LegendreQuad::setElementSize(int value)
{
	nSize=value;
}

int LegendreQuad::getElementSize()
{
  return nSize;
}

void LegendreQuad::PointsAndWeights()
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
	//~ std::cout<< "ii is " << ii << std::endl;
	ii=ii+1.0;
	E[nSize-1] = sqrt(ii/(2.0*ii-1.0));
	
//***************************************************
// 			      Print Cheby. Matrix			   **
//***************************************************

	//~ std::cout<<"The off diagonals "<< std::endl;
	//~ for(i=0;i<nSize; i++)
	//~ {
		//~ std::cout << E[i] << std::endl;
	//~ }
	//~ std::cout << "\n\n";
//~ 
	//~ std::cout<<"The diagonals "<< std::endl;
	//~ for(i=0;i<nSize+1; i++)
	//~ {
		//~ std::cout << D[i] << std::endl;
	//~ }
	
	
//***************************************************
//**	  Find the eigen values of Cheby. Mat.	   **
//**											   **
//***************************************************
	char c = 'V';		// Retrieve Eig.vecs.
	int LDZ = nSize1;	// Leading dim. or Mat.
	int info;			// Succes of DSTEV
	int N = nSize1;			// Order of mat.
	double Z[nSize1][nSize1];		// Eigenvectors
	double WORK[2*nSize1-2];

// D will be the eigenvalues, Z the eigenvectors
// Call DSTEV LAPACK function
// for more info, call "man dstev" in shell
	dstev_(&c,&N,D,E,&Z[0][0],&LDZ,WORK,&info);
	//~ std::cout << "INFO = " << info << std::endl;
//***************************************************
// 			      Print Eigen Things			   **
//***************************************************
	//~ std::cout << "eigenvalues: " << std::endl;
	//~ for(i=0;i<nSize1;i++)
	//~ {
		//~ std::cout << D[i] << std::endl;
	//~ }
//~ 
	//~ std::cout<< "\n\n";	
	//~ std::cout << "eigenvectors: " << std::endl;
	//~ int j;
	//~ for(j=0;j<nSize1;j++)
	//~ {
		//~ for(i=0;i<nSize1;i++)
		//~ { 
			//~ std::cout << Z[i][j] << "\t";
		//~ }
		//~ std::cout  << std::endl;
	//~ }

//***************************************************
//  Write Legendre-Gauss-Lobatto Points and Weights
//
//***************************************************
	for(i=0;i<nSize1;i++)
	{
		setCollocation(-1.0*D[i],i);
		setWeight(2*pow(Z[i][0],2),i);
		//~ std::cout << getCollocation(i) << "\t " << getWeight(i) << std::endl;
	}
	
}

// LegPolynomials defines the legendre polynomial matrix and 
// normalizing 
void LegendreQuad::LegPolynomials()
{
	const int nSize1=nSize+1;
	int i,j;
	double ii;
	// Initialize the Legendre Polynomial Matrix
	for(j=0;j<nSize1;j++)
	{
		setLegPolys(1.0, 0, j);
		setLegPolys(getCollocation(j), 1, j);
	}
	// Define the Legendre Polys
	double tempNum;
	for(i=2;i<nSize1;i++)
	{
		ii=(double)i;
		for(j=0;j<nSize1;j++)
		{
			tempNum=((2.0*ii-1.0)/ii)*getCollocation(j)*getLegPolys(i-1,j)-((ii-1.0)/ii)*getLegPolys(i-2,j);
			setLegPolys(tempNum,i,j);
		}
	}
	
	// Define the normalizing parameters Gamma
	for(i=0;i<nSize1;i++)
	{
		ii=(double)i;
		tempNum=1.0/(ii+0.5);
		setGamma(tempNum,i);
	}
			
	
}


void LegendreQuad::DerivativeMatrix()
{
	const int nSize1=nSize+1;
	double dummyVar, ii;
	int i,j;
	//initialize the first two rows of the derivatives.
	for(j=0;j<nSize1;j++)
	{
		setLegDeriv(0.0,0,j);
		setLegDeriv(1.0,1,j);
	}
	// define the legendre polynomlial matrix
	for(i=2; i<nSize1; i++)
	{
		for(j=0; j<nSize1; j++)
		{
			ii=(double)i;
			dummyVar=-1.0*(2.0*ii-1)*getLegPolys(i-1,j)+getLegDeriv(i-2,j);
			setLegDeriv(dummyVar,i,j);
		}
	}
	
}

void LegendreQuad::SecondDerivativeMatrix()
{
	char tA = 'T';
	char tB= 'T';
	int nSize1=nSize+1;
	int M=nSize1;
	int N=nSize1;
	int K=nSize1;
	int LDA=nSize1;
	int LDB=nSize1;
	int LDC=nSize1;
	
	double ALPHA = 1.0;
	double BETA = 0.0;
	
	double A[nSize1][nSize1];
	double C[nSize1][nSize1];
	
	int i,j;
	for(j=0;j<nSize1;j++)
	{
		for(i=0;i<nSize1;i++)
		{
			A[i][j]=getLegDeriv(i,j);

		}
	}
	// call the BLAS function dgemm
	dgemm_(&tA,&tB,&M,&N,&K,&ALPHA,&A[0][0],&LDA,&A[0][0],&LDB,&BETA,&C[0][0],&LDC);
	// Will need to transpose C. the output
	for(i=0;i<nSize1;i++)
	{
		for(j=0;j<nSize1;j++)
		{
			setLegSecondDeriv(C[i][j],j,i);
		}
	}	
}

double LegendreQuad::getCollocation(int n)
{
  return(x[n]);
}


void LegendreQuad::setCollocation(double val,int n)
{
  x[n] = val;
}


double LegendreQuad::getWeight(int n)
{
  return(w[n]);
}

void LegendreQuad::setWeight(double val,int n)
{
  w[n] = val;
}

double LegendreQuad::getLegPolys(int n,int nn)
{
	return(LegPoly[n][nn]);
}

// setLegPolys(value, row index, column index)
void LegendreQuad::setLegPolys(double val, int n,int nn)
{
	
	LegPoly[n][nn]=val;
}

double LegendreQuad::getLegDeriv(int n,int nn)
{
	return(LegDeriv[n][nn]);
}
void LegendreQuad::setLegDeriv(double val, int n,int nn)
{
	LegDeriv[n][nn]=val;
}

double LegendreQuad::getLegSecondDeriv(int n,int nn)
{
	return(LegSecondDeriv[n][nn]);
}
void LegendreQuad::setLegSecondDeriv(double val, int n,int nn)
{
	LegSecondDeriv[n][nn]=val;
}

double LegendreQuad::getGamma(int n)
{
  return(G[n]);
}



void LegendreQuad::setGamma(double val,int n)
{
  G[n] = val;
}












