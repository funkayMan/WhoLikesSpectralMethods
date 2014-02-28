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
}

BuildMassStiffness::~BuildMassStiffness()
{
	std::cout << "Destructing BuildMassStiffness" << std::endl;
}


void BuildMassStiffness::buildMass()
{	

	int i,j;
	for(i=0;i<nSize1;i++)
	{
		setMass(getWeight(i),i,i);
		//~ std::cout << getWeight(i) << std::endl;
	}
	
	//*******************************************
	//  Print Mass Matrix 
	//*******************************************
	//~ std::cout << "\n The Mass Matrix: " << std::endl;
	//~ for(i=0;i<nSize1;i++)
	//~ {
		//~ for(j=0;j<nSize1;j++)
		//~ {
			//~ 
			//~ std::cout << getMass(i,j) <<"\t";			
		//~ }
		//~ std::cout << std::endl;
	//~ }
}

void BuildMassStiffness::buildStiffness()
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
				//~ dummy=1.0;
				dummy=(getLegPolys(nSize,i)/getLegPolys(nSize,j))/(getCollocation(i)-getCollocation(j));
			}
			D1[i][j]=dummy;
		}
	}
	
	// The send derivative matrix (the stiffness matrix is D_1*D_1)
	// so we use the BLAS dgemm code to multiply the matrix
	char tA='n';
	char tB='n';
	
	int M = nSize1;
	int N = nSize1;
	int K = nSize1;
	
	double a = 1.0;
	double b=0.0;
	double D2[nSize1][nSize1];
	dgemm_(&tA, &tB, &M, &N, &K, &a, &D1[0][0], &nSize1, &D1[0][0], 
	&nSize1, &b, &D2[0][0], &nSize1); 
	
	//*******************************************
	//  Print Stiffness Matrix 
	//*******************************************
	
	//~ std::cout << "\n The second Derivative Matrix: " << std::endl;
	//~ for(i=0;i<nSize1;i++)
	//~ {
		//~ for(j=0;j<nSize1;j++)
		//~ {
			//~ std::cout << D2[i][j] <<"\t";			
		//~ }
		//~ std::cout << std::endl;
	//~ }	
}

void BuildMassStiffness::setMass(double val,int i, int j)
{
	M[i][j]=val;
}
double BuildMassStiffness::getMass(int i, int j)
{
	return(M[i][j]);
}

void BuildMassStiffness::setStiffness(double val,int i, int j)
{
	K[i][j]=val;
}
double BuildMassStiffness::getStiffness(int i, int j)
{
	return(K[i][j]);
}
