#ifndef OPS
#def OPS

#define MATSIZE 500

class operations
{
private:
	int nSize;
	double K[MATSIZE][MATSIZE];  // Stiffness Matrix
	double M[MATSIZE][MATSIZE];  // Mass Matrix
	double Result[MATSIZE][MATSIZE];	// Resultant matrix
	double u[MATSIZE];
	double a;
	
protected:
// The matrix system looks like
// [K+a*M]*u which will be solve as K*u+b*M*u for varying mass matrix form
	void MatrixSolve();
	
	void setVec(double val,int i, int j);
	double getVec(int i, int j);
	
	void setMass(double val,int i, int j);
	double getMass(int i, int j);
	
	void setStiffness(double val,int i, int j);
	double getStiffness(int i, int j);
	
	void setMatrixSoln(double val, int i, int j);
	double getMatrixSoln(int i, int j);
public:
}

#endif
