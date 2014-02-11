#ifndef LEGQUAD
#define LEGQUAD

// The biggest matrix we can handle is 10000. If you want more make it bigger.
#define MATSIZE 1001


// For future reference, Legendre-Gauss-Lobatto=LGL
class LegendreQuad{

private:

int nSize;	// This is the element size -1
double x[MATSIZE];	// Collocation pts
double w[MATSIZE];	// Weights
double G[MATSIZE];	// The normalizing parameters
double LegPoly[MATSIZE][MATSIZE];	//Leg polynomial matrix



public:


int setElementSize(int value);
int getElementSize();


// This function calculates points and weights for LGL quadrature
void PointsAndWeights();	

// This function calculates the Legendre polynomials, gamma, 
// for LGL quad
void LegPolynomials();

double getCollocation(int n);
void setCollocation(double val,int n);

double getWeight(int n);
void setWeight(double val,int n);

double getLegPolys(int n,int nn);
void setLegPolys(double val, int n,int nn);

double getGamma(int n);
void setGamma(double val, int n);

protected:


};


#endif
