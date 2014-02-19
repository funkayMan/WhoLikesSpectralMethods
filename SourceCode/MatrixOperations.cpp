#include <iostream>
#include <math.h>


# include "LegendreQuad.h"


// matrix -vector multiply
//  y := alpha*A*x + beta*y
extern "C" dgemv_(char *TRANS, int *M, int *N, double *ALPHA,
double *A, int *LDA, double* X, int *INCX, double *BETA, double *Y,
int *INCY );


// Not totally sure this syntax makes sense.
MatOperations::MatOperations(double input_vector) : LegendreQuad(value)
{
	std::cout << "Constructing MatrixOperations " << std::endl;
	// define the input vector "u"
	int i;
	for(i=0;i<(value+1);i++)
	{
		setVecIn(double input_vector[i],int i)
	}
}

MatOperations::~MatOperations();
{
	std::cout << "Destructing MatrixOperations " << std::endl;
}

void MatOperations::MatrixSolve()
{	
	char t='n';
	int m= nSize1;
	int n = nSize1;
	int LDA = nSize1;
	int incx = 1;
	int incy = 1;
	
	double a = 1.0;
	double b=0.0;
	double y[nSize1];
	
	// Stiffness Multiplication
	// 
	// this is computing
	// 1.0*K*u+0.0*{0.0} = y
	dgemv_(&t, &m, &n, &a, &LegSecondDeriv[0][0], 
	&LDA, &u[0], &b, &y, &incy);
	
	// Mass Multiplication
	// 
	// this is computing
	// a*M*u+b*y = y
	// where the y is from the result of the prior solve.
	double M[nSize1][nSize1];
	
	// set M as identity for now.
	int i;
	for(i=0;i<nSize1;i++)
	{
		M[i][i]=1.0;
	}
	
	a=5.0;	// wavespeed
	b=1.0;	// just makes it a simple add
	dgemv_(&t, &m, &n, &a, &M[0][0], &LDA, &u[0], &b, &y, &incy);
	
	for(i=0;i<nSize1;i++)
	{
		setVec(y[i],i);
	}	
	
}

void MatOperations::setVecIn(double val,int i)
{
	u[i]=val;
}
	
double MatOperations::getVecIn(int i)
{
	return(u[i]);
}

void MatOperations::setVecOut(double val,int i)
{
	result[i]=val;
}
	
double MatOperations::getVecOut(int i)
{
	return(result[i]);
}


void MatOperations::setMass(double val,int i, int j)
{
	M[i][j]=val;
}
double MatOperations::getMass(int i, int j)
{
	return(M[i][j]);
}

//~ void operations::setStiffness(double val,int i, int j)
//~ {
	//~ K[i][j]=val;
//~ }
//~ 
//~ double operations::getStiffness(int i, int j)
//~ {
	//~ return(K[i][j]);
//~ }
