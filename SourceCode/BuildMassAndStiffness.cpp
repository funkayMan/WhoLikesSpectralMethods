#include <iostream>
#include <math.h>
# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"

extern "C" void dgemm_(char *TRANSA,char *TRANSB, int *M, int *N, int *K, 
double *ALPHA, double *A, int *LDA, double* B, int *LDB, double *BETA, 
double *C,int *LDC );



BuildMassStiffness::BuildMassStiffness(int value) : LegendreQuad(value)
{
	std::cout << "Constructing BuildMassStiffness" << std::endl;
	// call the functions from legendreQuad so we have that info.
	PointsAndWeights();
	LegPolynomials();
	DerivativeMatrix();
}

BuildMassStiffness::~BuildMassStiffness(void)
{
	std::cout << "Destructing BuildMassStiffness" << std::endl;
}


void BuildMassStiffness::buildBasisDerivative()
{
//******************************************
// Define the derivative matrix from 
// Hesthaven p. 95 for Legendre
//******************************************

	int i,j;
	double dummy;
	double D1[nSize1][nSize1];
	
	for(i=0;i<nSize1;i++)
	{
		for(j=0;j<nSize1;j++)
		{
			if(i==j && i==0)
			{
				dummy=-(double)nSize*((double)nSize+1.0)/4.0;
			}
			if(i==j && i == nSize)
			{
				dummy=(double)nSize*((double)nSize+1.0)/4.0;
			}
			if(i==j && i>= 1 && i <= nSize-1)
			{
				dummy=0.0;
			}

			if(i!=j)
			{	
				dummy=(getLegPolys(nSize,i)/getLegPolys(nSize,j))/(getPoints(i)-getPoints(j));
			}
			setDerivativeMatrix(dummy,i,j);
		}
	}
}
void BuildMassStiffness::buildStiffness()
{
	int m,n,k;
	double k_el;
	for(m=0;m<nSize1;m++)
	{
		for(n=0;n<nSize1;n++)
		{
			k_el=0;
			for(k=0;k<nSize1;k++)
			{
				k_el=k_el+getDerivativeMatrix(m,k)*getDerivativeMatrix(n,k)*getWeight(k);
			}
			setStiffness(k_el,m,n);
		}
	}
	int i,j;
	std::cout << "Stiffness matrix" << std::endl;
	for(i=0; i<nSize1; i++)
	{
		for(j=0; j<nSize1; j++)
		{
			std::cout<< getStiffness(i,j) << "\t" ;
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}

void BuildMassStiffness::setDerivativeMatrix(double val,int i, int j)
{
	D[i][j]=val;
}
double BuildMassStiffness::getDerivativeMatrix(int i, int j)
{
	return(D[i][j]);
}

void BuildMassStiffness::setStiffness(double val,int i, int j)
{
	K[i][j]=val;
}
double BuildMassStiffness::getStiffness(int i, int j)
{
	return(K[i][j]);
}
