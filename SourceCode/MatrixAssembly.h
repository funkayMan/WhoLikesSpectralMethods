#ifndef MATASSEMBLE
#define MATASSEMBLE


# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"

class GlobalMatrixConstruct : protected BuildMassStiffness
{
protected:
	int n_el;
// Need to figure out how to streamline this memory allocation. 
// I mean, after I make the legpoly and all that stuff I should destruct
// to make more space. Also, I would like to only allocate what is 
// exactly required for storage not this MATSIZE business. 
	double GlobalM[MATSIZE][MATSIZE];	// Mass Matrix
	double GlobalK[MATSIZE][MATSIZE];	// Stiffness Matrix	

public:
// construct & destruct
	GlobalMatrixConstruct(int n_el, int value=0);
	~GlobalMatrixConstruct();
	//~ 
	//~ void AssembleGlobalMass();
	//~ 
	//~ void AssembleGlobalStiffness();
//~ 
	void setNumElements(int val);
	int getNumElements();
	//~ 
	//~ void setGlobalMass(double val,int i, int j);
	//~ double getGlobalMass(int i, int j);
	//~ 
	//~ void setGlobalStiffness(double val,int i, int j);
	//~ double getGlobalStiffness(int i, int j);
	

};

#endif
