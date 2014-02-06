
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

int LegendreQuad::setElementSize(int value)
{
  nSize=value;
  return nSize;
}

int LegendreQuad::getElementSize()
{
  return nSize;
}

//~ void LegendreQuad::tqli(double d,double e,int n,int,double z) {
  //~ /*  QL Algortihm to find the eigen vectors and eigen
      //~ values of a real symmetric tridiagonal matrix.
      //~ Found on page 480 of Numerical Recipes in C, 2nd ed.
//~ 
         //~ d[ ] = diagonal elements
	 //~ e[ ] = subdiagonal elements (e[1] arbitrary)
//~ 
  //~ */
//~ 
  //~ int m,l,iter,i,k;
  //~ double s,r,p,g,f,dd,c,b;
//~ 
  //~ for(i=1;i<=n;++i) {
    //~ for(k=1;k<=n;++k)
      //~ z[i][k] = 0.0;
    //~ z[i][i] = 1.0;
  //~ }
//~ 
  //~ for(i=2;i<=n;++i) e[i-1] = e[i];
  //~ e[n] = 0.0;
  //~ for(l=1;l<=n;++l) {
    //~ iter = 0;
    //~ do {
//~ 
      //~ for(m=l;m<=n-1;m++) {
	//~ dd = fabs(d[m]) + fabs(d[m+1]);
	//~ if ((double)(fabs(e[m]+dd)) == dd) break;
      //~ }
//~ 
      //~ if(m != l) {
	//~ if (iter++==300) {
	  //~ perror("To Many iterations in tqli\n");
	  //~ exit(3);
	//~ }
	//~ g = (d[l+1]-d[l])/(2.0*e[l]);
	//~ r = pythag(g,1.0);
	//~ g = d[m] - d[l] + e[l]/(g+SIGN(r,g));
	//~ s=(c=1.0);
	//~ p = 0.0;
//~ 
	//~ for(i=m-1;i>=l;--i) {
	  //~ f = s*e[i];
	  //~ b = c*e[i];
	  //~ e[i+1] = (r=pythag(f,g));
	  //~ if(fabs(r)==0.0) {
	    //~ d[i+1] -= p;
	    //~ e[m] = 0.0;
	    //~ break;
	  //~ }
	  //~ s = f/r;
	  //~ c = g/r;
	  //~ g = d[i+1] - p;
	  //~ r = (d[i]-g)*s+2.0*c*b;
	  //~ d[i+1] = g + (p=s*r);
	  //~ g = c*r-b;
//~ 
	  //~ for(k=1;k<=n;++k) {
	    //~ f = z[k][i+1];
	    //~ z[k][i+1] = s*z[k][i]+c*f;
	    //~ z[k][i]   = c*z[k][i]-s*f;
	  //~ }
	//~ }
//~ 
	//~ if(r == 0.0 && i) continue;
	//~ d[l] -= p;
	//~ e[l] = g;
	//~ e[m] = 0.0;
      //~ }
//~ 
    //~ } while(m!=l);
  //~ }
//~ }

void LegendreQuad::Eigs()
{
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

/****find the eigen values****/
// Not sure what each of these is yet, waiting for some literature 
// on the algorithm. book in mail..
	int m,l,iter,i,k;
	double s,r,p,g,f,dd,c,b;
	
// Identity matrix formulation
	for(i=1;i<=n;++i)
	{
		for(k=1;k<=n;++k)
		{
			z[i][k] = 0.0;
			z[i][i] = 1.0;
		}
	}
	
// ??? Back to the whole not knowing the algorithm
	for(i=2;i<=n;++i){e[i-1] = e[i]; e[n] = 0.0;}
	
	
	for(l=1;l<=n;++l) 
	{
		iter = 0;
		do
		{
			for(m=l;m<=n-1;m++)
			{
				dd = fabs(d[m]) + fabs(d[m+1]);
				if ((double)(fabs(e[m]+dd)) == dd) break;
			}

		if(m != l)
		{
			if (iter++==300)
			{
				perror("To Many iterations in tqli\n");
				exit(3);
			}
			g = (d[l+1]-d[l])/(2.0*e[l]);
			r = pythag(g,1.0);
			g = d[m] - d[l] + e[l]/(g+SIGN(r,g));
			s=(c=1.0);
			p = 0.0;
	
			for(i=m-1;i>=l;--i) 
			{
				f = s*e[i];
				b = c*e[i];
				e[i+1] = (r=pythag(f,g));
			
				if(fabs(r)==0.0)
				{
					d[i+1] -= p; e[m] = 0.0; break; 
				}
				
				s = f/r;
				c = g/r;
				g = d[i+1] - p;
				r = (d[i]-g)*s+2.0*c*b;
				d[i+1] = g + (p=s*r);
				g = c*r-b;

				for(k=1;k<=n;++k)
				{
					f = z[k][i+1];
					z[k][i+1] = s*z[k][i]+c*f;
					z[k][i]   = c*z[k][i]-s*f;
				}
	}

	if(r == 0.0 && i) continue;
	d[l] -= p;
	e[l] = g;
	e[m] = 0.0;
      }

	}while(m!=l);
		setCollocation
		setWeight(
	}
  
	//~ for(i=0;i<=nSize;++i)
	  //~ {
		//~ setCollocation((double)i,i);
		//~ setWeight(0.5*(double)i,i);
	  //~ }

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





