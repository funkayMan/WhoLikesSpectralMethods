#ifndef MASSSTIFF
#define MASSSTIFF


# include "LegendreQuad.h"


// Some notes
// 1. The basis function matrix is the identity. keep that in mind when
// it is needed...
//
// 2. The Mass matrix the weights on the diagonal, also keep that in mind
class BuildMassStiffness : protected LegendreQuad
{
private:
	//~ double phi[MATSIZE][MATSIZE];		// Basis Functions
	double D[MATSIZE][MATSIZE]; // Basis Derivatives

protected:
	double K[MATSIZE][MATSIZE];	// Stiffness Matrix	
	
public:
// construct & destruct
	BuildMassStiffness(int value=0);
	~BuildMassStiffness();
	
	void buildBasisDerivative();
	
	void buildStiffness();
	
	void setDerivativeMatrix(double val,int i, int j);
	double getDerivativeMatrix(int i, int j);
	
	void setStiffness(double val,int i, int j);
	double getStiffness(int i, int j);
	

};

#endif
