#include <iostream>

# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"
//~ # include "MatrixAssembly.h"
//~ # include "MatrixOperations.h"

//using namespace std;


int main(int argc,char **argv)
{
	int N=5;
	
	BuildMassStiffness dumdum(N);
	dumdum.buildBasis();
	//~ dumdum.PointsAndWeights();
	//~ dumdum.LegPolynomials();
	//~ dumdum.DerivativeMatrix();
	
}
	


