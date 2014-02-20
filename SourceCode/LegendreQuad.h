#ifndef LEGQUAD
#define LEGQUAD

// How can I remove this MATSIZE 500 business? I'd like to allocate
// memory only as I need it, for instance nSize1 x nSize1??
#define MATSIZE 500


// For future reference, Legendre-Gauss-Lobatto=LGL
class LegendreQuad{

private:

  double w[MATSIZE];	// Weights
  double G[MATSIZE];	// The normalizing parameters
  double LegPoly[MATSIZE][MATSIZE];	//Leg polynomial matrix
  double LegDeriv[MATSIZE][MATSIZE];	//Leg Poly Deriv Matrix


protected:

  double LegSecondDeriv[MATSIZE][MATSIZE];	//Leg Poly Deriv Matrix


public:

	int nSize;	// This is the element size -1
	int nSize1;
	
	double x[MATSIZE];	// Collocation pts

// Constructor
	LegendreQuad(int initial=0);
// Destructor
	~LegendreQuad();
// 
	int setElementSize(int value);
	int getElementSize();


// This function calculates points and weights for LGL quadrature
void PointsAndWeights();	

// This function calculates the Legendre polynomials, gamma, 
// for LGL quad
void LegPolynomials();

// This function calculated the derivative matrix
void DerivativeMatrix();

// This function calculated the second derivative matrix
// which also turn out to be D_2=D_1*D_1;
void SecondDerivativeMatrix();

// Set and Get collocations Pts
double getCollocation(int n);
void setCollocation(double val,int n);

// Set and Get Weights
double getWeight(int n);
void setWeight(double val,int n);

// Set and get legendre Polys
double getLegPolys(int n,int nn);
void setLegPolys(double val, int n,int nn);

// Set and get 1st Derivative matrix
double getLegDeriv(int n,int nn);
void setLegDeriv(double val, int n,int nn);

// Set and get 2nd derivative matrix
double getLegSecondDeriv(int n,int nn);
void setLegSecondDeriv(double val, int n,int nn);

// Set and get normalization parameters
double getGamma(int n);
void setGamma(double val, int n);
};


#endif
