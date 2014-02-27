#include <iostream>
#include <math.h>


# include "LegendreQuad.h"
# include "BuildMassAndStiffness.h"


// Not totally sure this syntax makes sense.
BuildMassStiffness::BuildMassStiffness(int value) : LegendreQuad(value)
{
	std::cout << "Constructing MatrixOperations " << std::endl;
	// call the functions from legendreQuad so we have that info.
	PointsAndWeights();
	LegPolynomials();
}

BuildMassStiffness::~BuildMassStiffness()
{
	std::cout << "Destructing MatrixOperations " << std::endl;
}


void BuildMassStiffness::buildMass()
{	

	int i,j;
	for(i=0;i<nSize1;i++)
	{
		setMass(getWeight(i),i,i);
		//~ std::cout << getWeight(i) << std::endl;
	}
	
	std::cout << "\n The Mass Matrix: " << std::endl;
	for(i=0;i<nSize1;i++)
	{
		for(j=0;j<nSize1;j++)
		{
			
			std::cout << getMass(i,j) <<"\t";			
		}
		std::cout << std::endl;
	}
}

void BuildMassStiffness::buildStiffness()
{
	int i,j;
	double dummy;
	
	for(i=0;i<nSize1;i++)
	{
		for(j=0;j<nSize1;j++)
		{
			if(i==j && i==0)
			{
				dummy=-(double)nSize*((double)nSize+1.0)/4.0;
			}
			else if(i==j && i>= 1 && i <= nSize)
			{
				dummy=0.0;
			}
			else if(i==j && i == nSize1)
			{
				dummy=double(nSize);
			}
			else
			{
				dummy=getLegPolys(nSize1,i)/(getLegPolys(nSize1,i)*getCollocation(i)-getCollocation(j));
			}
			setStiffness(dummy,i,j);			
		}
	}
	
	std::cout << "\n The Stiffness Matrix: " << std::endl;
	for(i=0;i<nSize1;i++)
	{
		for(j=0;j<nSize1;j++)
		{
			std::cout << getStiffness(i,j) <<"\t";			
		}
		std::cout << std::endl;
	}	
}

void BuildMassStiffness::setMass(double val,int i, int j)
{
	M[i][j]=val;
}
double BuildMassStiffness::getMass(int i, int j)
{
	return(M[i][j]);
}

void BuildMassStiffness::setStiffness(double val,int i, int j)
{
	K[i][j]=val;
}
double BuildMassStiffness::getStiffness(int i, int j)
{
	return(K[i][j]);
}
