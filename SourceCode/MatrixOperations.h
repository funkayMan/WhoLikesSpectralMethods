#ifndef MATOPS
#define MATOPS


# include "LegendreQuad.h"

class MatOperations : protected LegendreQuad
{
private:
	double M[MATSIZE][MATSIZE];  // Mass Matrix
	
	double a;
	
public:

// construct & destruct
	MatOperations(double input_vector=0);
	~MatOperations();

	double u[MATSIZE];
	
	void MatrixSolve();
	
	void setVecIn(double val,int i);
	double getVecIn(int i);
	
	void setVecOut(double val,int i);
	double getVecOut(int i);
	
	void setMass(double val,int i, int j);
	double getMass(int i, int j);
	
public:
	double result[MATSIZE];	// Resultant matrix
};

#endif
