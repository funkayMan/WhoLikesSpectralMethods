
/*
LGLquadrature.()
	abcissa  - Legendre Gauss-Lobatto abcissa
	weights - Gauss-Lobatto Weights
	nSize  - Polynomial Degree
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
//~ #include "util.h"

//~ LegendreQuad::LegendreQuad()
//~ {
	//~ setElementSize(0);
//~ }

int LegendreQuad::setElementSize(int value){
	nSize=value;
	return nSize;}

int LegendreQuad::getElementSize(){
	return nSize;
}

void LegendreQuad::MakeTmatrix(){
	float fBeta = 1/sqrt(3);
	
	int nSize1=nSize+1;
	
	double tMat[nSize1][nSize1];
	
	// initialize the t matrix
	for(int i = 0; i<nSize1;i++)
	{
		for(int j=0;j<nSize1;j++)
		{
			tMat[i][j]=0.0;
		}
	}	
	// Define the t matrix
	tMat[0][1]=fBeta; tMat[1][0]=fBeta;
	
	double ii=1.0; // this i is used for the calculation (not indexing)
	
        int i;
	for(i=1;i<nSize;i++)
	{
                ii = 1.0+(double)i;
		tMat[i+1][i] = sqrt((2.0*ii-1.0)/(2.0*ii+1.0))*ii/(2.0*ii-1.0);
		tMat[i][i+1] = tMat[i+1][i];
	}
	
	tMat[nSize][nSize-1] = sqrt(ii/(2.0*ii-1.0));
	tMat[nSize-1][nSize] = tMat[nSize][nSize-1];

	// find the eigen values.....

        for(i=0;i<=nSize;++i)
          {
            setCollocation((double)i,i);
            setWeight(0.5*(double)i,i);
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





