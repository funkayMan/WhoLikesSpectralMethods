
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

#include <iostream>
#include <math.h>
#include "LegendreQuad.h"

LegendreQuad::LegendreQuad()
{setElementSize(0);}

void LegendreQuad::setElementSize(int value){return nSize;}

double LegendreQuad::MakeTmatrix(){
	float fBeta = 1/sqrt(3);
	
	int nSize1=nSize+1;
	
	double tMat[nSize][nSize];
	
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
	
	double ii=1; // this i is used for the calculation (not indexing)
	
	for(int i=1;i<nSize;i++)
	{
		ii++;
		tMat[i+1][i] = sqrt((2*ii-1)/(2*ii+1))*ii/(2*ii-1);
		tMat[i][i+1] = tMat[i+1][i];
	}
	
	tMat[nSize][nSize-1] = sqrt(ii/(2*ii-1));
	tMat[nSize-1][nSize] = tMat[nSize][nSize-1];

	return tMat;}





