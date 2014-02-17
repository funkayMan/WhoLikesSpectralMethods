#include <iostream>
#include <math.h>
#include <MatrixOperations.h>


// matrix -vector multiply
//  y := alpha*A*x + beta*y
extern "C" dgemv_(char *TRANS, int *M, int *N, double *ALPHA,
double *A, int *LDA, double* X, int *INCX, double *BETA, double *Y,
int *INCY );

void operations::MatrixSolve()
{	
	int nSize1=nSize+1;
	char t='n';
	int m= nSize1;
	int n = nSize1;
	int LDA = nSize1;
	int incx = 1;
	int incy = 1;
	
	double a = 1.0; // wavespeed
	double b=0.0;
	double y[nSize1];
	
	// Stiffness Multiplication
	// 
	// this is computing
	// 1.0*K*u+0.0*{0.0} = y
	dgemv_(&t, &m, &n, &a, &K[0][0], &LDA, &u[0], &b, &y, &incy);
	
	// Mass Multiplication
	// 
	// this is computing
	// a*M*u+b*y = y
	// where the y is from the result of the prior solve.
	a=5.0;
	dgemv_(&t, &m, &n, &a, &M[0][0], &LDA, &u[0], &b, &y, &incy);
	
	for(i=0;i<nSize1;i++)
	{
		setVec(y[i],i);
	}
	
	
}

void operations::setVec(double val,int i)
{
	u[i]=val;
}
	
double operations::getVec(int i)
{
	return(u[i]);
}

void operations::setMass(double val,int i, int j)
{
	M[i][j]=val;
}
double operations::getMass(int i, int j)
{
	return(M[i][j]);
}

void operations::setStiffness(double val,int i, int j)
{
	K[i][j]=val;
}

double operations::getStiffness(int i, int j)
{
	return(K[i][j]);
}

void operations::setMatrixSoln(double val, int i, int j)
{
	Result[i][j]=val;
}
double operations::getMatrixSoln(int i, int j);
{
	return(Result[i][j];
}
