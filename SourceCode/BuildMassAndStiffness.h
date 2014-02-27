#ifndef MASSSTIFF
#define MASSSTIFF


# include "LegendreQuad.h"

class BuildMassStiffness : protected LegendreQuad
{
protected:
	double M[MATSIZE][MATSIZE];	// Mass Matrix
	double K[MATSIZE][MATSIZE];	// Stiffness Matrix	
	double phi[MATSIZE];		// Basis Functions
	double a;
	
public:
// construct & destruct
	BuildMassStiffness(int value=0);
	~BuildMassStiffness();
	
	void buildMass();
	
	void buildStiffness();
	
	void setBasis(double val,int i);
	double getBasis(int i);
	
	void setMass(double val,int i, int j);
	double getMass(int i, int j);
	
	void setStiffness(double val,int i, int j);
	double getStiffness(int i, int j);
	

};

#endif
