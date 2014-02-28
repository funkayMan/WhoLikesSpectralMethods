#include <iostream>
#include <math.h>

# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"
# include "MatrixAssembly.h"

// construct & destruct
GlobalMatrixConstruct::GlobalMatrixConstruct(int n_el,int value) : BuildMassStiffness(value)
{
	std::cout << "Constructing AssembleMatrix" << std::endl;
	
	setNumElements(n_el);
	
	buildMass();
	buildStiffness();
}

GlobalMatrixConstruct::~GlobalMatrixConstruct()
{
	std::cout << "Destructing AssembleMatrix" << std::endl;
}


//~ GlobalMatrixConstruct::AssembleGlobalMass()
//~ {
	//~ int i,j;
	//~ int index;
	//~ double dum;
	//~ 
	//~ for(j=0;j<n_el;j++)
	//~ {
		//~ for(i=0;i<nSize1;i++)
		//~ {
			//~ index=nSize1*n_el+i;
			//~ dum=getMass(i,i);
			//~ setGlobalMass(dum,index,index);
		//~ }
	//~ }
	//~ 
	//~ for(i=0;i<(
//~ }
//~ GlobalMatrixConstruct::AssembleGlobalStiffness();
//~ 
GlobalMatrixConstruct::setNumElements(int val)
{
	n_el=val;
}

GlobalMatrixConstruct::getNumElements()
{
	return(n_el);
}
//~ 
//~ GlobalMatrixConstruct::setGlobalMass(double val,int i, int j)
//~ {
	//~ GlobalM[i][j]=val;
//~ }
//~ 
//~ GlobalMatrixConstruct::getGlobalMass(int i, int j)
//~ {
	//~ return(GlobalM[i][j]);
//~ }
//~ 
//~ GlobalMatrixConstruct::setGlobalStiffness(double val,int i, int j)
//~ {
	//~ GlobalK[i][j]=val;
//~ }
//~ 
//~ GlobalMatrixConstruct::getGlobalStiffness(int i, int j)
//~ {
	//~ return(GlobalK[i][j]);
//~ }



