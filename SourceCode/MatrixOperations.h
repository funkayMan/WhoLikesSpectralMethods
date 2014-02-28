#ifndef MATOPS
#define MATOPS


# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"
# include "MatrixAssembly.h"

class MatOperations : protected BuildMassStiffness
{
private:
	double M[MATSIZE][MATSIZE];	// Mass Matrix
	double K[MATSIZE][MATSIZE];	// Stiffness Matrix	
	double a;
	
public:

// construct & destruct
	MatOperations(int value=0);
	~MatOperations();

	//~ double u[MATSIZE];
	//~ 
	//~ void MatrixSolve();
	//~ 
	//~ void setVecIn(double val,int i);
	//~ double getVecIn(int i);
	//~ 
	//~ void setVecOut(double val,int i);
	//~ double getVecOut(int i);
	//~ 
//~ public:
	//~ double result[MATSIZE];	// Resultant matrix
};

#endif
