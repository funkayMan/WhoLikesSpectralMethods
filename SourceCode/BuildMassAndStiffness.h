#ifndef MASSSTIFF
#define MASSSTIFF


# include "LegendreQuad.h"

class BuildMassStiffness : protected LegendreQuad
{
private:
	double phi[MATSIZE][MATSIZE];		// Basis Functions
	double D[MATSIZE][MATSIZE]; // Basis Derivatives

protected:
	double M[MATSIZE][MATSIZE];	// Mass Matrix
	double K[MATSIZE][MATSIZE];	// Stiffness Matrix	
	double a;
	
public:
// construct & destruct
	BuildMassStiffness(int value=0);
	~BuildMassStiffness();
	
	void buildMass();
	
	void buildBasis();
	
	void buildStiffness();
	
	void setMass(double val,int i, int j);
	double getMass(int i, int j);
	
	void setBasis(double val,int i,int j);
	double getBasis(int i,int j);
	
	void setDerivativeMatrix(double val,int i, int j);
	double getDerivativeMatrix(int i, int j);
	
	void setStiffness(double val,int i, int j);
	double getStiffness(int i, int j);
	

};

#endif
